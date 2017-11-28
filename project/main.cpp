#include <iostream>
#include <cstdlib>
#include "BST.h"

using namespace std;
  
int main()
{
    // create tree
    int Tree[20] = {60,58,21,3,13,100,81,76,66,10,2,32,83,78,80,86,44,5,19,93};
    //binary tree object
    BST myTree;
    
    cout << "printing the tree in order: Before adding numbers\n";//add numbers inside of my tree values array
    myTree.PrintInOrder();//print the values of my tree  
    
    for(int i = 0;i<20;i++)
    {
        //add the nodes to the tree
        myTree.AddNode(Tree[i]);//grab the current array element
    }
    cout << "printing the tree in order: After adding numbers\n" <<endl;
    
    myTree.PrintInOrder();
    
    cout << endl;
    cout << endl;

    //myTree.PrintChildren(myTree.ReturnRootValue());
    
    for(int i = 0;i<20;i++)
    {
        //add the nodes to the tree
        myTree.PrintChildren(Tree[i]);//grab the current array element
        cout << endl;
    }
    
    return 0;
}
