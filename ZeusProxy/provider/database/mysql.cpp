#include "mysql.h"

#include <iostream>

#include "../alert/alert_manager.h"

using namespace std;
using namespace alert;

namespace provider
{
    namespace database
    {
        std::string mysql::host_;
        std::string mysql::port_;
        std::string mysql::user_;
        std::string mysql::password_;
        std::string mysql::database_;
        
        mysql::mysql(const std::string& _host, const std::string& _port, const std::string& _user, const std::string& _password, const std::string& _database)
        {
            host_ = _host;
            port_ = _port;
            user_ = _user;
            password_ = _password;
            database_ = _database;

            string createTableSQL =
                "CREATE TABLE IF NOT EXISTS " + database_ + " ("
                "id INT PRIMARY KEY AUTO_INCREMENT,"
                "uuid VARCHAR(100) NOT NULL,"
                "banned BOOLEAN DEFAULT FALSE,"
                "reason VARCHAR(100) NOT NULL"
                ")";
        }

        std::string mysql::get_host()
        {
            return host_;
        }

        std::string mysql::get_port()
        {
            return port_;
        }

        std::string mysql::get_user()
        {
            return user_;
        }

        std::string mysql::get_password()
        {
            return password_;
        }

        std::string mysql::get_database()
        {
            return database_;
        }

        void mysql::connect(const std::function<void(sql::Connection*)>& callback)
        {
            try {
                sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
                sql::Connection* con = driver->connect("tcp://" + host_ + ":" + port_, user_, password_);

                con->setSchema(database_);
                callback(con);
                delete con;
            }
            catch (sql::SQLException& e) {
                alert_manager::alert_error("SQL Error: " + static_cast<std::string>(e.what()));
            }
        }

        void mysql::execute_query(const std::string& query, const std::function<void(sql::ResultSet*)>& callback)
        {
            connect([&](sql::Connection* con) {
                sql::Statement* stmt = con->createStatement();
                sql::ResultSet* res = stmt->executeQuery(query);
                callback(res);
                delete res;
                delete stmt;
            });
        }

        void mysql::execute_update(const std::string& query, const std::function<void(int)>& callback)
        {
            connect([&](sql::Connection* con) {
                sql::Statement* stmt = con->createStatement();
                const int res = stmt->executeUpdate(query);
                callback(res);
                delete stmt;
            });
        }

        void mysql::execute(const std::string& query, const std::function<void(bool)>& callback)
        {
            connect([&](sql::Connection* con) {
                sql::Statement* stmt = con->createStatement();
                const bool res = stmt->execute(query);
                callback(res);
                delete stmt;
            });
        }

        bool mysql::player_is_banned(const std::string& uuid)
        {
            bool banned = false;
            
            execute_query("SELECT * FROM " + database_ + " WHERE uuid = '" + uuid + "'", [&](sql::ResultSet* res) {
                while (res->next()) {
                    banned = res->getBoolean("banned");
                }
            });
            
            return banned;
        }

        void mysql::set_player_ban(const std::string& uuid, const std::string& reason)
        {
            int error = 0;
            
            execute_update("UPDATE " + database_ + " SET banned = true, reason = '" + reason + "' WHERE uuid = '" + uuid + "'", [&](const int res) {
                error = res;
            });

            if (error == 0) {
                execute_update("INSERT INTO " + database_ + " (uuid, banned, reason) VALUES ('" + uuid + "', '" + uuid + "', true, '" + reason + "')", [&](const int res) {
                    error = res;
                });
            }
        }
    }
}