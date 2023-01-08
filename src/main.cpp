#include "mapping-table.hpp"
#include <iostream>
#include <vector>
#include <string>


int main()
{
  std::string txt = "ania ma kota";
  MappingTable *mt = MappingTable::generateMappingTable(txt.c_str());
  for(int i = 0; i < 128; i++) {
    std::string code = mt->get(i);
    if(code.empty())
      continue;

    std::cout << (char) i << " == " << code << std::endl;
  }
  return 0;
}
