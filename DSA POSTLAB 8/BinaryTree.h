#ifndef BINARYTREE_H 
#define BINARYTREE_H 
#include<stack> 
#include<queue>
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
		{
			return r;
		}
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
	
	
	void PostOrder()
	{
		BNode<DT>* temp = new BNode<DT>();
		BNode<DT>* n = new BNode<DT>();
		temp = root;
		stack<BNode<DT>*>* s1 = new stack<BNode<DT>*>();
		stack<BNode<DT>*>* s2 = new stack<BNode<DT>*>();
		s1->push(temp);
		while (!s1->empty())
		{
			n = s1->top();
			s1->pop();
			s2->push(n);
			if (n->getLeftChild())
			{
				s1->push(n->getLeftChild());
			}
			if (n->getRightChild())
			{
				s1->push(n->getRightChild());
			}
		}
		while (!s2->empty()) 
		{
			n = s2->top();
			s2->pop();
			cout << n->getData() << " ";
		}
		
	}
	/*part4: pre order traversal (recursive)
	 you may call any other function with parameters which might be needed*/
	void PreOrder()
	{
		stack<BNode<DT>*>* s = new stack<BNode<DT>*>();
		BNode<DT>* temp = new BNode<DT>();
		temp = root;
		s->push(temp);
		while (!s->empty()) 
		{
			temp= s->top();
			cout<<temp->getData()<<" ";
			s->pop();
			if (temp->getRightChild() != NULL)
			{
				s->push(temp->getRightChild());
			}
			if (temp->getLeftChild()!=NULL)
			{
				s->push(temp->getLeftChild());
			}
		}
		
	}
	/*part5: in order traversal (recursive)
	 you may call any other function with parameters which might be needed*/
void InOrder()
{
	stack<BNode<DT>*>* s = new stack<BNode<int>*>();
	BNode<DT>* temp = root;

	while (temp != NULL || !s->empty())
	{
		while (temp != NULL)
		{
			s->push(temp);
			temp = temp->getLeftChild();
		}
		temp = s->top();
		s->pop();
		cout << temp->getData() << " ";
		temp = temp->getRightChild();
	}
}
	// part6: prints the height of the binary tree, you may pass any parameters needed
int calculateHeightItr()
{
	BNode<DT>* temp = new BNode<DT>();
	BNode<DT>* n = new BNode<DT>();
	temp = root;
	queue<BNode<DT>*>* q = new queue<BNode<DT>*>();
	int c = 0;
	int height = 0;
	q->push(temp);
	while (!q->empty())
	{
		c = q->size();
		if (c == 0)
		{
			return height;
		}
		height++;
		while (c > 0)
		{
			n = q->front();
			q->pop();
			if (n->getLeftChild() != NULL)
			{
				q->push(n->getLeftChild());
			}
			if (n->getRightChild() != NULL)
			{
				q->push(n->getRightChild());
			}
			c--;

		}

	}

	return height;
}

	
void LevelOrder()
{
		BNode<DT>* temp = new BNode<DT>();
		temp = root;
		if (temp == NULL)
		{
			return;
		}
		stack<BNode<DT>*> *s=new stack<BNode<DT>*>();
		queue<BNode<DT>*> *q=new queue<BNode<DT>*>();
		q->push(temp);
		while (!q->empty()) 
		{
			int size = q->size();
			while (size) 
			{
				BNode<DT>* p = q->front();
				q->pop();
				cout << p->getData() << " ";
				if (p->getLeftChild()!=NULL)
					{
						q->push(p->getLeftChild());
					}
				if (p->getRightChild()!=NULL)
					{
						q->push(p->getRightChild());
					}
				size--;
			}	
		}
	
}
	int count;
	private:
	BNode<DT>* root;

};
#endif



