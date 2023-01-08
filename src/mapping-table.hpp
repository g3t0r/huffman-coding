#ifndef MAPPING_TABLE
#define MAPPING_TABLE
#include <string>

class MappingTable
{
private:
    std::string map[128];
public:
    void put(char c, std::string);
    std::string get(char c);
    static MappingTable* generateMappingTable(const char *txt);
};

#endif