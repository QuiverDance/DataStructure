#include "ChainingHashing.h"
#include <iostream>

int main(void)
{
	HashElement element1 = { "january", 1 };
	HashElement element2 = { "february", 2 };
	HashElement element3 = { "march", 3 };
	HashElement element4 = { "april", 4 };
	HashElement element5 = { "may", 5 };
	HashElement element6 = { "june", 6 };
	HashElement element7 = { "july", 7 };
	HashElement element8 = { "august", 8 };
	HashElement element9 = { "september", 9 };
	HashElement element10 = { "october", 10 };
	HashElement element11 = { "november", 11 };
	HashElement element12 = { "december", 12 };

	ChainingHashTable* pHashTable = new ChainingHashTable(13);
	if (!pHashTable)
		return 0;

	pHashTable->addElement(element1);
	pHashTable->addElement(element2);
	pHashTable->addElement(element3);
	pHashTable->addElement(element4);
	pHashTable->addElement(element5);
	pHashTable->addElement(element6);
	pHashTable->addElement(element7);
	pHashTable->addElement(element8);
	pHashTable->addElement(element9);
	pHashTable->addElement(element10);
	pHashTable->addElement(element11);
	pHashTable->addElement(element12);

	pHashTable->displayHashTable();
	HashElement* pElement = pHashTable->search(element4.key);
	std::cout << "검색결과: " << pElement->key << ", " << pElement->value << std::endl;
	pHashTable->deleteElement(element4.key);
	HashElement* pElement2 = pHashTable->search(element4.key);
	pElement = pHashTable->search(element12.key);
	if (pElement)
		std::cout << "검색결과: " << pElement->key << ", " << pElement->value << std::endl;

	pHashTable->displayHashTable();

	delete pHashTable;
}