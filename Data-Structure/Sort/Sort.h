#pragma once
#include "SortQueue.h"
#include "SortHeap.h"

void printArray(int value[], int count);

void selectionSort(int value[], int count);
void bubbleSort(int value[], int count);

int partitionQuickSort(int value[], int start, int end);
void quickSort(int value[], int start, int end);

void insertionSort(int value[], int count);

void shellInsertionSort(int value[], int start, int end, int interval);
void shellShort(int value[], int count);

void mergeSortInternal(int value[], int buffer[], int start, int middle, int end);
void mergeSort(int value[], int buffer[], int start, int end);

void radixSort(int value[], int count, int radix, int digit);

void heapSort(int value[], int count);