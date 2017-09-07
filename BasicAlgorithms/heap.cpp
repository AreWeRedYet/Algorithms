#include <iostream>
#include <vector>

using namespace std;

class Heap
{
public:
	vector<int> heapArray;
	
	Heap(vector<int> a)
	{
		for (int i = 0; i < a.size(); i++)
		{
			insertKey(a[i]);
		}
	}

	int extractMax()
	{
		int max = heapArray[0];

		swap(&heapArray[0], &heapArray[heapArray.size() - 1]);
		heapArray.pop_back();

		int i = 0;
		heapify(i);

		return max;
	}

	void increaseKey(int i, int new_val)
	{
		heapArray[i] = new_val;

		while (i > 0 && heapArray[i] > heapArray[parent(i)])
		{
			swap(&heapArray[i], &heapArray[parent(i)]);
			i = parent(i);
		}       
	}

	void deleteKey(int i)
	{
		swap(&heapArray[i], &heapArray[heapArray.size() - 1]);
		heapArray.pop_back();

		heapify(i);
	}

	void insertKey(int k)
	{
		heapArray.push_back(k);
		int lastElementIndex = heapArray.size() - 1;

		while (lastElementIndex > 0 && heapArray[lastElementIndex] > heapArray[parent(lastElementIndex)])
		{
			swap(&heapArray[lastElementIndex], &heapArray[parent(lastElementIndex)]);
			lastElementIndex = parent(lastElementIndex);
		}
	}

private:

	void swap(int *a, int *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}

	void heapify(int i)
	{
		bool canSwap = true;
		while (canSwap)
		{
			int indexToSwapWith = i;

			if (left(i) < heapArray.size() && heapArray[left(i)] > heapArray[indexToSwapWith])
			{
				indexToSwapWith = left(i);
			}

			if (right(i) < heapArray.size() && heapArray[right(i)] > heapArray[indexToSwapWith])
			{
				indexToSwapWith = right(i);
			}

			if (indexToSwapWith != i)
			{
				swap(&heapArray[i], &heapArray[indexToSwapWith]);
				i = indexToSwapWith;
			}
			else
			{
				canSwap = false;
			}
		}
	}

	int parent(int i) 
	{
		return (i - 1) / 2;
	}

	int left (int i)
	{
		return 2*i + 1;
	}

	int right (int i)
	{
		return 2*i + 2;
	}
};

int main()
{
	int n;
	cin >> n;
	
	vector<int> numbers(n);
	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	Heap heap(numbers);

	cout << heap.extractMax() << endl;

	cout << heap.extractMax() << endl;
	cout << heap.extractMax() << endl;

}