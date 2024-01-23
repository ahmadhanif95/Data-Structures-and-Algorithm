//#ifndef MAX_HEAP_H
//#define MAX_HEAP_H
//using namespace std;
//template<class DT>
//class MaxHeap
//{
//public:
//	//part1: constructor initializes array of size maxsize
//	MaxHeap()
//	{
//		size = 0;
//	}
//	//part2: Inserts data into its appropriate position
//	//within the Heap
//	bool insert(const DT data)
//	{
//		size++;
//		arr[size] = data;
//		int i = 0;
//		i = size;
//		int par = 0;
//		while (i > 1)
//		{
//			par = i / 2;
//
//			{
//				if (arr[par] < arr[i])
//				{
//					int x;
//					x = arr[par];
//					arr[par] = arr[i];
//					arr[i] = x;
//					i = par;
//				}
//				else
//				{
//					return true;
//				}
//			}
//		}
//		return true;
//	}
//	//part3: removes the element present in the the root
//	//of the Heap and readjusts it to form MaxHeap again
//	DT Delete()
//	{
//		int i = 1;
//		int x;
//		int del = 0;
//		del = arr[i];
//		x = arr[size];
//		arr[i]=x;
//		arr[size] = 0;
//		size--;
//		
//			
//			if (arr[i] < arr[2 * i] || arr[i] < arr[(2 * i) + 1])
//			{
//				if (arr[2 * i] > arr[(2 * i) + 1])
//				{
//					x = arr[2 * i];
//					arr[2 * i] = arr[i];
//					arr[i] = x;
//					i = 2 * i;
//				}
//				else if (arr[(2 * i) + 1] > arr[2 * i])
//				{
//					x = arr[(2 * i) + 1];
//					arr[(2 * i) + 1] = arr[i];
//					arr[i] = x;
//					i = (2 * i) + 1;
//				}
//			}
//		
//		
//		return del;
//		
//	}
//	//part4: prints all the data present in the Heap
//	//use the appropriate traversal
//	void printContents()
//	{
//		cout << "\n\nTHE HEAP IS: \t";
//		for (int i = 1; i <=size; i++)
//		{
//			cout << arr[i] << "\t";
//		}
//	}
//	//part5: destructor, deletes the MaxHeap
//	/*~MaxHeap()*/
//private:
//	int arr[40];
//	int size;
//
//};
//#endif