#ifndef STAT_COLLECTOR
#define STAT_COLLECTOR
#define ASCII_SIZE 128
#include <iostream>

class CharacterStatistics
{
private:
  char character;
  float percentage;

public:
  CharacterStatistics();
  CharacterStatistics(char character, float percentage);
  char getCharacter() const;
  float getPercentage() const;
  void setCharacter(char character);
  void setPercentage(float percentage);

  friend std::ostream & operator << (std::ostream& os, const CharacterStatistics& cs);
};

class CharacterCountMap
{
private:
  int data[ASCII_SIZE]{0};
  int size = 0;
  void sortDesc(CharacterStatistics* array, int n);

public:
  void addCharacter(char character);
  void printInfo();
  void printNonEmpty();
  int getSize();
  int countNonEmpty();
  CharacterStatistics *getArrayPercDesc();
};
#endif
