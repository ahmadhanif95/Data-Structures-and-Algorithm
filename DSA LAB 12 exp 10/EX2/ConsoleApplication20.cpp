#include<iostream>
#include<Windows.h>
#include "Hashtable.h"
using namespace std;
int main()
{
	int num_of_identifiers;
	cout << "Enter maximum number of keys that need to be stored in the hashtable:";
		cin >> num_of_identifiers;
	int size_hashtable;
	cout << "Enter size of hashtable needed to store these many identifiers (hint:use prime number): ";
	cin >> size_hashtable;
	//create a hashtable of this size
	Hashtable<int>* ht = new Hashtable<int>(size_hashtable);
	for (int i = 0; i < num_of_identifiers; i++)
	{
		int key = rand() % 1000;
		bool was_stored = ht->store(key);
		if (!was_stored)
		{
			cout << key << " could not be stored as it already exists or table is full" << endl;
		}
	}
	int find_key;
	cout << "Enter the key to search for " << endl;
	cin >> find_key;
	DWORD start, end;//measure time
	start = GetTickCount64();
	bool found = ht->search(find_key);
	ht->printdata();
	end = GetTickCount64();
	double cpu_time_used = end - start;
	if (found)
		cout << "\nit was found in " << cpu_time_used << " milliseconds" << endl;
	else
		cout << "\nnot found in " << cpu_time_used << " milliseconds" << endl;
	return 0;
}