#include "heap-node.hpp"
#include <iostream>

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
