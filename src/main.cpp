#include "stat-collector.hpp"
#include <iostream>

int main() {
  CharacterCountMap* ccm = new CharacterCountMap();

  ccm->addCharacter('a');
  ccm->addCharacter('b');
  ccm->addCharacter('b');
  ccm->addCharacter('b');
  ccm->addCharacter('b');
  ccm->addCharacter('b');
  ccm->addCharacter('b');

  CharacterStatistics* array = ccm->getArrayPercDesc();
  int total = ccm->countNonEmpty();
  for(int i = 0; i < total; i++) {
    std::cout << array[i] << std::endl;
  }

  return 0;
}

