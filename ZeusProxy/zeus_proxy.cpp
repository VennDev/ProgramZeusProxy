#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "zeus_proxy.h"
#include "loader/zeus_type_loader.h"
#include "compat/packet_manager.h"
#include "alert/alert_manager.h"
#include "utils/zmath.h"
#include "protocols/protocols.h"
#include "data/manager/data_manager.h"

#include <winsock2.h>
#include <future>
#include <fstream>
#include <string>
#include <ws2def.h>
#include <Windows.h>
#include <cmath>
#include <nlohmann/json.hpp>

using namespace std;
using namespace loader;
using namespace compat;
using namespace alert;
using namespace utils;
using namespace data;
using namespace protocols;

int main()
{
	SetConsoleTitleW(L"Zeus Proxy 1.0.0-ALPHA");

	packet_manager packet_manager;

	short size_font = 14;

	unsigned short port = 19137;
	std::string hostname = "127.0.0.1";
	std::string file_settings = "proxy.json";

	bool debug = false;

	std::ifstream file(file_settings);
	bool file_exists = file.good();
	file.close();

	if (!file_exists) {
		std::ofstream output_file(file_settings);
		if (output_file.is_open()) {
			nlohmann::json json_data;
			
			json_data["hostname"] = "127.0.0.1";
			json_data["port"] = 19137;
			json_data["size-font-terminal"] = 14;
			json_data["debug-mode"] = false;

			nlohmann::json database;
			database["type"] = "mysql";
			database["user"] = "root";
			database["password"] = "";
			database["host"] = "localhost";
			database["port"] = 3306;
			
			json_data["data-base"] = database;

			output_file << std::setw(4) << json_data;
			output_file.close();
			
			alert_manager::alert_notice("Creating one json data...");
		}
		else
		{
			alert_manager::alert_error("Failed in creating one json data!");
		}
	} 
	else
	{
		std::ifstream input_file(file_settings);
		if (input_file.is_open()) {
			nlohmann::json json_data;
			input_file >> json_data;
			input_file.close();

			if (
				json_data.contains("hostname") && 
				json_data.contains("port") &&
				json_data.contains("size-font-terminal") &&
				json_data.contains("debug-mode") &&
				json_data.contains("data-base")
			) {
				hostname = json_data["hostname"];
				port = json_data["port"];
				debug = static_cast<bool>(json_data["debug-mode"]);

				if (z_math::can_double_to_short(json_data["size-font-terminal"])) size_font = static_cast<short>(json_data["size-font-terminal"]);
			}
		}
		else
		{
			alert_manager::alert_error("Failed to open file for reading.");
		}
	}

	HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_FONT_INFOEX font_info;
	font_info.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(console_handle, FALSE, &font_info);

	double font_y = floor(size_font * 0.2 + size_font);

	if (z_math::can_double_to_short(font_y)) {
		auto cal_font_y = static_cast<short>(font_y);
		font_info.dwFontSize.X = static_cast<short>(floor(size_font));
		font_info.dwFontSize.Y = cal_font_y;
	}
	else 
	{
		font_info.dwFontSize.X = static_cast<short>(floor(size_font));
		font_info.dwFontSize.Y = static_cast<short>(font_y);
		alert_manager::alert_warning("The Font Size value of double cannot be converted to SHORT due to exceeding the range.");
	}

	SetCurrentConsoleFontEx(console_handle, FALSE, &font_info);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 63);

	alert_manager::alert_info("Currently supported for several database types such as: MySQL.");
	alert_manager::alert_info("Listing on " + hostname + ":" + std::to_string(port));

	zeus_type_loader::load();
	packet_manager::enable();

	WSADATA wsa_data;
	SOCKADDR_IN server_address;

	if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0) return 1;

	const SOCKET server = socket(AF_INET, SOCK_DGRAM, 0);

	server_address.sin_addr.s_addr = inet_addr(hostname.c_str());
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(port);

	const int i_result = ::bind(server, reinterpret_cast<SOCKADDR*>(&server_address), sizeof(server_address));

	if (i_result == SOCKET_ERROR) {
		wprintf(L"bind failed with error %u\n", WSAGetLastError());
		closesocket(server);
		WSACleanup();
		return 1;
	}

	listen(server, 0);

	alert_manager::alert_info("Listening for incoming connections...");
	for (;;)
	{
		try
		{
			sockaddr remote_address{};

			char buffer[256] = { 0 };
			int remote_address_size = sizeof(remote_address);

			const int bytes_received = recvfrom(server, buffer, sizeof(buffer), 0, &remote_address, &remote_address_size);

			if (bytes_received != SOCKET_ERROR)
			{
				std::string str(buffer);
				nlohmann::json data = nlohmann::json::parse(str);

				if (debug) alert_manager::alert_debug(str);

				packet* packet = protocol::process_data_packet(data);

				if (packet == nullptr) {
					alert_manager::alert_warning("Can't process packet.");
					continue;
				}

				manager::player_data player_data = manager::data_manager::get_player_data(packet->origin);
				if (player_data.get_name() != "null" && player_data.get_xuid() != "null") {
					player_data.handle_packet(packet);

					if (dynamic_cast<packet_player_logout*>(packet))
					{
						packet_player_logout* packet_logout = dynamic_cast<packet_player_logout*>(packet);
						manager::data_manager::uninject(packet_logout->get_origin());
						alert_manager::alert_info("Player " + packet_logout->get_origin() + " has left the game.");
					}
				}
				else
				{
					// If the player is not in the list,
					// then we will check if the player is logging in or logging out.
					if (dynamic_cast<packet_player_login*>(packet)) {
						packet_player_login* packet_login = dynamic_cast<packet_player_login*>(packet);
						manager::data_manager::inject(packet_login->get_origin(), packet_login->get_xuid());
						alert_manager::alert_info("Player " + packet_login->get_origin() + " has joined the game.");
					}
				}

				delete packet;

				auto packet_list = packet_manager.get_handler().get_packet_list();
				packet_manager.get_handler().drop_packets();
			}
		}
		catch (const std::exception& e)
		{
			alert_manager::alert_error(e.what());
		}
	}
}