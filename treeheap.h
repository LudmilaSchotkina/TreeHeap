#ifndef TREEHEAP_H
#define TREEHEAP_H
#include <iostream>
#include "node.h"

class Treap
{
public:
    Treap();
    void addNode (const int &val);
    void deleteNode(Node *&ptr);

    Treap (const Treap &original);
    void copyNode(Node *&newNode, Node *original);
    Treap &operator=(const Treap &original);
    Treap operator+(const Treap &b);

    void print(int level);
    void bypass();
    void length();

    Node *merge(Node *a,Node *b);
    void insert(int value, int priority);
    void split (Node *ptr, int value, Node *&left, Node *&right);

    void unite(Treap a,Treap b);

private:
    Node *root;
    void insert(Node *tn,int value, int priority);
    void print(Node *t,int level);
    void bypass(Node *ptr);
    int length(Node *ptr);
    void unite(Node *&rt, Node *&r);
};


#endif
