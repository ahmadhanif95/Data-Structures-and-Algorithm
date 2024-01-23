#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
using namespace std;
template<class DT>
class BNode
{
public:
	BNode()
	{
		leftchild = NULL;
		rightchild = NULL;
		data = 0;
	}
	void setLeftChild(BNode<DT>* n)
	{
		leftchild = n;
	}
	BNode<DT>* getLeftChild()
	{
		return leftchild;
	}
	void setRightChild(BNode<DT>* n)
	{
		rightchild = n;
	}
	BNode<DT>* getRightChild()
	{
		return rightchild;
	}
	void setData(DT pdate)
	{
		data = pdate;
	}
	DT getData()
	{
		return data;
	}

	DT data;
	BNode* leftchild;
	BNode* rightchild;
}; 

template<class DT>
class BinarySearchTree
{
public:
	//part1: constructor
	BinarySearchTree()
	{
		root = NULL;
	}
	//part2: Create and insert a BNode carrying data
	//in the binary search tree. It return true if
	//insertion takes place successfully and false otherwise
	
bool insert(const DT dt)
{
		
	BNode<DT>* n = new BNode<DT>();
	n->data = dt;
	if (root == NULL)
	{
		root=n;
		return true;
	}
	BNode<DT>* temp = new BNode<DT>();
	temp = root;
	BNode<DT>* parent = new BNode<DT>();
	parent = NULL;
	while (temp != NULL) 
	{
		parent = temp;
		if (dt < temp->data)
		{
			temp = temp->getLeftChild();
		}
		
		else if(dt> temp->data)
		{
			temp = temp->getRightChild();
		}
		else if (dt == temp->data)
		{
			return false;
		}
	}
	if (parent == NULL)
	{
		parent=n;
	}
	if (dt < parent->data)
	{
		parent->setLeftChild(n);
			
	}
	else
	{
		parent->setRightChild(n);
			
	}
	return true;
	
}
	//part3: Search for data in the binary search tree
	// and return the pointer of the node carrying data
	//return null/0 if data doesn’t exist
BNode<DT>* search(const DT dt)
{
	
	BNode<DT>* temp = new BNode<DT>();
	temp = root;
		 
	while (temp != NULL)
	{
		if (dt > temp->getData())
		{
			temp = temp->getRightChild();
		}
		else if (dt < temp->getData())
		{
			temp = temp->getLeftChild();
		}
		else
		{
			return temp;  
		}
	}
	return 0;
}

//part4: prints all the data present in the tree
	//sorted in ascending order
	void printSorted(BNode<DT>* temp)
	{
		
		if (temp != NULL)
		{
			printSorted(temp->getLeftChild());
			cout << temp->getData() << "\t";
			printSorted(temp->getRightChild());
		}
	}
	////part5: delete the BNode carrying data from the
	////binary search tree. It return true if
	////deletion takes place successfully and false otherwise
	//bool delete(const DT data);
	////part6: destructor, delete all nodes
	//~BinarySearchTree();
	BNode<DT>* root;
};

#endif