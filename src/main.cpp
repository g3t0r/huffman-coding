#include "mapping-table.hpp"
#include "bit-writer.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdint.h>
#include <string.h>

int main()
{
  std::ifstream srcFile;
  srcFile.open("plain.txt");
  char *buf = (char *)calloc(4096, 1);
  srcFile.read(buf, 4096);
  realloc(buf, strlen(buf) + 1);
  std::string txt(buf);
  std::cout << "Loaded text: " <<  txt;
  MappingTable *mt = MappingTable::generateMappingTable(buf);
  std::cout << *mt;

  std::ofstream mt_file;
  mt_file.open("mapping-table.txt");
  mt_file << *mt;
  mt_file.close();

  std::ofstream compressed;
  compressed.open("compressed.bin", std::ios::binary);
  BitWriter *bw = new BitWriter(&compressed);

  int i = 0;
  char c = 0;
  while((c = buf[i]) != '\0' ) {
    std::string bin = mt->get(c);
    for(int j = 0; j < bin.size(); j++) {
      bw->writeBit(bin[j]);
    }
    i++;
  }
  bw->close();

  return 0;
}
