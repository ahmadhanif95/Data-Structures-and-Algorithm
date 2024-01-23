#ifndef GRAPH_H
#define GRAPH_H
#include <queue>
#include<list>
#include <iostream>
using namespace std;
class Graph
{
public:
	
	//part1: constructor initializes adjacency matrix
	Graph(int numVertex)
	{
		numVertices = numVertex;
		List = new list<int>[numVertex];
		explored = new int[10];
		for (int i = 0; i < 10; i++)
		{
			explored[i] = 0;
		}
		exploredbfs = new int[numVertices];
		for (int i = 0; i < numVertices; i++)
		{
			exploredbfs[i] = 0;
		}
	}
	//part2: returns the number of vertices in the graph
	int GetNumVertices()
	{
		return numVertices;
	}
	//part3: returns the number of edges in the graph
	int numberOfEdges()
	{
		int count = 0;
		list<int> ::iterator it;
		for (int i = 0; i < numVertices; i++)
		{
			for (it = List[i].begin(); it != List[i].end(); it++)
			{
				count++;
			}
		}
		count = count / 2;
		return count;
	}
	//part4: inserts edge going from one vertex to another
	void inserEdge(int frmVertex, int toVertex)
	{
		List[frmVertex].push_back(toVertex);
	}
	//part5: removes edge going from one vertex to another
	void removeEdge(int frmVertex, int toVertex)
	{
		List[frmVertex].remove(toVertex);
	}
	//part6: returns the degree of the node passed
	int degree(int vertex)
	{
		int count=0;
		list<int> ::iterator it;
		for (it = List[vertex].begin(); it != List[vertex].end(); it++)
		{
			count++;
		}
		return count;
	}
	//part7: outputs the order in which vertices are visited during DFS
	//Starting from node s.
	void depthfirstSearch(int s)
	{
		cout<<s<<"\t";
		explored[s] = 1;
		list<int> ::iterator it;
		for (it = List[s].begin(); it != List[s].end(); it++)
		{
			int x = *it;
			if (!explored[x])
			{
				depthfirstSearch(x);
			}
		}
	}
	//part8: outputs the order in which vertices are visited during BFS
	//Starting from node s.
	void breadthfirstSearch(int s)
	{
		queue<int> q;
		q.push(s);
		exploredbfs[s] = 1;
		while (!q.empty()) 
		{
			int top = q.front();
			cout << top << "\t";
			q.pop();
			list<int> ::iterator it;
			for (it = List[top].begin(); it != List[top].end(); it++)
			{
				int x = *it;
				if ( (!exploredbfs[x]))
				{
					q.push(x);
					exploredbfs[x] = 1;
				}
			}
		}
		
	}
	void print()
	{
		cout << "\nThe Adjacency List is: \n";
		for (int i = 0; i < numVertices; i++)
		{
			list<int> ::iterator it;
			cout << "["<<i<<"]";
			for (it = List[i].begin(); it != List[i].end(); it++)
			{
				int s = *it;
				cout << "--->" << s;
			}
			cout << endl;
		}
	}
private:
	list<int>* List;
	int* explored;
	int* exploredbfs;
	int numVertices;
	
};
#endif
