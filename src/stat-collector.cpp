#include "stat-collector.hpp"
#include <iostream>

void CharacterCountMap::sortDesc(CharacterStatistics *array, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n - 1; j++)
    {
      if(array[j].getPercentage() < array[j+1].getPercentage()) {
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
      std::cout << ", " << (float)data[i] / (float)this->size * 100 << "%" << std::endl;
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

CharacterStatistics *CharacterCountMap::getArrayPercDesc()
{
  int total = this->countNonEmpty();
  CharacterStatistics *array = new CharacterStatistics[total];
  int shift = 0;

  for (int lastIndex = 0; lastIndex < ASCII_SIZE; lastIndex++)
  {
    if (data[lastIndex] > 0)
    {
      array[shift].setCharacter(lastIndex);
      (array + shift)->setPercentage((float)data[lastIndex] / (float)size);
      shift++;
    }
  }

  sortDesc(array, total);
  return array;
}

std::ostream &operator<<(std::ostream &os, const CharacterStatistics &cs)
{
  os << "[" << cs.getCharacter() << ", " << cs.getPercentage() << "%]";
  return os;
}

CharacterStatistics::CharacterStatistics()
{
}

CharacterStatistics::CharacterStatistics(char character, float percentage)
{
}

char CharacterStatistics::getCharacter() const
{
  return character;
}

float CharacterStatistics::getPercentage() const
{
  return percentage;
}

void CharacterStatistics::setCharacter(char character)
{
  this->character = character;
}

void CharacterStatistics::setPercentage(float percentage)
{
  this->percentage = percentage;
}
