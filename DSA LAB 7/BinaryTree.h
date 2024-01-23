#ifndef BINARYTREE_H 
#define BINARYTREE_H 
using namespace std;
int i = 0;
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
private:
	DT data;
	BNode* leftchild;
	BNode* rightchild;
};

template<class DT>
class BinaryTree
{
public:
	//part1: constructor
	BinaryTree()
	{
		root = NULL;
		count = 0;
	}
	BNode<DT>* Create(BNode<DT>* r, DT* arr, int size, int in)
	{
		if (in >= size)
			return r;
		BNode<DT>* temp;
		temp = new BNode<DT>();
		temp->setData(arr[in]);
		r = temp;
		r->setLeftChild(Create(r->getLeftChild(), arr, size, 2 * in + 1));
		r->setRightChild(Create(r->getRightChild(), arr, size, 2 * in + 2));
	}
	//part 2:
	//Build the binary tree from the data given in the array.
	//If a node doen't exist the array element is 0

	void BuildTree(DT* Arr, int Size)
	{
		root = Create(root, Arr, Size, 0);
	}
	//part3: post order traversal (recursive)
	//you may call any other function with parameters which might be needed
	void pstorder(BNode<DT>* r)
	{
		if (r != NULL)
		{
			pstorder(r->getLeftChild());
			pstorder(r->getRightChild());
			cout << r->getData() << "\t";
		}
	}
	void prorder(BNode<DT>* r)
	{
		if (r != NULL)
		{
			cout << r->getData() << "\t";
			prorder(r->getLeftChild());
			prorder(r->getRightChild());
		}
	}
	void iorder(BNode<DT>* r)
	{
		if (r != NULL)
		{
			iorder(r->getLeftChild());
			cout << r->getData() << "\t";
			iorder(r->getRightChild());
		}

	}
	void PostOrder()
	{
		pstorder(root);
	}
	//part4: pre order traversal (recursive)
	// you may call any other function with parameters which might be needed
	void PreOrder()
	{
		prorder(root);
	}
	//part5: in order traversal (recursive)
	// you may call any other function with parameters which might be needed
	void InOrder()
	{
		iorder(root);
	}
	// part6: prints the height of the binary tree, you may pass any parameters needed
	int calculateDepth()
	{
		BNode<DT>* temp = new BNode<DT>();
		temp = root;
		int c = 0;
		c=calHeight(temp);
		return c;


	}
	
	int calHeight(BNode<DT>* r)
	{
		
		if (r != NULL)
		{
			count++;
			calHeight(r->getLeftChild());
			
			
		}
		return count;
	}
	int count;
private:
	// you may add any other private members which might be needed by recursive functions
	BNode<DT>* root;
	
};
#endif


