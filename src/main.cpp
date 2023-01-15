#include "mapping-table.hpp"
#include "bit-writer.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdint.h>


int main()
{
  std::string txt = "ania ma kota";
  MappingTable *mt = MappingTable::generateMappingTable(txt.c_str());
  std::cout << *mt;

  std::ofstream mt_file;
  mt_file.open("mapping-table.txt");
  mt_file << *mt;
  mt_file.close();

  std::ofstream compressed;
  compressed.open("compressed.bin", std::ios::binary);
  BitWriter *bw = new BitWriter(&compressed);
  bw->writeBit('0');
  bw->writeBit('0');
  bw->writeBit('0');
  bw->writeBit('0');
  bw->writeBit('1');
  bw->writeBit('1');
  bw->writeBit('1');
  bw->writeBit('1');

  


  return 0;
}
