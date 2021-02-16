#include "Sort.h"
#include <iostream>

void printArray(int value[], int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << value[i] << " ";
	}
	std::cout << std::endl;
}

void selectionSort(int value[], int count)
{
	int min = 0;
	for (int i = 0; i < count - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < count; j++)
		{
			if (value[min] > value[j])
				min = j;
		}
		int temp = value[i];
		value[i] = value[min];
		value[min] = temp;
	}
	printArray(value, 8);
}

void bubbleSort(int value[], int count)
{
	for (int i = count - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (value[j] > value[j + 1])
			{
				int temp = value[j];
				value[j] = value[j + 1];
				value[j + 1] = temp;
			}
		}
		printArray(value, 8);
	}
}

int partitionQuickSort(int value[], int start, int end)
{
	int pivot = end;
	int left = start;
	int right = end;
	int temp = 0;

	while (left < right)
	{
		while ((value[left] < value[pivot]) && (left < right))
			left++;
		while ((value[right] >= value[pivot]) && (left < right))
			right--;

		if (left < right)
		{
			temp = value[left];
			value[left] = value[right];
			value[right] = temp;

			printArray(value, end - start + 1);
		}
	}
	temp = value[pivot];
	value[pivot] = value[right];
	value[right] = temp;

	printArray(value, end - start + 1);
	return right;
	
}

void quickSort(int value[], int start, int end)
{
	int pivot = 0;
	if (start < end)
	{
		pivot = partitionQuickSort(value, start, end);
		quickSort(value, start, pivot - 1);
		quickSort(value, pivot + 1, end);
	}
}

void insertionSort(int value[], int count)
{
	int temp = 0;
	for (int i = 1; i < count; i++)
	{
		temp = value[i];
		int j = i;
		while ((j > 0) && value[j - 1] > temp)
		{
			value[j] = value[j - 1];
			value[j - 1] = temp;
			j--;

		}
		printArray(value, count);
	}
}

void shellInsertionSort(int value[], int start, int end, int interval)
{
	int item = 0, index = 0;
	for (int i = start + interval; i <= end; i += interval)
	{
		item = value[i];
		index = i - interval;
		while ((index >= start) && item < value[index])
		{
			value[index + interval] = value[index];
			index = index - interval;
		}
		value[index + interval] = item;
	}
}

void shellShort(int value[], int count)
{
	int interval = count / 2;
	while (interval >= 1)
	{
		for (int i = 0; i < interval; i++)
			shellInsertionSort(value, i, count - 1, interval);

		printArray(value, count);
		interval /= 2;
	}
}

void mergeSortInternal(int value[], int buffer[], int start, int middle, int end)
{
	int i = start;
	int j = middle + 1;
	int k = start;
	while (i <= middle && j <= end)
	{
		if (value[i] <= value[j])
		{
			buffer[k] = value[i];
			i++;
		}
		else
		{
			buffer[k] = value[j];
			j++;
		}
		k++;
	}
	if (i > middle)
	{
		for (int t = j; t <= end; t++, k++)
			buffer[k] = value[t];
	}
	else
	{
		for (int t = i; t <= middle; t++, k++)
			buffer[k] = value[t];
	}

	for (int t = start; t <= end; t++)
		value[t] = buffer[t];
}

void mergeSort(int value[], int buffer[], int start, int end)
{
	int middle = 0;
	if (start < end)
	{
		middle = (start + end) / 2;

		mergeSort(value, buffer, start, middle);
		mergeSort(value, buffer, middle + 1, end);

		mergeSortInternal(value, buffer, start, middle, end);
	}
}

void radixSort(int value[], int count, int radix, int digit)
{
	SortQueue** ppQueue = nullptr;
	int factor = 1;
	ppQueue = new SortQueue*[radix];
	if (!ppQueue)
		return;

	for (int bucket = 0; bucket < radix; bucket++)
	{
		ppQueue[bucket] = new SortQueue();
		if (!ppQueue[bucket])
		{
			for (int i = 0; i < bucket - 1; i++)
				ppQueue[i]->deleteQueue();
			delete []ppQueue;
			return;
		}
	}

	QueueNode node = { 0, };
	for (int d = 0; d < digit; d++)
	{
		for (int i = 0; i < count; i++)
		{
			node.data = value[i];
			ppQueue[(value[i] / factor) % radix]->enqueue(node);
		}
		int i = 0;
		for (int bucket = 0; bucket < radix; bucket++)
		{
			while (ppQueue[bucket]->isEmpty() == false)
			{
				QueueNode* pNode = ppQueue[bucket]->dequeue();
				if (pNode)
				{
					value[i] = pNode->data;
					i++;
					delete pNode;
				}
			}
		}
		factor *= radix;
		printArray(value, count);
	}

	for (int bucket = 0; bucket < radix; bucket++)
		ppQueue[bucket]->deleteQueue();
	delete[] ppQueue;
}

void heapSort(int value[], int count)
{
	ArrayHeap* pHeap = new ArrayHeap(count);
	if (!pHeap)
		return;
	HeapNode node = { 0, };
	for (int i = 0; i < count; i++)
	{
		node.key = value[i];
		pHeap->intsetMinHeap(node);
	}
	for (int i = 0; i < count; i++)
	{
		HeapNode* pNode = pHeap->deleteMinElement();
		if (pNode)
		{
			value[i] = pNode->key;
			delete pNode;
		}
	}
	pHeap->deleteHeap();
}
