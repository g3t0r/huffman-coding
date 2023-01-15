#include "bit-writer.hpp"

#include <fstream>
#include <iostream>

void BitWriter::writeBit(char bit)
{
    buf[index] = bit;
    index += 1;

    if (index != 8)
        return;

    writeByte();
    clearBuff();
    index = 0;
}

void BitWriter::writeByte()
{
    byte b = buffToByte();
    file->write((char *)&b, sizeof(uint8_t));
}

byte BitWriter::buffToByte()
{
    byte result = 0;

    for (int i = 0; i <= 7; i++)
    {
        if(buf[i] == '0')
            continue;

        int bin2dec = 1 << (7 - i);
        result += bin2dec;
    }

    return result;
}

void BitWriter::clearBuff()
{
    for (int i = 0; i < 8; i++)
    {
        buf[i] = '0';
    }
}

void BitWriter::close()
{
    writeByte();
}

BitWriter::BitWriter(std::ofstream *file)
{
    this->file = file;
}