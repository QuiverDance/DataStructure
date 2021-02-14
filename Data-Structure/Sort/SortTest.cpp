#include "Sort.h"
#include <iostream>

int main(void)
{
	int value[] = { 8, 5, 7, 1, 6, 2, 4, 3 };
	
	std::cout << "Before Sort: " << std::endl;
	printArray(value, 8);
	std::cout << std::endl;

	insertionSort(value, 8);
	std::cout << std::endl << "After Sort: " << std::endl;
	printArray(value, 8);
}