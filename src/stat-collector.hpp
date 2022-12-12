#ifndef STAT_COLLECTOR
#define STAT_COLLECTOR
#define ASCII_SIZE 128
#include <iostream>

class CharacterStatistics
{
private:
  char character;
  int occurrences;

public:
  CharacterStatistics();
  CharacterStatistics(char character, int occurrences);
  char getCharacter() const;
  int getOccurrences() const;
  void setCharacter(char character);
  void setOccurrences(int occurrences);

  friend std::ostream & operator << (std::ostream& os, const CharacterStatistics& cs);
};

class CharacterCountMap
{
private:
  int data[ASCII_SIZE]{0};
  int size = 0;
  void sort(CharacterStatistics* array, int n);

public:
  void addCharacter(char character);
  void printInfo();
  void printNonEmpty();
  int getSize();
  int countNonEmpty();
  CharacterStatistics *getSortedArray();
};
#endif
