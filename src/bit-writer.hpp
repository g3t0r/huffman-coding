#ifndef BIT_WRITER
#define BIT_WRITER

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

class BitWriter
{
private:
    int index = 0;
    byte buf = 0;
    FILE* file; 
    void writeBit(int bit);
    void writeByte();

public:
    void writeZero();
    void wrtieOne();
};

BitWriter::BitWriter(/* args */)
{
}

BitWriter::~BitWriter()
{
}


#endif