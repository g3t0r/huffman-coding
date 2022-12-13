#include "stat-collector.hpp"
#include <iostream>

void CharacterCountMap::sort(CharacterStatistics *array, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n - 1; j++)
    {
      if(array[j].getOccurrences() > array[j+1].getOccurrences()) {
        CharacterStatistics tmp = array[j];
        array[j] = array[j+1];
        array[j + 1] = tmp; 
      }
    }
  }
}

void CharacterCountMap::addCharacter(char character)
{
  this->size++;
  data[character]++;
}

void CharacterCountMap::printInfo()
{
  for (int i = 0; i < ASCII_SIZE; i++)
  {
    std::cout << "[" << i << "] -> " << data[i] << std::endl;
  }
}

void CharacterCountMap::printNonEmpty()
{
  std::cout << "Size: " << this->size << std::endl;
  for (int i = 0; i < ASCII_SIZE; i++)
  {
    if (data[i] > 0)
    {
      std::cout << "[" << i << "] -> " << data[i];
    }
  }
}

int CharacterCountMap::getSize()
{
  return this->size;
}

int CharacterCountMap::countNonEmpty()
{
  int count = 0;
  for (int i = 0; i < ASCII_SIZE; i++)
  {
    if (data[i] > 0)
    {
      count++;
    }
  }
  return count;
}

CharacterStatistics *CharacterCountMap::getSortedArray()
{
  int total = this->countNonEmpty();
  CharacterStatistics *array = new CharacterStatistics[total];
  int shift = 0;

  for (int lastIndex = 0; lastIndex < ASCII_SIZE; lastIndex++)
  {
    if (data[lastIndex] > 0)
    {
      array[shift].setCharacter(lastIndex);
      array[shift].setOccurrences(data[lastIndex]);
      shift++;
    }
  }

  // sort(array, total);
  return array;
}

std::ostream &operator<<(std::ostream &os, const CharacterStatistics &cs)
{
  os << "[" << cs.getCharacter() << ", " << cs.getOccurrences() << "]";
  return os;
}

CharacterStatistics::CharacterStatistics()
{
}

CharacterStatistics::CharacterStatistics(char character, int percentage)
{
}

char CharacterStatistics::getCharacter() const
{
  return character;
}

int CharacterStatistics::getOccurrences() const
{
  return occurrences;
}

void CharacterStatistics::setCharacter(char character)
{
  this->character = character;
}

void CharacterStatistics::setOccurrences(int percentage)
{
  this->occurrences = percentage;
}
