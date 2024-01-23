#include<iostream>
#include "Graph.h"
using namespace std;
int main()
{
	Graph* g; //creating an object of graph with 5 vertices
	g = new Graph(5);
	//inserting edges in the graph
	g->inserEdge(0, 1);
	g->inserEdge(0, 4);
	g->inserEdge(1, 0);
	g->inserEdge(1, 2);
	g->inserEdge(1, 3);
	g->inserEdge(1, 4);
	g->inserEdge(2, 1);
	g->inserEdge(2, 3);
	g->inserEdge(3, 1);
	g->inserEdge(3, 2);
	g->inserEdge(3, 4);
	g->inserEdge(4, 0);
	g->inserEdge(4, 1);
	g->inserEdge(4, 3);
	g->print();
	//display total number of edges
	cout <<"Number of edges are " << g->numberOfEdges() << endl;
	//display degree of vertex number 4
	cout << "Degree of vertex "<< g->degree(4) << endl;
	cout << "\nOutput for Depth first search starting from vertex 0 " << endl;
	g->depthfirstSearch(0);
	cout << "\nOutput for Breadth first search starting from vertex 0 "<< endl;
	g->breadthfirstSearch(0);
	return 0;
}