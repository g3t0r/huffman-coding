#include "stat-collector.h"

int main() {
  CharacterCountMap* ccm = new CharacterCountMap();

  ccm->addCharacter('a');
  ccm->addCharacter('a');
  ccm->addCharacter('a');
  ccm->addCharacter('a');
  ccm->addCharacter('a');
  ccm->addCharacter('b');
  ccm->printNonEmpty();

  return 0;
}

