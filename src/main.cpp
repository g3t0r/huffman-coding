#include "mapping-table.hpp"
#include "bit-writer.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdint.h>
#include <string.h>

#define MAX_SIZE 8192

int main()
{
  std::ifstream srcFile;
  srcFile.open("plain.txt");
  char *buf = (char *)calloc(MAX_SIZE, 1);
  srcFile.read(buf, MAX_SIZE);
  buf = (char *)realloc(buf, strlen(buf) + 1);
  std::string txt(buf);
  std::cout << "Loaded text size: " << txt.size() << std::endl;
  MappingTable *mt = MappingTable::generateMappingTable(buf);
  std::cout << *mt;

  std::ofstream mt_file;
  mt_file.open("mapping-table.txt");
  mt_file << *mt;
  mt_file.close();

  std::ofstream compressed;
  compressed.open("compressed.bin", std::ios::binary);
  compressed << txt.size();
  BitWriter *bw = new BitWriter(&compressed);

  int i = 0;
  char c = 0;
  while ((c = buf[i]) != '\0')
  {
    std::string bin = mt->get(c);
    for (int j = 0; j < bin.size(); j++)
    {
      bw->writeBit(bin[j]);
    }
    i++;
  }
  bw->close();

  return 0;
}
