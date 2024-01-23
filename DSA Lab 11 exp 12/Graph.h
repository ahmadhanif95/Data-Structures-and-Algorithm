#ifndef GRAPH_H
#define GRAPH_H
#include <queue>
#include <iostream>
using namespace std;

class Graph
{
public:
	//part1: constructor initializes adjacency matrix
	Graph(int numVertex)
	{
		numVertices = numVertex;
		adj_matrix = new int * [numVertex];
		for (int i = 0; i < numVertex; i++)
		{
			adj_matrix[i] = new int[numVertex];
		}
		for (int i = 0; i < numVertices; i++)
		{
			for (int j = 0; j < numVertices; j++)
			{
				adj_matrix[i][j] = 0;
			}
		}
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
		for (int i = 0; i < numVertices; i++)
		{
			for (int j = 0; j < numVertices; j++)
			{
				if (adj_matrix[i][j] == 1)
				{
					count++;
				}
			}
		}
		count = count / 2;
		return count;
	}
	//part4: inserts edge going from one vertex to another
	void inserEdge(int frmVertex, int toVertex)
	{
		adj_matrix[frmVertex][toVertex] = 1;
		adj_matrix[toVertex][frmVertex] = 1;

	}
	//part5: removes edge going from one vertex to another
	void removeEdge(int frmVertex, int toVertex)
	{
		adj_matrix[frmVertex][toVertex] = 0;
		adj_matrix[toVertex][frmVertex] = 0;
	}
	//part6: returns the degree of the node passed
	int degree(int vertex)
	{
		int count=0;
		for (int i = 0; i < numVertices; i++)
		{
			if (adj_matrix[vertex][i] == 1)
			{
				count++;
			}
		}
		return count;
	}
	//part7: outputs the order in which vertices are visited during DFS
	//Starting from node s.
	void depthfirstSearch(int s)
	{
		int j;
		cout<<s<<"\t";
		explored[s] = 1;

		for (j = 0; j < numVertices; j++)
		{
			if (!explored[j] && adj_matrix[s][j] == 1)
			{
				depthfirstSearch(j);
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
			for (int i = 0; i < numVertices; ++i) 
			{
				if (adj_matrix[top][i] != 0 && (!exploredbfs[i]))
				{
					q.push(i);
					exploredbfs[i] = 1;
				}
			}
		}
		
	}
	void print()
	{
		cout << "\nThe Adjacency Matrix is: \n";
		for (int i = 0; i < numVertices; i++)
		{
			for (int j = 0; j < numVertices; j++)
			{
				cout << adj_matrix[i][j] << "\t";
			}
			cout << endl;
		}
	}
private:
	int** adj_matrix;
	int* explored;
	int* exploredbfs;
	int numVertices;
	
};
#endif
