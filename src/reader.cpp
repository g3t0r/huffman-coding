#include <iostream>
#include <fstream>

#include <stdint.h>

int main() {
    uint8_t c = 0;
    std::ifstream o;
    o.open("compressed.bin", std::ios::binary);
    while(o.peek() != EOF || !o.eof()) {
        o.read((char *)&c, sizeof(char));
        std::cout << (unsigned short) c << std::endl;
    }
    return 0;
}