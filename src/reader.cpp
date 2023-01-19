#include "mapping-table.hpp" 
#include <iostream>
#include <fstream>

#include <stdint.h>

std::string dec2bin(uint8_t byte) {
    std::string bin;
    for(int i = 7; i >= 0; i--) {
        int calculated = 1 << i;
        if(byte >= calculated)  {
            byte -= calculated;
            bin = bin + "1";
        } else {
            bin = bin + "0";
        }
    }
    return bin;
}

int main() {
    uint8_t c = 0;
    std::ifstream o;

    std::ifstream m;
    m.open("mapping-table.txt");
    MappingTable *mt = importMappingTable(m);

    std::string convertedToBin;

    o.open("compressed.bin", std::ios::binary);
    size_t expected;
    o >> expected;
    while(o.peek() != EOF || !o.eof()) {
        o.read((char *)&c, sizeof(char));
        convertedToBin += dec2bin(c);
    }

    std::string decoded;
    std::string code;
    size_t convertedSize = convertedToBin.size();
    size_t found = 0;
    for(int i =0; i < convertedSize; i++) {
        if(found == expected)
            break;
        code += convertedToBin[i];
        char l;
        if((l = mt->find(code)) == -1) {
            continue;
        }
        found++;
        decoded += l;
        code = "";
    }

    std::ofstream decodedFile;
    decodedFile.open("decoded.txt");
    decodedFile << decoded;

    return 0;
}