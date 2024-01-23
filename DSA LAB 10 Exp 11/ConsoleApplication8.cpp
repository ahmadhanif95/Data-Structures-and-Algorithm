#include<iostream>
#include "MinHeap.h"
using namespace std;
int main()
{
	MinHeap<int>* mnHeap; //creating an object of MinHeap
	mnHeap = new MinHeap<int>;
	//insert following data in the MinHeap
	mnHeap->insert(12);
	mnHeap->insert(43);
	mnHeap->insert(9);
	mnHeap->insert(2);
	mnHeap->insert(14);
	mnHeap->insert(16);
	mnHeap->insert(13);
	mnHeap->insert(12);
	mnHeap->printContents();
	//Carry out 2 deletions from the MinHeap
	int output;
	output = mnHeap->Delete();
	cout << "Output of first deletion is " << output << endl;
	mnHeap->printContents();
	output = mnHeap->Delete();
	cout << "Output of second deletion is " << output << endl;
	mnHeap->printContents();
	return 0;
}