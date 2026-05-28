#include<iostream>
#include<string>
#include"BSTree.cpp"
using namespace std;

int main()
{
    BSTreeNode<int, int> root(10, 10);
    BSTree<int, int> bst;
    bst.Insert(1, 1);
    bst.Insert(2, 2);
    bst.Insert(3, 3);
    bst.Insert(4, 4);
    bst.Insert(5, 5);
    bst.Insert(6, 6);
    bst.Insert(7, 7);

    bst.InOrder();
    return 0;
}