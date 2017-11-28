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
    
    cout << endl;
    cout << "**********Add elements to exisiting tree and print In order traversal**********"<< endl;
    
    cout << endl;

    cout << "Printing the tree in order traversal: Before adding elements to existing tree:\n";//add numbers inside of my tree values array
    myTree.PrintInOrderTraversal();//print the values of my tree  
    
    for(int i = 0;i<20;i++)
    {
        //add the nodes to the tree
        myTree.AddNode(Tree[i]);//grab the current array element
    }
    cout << "Printing the tree in order traversal: After adding elements to existing tree:\n" <<endl;

    myTree.PrintInOrderTraversal();
    
    cout << endl;
    cout << endl;

    cout << "********************Find parent nodes and their children********************"<< endl;
    cout << endl;

    for(int i = 0;i<20;i++)
    {
        //add the nodes to the tree
        myTree.PrintChildren(Tree[i]);//grab the current array element
        cout << endl;
    }
    
    return 0;
}
