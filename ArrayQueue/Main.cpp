#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	Queue QueObj;
	ItemType iTempItem;
	cout << "Adding data to the queue.\n";
	for (int i = 0; i < 6; i++)
	{
		iTempItem.Set(i);
		try
		{
			QueObj.Enqeue(iTempItem);
			cout << i << " has been added to the queue.\n";
		} catch (FullQueue exception) {
			cerr << "Exception caught: The queue is currently full.\n";
		}
	}

	cout << "\nDequeuing data: \n";
	for (int i = 0; i < 6; i++)
	{
		try
		{
			QueObj.Deqeue(iTempItem);
			cout << iTempItem.Get() << " has been dequeued.\n";
		} catch (EmptyQueue exception) {
			cerr << "Exception caugth: The queue is empty.\n";
		}
	}




	return 0;
}