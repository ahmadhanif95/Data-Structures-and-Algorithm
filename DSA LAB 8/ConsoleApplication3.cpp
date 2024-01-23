#include<iostream> 
#include<stack> 
#include<queue> 
#include "Binarytree.h" 
using namespace std; 
int main() 
{  
	BinaryTree<int> *BT;
	//creating an object of binary tree  
	BT=new BinaryTree<int>(); 


	//array to pass,0 means no node exists  
	int Arr[15]={0,1,2,3,4,5,6,7,8,9,10,0,12,13,14}; 

BT->BuildTree(Arr, 15); 
//building the tree from the array  
cout<<"***************************************************"<<endl;  
cout<<"Inorder Traversal(Iterative is: "<<endl;  BT->InOrder(); 
cout<<"***************************************************"<<endl;  
cout<<"Preorder Traversal(Iterative) is: "<<endl;  BT->PreOrder();  
cout<<"***************************************************"<<endl; 
cout<<"Post order Traversal(Iterative) is: "<<endl;  BT->PostOrder();
cout<<"***************************************************"<<endl;  
cout<<"Level order Traversal(Iterative) is: "<<endl;  BT->LevelOrder();  
cout<<"***************************************************"<<endl; 

return 0; 
}