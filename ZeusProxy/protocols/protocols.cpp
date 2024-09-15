#include "protocols.h"

#include <vector>

namespace protocols
{

	packet* protocol::process_data_packet(nlohmann::json data)
	{
		int id = data["id"];
		std::string origin = static_cast<std::string>(data["origin"]);
		double time_current = data["timeCurrent"];

		packet* p = nullptr;

		if (id == PACKET_KEEP_ALIVE) {
			p = new packet_keep_alive(id, origin, time_current);
		}
		else if (id == PACKET_PLAY_IN_CHANGE_MODE)
		{
			unsigned char mode = data["mode"];
			p = new packet_play_in_change_mode(id, origin, time_current, mode);
		}
		else if (id == PACKET_PLAY_IN_CLOSE_WINDOW)
		{
			p = new packet_play_in_close_window(id, origin, time_current);
		}
		else if (id == PACKET_PLAY_IN_DEATH)
		{
			float x = data["x"];
			float y = data["y"];
			float z = data["z"];
			p = new packet_play_in_death(id, origin, time_current, x, y, z);
		}
		else if (id == PACKET_PLAY_IN_HELD_ITEM_SLOT)
		{
			int idi = data["idi"];
			int meta = data["meta"];
			int slot = data["slot"];
			std::string name = static_cast<std::string>(data["name"]);
			std::string lore = static_cast<std::string>(data["lore"]);
			p = new packet_play_in_held_item_slot(id, origin, time_current, idi, meta, slot, name, lore);
		}
		else if (id == PACKET_PLAY_IN_OPEN_WINDOW)
		{
			p = new packet_play_in_open_window(id, origin, time_current);
		}
		else if (id == PACKET_PLAY_IN_ROTATION)
		{
			float yaw = data["yaw"];
			float pitch = data["pitch"];
			p = new packet_play_in_rotation(id, origin, time_current, yaw, pitch);
		}
		else if (id == PACKET_PLAY_IN_SNEAKING)
		{
			p = new packet_play_in_sneaking(id, origin, time_current);
		}
		else if (id == PACKET_PLAY_IN_SPRINTING)
		{
			p = new packet_play_in_sprinting(id, origin, time_current);
		}
		else if (id == PACKET_PLAY_IN_STEER_VEHICLE)
		{
			float strafe = data["strafe"];
			float forward = data["forward"];
			p = new packet_play_in_steer_vehicle(id, origin, time_current, strafe, forward);
		}
		else if (id == PACKET_PLAY_IN_TRANSACTION)
		{
			int source_type = data["sourceType"];
			int source_flags = data["sourceFlags"];
			unsigned char slot = data["slot"];
			p = new packet_play_in_transaction(id, origin, time_current, source_type, source_flags, slot);
		}
		else if (id == PACKET_PLAY_IN_USE_ENTITY)
		{
			float origin_x = data["originX"];
			float origin_y = data["originY"];
			float origin_z = data["originZ"];
			float origin_yaw = data["originYaw"];
			float origin_pitch = data["originPitch"];
			float target_x = data["targetX"];
			float target_y = data["targetY"];
			float target_z = data["targetZ"];
			float target_yaw = data["targetYaw"];
			float target_pitch = data["targetPitch"];
			p = new packet_play_in_use_entity(id, origin, time_current, origin_x, origin_y, origin_z, origin_yaw, origin_pitch, target_x, target_y, target_z, target_yaw, target_pitch);
		}
		else if (id == PACKET_PLAY_OUT_BLOCKS_DOWN)
		{
			std::vector<int> blocks = data["blocks"];
			p = new packet_play_out_blocks_down(id, origin, time_current, blocks);
		}
		else if (id == PACKET_PLAY_OUT_ENTITY_EFFECT)
		{
			unsigned char effect_id = data["effectId"];
			float amplifier = data["amplifier"];
			float duration = data["duration"];
			unsigned char flags = data["flags"];
			p = new packet_play_out_entity_effect(id, origin, time_current, effect_id, amplifier, duration, flags);
		}
		else if (id == PACKET_PLAY_OUT_ENTITY_TELEPORT)
		{
			float x = data["x"];
			float y = data["y"];
			float z = data["z"];
			p = new packet_play_out_entity_teleport(id, origin, time_current, x, y, z);
		}
		else if (id == PACKET_PLAY_OUT_EXPLOSION)
		{
			float x = data["x"];
			float y = data["y"];
			float z = data["z"];
			p = new packet_play_out_explosion(id, origin, time_current, x, y, z);
		}
		else if (id == PACKET_PLAY_OUT_RESPAWN)
		{
			float x = data["x"];
			float y = data["y"];
			float z = data["z"];
			p = new packet_play_out_respawn(id, origin, time_current, x, y, z);
		}
		else if (id == PACKET_PLAY_OUT_TRANSACTION)
		{
			int source_type = data["sourceType"];
			int source_flags = data["sourceFlags"];
			unsigned char slot = data["slot"];
			p = new packet_play_out_transaction(id, origin, time_current, source_type, source_flags, slot);
		}
		else if (id == PACKET_PLAYER_ARM_ANIMATION)
		{ 
			p = new packet_player_arm_animation(id, origin, time_current);
		}
		else if (id == PACKET_PLAYER_BREAK_BLOCK)
		{
			float x = data["x"];
			float y = data["y"];
			float z = data["z"];
			p = new packet_player_break_block(id, origin, time_current, x, y, z);
		}
		else if (id == PACKET_PLAYER_LOGIN)
		{
			std::string xuid = static_cast<std::string>(data["xuid"]);
			p = new packet_player_login(id, origin, time_current, xuid);
		}
		else if (id == PACKET_PLAYER_LOGOUT)
		{
			std::string xuid = static_cast<std::string>(data["xuid"]);
			p = new packet_player_logout(id, origin, time_current, xuid);
		}
		else if (id == PACKET_PLAYER_PLACE_BLOCK)
		{
			float x = data["x"];
			float y = data["y"];
			float z = data["z"];
			p = new packet_player_place_block(id, origin, time_current, x, y, z);
		}
		else if (id == PACKET_PLAYER_POSITION)
		{
			float x = data["x"];
			float y = data["y"];
			float z = data["z"];
			float yaw = data["yaw"];
			float pitch = data["pitch"];
			bool on_ground = data["onGround"];
			p = new packet_player_position(id, origin, time_current, x, y, z, yaw, pitch, on_ground);
		}

		return p;
	}

}