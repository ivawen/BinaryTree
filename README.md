# BinaryTree
In this program, I am implementing a binary tree. The binary tree in question is an array which consists of 20 elements {60,58,21,3,13,100,81,76,66,10,2,32,83,78,80,86,44,5,19,93}.  
Here is a graphic representation of the tree with the same values in the array.  

![Alt text](C:\Users\ivawen\Desktop\Capture.JPG "Optional Title")


The purpose here is to write a function that adds these elements to the tree first, by using linked lists to create nodes createNode(), then add nodes addNode() to each element in the tree. After adding the elements, we want to perform an in-Order traversal on the tree. Lastly we want to print the parent nodes along with their children PrintChildren(). We declare a left and right child pointers, a value variable which hold the value inside each node, a root node (top of the tree, pointer also)   

CreateNode function creates nodes by initializing the tree values. We start by creating node pointer that we return, then the first value at left child refers to the value inside of the node and the second value is what is passed in by the function, same thing for the right child. Also, we initialize left and right child to be null at start, then return the new pointer node we created.  
 
addNode function adds nodes to the tree. It first checks if tree is empty, if it’s the case make root point to new node. if tree is not empty, it first recursively moves down the tree in the left child and checks, else, if left child is not pointing to anything it makes its left child pointer point to new node. Else if the value we want to add is greater than value in current node, it goes to the right child and does the same steps as in left child 
Print in order traversal function take a node pointer as parameter.  It first checks if left child points to something or if it is possible to go left, if it’s the case we recursively traverse the sub left tree and print the current values. Then, does the same thing for the right child. If tree is empty return a string saying its empty. 
Return node function simply returns a pointer to a node that corresponds to a value that we’re passing in. if the pointer we passing in is pointing to something we return the pointer pointing to current node. If not, which means the value we looking for is less than value inside current node, we go to left child, if greater we go to right child else return null. This function is used to print the children and parents in the tree. 
Print children function prints a parent node and its children separately. It passes in the value we want to look out and if node and value are found in tree the return node will make the pointer point to that node otherwise it make pointer point to null: if it is pointing to null we say key not in tree if pointer pointing to node, we found a node with this value in tree : then print out that node value and print out the leftChild and rightChild child values as well.
