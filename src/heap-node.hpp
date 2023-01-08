#include <iostream>
#include <vector>

class HeapNode
{
private:
    HeapNode *left;
    HeapNode *right;
    char character;
    int value;

public:
    HeapNode(char character, int value);
    HeapNode *getLeft();
    HeapNode *getRight();
    void setLeft(HeapNode *node);
    void setRight(HeapNode *node);
    int getValue() const;
    char getCharacter() const;

    friend std::ostream &operator<<(std::ostream &os, const HeapNode &node);
};

void printPreorder(HeapNode& root, int level = 0);
void printBinPreorder(HeapNode& root, std::string s = "");
HeapNode* popTheSmallest(std::vector<HeapNode *> &list);
HeapNode* buildTree(std::vector<HeapNode*> &list);
