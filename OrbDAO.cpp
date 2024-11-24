#include <sqlite3.h>
#include <vector>
#include <iostream>

#include "OrbDAO.h"

using namespace std;

OrbDAO::OrbDAO() {
        int rc = sqlite3_open("/var/db/ORB_DATABASE.db", &db);
        if (rc) {
            std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
            exit(1);
        }
    }

OrbDAO::~OrbDAO() {
        sqlite3_close(db);
    }

    std::vector<std::string> OrbDAO::GetStates() {
        std::vector<string> states;
        sqlite3_stmt* stmt;
        const char* sql = "SELECT DISTINCT State FROM Orb";

        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                std::string state = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
                states.push_back(state);
            }
            sqlite3_finalize(stmt);
        } else {
            std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        }

        return states;
    }

    std::vector<std::string> OrbDAO::GetCountiesByState(std::string st) {
        std::vector<std::string> counties;

        sqlite3_stmt* stmt;
        std::string sql = "SELECT County FROM Orb WHERE State='";
        sql += st;
        sql += "';";

        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                std::string county = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
                counties.push_back(county);
            }
            sqlite3_finalize(stmt);
        } else {
            std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        }

        return counties;


};

