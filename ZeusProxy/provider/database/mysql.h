#ifndef PROVIDER_MYSQL_H
#define PROVIDER_MYSQL_H
#include <string>
#include <vector>
#include <functional>
#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/statement.h> 
#include <mysql_connection.h> 
#include <mysql_driver.h>

namespace provider
{
    namespace database
    {
        
        class mysql
        {
            static std::string host_;
            static std::string port_;
            static std::string user_;
            static std::string password_;
            static std::string database_;

            static void connect(const std::function<void(sql::Connection*)>& callback);
            
        public:
            mysql(const std::string& _host, const std::string& _port, const std::string& _user, const std::string& _password, const std::string& _database);

            static std::string get_host();

            static std::string get_port();

            static std::string get_user();

            static std::string get_password();

            static std::string get_database();

            static void execute_query(const std::string& query, const std::function<void(sql::ResultSet*)>& callback);

            static void execute_update(const std::string& query, const std::function<void(int)>& callback);

            static void execute(const std::string& query, const std::function<void(bool)>& callback);

            static bool player_is_banned(const std::string& uuid);

            static void set_player_ban(const std::string& uuid, const std::string& reason);
        };
    }
}

#endif
