#ifndef NODE_H
#define NODE_H
#include "treeheap.h"

class Node
{
    friend class Treap;
public:
    Node(const int &val,const int &prior);
    int getValue();
private:
    int value;
    int priority;
    Node *left;
    Node *right;
};

#endif

