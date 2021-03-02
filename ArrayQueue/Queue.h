#ifndef QUEUE_H
#define QUEUE_H
#define DEFAULT_MAX 5
#include "ItemType.h"

class FullQueue {};
class EmptyQueue {};

class Queue
{
private:
	int nMaxSize;
	ItemType* pItems;
	int nFront; //Points to location before front
	//Note that nFront never stores a value logically, it is just a marker.
	int nRear;

public:
	Queue();
	Queue(int nMax);
	void MakeEmpty();
	void Enqeue(ItemType iNewItem);
	void Deqeue(ItemType& iRemovedItem);
	bool IsFull() const;
	bool IsEmpty() const;
	~Queue();
};

#endif QUEUE_H