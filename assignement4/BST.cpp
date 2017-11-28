#include "BST.h"
#include <iostream>
#include <cstdlib>

//CreateNode()::precondition: Tree not empty T!= null
//           postCondition: retrun the pointer node

//AddNode()::Precondition: root is the root pointer of a nonempty binary SEARCH tree, There is memory available in the tree for the new item.  
//                         Item is a value of type node to be inserted in the tree.
//           PostCondition: Item is added to the tree in a way that maintains the tree in hierarchical property. root top => left=>right

//PrintInOrderTraversal()::Precondition: Tree not empty T!= null
//                       ::PostCondition:Each node at the tree is visited in the following order: First visit the root at the tree, 
//                                       then visit recursively all nodes in the left subtree, then visit recursively all nodes in the right subtree. 
//                                        As each node is visited, process is applied to it.

//ReturnNode()::Precondition::node* pointer is the root of a binary search tree
//              PostCondition:: returns a pointer to the first node of a sorted array containing same values as pointer

//PrintChildren()::Precondition:Binary tree nodes have a root a left and a right child.Either or both children can be empty 
//                 PostoCondition: Print the parent, left and right child to screen

using namespace std;

    //define the constructor BST.cpp
    BST::BST()
    {
        //root does not point to anything at the begining
        root = NULL;
    }
    //define the createNode Function from BST.cpp
    BST::node* BST::createNode(int value)
    {
        node* neww = new node; // the pointer that we will be returning
        
        /* the first value at leftChild refers to the value inside of the node, 
         * the second value is what is passed in by the function*/
        neww->value = value;
        //make leftChild and rightChild pointers point to NULL
        neww-> leftChild = NULL;
        neww-> rightChild = NULL;
        
        return neww;       
    }
    
    
    void BST::AddNode(int value)// int value will take care of the value we want to insert
    {
        // call addNodePrivate(), addNode to be called from main.cpp and start at root
        // value search for the rightChild location
        AddNodePrivate(value, root);
    }
    
    void BST::AddNodePrivate(int value, node* pointer)
    {
        // if tree is empty
       if(root == NULL)
       {
           //make root point to new node with value passed in at addNode()
           root = createNode(value);
       }
       // if tree is not empty
       else if (value < pointer->value) // is the value we want add is less then value in current node 
       {
           // want go leftChild. is there node connected to this node leftChild pointer
           if(pointer->leftChild != NULL)// leftChild pointer points to something
           {
               //travers down leftChild pointer, recursive move to leftChild pointer and check again 
               AddNodePrivate(value, pointer->leftChild);
           }
           // if leftChild pointer is not pointing to anything ****THATS THE POINT WHERE WE WANT ADD NODE TO TREE****
           else
           {
               //node we looking at make its leftChild pointer point to newNode
               pointer->leftChild = createNode(value);
           }
       }
       // if greater than value we looking at
       else if (value > pointer->value) // is the value we want add is greater than value in current node 
       {
           // want go rightChild. is there node connected to this node rightChild pointer
           if(pointer->rightChild != NULL)// rightChild pointer points to something
           {
               //travers down rightChild pointer, recursive move to leftChild pointer and check again 
               AddNodePrivate(value, pointer->rightChild);
           }
           // if leftChild pointer is not pointing to anything ****THATS THE POINTWHERE WE WANT ADD NODE TO TREE****
           else
           {
               //node we looking at make its rightChild pointer point to newNode
               pointer->rightChild = createNode(value);
           }
       }
       //if value want to add is equal to value inside current node
       else
           {
               cout << "The value " << value << " has already been added to the tree\n";                  
           }
    }
    
    void BST::PrintInOrderTraversal()
    {
        //
        PrintInOrderTraversalPrivate(root);        
    }
    
    void BST::PrintInOrderTraversalPrivate(node* pointer)
    {
        // if there is something in the tree
        if(root != NULL)
        {
            //if leftChild pointer points to something or if it is possible to go left
            if(pointer->leftChild !=NULL)
            {
                //go left
                PrintInOrderTraversalPrivate(pointer->leftChild);                
            }
            //print value of current node
            cout << pointer->value <<" ";
            
            /*if the rightChild pointer points to something.
              go right if possible*/
            if(pointer->rightChild !=NULL)
            {
                PrintInOrderTraversalPrivate(pointer-> rightChild);                
            }
        }
        //if tree empty
        else
        {
            cout << "The tree is empty.\n" << endl;
        }
    }
    
    BST::node* BST::ReturnNode(int value)
    {
       return ReturnNodePrivate(value, root);
    }
    
    BST::node* BST::ReturnNodePrivate(int value, node* pointer)
    {
        //if pointer passing in is pointing to something or not
        if(pointer != NULL)
        {
            // if we pointing to something
            if (pointer-> value == value)
            {
                // return the pointer that is pointing to the current node
                return pointer;
            }
            //if current pointer is not pointing to the correct node
            else
            {
                //if value looking for is less than value inside current node
                if(value < pointer->value)
                {
                    //we want to go leftChild
                    return ReturnNodePrivate(value, pointer->leftChild);
                }
                // if value is greater than the value inside current node
                else
                {
                    // go rightChild
                    return ReturnNodePrivate(value, pointer->rightChild);
                }
            }
        }   
        //if pointer not pointing to something
        else 
        {
            //return null
            return NULL;
        }
    }

/*    int BST::ReturnRootValue()
    {
        //check if root points to node
        if(root != NULL)
        {
            return root->value;// return the value inside root
        }
        else
            {
                // cheating :D , cuz we looking for int value and 1000 is not in our tree
                return -1000;
            }
    }
    */
    
    /*pass in the value we want to look out and if node and value are found in tree the return node will make the pointer point to that node
     * otherwise it make pointer point to null : if it is pointing to null we say key not in tree
     * if pointer pointing to node "we found a node with this value in tree : then print out that node value and print out the leftChild and rightChild child
     * values as well"*/
    void BST::PrintChildren(int value)
    {
        //make it point to the return value of the ReturnNode(),
        node* pointer = ReturnNode(value);// pass in value of printChildren and if node contain that value  inside tree, return pointer that points to that node 
        
        if(pointer != NULL)// if pointing to something
        {
            cout << "Parent node = " << pointer->value << endl;
            
            pointer -> leftChild == NULL ?
            cout << "left child = NULL\n":
            cout << "left child = " << pointer ->leftChild->value << endl;
            
            pointer -> rightChild == NULL ?
            cout << "right child = NULL\n":
            cout << "right child = " << pointer ->rightChild->value << endl;
        }
        else // if pointing to NULL
        {
            cout << "Value " << value << " is not in the tree\n";
        }
    }




