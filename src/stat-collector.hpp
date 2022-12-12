#ifndef STAT_COLLECTOR
#define STAT_COLLECTOR
#define ASCII_SIZE 128

class CharacterStatistics {
private:
  char character;
  float percentage;

public:
  CharacterStatistics(char character, float percentage);
};

class CharacterCountMap {
private:
  unsigned int data[ASCII_SIZE]{0};
  unsigned int size = 0;
public:
  void addCharacter(char character);
  void printInfo();
  void printNonEmpty();
  
};
#endif

