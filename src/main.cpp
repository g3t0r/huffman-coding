#include "mapping-table.hpp"
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
  uint8_t test = 123;
  compressed.write((char *)&test, sizeof(test));
  test = 204;
  compressed.write((char *)&test, sizeof(test));
  test = 77;
  compressed.write((char *)&test, sizeof(test));
  test = 32;
  compressed.write((char *)&test, sizeof(test));
  


  return 0;
}
