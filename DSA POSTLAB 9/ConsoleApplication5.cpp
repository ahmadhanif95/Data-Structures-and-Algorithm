#include<iostream>
#include "BinarySearchTree.h"
using namespace std;
int main()
{
	//creating an object of binary search tree
	BinarySearchTree<int>* BST = new BinarySearchTree<int>();
	//following insertions should happen successfully as we are inserting
	//unique values
	BST->insert(12);
	BST->insert(4);
	BST->insert(9);
	BST->insert(2);
	BST->insert(14);
	BST->insert(16);
	BST->insert(13);
	BST->insert(1);
	//prints data carried by the BST in sorted manner
	BNode<int>* rt=BST->root;
	BST->printSorted(rt);
	//deleting leaf node
	if(BST->deleteNode(16))
	{
		cout << "node carrying 16 deleted successfully"<< endl;
	}
	//deleting degree 1 node
	if(BST->deleteNode(2))
	{
		cout << "node carrying 2 deleted successfully" << endl;
	}
	//deleting degree 2 node
	if(BST->deleteNode(12))
	{
		cout << "node carrying 12 deleted successfully" << endl;
	}
	//prints data carried by the BST in sorted manner
	BST->printSorted(rt);
	//destructor called
	/*delete BST;*/
	return 0;
}
