#include "heap-node.hpp"
#include <iostream>
#include <vector>

HeapNode::HeapNode(char character, int value)
{
    left = nullptr;
    right = nullptr;
    this->character = character;
    this->value = value;
}

HeapNode *HeapNode::getLeft()
{
    return left;
}

HeapNode *HeapNode::getRight()
{
    return right;
}

void HeapNode::setLeft(HeapNode *node)
{
    this->left = node;
}

void HeapNode::setRight(HeapNode *node)
{
    this->right = node;
}

int HeapNode::getValue() const
{
    return value;
}

char HeapNode::getCharacter() const
{
    return character;
}

std::ostream &operator<<(std::ostream &os, const HeapNode &node)
{
    os << "[character: ";
    if (node.character == 0)
    {
        os << "<NULL>";
    }
    else
    {
        os << node.character;
    }

    os << ", value: " << node.value << "]";

    return os;
}

void printIndent(int level) {
    for(int i = 0; i < level; i++) {
        std::cout << "    ";
    }
}

void printPreorder(HeapNode &root, int level)
{
    std::cout << root << std::endl;

    printIndent(level);
    std::cout << "LEFT: ";

    if(root.getLeft() == nullptr) {
        std::cout  << "NULL" << std::endl;
    } else {
        printPreorder(*root.getLeft(), level + 1);
    }

    printIndent(level);
    std::cout << "RIGHT: ";
    if(root.getRight() == nullptr) {
        std::cout  << "NULL" << std::endl;
    } else {
        printPreorder(*root.getRight(), level + 1);
    }

    printIndent(level);
    std::cout << "back" << std::endl;
}

void printBinPreorder(HeapNode& root, std::string s) {
    if(root.getLeft() == nullptr && root.getRight() == nullptr) {
        std::cout << root.getCharacter() << " == " << s << std::endl;
        return;
    }

    if(root.getLeft() == nullptr) {
    } else {
        std::string local = s;
        local.append("0");
        printBinPreorder(*root.getLeft(), local);
    }

    if(root.getRight() == nullptr) {
    } else {
        std::string local = s;
        local.append("1");
        printBinPreorder(*root.getRight(), s.append("1"));
    }
}

HeapNode *buildTree(std::vector<HeapNode *> &list)
{
  while (list.size() > 1)
  {
    HeapNode* l = popTheSmallest(list);
    HeapNode* r = popTheSmallest(list);
    HeapNode* root = new HeapNode(0, l->getValue() + r->getValue());
    root->setLeft(l);
    root->setRight(r);
    list.push_back(root);
  }
    return list.at(0);
}

HeapNode* popTheSmallest(std::vector<HeapNode *> &list) {
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