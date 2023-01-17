#ifndef MAPPING_TABLE
#define MAPPING_TABLE
#include <string>
#include <fstream>

class MappingTable
{
private:
    std::string map[128];

public:
    void put(char c, std::string);
    std::string get(char c) const;
    char find(std::string bin);
    static MappingTable *generateMappingTable(const char *txt);
    friend std::ostream &operator<<(std::ostream &os, const MappingTable &mt);
};

MappingTable * importMappingTable(std::ifstream & input);

#endif