#include "stat-collector.hpp"
#include "heap-node.hpp"
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

  CharacterStatistics* array = ccm->getSortedArray();
  int total = ccm->countNonEmpty();
  for(int i = 0; i < total; i++) {
    std::cout << array[i] << std::endl;
  }


  for(int i = 0; i < total; i += 2) {
    HeapNode *left = new HeapNode(array[i].getCharacter());
    HeapNode *right = new HeapNode(array[i + 1].getCharacter());
    HeapNode *root = new HeapNode((char)nullptr);
    root->setLeft(left);
    root->setRight(right);
  }



  delete [] array;
  return 0;
}

