#include "stat-collector.hpp"
#include "heap-node.hpp"
#include <iostream>
#include <vector>
#include <string>

HeapNode *popTheSmallest(std::vector<HeapNode *> &list)
{
  int min = 0;
  for (int i = 1; i < list.size(); i++)
  {
    if (list.at(min)->getValue() > list.at(i)->getValue())
    {
      min = i;
    }
  }
  HeapNode *n = list.at(min);
  // std::cout << "got the smallest: " << (int) n->getCharacter() << "-" << n->getValue() << std::endl;
  list.erase(list.begin() + min);
  return n;
}

int main()
{
  CharacterCountMap *ccm = new CharacterCountMap();

  std::string txt = "ania ma kota";
  for(char c : txt) {
    ccm->addCharacter(c);
  }
  std::vector<HeapNode *> list = {};

  CharacterStatistics *array = ccm->getSortedArray();
  int total = ccm->countNonEmpty();

  for (int i = 0; i < total; i++)
  {
    char c = array[i].getCharacter();
    int v = array[i].getOccurrences();
    list.push_back(new HeapNode(c, v));
  }

  while (list.size() > 1)
  {
    HeapNode* l = popTheSmallest(list);
    HeapNode* r = popTheSmallest(list);
    HeapNode* root = new HeapNode(0, l->getValue() + r->getValue());
    root->setLeft(l);
    root->setRight(r);
    list.push_back(root);
  }

  // printPreorder(*list.at(0));
  std::cout << "Wygenerowano tablicę mapowania dla \"" << txt << "\"" << std::endl;
  printBinPreorder(*list.at(0));
  delete[] array;
  return 0;
}
