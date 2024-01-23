#include<iostream>
#include<string>
#include <array>
#include <windows.h>
#include <sstream>
#include <stdlib.h>
#include <stack>
#include<fstream>
using namespace std;
int quantity = 0;

int generateBookID(string basicString);

int generateAlphabetID(char c);

int queue_array[20];

struct BST *rack[10][5];

struct User *start = nullptr;
//basic functions as we develop in our lab 5,6
class Queue {
public:
    int top;

    Queue() {
        top = -1;
    }

    bool isFull() {
        return top == 19;
    }

    bool isEmpty() {
        return top == -1;
    }

    void enQueue(int value) {
        if (!isFull()) {
            top++;
            queue_array[top] = value;
        } else {
            cout << "Queue is full!";
        }
    }

    int deQueue() {
        int value = queue_array[0];
        // Push left
        for (int i = 0; i < top; ++i) {
            queue_array[i] = queue_array[i + 1];
        }
        top--;
        return value;
    }

    void reset() {
        top = -1;
    }

    int get_top() {
        return top;
    }
}
struct Book {
    string name;
    string author;
    int id, amount;
    int rack;
    struct Book *next;
public:
    Book(string new_name, string new_author, int new_id, int new_rack) {
        name = new_name;
        author = new_author;
        id = new_id;
        rack = new_rack;
        next = nullptr;
        amount = 1;
    }
};


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


struct edge  // to store the details of each node of graph
{
    char block;
    int weight;
    edge *conc;
};
struct dgst  // To store the information of each vertax to find shortest path
{
    char verrt, conc;
    bool vist;
    int dist;
};
struct hsl  // for storing the shortest paths
{
    string path;
    int dist;
};
class graph 
{
   protected:
    edge **vertex;
    hsl *lt;
    int siz;

   public:
    // constructors
    graph(int s) 
	{
        vertex = new edge *[s];  // to make an array equal to number of vertices
        siz = s;
        for (int i = 0; i < s; i++)  // making of array
        {
            vertex[i] = new edge();
            vertex[i]->block = NULL;
            vertex[i]->weight = 0;
            vertex[i]->conc = NULL;
        }

        lt = new hsl[siz * siz];  // making array of size square to store all
                                  // the shortest paths
        for (int v = 0; v < siz * siz; v++)  // inetializing all paths to null and distance to 0
        {
            lt[v].dist = 0;
            lt[v].path = "\0";
        }
    }

    void addvertx(char nm) 
	{
        int i = nm % 65;
        vertex[i]->block = nm;
    }
   
    void addedge(char n1, char n2, int w)
	{
        edge *nw;
        int i = n1 % 65;
        nw = new edge();
        nw->block = n2;
        nw->weight = w;
        nw->conc = NULL;
        edge *nx;
        nx = vertex[i];
        while (nx->conc)  // to go to the end of list
            nx = nx->conc;
        nx->conc = nw;  // entering at the end
    }
  
    void shortpthstor() 
	{
        dgst *chck, pre;  // struct for keeping the record of vertex that is
                          // visited or not its weight and its shortest conection
        queue<edge*> *qu;  // to traverse qraph
        qu = new queue<edge *>();
        edge *pt;
        chck = new dgst[siz];  // inetializing the size equal to the number of  vertises
                            
        for (int c = 0; c < siz; c++)
		{
            for (int i = 0; i < siz; i++)  // inetializing vertises and making visited false and  distance infinate.
                 
            {
                chck[i].conc = NULL;
                chck[i].verrt = vertex[i]->block;
                chck[i].dist = INT_MAX;  // making distance infinate.
                chck[i].vist = 0;
            }

            int j = c;
            chck[j].vist = 1;  // making inetial place as visited
            chck[j].dist = 0;  // making its distance 0
            qu->push(vertex[j]);
            while (!qu->empty())
			{
                pt = qu->front();
                qu->pop();
                int v = pt->block % 65;
                pre = chck[v];  // to get the record of the main vertax
                while (pt)      // to store non visited nodes in queue
                {
                    pt = pt->conc;
                    if (pt)  // to check if the node exist
                    {
                        int i = pt->block % 65;
                        if (!chck[i].vist)  // if it is not visited then push it
                                            // in queue and mark it as visited
                        {
                            qu->push(vertex[pt->block % 65]);
                            chck[i].vist = 1;
                        }
                        if (pre.dist + pt->weight < chck[i].dist)  // seting the shortest path of the node
                        {
                            chck[i].dist = pre.dist + pt->weight;
                            chck[i].conc = pre.verrt;
                        }
                    }
                }
            }
            stack<dgst> st;
            for (int b = 0; b < siz; b++) 
			{
                char d = 65 + b;
                while (d)  // storing the data in stack
                {
                    st.push(chck[d % 65]);
                    d = chck[d % 65].conc;
                }
                // saving data at the specific position of array
                lt[c * siz + b].path = st.top().verrt;
                lt[c * siz + b].dist = st.top().dist;
                st.pop();
                while (!st.empty()) 
				{
                    lt[c * siz + b].path += "-->";
                    lt[c * siz + b].path += st.top().verrt;
                    lt[c * siz + b].dist = st.top().dist;
                    st.pop();
                }
            }
        }
    }

    void prntpth(char c, char d)  // printing data
    {
        cout << endl;
        // c%65*siz+d%65 formula to convert char to int and going to the
        // specified position of array without any iteration
        if ((c % 65 * siz + d % 65) >= 0 && (c % 65 * siz + d % 65) <siz * siz)  // checking the entered values if they exist or not in array
                           
        {
            // printing the path and distance
            cout << "Shortest path from Library '" << c << "' to " << d << " is: ";
            cout << lt[c % 65 * siz + d % 65].path << endl << endl;
            cout << "Total distance from " << c << " to " << d << " for the above path is: ";
            cout << lt[c % 65 * siz + d % 65].dist;
            cout << endl << endl;
        } 
		else
            cout << "Wrong Places Entered\n";
    }
    // Destructor
    ~graph() 
	{
        edge *pr, *th;
        for (int i = 0; i < siz; i++)
		{
            while (vertex[i]->conc != NULL)
			{
                pr = vertex[i];
                th = vertex[i]->conc;
                while (th->conc)
				{
                    pr = th;
                    th = th->conc;
                }
                pr->conc = NULL;
                delete th;
            }
            delete vertex[i];
        }
        delete[] vertex;
        siz = 0;
        vertex = NULL;
        delete[] lt;
        lt = NULL;
    }
};
int quantity = 0;

int generateBookID(string basicString);

int generateAlphabetID(char c);

int queue_array[50];

struct BST *rack[10][5];

struct User *start = nullptr;
//basic functions as we develop in our lab 5,6
class Queue {
public:
    int top;

    Queue() {
        top = -1;
    }

    bool isFull() {
        return top == 49;
    }

    bool isEmpty() {
        return top == -1;
    }

    void enQueue(int value) {
        if (!isFull()) {
            top++;
            queue_array[top] = value;
        } else {
            cout << "Queue is full!";
        }
    }

    int deQueue() {
        int value = queue_array[0];
        // Push left
        for (int i = 0; i < top; ++i) {
            queue_array[i] = queue_array[i + 1];
        }
        top--;
        return value;
    }

    void reset() {
        top = -1;
    }

    int get_top() {
        return top;
    }
};
//for one book then points to bst for next book
struct Book 
{
    string bookname;
    string author;
	string eddition;
	string publisher;
	string issued;
	string returnd;
	int rack;
    int id;
	int amount;
    struct Book *next;
public:
    Book(string new_name, string new_author, int new_id,string new_eddition,string new_publisher,string new_issued,string new_returnd,int new_rack) {
        bookname = new_name;
        author = new_author;
		eddition=new_eddition;
	   publisher=new_publisher;
	   issued=new_issued;
	    rack = new_rack;
	   returnd=new_returnd;
        id = new_id;
        next = nullptr;
        amount = 1;
    }
};
struct BST {
    int id;
    struct BST *left, *right;
    struct Book *next;
public:
    BST(int new_id) {
        id = new_id;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};
struct User {
    string cnic;
    struct Book *book;
    struct User *next;
public:
    User(string new_name) {
        cnic = new_name;
        next = nullptr;
        book = nullptr;
    }
};
BST *searchBST(struct BST *root, int id);
void displayIssuedBooks();
void warning_letter(string cnic);
bool returnBook(string user_name, string book_name);
Book *searchBook(int rack_no, int shelve, string name, string author_name);
Book *searchPreviousBook(struct BST *root, string name, string author_name);
bool searchBookcheck(struct BST *root, string name, string author_name);
bool issueBook(string username, string bookname, string author_name);
bool deleteBook(string name, string author_name);
Book *searchBook(struct BST *bst, string name, string author_name);
bool SearchingsearchBook(struct BST *bst, string name, int rack, int shelve);
void generateLibraryData();
Book *searchBookmain(struct BST *root, string name, string author_name);
void addBook(int shelve, string book_name, string author_name, string eddition_name,string publisher_name );
BST *createBST(int id, struct BST *root);
void displayLibrary(struct BST *root);
Queue queue;
int main()
{
	generateLibraryData();
	// 19l-1316 19l-1367  hafiz ahmad moaz awan
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
    
	graph map(40);
    map.addvertx('A');  //adding vertexes
    map.addvertx('B');
    map.addvertx('C');
    map.addvertx('D');
    map.addvertx('E');
    map.addvertx('F');
    map.addvertx('G');
    map.addvertx('H');
    map.addvertx('I');
    map.addvertx('J');
    map.addvertx('K');
    map.addvertx('L');
    map.addvertx('M');
    map.addvertx('N');
    map.addvertx('O');
    map.addvertx('P');
    map.addvertx('Q');
    map.addvertx('R');
    map.addvertx('S');
    map.addvertx('T');
    map.addvertx('U');
    map.addvertx('V');
    map.addvertx('W');
    map.addvertx('X');
    map.addvertx('Y');
    map.addvertx('Z');
    map.addvertx('a');
    map.addvertx('b');
    map.addvertx('c');
    map.addvertx('d');

    string First, Second;  // for storing file data
    string Weight;

    ifstream file("Graph.txt");

    if (file.is_open()) // file handling
	{
        while (!file.eof())
		{
            getline(file, First, ',');
            getline(file, Second, ',');
            getline(file, Weight, '\n');
            char F, S;
            int W;

            F = First[0];    //converting single character string into char
            S = Second[0];  //converting single character string into char

            W = stoi(Weight);     //converting string into int
            map.addedge(F, S, W);
        }
    }

    File.close();

    // calling funcion to store all data in data structure with time complexity O(1)
    map.shortpthstor();
    // user controled information displayed on console
    cout << "-------------------------------------------------------------------\n";
    cout << "Our Graph Covers All of The JOHAR TOWN BLOCKs\n\n";
    cout << "BlOCKS are from A TO Z and VIP blocks are 4 with small letters 'a,b,c,d' \n\n";
    cout << "Library is in 'L' Block \n";
    cout << "-------------------------------------------------------------------"<< endl;

    int n;
    char destination;
    while (1) 
	{
        n = 0;
		cout << "Press 0 : For Exit\n";
        cout << "Press 1 : To find Shortest path from the Library to Borrowers Address : ";
        cin >> n;
        if (n == 1)
		{
            cout << "\nStarting from the Library 'L'\n";
            cout << "\nEnter Borrowers Address : ";
            cin >> destination;
            map.prntpth('L', destination);

        } else
            break;
    }
   int a;
	while (true) {
        cout << "***********************************************************";
        cout << "0. Exit\n";
        cout << "1. Display All Books\n";
        cout << "2. Insert a Book\n";
        cout << "3. Delete a Book\n";
        cout << "4. Search Book By Name\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Display Issues\n";
		cout << "8. Warning Issue\n";
        cout << "\nSelect an option : ";
		cout << "***********************************************************";

        cin >>a;
	}
	switch(a)
	{
		case 0: {
                exit(0);
                }
            case 1: 
				{
                cout << "                 D I S P L A Y                          "<<endl;
                // For each rack
                for (int c = 0; c < 5; ++c) {
                    cout << "Rack" << c + 1 <<endl;

                    // For each shelve
                    for (int r = 0; r < 10; ++r) {
                        cout << "Shelve" << r + 1 <<endl;
                        displayLibrary(rack[r][c]);
                    }
                }
                break;
              }
				case 2: 
					{
                string book_name;
                string author_name;
				string eddition;
                string publisher;
				// 5 rows shows 5 types of books in the univerity
                cout << "                I N S E R T                    "<<endl;
                cout << "0. Back\n";
                cout << "1. calculus\n";
                cout << "2. Computerscience\n";
                cout << "3. Physicsfor engineers\n";
                cout << "4. Islamic studies\n";
                cout << "5. Other social sciences and humanaities\n";
                cout << "\nSelect an option : ";
                cin >> a;
                if (a == 0) break;
                else {
                    cout << "\nBook Name : ";

                    cin.ignore();
                    getline(cin, book_name);

                    cout << "\nAuthor Name : ";
                    getline(cin, author_name);

					cout << "\neddition : ";
                    getline(cin, eddition);

					cout << "\npublisher Name : ";
                    getline(cin, publisher);

                    addBook(a- 1, book_name, author_name,eddition,publisher);
                }
                break;
					}
				case 3: 
					{
                string name, author_name;
                cout << "                 D E L E T E               "<<endl;
                cout << "\nEnter Book Name : ";
                cin.ignore();
                getline(cin, name);
                cout << "\nEnter Author Name : ";
                getline(cin, author_name);
                bool deleted = deleteBook(name, author_name);
                if (deleted) cout << "Successfully Deleted book";
                else cout << "Book not found on record";
                break;
            }
			    case 4: 
					{
                string name;
                bool found = false;
                cout << "                     S E A R C H                 "<<endl;
                cout << "Enter Book Name : ";
                cin.ignore();
                getline(cin, name);

                int id = generateBookID(name);
                // For each rack
                for (int c = 0; c < 5; ++c) {
                    // For shelve
                    int shelve = id % 10;

                    // search BST
                    struct BST *bst = searchBST(rack[shelve][c], id);

                    // If BST found
                    if (bst != nullptr) {
                        found = SearchingsearchBook(bst, name, c, shelve);
                        break;
                    }
                }
				if (!found) {
                    cout << "Book not found"<<endl;
                }
                break;
            }
				case 5: 
				{
                string book_name;
                string author_name;
				string eddition;
				string publisher;
				string issued;
				string returnd;
                string cnic;
                cout << "                 issue book                 "<<endl;
                cout << "Enter User CNIC : ";
                cin.ignore();
                getline(cin, cnic);
                cout << "Enter Book Name : ";
                getline(cin, book_name);
                cout << "Enter Author Name : ";
                getline(cin, author_name);
				cout << "Enter eddition : ";
                getline(cin, eddition);
                cout << "Enter publisher Name : ";
                getline(cin, publisher);
				cout << "Enter issue date : ";
                getline(cin, issued);
                cout << "Enter return date : ";
                getline(cin, returnd);

                bool issue = issueBook(cnic, book_name, author_name,eddition,publisher,issued,returnd);
                if (issue) 
					cout << "Book issued successfully!"<<endl;
                break;
            }
				case 6: {
                string book_name;
				string author_name;
				string eddition;
				string publisher;
                string username;
                cout << "                     return book                 "<<endl;
                cout << "Enter User CNIC : ";
                cin.ignore();
                getline(cin, username);
                cout << "Enter Book Name : ";
                getline(cin, book_name,author_name,eddition,publisher);


                bool issue = returnBook(username, book_name,author_name,eddition,publisher);
                if (issue) cout << "Book returned successfully!"<<endl;
                break;
            }
            case 7: {
                cout << "            issued books detail                 ";
                displayIssuedBooks();
                break;
            }
					case 8: {
                cout << "            issued books late warning letter               ";
                displayIssuedBooks();
			    string hh;
		        cout << "Enter the cnic number::";
		        cin >> hh;
				bool issue = warning_letter(hh);
                if (issue) 
					cout << "Warning Letter send successfully!"<<endl;
                break;
                
            }
            default: {
                cout << "Invalid input!";
					 }
	}

	system("pause");
	return 0;
}
/function to genrate book id
int generateBookID(string str) {
    queue.reset();
    int value = 0;
    // Check for each character in str
    for (int i = 0; i < str.length(); ++i) {
        // If str[i] is a space
        if (str[i] == ' ') {
            queue.enQueue(value);
            value = 0;
        } else {
            value += generateAlphabetID(str[i]);
        }
    }
    queue.enQueue(value);
    value = 0;

    stringstream string_stream;

    while (!queue.isEmpty()) {
        // Adding whole que values to string_stream
        string_stream << queue.deQueue();
    }

    // Combining different parts
    string combining_values = string_stream.str();

    istringstream integer_string_stream(combining_values);

    // Converting combining_values to int
    integer_string_stream >> value;
    return value;
}

int generateAlphabetID(char c) {

    char alphabets[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j','k', 'l', 'm', 'n'
		, 'o', 'p', 'q', 'r', 's', 't','u', 'v', 'w', 'x', 'y', 'z'};
    c = tolower(c);

    for (int i = 0; i < 26; ++i) {
        if (c == alphabets[i])
            return ++i;
    }

    return -1;
}

BST *searchBST(struct BST *root, int id) {

    if (root == nullptr) {
        return nullptr;
    } else {
        while (root != nullptr) {
            if (root->id > id) root = root->left;
            else if (root->id < id) root = root->right;
            else return root;
        }
        return nullptr;
    }
}
//to add book in O(1) by hasing technique and bst
void addBook(int shelve, string book_name, string author_name, string eddition_name,string publisher_name ) 
{
     // shelve are the columns
     

    int id = generateBookID(book_name);
    int row = id % 10;
    struct Book *new_book = new Book(book_name, author_name,eddition_name,publisher_name, id, row);

    // Checking if BST already exists then work on it
    if (rack[row][shelve] != nullptr) {

        // Create it root and search if any BST already exists
        struct BST *root = rack[row][shelve];
        struct BST *searched = searchBST(root, id);

        // If no BST with such ID exists
        if (searched == nullptr) {
            struct BST *new_BST = createBST(id, root);

            // Adding new_book book to BST
            new_BST->next = new_book;
        }

            // If BST exists with same ID
        else {

            // Search if book with same name exists
            struct Book *searched_book = searchBook(searched, book_name, author_name);

            // If same book is alredy present
            if (searched_book != nullptr)
                searched_book->amount++;
            else {
                new_book->next = searched->next;
                searched->next = new_book;
            }
        }
    }

        // If BST does not exist at shelve array
    else {
        rack[row][shelve] = new BST(id);
        rack[row][shelve]->next = new_book;
    }
}

BST *createBST(int id, struct BST *root) {
    struct BST *current = new BST(id);

    struct BST *p = root;
    struct BST *k = p;

    if (p == nullptr) {
        root = current;
    } else {
        while (p != nullptr) {
            k = p;
            if (p->id > id) p = p->left;
            else p = p->right;
        }

        if (k->id > id) k->left = current;
        else k->right = current;
    }
    return current;
}

void displayLibrary(struct BST *root) {
    if (root != nullptr) {
        displayLibrary(root->left);

        // Displaying book linked list
        struct Book *book = root->next;
        while (book != nullptr) {

            cout<<"Book id book name book eddition book publisher \n"<< book->id<< book->amount<<
				book->bookname.c_str()<<book->author.c_str()<<book->eddition.c_str()<<book->publisher.c_str();
            book = book->next;

        }

        displayLibrary(root->right);
    }
}
Book *searchBook(struct BST *bst, string bookname, string author_name) {
    int id = generateBookID(bookname);
    struct Book *book = bst->next;

    while (book != nullptr) {
        if (book->bookname == bookname && book->author == author_name)
            return book;
        book = book->next;
    }

    return nullptr;
}

bool SearchingsearchBook(struct BST *bst, string name, int rack, int shelve) {
    int id = generateBookID(name);
    struct Book *book = bst->next;
    bool found = false;

    while (book != nullptr) {
        if (book->bookname == name) {
            found = true;
            cout << "\nBook name : " << book->bookname << "       ID : " << book->id << "   Rack: " << rack + 1
                 << "  Shelve: "
                 << shelve + 1 << "  Author Name: " << book->author;
        }
        book = book->next;
    }

    return found;
}

bool deleteBook(string name, string author_name) {
    int id = generateBookID(name);
    // For each rack
    for (int c = 0; c < 5; ++c) {
        // For shelve
        int shelve = id % 10;

        // search BST
        struct BST *bst = searchBST(rack[shelve][c], id);

        // If BST found
        if (bst != nullptr) {
            // Searching book
            if (searchBookcheck(bst, name, author_name)) {
                struct Book *book = searchBookmain(bst, name, author_name);
                struct Book *prevbook = searchPreviousBook(bst, name, author_name);
                if (book->bookname == name && book->author == author_name) {
                    struct Book *del_book = book;
                    if (book->amount > 1) {
                        book->amount--;
                    } else {
                        if (book->next == nullptr) {
                            bst->next = nullptr;
                        } else {
                            bst->next = book->next;
                        }
                    }
                    return true;
                } else if (prevbook != nullptr) {
                    struct Book *del_book = book->next;
                    if (book->next->bookname == name && book->next->author == author_name) {
                        // If amount is greater than 1
                        if (book->next->amount > 1) {
                            book->next->amount--;
                            return true;
                        }
                        if (book->next->next != nullptr) {
                            book->next = book->next->next;
                        } else {
                            book->next = nullptr;
                        }
                        delete (del_book);
                        return true;
                    }


                }
            }


        }
    }

    return false;
}

Book *searchPreviousBook(struct BST *root, string name, string author_name) {
    int id = generateBookID(name);
    struct Book *book = root->next;
    struct Book *prev_book = book;

    while (book != nullptr) {
        if (book->bookname == name && book->author == author_name)
            return prev_book;
        prev_book = book;
        book = book->next;
    }
    return nullptr;
}

Book *searchBookmain(struct BST *root, string name, string author_name) {
    int id = generateBookID(name);
    struct Book *book = root->next;

    while (book != nullptr) {
        if (book->bookname == name && book->author == author_name)
            return root->next;

        book = book->next;
    }
    return nullptr;
}

bool searchBookcheck(struct BST *root, string name, string author_name) {
    int id = generateBookID(name);
    struct Book *book = root->next;

    while (book != nullptr) {
        if (book->bookname == name && book->author == author_name)
            return true;

        book = book->next;
    }
    return false;
}

void generateLibraryData() {
    ifstream inFile;
    inFile.open("bookdata.txt");
    if (!inFile) {
        cerr << "Unable to open file error";
        exit(1);   // call system to stop
    }

    // Variables that will collect data
    int shelve;
    string shelve_str;
    string book_name;
    string author_name;
	  string eddition;
	    string publisher;
    while (getline(inFile, shelve_str)) {
        // converting shelve_str to int
        shelve = stoi(shelve_str);

        getline(inFile, book_name);
        getline(inFile, author_name);
		getline(inFile, eddition);
        getline(inFile, publisher);
        addBook(shelve, book_name, author_name,eddition,publisher);
    }
    inFile.close();
}

bool issueBook(string user_id, string book_name, string author_name,string eddition, string publisher) {

    bool user_exists = false;
    struct User *u = start;
    struct User *user1 = nullptr;
    struct User *user = nullptr;

    while (u != nullptr) {
        if (u->cnic == user_id) {
            user_exists = true;
        }
        user1 = u;
        u= u->next;
    }
    if(!user_exists) {
        user = new User(user_id);

        int id = generateBookID(book_name);
        int shelve = id % 10;
        struct Book *book = nullptr;
        struct Book *temp_book = nullptr;
        struct BST *bst = nullptr;

        for (int i = 0; i < 5; ++i) {
            bst = searchBST(rack[shelve][i], id);
            if (bst != nullptr) {
                book = searchBook(bst, book_name, author_name,eddition,publisher);
                if (book != nullptr) {
                    temp_book = new Book(book_name, author_name,eddition,publisher, id, i);
                    temp_book->author = book->author;
					if (book != nullptr) {
                    temp_book = new Book(book_name, author_name,eddition,publisher, id, i);
                    temp_book->eddition = book->eddition;

                    // deleteing book now
                    deleteBook(book_name, author_name,eddition,publisher);

                    // Now looking if user linked list is null
                        user->book = temp_book;
                    if(start== nullptr){
                        start = user;
                    }
                    else{
                        user1->next=user;
                    }
                    return true;
                }
            }
        }
        cout<<"Book Not Found";
    }
    else{
        cout<<"\n"<<"One User can Issue Only One Book";
    }
    return false;
}

bool returnBook(string user_id, string book_name,string eddition, string publisher) {
    // searching username in list
    struct User *user = start;
    struct User *prev_user = start;
    while (user != nullptr) {
        prev_user = user;
        if (user->cnic == user_id) break;
        user = user->next;
    }

    // If user exists
    if (user != nullptr) {
        // Searching book
        struct Book *book = user->book;

        // If book exists
        if (book != nullptr&&book->bookname==book_name) {

            // If there is only one book in user
            if (user->book == book) {
                addBook(book->rack, book_name, book->author,book->eddition,book->publisher);
                user->book= nullptr;
                delete book;

                // If the user is the root
                if (user == start) {
                    if(start->next!= nullptr){
                    start = start->next;
                    }
                    else{
                        start = nullptr;
                    }
                }
                else {
                    prev_user->next= user->next;
                    delete user;
                }
                return true;
            }
        }
        else{
            cout<<"\nBook not Found";
        }
    }
    else{
        cout<<"User Doesn't Exist on record";
    }
    return false;

}

void displayIssuedBooks() {
    struct User *user = start;
    while (user != nullptr) {
        struct Book *book = user->book;

        // Books
        while (book != nullptr) {
            cout<<"cnic bookname eddition publisher issued date return date\n"<< user->cnic.c_str()<< book->bookname.c_str()<<
				book->author.c_str()<<book->eddition.c_str()<<book->publisher.c_str()<<book->issued.c_str()<<
				book->returnd.c_str();
            book = book->next;
        }

        user = user->next;
    }
}
//issue warning letter
	void warning_letter(string cnic)
	{

		
		
			
				cout << "*-----------------------------------------------*" << endl;
				cout << "IISSUEING THE WARNING LEETER::" << endl;
				cout << "NATIONAL UNIVERSITY OF COMPUTING AND EMERGING SCIENCES,LAHORE" << endl;
				cout << "NOTICE" << endl;
				cout << "LIBRARY BOOKS" << endl;
				cout << cnic<<endl;
				cout << "All students of classes of all batchs are hereby informed to return all library books" << endl;
				cout << "issued to them, to the library before the 10th of this month as the school will close" << endl;
				cout << "down for winter holidays. Students who fail to return the books on time will be fined." << endl;
				cout << "Mr.Amar omar" << endl;
				cout << "(Librarian)" << endl;
				cout << "AGANIST THE BORROWER::" << endl;
				
	}
