#include <iostream>
#include <fstream>
#include "treeheap.h"
#include "node.h"

using namespace std;

int main()
{
    Treap tree;
    int value;
    int priority;

    fstream fileTreap;
    fileTreap.open("treap.txt");

    if(!fileTreap)
    {
        cerr<<"Error 404"<<endl;
        return -1;
    }

    while(!fileTreap.eof())
    {
        fileTreap>>value;
        fileTreap>>priority;
        tree.insert(value,priority);
    }
    fileTreap.close();
    tree.print(0);
    cout<<endl<<endl;
    tree.bypass();
    cout<<endl<<"Length: ";
    tree.length();
    cout<<endl<<endl<<endl;

////////////////////////////////////////////
    Treap tree2;
    fstream file;
    file.open("treap2.txt");
    if(!file)
    {
        cerr<<"Error 404"<<endl;
        return -1;
    }

    while(!file.eof())
    {
        file>>value;
        file>>priority;
        tree2.insert(value,priority);
    }
    file.close();

    tree2.print(0);
    cout<<endl<<endl;

    tree2.bypass();

    cout<<endl<<"Length: ";
    tree2.length();


    cout<<endl<<endl<<"============================================="<<endl<<"UNION:"<<endl;

    Treap c;
    c.unite(tree,tree2);
    c.print(0);
    cout<<endl<<endl;
    c.bypass();
    cout<<endl<<"Length: ";
    c.length();
    cout<<endl;

    return 0;
}
