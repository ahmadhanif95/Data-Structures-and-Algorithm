#include<iostream>
#include "BinarySearchTree.h"
using namespace std;
int main()
{
	//creating an object of binary search tree
	BinarySearchTree<int>* BST = new BinarySearchTree<int>();
	//following insertions should happen successfully as we are inserting unique values
	BST->insert(12);
	BST->insert(4);
	BST->insert(9);
	BST->insert(2);
	BST->insert(14);
	BST->insert(16);
	BST->insert(13);
	//this insertion should fail as 12 already exists in the Binary Search tree
	BST->insert(12);
	//prints data carried by the BST in sorted manner
	BNode<int>* r;
	r = new BNode<int>();
	r = BST->root;
	BST->printSorted(r);
	//the first search would be successful and second would fail
	BNode<int>* n = BST->search(12);
	if(n)
	{
		cout << "\nValue exists" << endl;
	}
	else
	{
		cout << "\nValue does not exist" << endl;
	}
	BNode<int>* node = BST->search(23);
	if(node)
	{
	cout << "\nValue exists"<< endl;
	}
	else
	{
		cout << "\nValue does not exist" << endl;
	}
	return 0;
}
