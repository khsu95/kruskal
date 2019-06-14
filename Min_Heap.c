#include<stdio.h>
#include"Min_Heap.h"

int HEAP_INDEX = 0;
EDGE HEAP[Max_Heap_Size] = { 0 };

EDGE pop(int* index)
{
	EDGE item, temp;
	int parent, child;
	if (*index < 1)
	{
		printf("Input Error too Big\n");
		temp.v = 0;
		return temp;
	}
	item = HEAP[1];
	temp = HEAP[(*index)--];
	parent = 1;	child = 2;
	while (child <= *index)
	{
		if ((child < *index) && HEAP[child].key > HEAP[child + 1].key)
			child++;
		if (temp.key <= HEAP[child].key)	break;
		HEAP[parent] = HEAP[child];
		parent = child;
		child *= 2;
	}
	HEAP[parent] = temp;
	printf("Pop Had Done\n");
	return item;
}

/* Insert x into Max heap*/

int push(int* index, EDGE item)
{
	int i;
	if (item.key < 0 || item.v < 0 || item.w < 0)	return 0;
	i = ++(*index);
	while ((i != 1) && (item.key < HEAP[i / 2].key))
	{
		HEAP[i] = HEAP[i / 2];
		i /= 2;
	}
	HEAP[i] = item;
	printf("Push Had Done\n");
	return 0;
}