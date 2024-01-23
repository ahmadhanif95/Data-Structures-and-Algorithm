#include<iostream>
#include "MaxHeap.h"
using namespace std;
int main()
{
	MaxHeap<int>* mxHeap; //creating an object of MinHeap
	mxHeap = new MaxHeap<int>;
	int op, x, size;
	op =1;
	size = 0;
	cout << "\nWelcome to Lahore airport civil aviation landing system\n";
	
	while (op == 1)
	{
		cout << "\nEnter 1 if there is an aircraft in airspace requesting to land , OR 0 to exit and Print: ";
		cin >> op;
		if (op == 0)
		{
			break;
		}
		cout << "\nEnter the amount of fuel in the Aircraft: ";
		cin >> x;
		mxHeap->insert(x);
		size++;

	}
	mxHeap->HeapSort(mxHeap->arr, size);
	cout << "\nGrant Access to Aircraft in the following order: ";
	for (int i = 0; i < size; i++)
	{
		cout << "\nAircraft with "<< mxHeap->arr[i] <<" units of fuel";
	}
	
	return 0;
}