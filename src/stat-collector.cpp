#include "stat-collector.h"
#include <iostream>

void CharacterCountMap::addCharacter(char character) { 
  this->size++;
  data[character]++;
}

void CharacterCountMap::printInfo() {
  for (int i = 0; i < ASCII_SIZE; i++) {
    std::cout << "[" << i << "] -> " << data[i] << std::endl;
  }
}

void CharacterCountMap::printNonEmpty() {
  std::cout << "Size: " << this->size <<  std::endl;
  for (int i = 0; i < ASCII_SIZE; i++) {
    if(data[i] > 0) {
      std::cout << "[" << i << "] -> " << data[i];
      std::cout << ", " << (float) data[i] / (float) this->size * 100 << "%" << std::endl;
    }
  }
}

