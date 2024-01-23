#include<iostream> 
#include "Binarytree.h" 
using namespace std; 
int main() 
{  
	//creating an object of binary tree 
	BinaryTree<int> *BT=new BinaryTree<int>(); 

//array to pass, 0 means no node exists  
	int Arr[15]={0,1,2,3,4,5,6,7,8,9,10,0,12,13,14};    
	BT->BuildTree(Arr,15);
	
	//building the tree from the array  
	cout<<"***************************************************"<<endl;    
	cout<<"Preorder Traversal(Recursive) is: "<<endl; 
	BT->PreOrder();  
	cout<<"***************************************************"<<endl;  
	cout<<"Post order Traversal(Recursive) is: "<<endl; 
	BT->PostOrder();
	cout<<"***************************************************"<<endl;        
	cout<<"Inorder Traversal(Recursive) is: "<<endl;  
	BT->InOrder();
	cout<<"***************************************************"<<endl;
	cout << "Height of the Binary Tree is: ";  
	cout<<BT->calculateDepth()<<endl;  
	cout << "***************************************************" << endl;

return 0; 
}