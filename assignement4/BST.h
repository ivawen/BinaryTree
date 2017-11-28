#ifndef BST_H
#define BST_H

class ReturnNode;
class BST
{
public:
    // constructor prototype
    BST();
    void AddNode(int value);
    void PrintInOrderTraversal();// print tree from lower to greater value
    int  ReturnRootValue();
    void PrintChildren(int value);

private:
    //object
    struct node
    {
        int value; // value inside each node
        node* leftChild; // left node
        node* rightChild; // right node
    };
    
    node* root; //the very top of the tree
    node* createNode(int value); // private to the class should not be called from main
    // 
    void AddNodePrivate(int value, node* pointer);
    void PrintInOrderTraversalPrivate(node* pointer);//inOrder traversal
    node* ReturnNode(int value);//return pointer to a node that corresponds to a value that we passing in 
    node* ReturnNodePrivate(int value, node* pointer);

};

#endif // BST_H
