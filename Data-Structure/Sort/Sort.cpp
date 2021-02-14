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
