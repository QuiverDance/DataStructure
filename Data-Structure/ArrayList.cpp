#include "ArrayList.h"
#include <iostream>

ArrayList::ArrayList(int maxElementCount)
{
	if (maxElementCount > 0)
	{
		this->maxElementCount = maxElementCount;
		pElement = new ArrayListNode[maxElementCount];
		this->currentElementCount = 0;
	}
	else
	{
		std::cout << "Error: �ִ���Ұ����� 0���� Ŀ���մϴ�." << std::endl;
		return;
	}
}

void ArrayList::deleteList()
{
	delete pElement;
}

bool ArrayList::isFull()
{
	if (currentElementCount == maxElementCount)
		return true;
	else
		return false;
}

void ArrayList::addElement(int positon, ArrayListNode element)
{
	if (pElement != NULL)
	{
		if (positon >= 0 && positon < maxElementCount)
		{
			if (!isFull())
			{
				for (int i = positon; i < currentElementCount; i++)
				{
					pElement[positon + 1] = pElement[positon];
				}
				pElement[positon] = element;
				currentElementCount++;
				std::cout << "���� �߰� ����." << std::endl;
				return;
			}
		}
	}
	std::cout << "Error: ���� �߰� ����." << std::endl;
}

void ArrayList::removeElement(int positon)
{
	if (pElement != NULL)
	{
		if (currentElementCount > 0)
		{
			if (positon >= 0 && positon < currentElementCount)
			{
				for (int i = positon; i < currentElementCount; i++)
				{
					pElement[positon] = pElement[positon+1];
				}

				ArrayListNode Null;
				Null.data = 0;

				pElement[positon] = Null;
				std::cout << "���� ���� ����." << std::endl;
				return;
			}
		}
	}
	std::cout << "Error: ���� ���� ����." << std::endl;
}

void ArrayList::clearList()
{
	ArrayListNode Null;
	Null.data = 0;

	for (int i = 0; i < currentElementCount; i++)
		pElement[i] = Null;
}

void ArrayList::displayList()
{
	for (int i = 0; i < currentElementCount; i++)
		std::cout << i << ": " << pElement[i].data << std::endl;
}

int ArrayList::getListLength()
{
	return currentElementCount;
}

ArrayListNode ArrayList::getElement(int positon)
{
	if (pElement != NULL)
	{
		if (positon >= 0 && positon < maxElementCount)
		{
			return pElement[positon];
		}
	}
}
