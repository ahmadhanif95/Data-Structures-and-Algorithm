//GROUP 19L-1367 M.MOAZ AWAN , 19L-1316 AHMAD HANF

//THIS PART 2 IS DONE BY HAFIZ AHMAD 19L-1316 M.MOAZ AWAN 19L-1367

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <fstream>
using namespace std;

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
void main() {
    // back end information not displayed on console
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

    ifstream File("Graph.txt");

    if (File.is_open()) // file handling
	{
        while (!File.eof())
		{
            getline(File, First, ',');
            getline(File, Second, ',');
            getline(File, Weight, '\n');
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
   
    system("pause");
}
