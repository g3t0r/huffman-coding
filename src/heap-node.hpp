class HeapNode
{
private:
    HeapNode *left;
    HeapNode *right;
    char character;

public:
    HeapNode(char character);
    HeapNode *getLeft();
    HeapNode *getRight();
    void setLeft(HeapNode *node);
    void setRight(HeapNode *node);
};
