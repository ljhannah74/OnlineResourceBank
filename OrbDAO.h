#ifndef ORBDAO_H_INCLUDED
#define ORBDAO_H_INCLUDED

#include <sqlite3.h>

class OrbDAO{

private:
    sqlite3* db;

public:
    OrbDAO();
    ~OrbDAO();
    std::vector<std::string> GetStates();
    std::vector<std::string> GetCountiesByState(std::string st);
};

#endif // ORBDAO_H_INCLUDED
