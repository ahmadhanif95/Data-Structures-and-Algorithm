#ifndef HSH_H
#define HSH_H
#include<list>
using namespace std;
template<class DT>
class Hashtable
{
public:
	Hashtable(int sizehash)
	{
		size = sizehash;
		arr = new list <int>[size];
	}
	bool store(DT key)
	{
		int hash;
		hash = key % size;
		arr[hash].push_back(key);

		return true;
	}
	bool search(DT key)
	{
		int location = key % size;
		list<int> ::iterator it;
		for (it = arr[location].begin(); it != arr[location].end(); it++)
		{
			int x = *it;
			if (x == key)
			{
				cout << "Found in the Chain at index [" << location << "] ";
				return true;
			}
		}
		return false;
	}
	void Delete(DT key)
	{
		int location = key % size;
		arr[location].remove(key);
	}
	void printdata()
	{
		cout << "\nThe Hashtable is: \n\n";
		for (int i = 0; i < size; i++)
		{
			if (!arr[i].empty())
			{
				cout << "\n[" << i << "] ";
				list<int> ::iterator it;
				for (it = arr[i].begin(); it != arr[i].end(); it++)
				{
					cout << "-->" << *it;
				}
			}
		}
	}
private:
	int size;
	list<int>* arr;
};
#endif
