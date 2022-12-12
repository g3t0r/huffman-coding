#include "heap-node.hpp"

HeapNode::HeapNode(char character)
{
    left = nullptr;
    right = nullptr;
    this->character = character;
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