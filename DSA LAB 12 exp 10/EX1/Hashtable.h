#ifndef HSH_H
#define HSH_H
using namespace std;
template<class DT>
class Hashtable
{
public:
	Hashtable(int sizehash)
	{
		size = sizehash;
		arr = new DT[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = -1;
		}
	}
	bool store(DT key)
	{
		int hash;
		hash = key % size;
		if (arr[hash] == -1)
		{
			arr[hash] = key;
			return true;
		}
		else if (arr[hash] != -1)
		{
			for (int i = hash+1; i < size; i++)
			{
				if (arr[i] == -1)
				{
					arr[i] = key;
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
	bool search(DT key)
	{
		bool success = true;
		int location = key % size;
		int j;
		for (j = location; arr[j] != key; )
		{
			j = (j + 1) % size;
			if (j == location || arr[j] == -1)
			{
				success = false;//doesn't exist
				break;
			}
		}
		if (success)
		{
			cout << "found at " << j << endl;
		}
		return success;

	}
private:
	int size;
	DT* arr;
};
#endif
