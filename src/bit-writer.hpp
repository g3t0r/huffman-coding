#ifndef BIT_WRITER
#define BIT_WRITER

#include <fstream>
#include <stdint.h>

typedef uint8_t byte;

class BitWriter
{
private:
    int index = 0;
    char buf[8];

    std::ofstream * file;
    
    void writeByte();
    byte buffToByte();
    void clearBuff();

public:
    void writeBit(char bit);
    void close();
    BitWriter(std::ofstream *file);
    ~BitWriter(){};
};

#endif