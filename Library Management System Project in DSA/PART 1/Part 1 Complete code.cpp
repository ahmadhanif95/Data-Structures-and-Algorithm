// GROUP 19L-1367 M.MOAZ AWAN , 19L-1316 AHMAD HANF

//THIS PART 1 IS DONE BY HAFIZ AHMAD 19L-1316 M.MOAZ AWAN 19L-1367 

#include<iostream>
#include<string>
#include<fstream>
using namespace std;


class BNode
{
public:

	//constructor with all string parameters
	BNode (string cnic,string name,string mobnumber,string address) 
	{
		CNIC=cnic;
		Name=name;
		Mobnumber=mobnumber;
		Address=address;
		leftchild=NULL;
		rightchild=NULL;
	}

	//setting left child of the Node
	void setLeftChild(BNode* n)
	{
		leftchild=n;
	}
	
	//getting left child of the Node
	BNode* getLeftChild()
	{
		return leftchild;
	}

	//setting right child of the Node
	void setRightChild(BNode* n)
	{
		rightchild=n;
	}

	//getting left child of the Node
	BNode* getRightChild()
	{
		return rightchild;
	}
	
    //getting CNIC
	string getCNIC()
	{
		return CNIC;
	}
	
	//getting Name
	string getName()
	{
		return Name;
	}

	//getting  Mobile number
	string getMobnumber()
	{
		return Mobnumber;
	}

	//getting Address
	string getAddress()
	{
		return Address;
	}

private:
	string CNIC;
	string Name;
	string Mobnumber;
	string Address;
	BNode* leftchild;
	BNode* rightchild;

};

// for testing my binary search tree 
//we know inorder traversal gives the Sorted data
void iorder(BNode *nod)
{
	if(nod!=NULL)
	{
		iorder(nod->getLeftChild());
		cout<<nod->getCNIC()<<"	"<<nod->getName()<<"	"<<nod->getMobnumber()<<"	"<<nod->getAddress()<<endl;
		iorder(nod->getRightChild());
	}
}


class BinarySearchTree
{
public:

	//constructor
	BinarySearchTree()
	{
		root=NULL;
	}
	
	//insert function that inserts data of the persons in the Binary Search tree

	void insert(string cnic,string name,string mobnumber,string address)
	{
		BNode *newNode; //creating new node
		newNode=new BNode(cnic,name,mobnumber,address); //storing data with parameters
		if(root==NULL) 
		{
			root=newNode;  //if there's no root node first newNode will be the root node
		}
		
		else
		{
			BNode *next,*previous;
			next=root;
			previous=NULL;
			while(next!=NULL) 
			{
				 // taking CNIC as key and checking the coming cnic strating from root

				if(stoll(cnic) < stoll (next->getCNIC())) //checking the coming CNIC (Smaller) 
				{
					previous=next;              //setting previous as next
					next=next->getLeftChild();  //so next will be in left
				}
				
				else if(stoll(cnic) > stoll (next->getCNIC()))  //checking the coming CNIC (greator) 
				{
					previous=next;                 //setting pre as next 
					next=next->getRightChild();   //so next will be in right
				}
				
			}
			
			if(stoll(previous->getCNIC()) > stoll(cnic))   //checking CNIC (smaller)
			{
				previous->setLeftChild(newNode);  // inserting all the data in left child
			}
			
			else
			{
				previous->setRightChild(newNode);  // else greator and inserting in right child

			}
		}
		
		    cout<<stoll(cnic)<<"	"<<name<<"	"<<mobnumber<<"	"<<address<<endl;  // Just printing data coming from the file
	}
	
	
	void printSorted()  // Inrder ttraversa
	{
		if(root!=NULL)
		{
			iorder(root); //recursive approach
			cout<<endl;
		}
	}

	void search(string data)   //search in tree by cnic
	{
	    BNode *temp;
		temp=root;
		while(temp!=NULL) // until we didn't get Null
		{
			if(stoll(temp->getCNIC()) > stoll(data)) //chechking smaller that will be in left
			{
				temp=temp->getLeftChild();  // go in left
			}
			else if(stoll(temp->getCNIC()) < stoll(data))  //chechking greator that will be in left
			{
				temp=temp->getRightChild();    //go in right
			}
			else                      //else will be the case where we find the required cnic
			{
				cout<<"CNIC :"<<temp->getCNIC()<<endl;
				cout<<"Name :"<<temp->getName()<<endl;
				cout<<"Mobile Number :"<<temp->getMobnumber()<<endl;
				cout<<"Address :"<<temp->getAddress()<<endl;
			    return;
			}
		}

		cout<<"INVALID CNIC"<<endl;
	}




private:
	BNode* root;

};

int main()
{
	//creating an object of binary search tree
    BinarySearchTree *Person; 
	Person = new BinarySearchTree();

	string Cnic,NAME,MOBNUMBER,ADDRESS;  //variables to store data coming from file to put in insert function
	cout<<"File Data :\n"<<endl;

	ifstream File("PersonsDatasheet.txt");   //file handling
	
	if(File.is_open())
	{
		while(!File.eof())
		{
			getline(File,Cnic,',');
			getline(File,NAME,',');
			getline(File,MOBNUMBER,',');
			getline(File,ADDRESS,'\n');
		    
			Person->insert(Cnic,NAME,MOBNUMBER,ADDRESS);  // inserting data from file
		}
	}

	File.close();

	// just testing my binary search tree
	//we know that INORDER traversal of binary search tree gives sorted data 
	cout<<"\nBinary Search tree Sorted list:\n"<<endl;  
	Person->printSorted();  
	cout<<endl;

	string c;
	cout<<"Enter the CNIC :";
	getline(cin,c);
	Person->search(c);

	system("pause");
	return 0;
}
