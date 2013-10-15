#include <iostream>
#include "treeheap.h"
using namespace std;

//////////////////////////////////////////////////
//////////FUNCTIONS FROM NODE.H///////////////////
//////////////////////////////////////////////////
Node::Node(const int &val,const int &prior)
{
    value=val;
    priority=prior;
    left=right=0;
}

int Node::getValue()
{
    return value;
}
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////

Treap::Treap():root(NULL) {}

void Treap::deleteNode(Node *&ptr)
{
    if(ptr)
    {
        deleteNode(ptr->left);
        deleteNode(ptr->right);
        delete ptr;
        ptr=0;
    }
}

Treap::Treap (const Treap &original)
{
    if (original.root)
    {
        root=new Node(original.root->value,original.root->priority);
        copyNode(root, original.root);
    }
    else root=0;
}

void Treap::copyNode(Node *&newNode, Node *original)
{
    if(original==0)
        newNode = 0;

    if (original)
    {
        newNode= new Node(original->value,original->priority);
        if(original->left)
            copyNode(newNode->left,original->left);
        else
            newNode->left =0;

        if(original->right)
            copyNode(newNode->right,original->right);
        else
            newNode->right =0;
    }
}
Treap &Treap::operator=(const Treap &original)
{
    if(this==&original)
        return *this;
    deleteNode(root);
    copyNode(root,original.root);
    return *this;
}

void Treap::print(int element)
{
    print(root,element);
}
void Treap::print(Node *t,int element)
{
    if (t!=0)
    {
        print(t->left,element+1);
        for (int i=0; i<element; ++i)
            cout<<"|";
        cout<<t->value<<endl;
        print(t->right,element+1);
    }
}

void Treap::bypass()
{
    bypass(root);
}
void Treap::bypass(Node *ptr)
{
    if (ptr!=0)
    {
        cout<<ptr->value<<" ";
        bypass(ptr->left);
        bypass(ptr->right);
    }
}

void Treap::length ()
{
    cout<<length(root);
}
int Treap::length(Node *ptr)
{
    if (ptr->left== NULL && ptr->right== NULL)
        return 1;
    int leftChild, rightChild;
    if (ptr->left!=NULL)
        leftChild = length(ptr->left);
    else
        leftChild = 0;
    if (ptr->right != NULL)
        rightChild= length(ptr->right);
    else
        rightChild = 0;
    return leftChild+rightChild+1;
}

/////////////////////////////////////////////////////////////////
///////////////////MERGE AND OTHER/////////////////////////////////
/////////////////////////////////////////////////////////////////
void Treap::insert(int value, int priority)
{
    insert(root,value,priority);
}
void Treap::insert(Node *tn, int value, int priority)
{
    tn = new Node(value, priority);
    Node *t1, *t2;
    split(root, value, t1, t2);
    root=merge(t1,tn);
    root=merge(root,t2);
}

Node *Treap::merge(Node *a,Node *b)
{
    if (!a || !b)
        return a ? a : b;
    if (a->priority > b->priority)
    {
        a->right = merge(a->right, b);
        return a;
    }
    else
    {
        b->left = merge(a, b->left);
        return b;
    }
}

void Treap::split (Node *ptr, int value, Node *&left, Node *&right)
{
    if (!ptr)
        left=right=NULL;
    else if (value<ptr->value)
    {
        split(ptr->left,value,left,ptr->left);
        right=ptr;
    }
    else if (value>=ptr->value)
    {
        split (ptr->right, value, ptr->right, right);
        left=ptr;
    }
}

////////////////////////////////////////
////==================================//
////////////////////////////////////////

Treap Treap::operator+(const Treap &b)
{
    Treap temp;
    if (this!=&b)
    {
        temp=b;
        unite(root,temp.root);
        return temp;
    }
    else return *this;
}

void Treap::unite(Node *&rt, Node *&r)
{
    if(r!=0)
    {
        insert(rt,r->value,r->priority);
        unite(rt,r->left);
        unite(rt,r->right);
    }
}
void Treap::unite(Treap a,Treap b)
{
    copyNode(root,a.root);
    unite(root,b.root);
}

