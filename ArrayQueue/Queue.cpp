#include "Queue.h"

Queue::Queue()
{
	nMaxSize = DEFAULT_MAX + 1; //Memory is allocated for one more than the size of the desired array slots to make room
								//for the space that the nFront pointer will sit in.
	pItems = new ItemType[nMaxSize];
	nFront = nMaxSize - 1; 
	nRear = nMaxSize - 1;
}

Queue::Queue(int nMax)
{
	nMaxSize = nMax + 1;
	pItems = new ItemType[nMaxSize];
	nFront = nMaxSize - 1;
	nRear = nMaxSize - 1;
}

void Queue::MakeEmpty()
{
	nFront = nMaxSize - 1;
	nRear = nMaxSize - 1;
}

bool Queue::IsFull() const
{
	return ((nRear + 1) % nMaxSize == nFront);
}

bool Queue::IsEmpty() const
{
	return (nFront == nRear);
}

void Queue::Enqeue(ItemType iNewItem)
{
	if (IsFull() == true)
		throw FullQueue();
	else
	{
		nRear = (nRear + 1) % nMaxSize; //By moding with max size the array is circular if it reaches its max length.
		pItems[nRear] = iNewItem;
	}
}

void Queue::Deqeue(ItemType& iRemovedItem)
{
	if (IsEmpty() == true)
		throw EmptyQueue();
	else
	{
		nFront = (nFront + 1) % nMaxSize; //Advance front pointer.
		iRemovedItem = pItems[nFront]; //"deleted" item stored and front again pointing to the location just before the actual front item.
	}
}

Queue::~Queue()
{
	delete[] pItems; //Deallocate memory for dynamically allocated array.
}