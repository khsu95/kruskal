#ifndef Min_HEAP_H
#define Min_HEAP_H

#include"main.h"/*EDGE Ÿ�� ����ü*/
#define Max_Heap_Size 15

extern int HEAP_INDEX;
extern EDGE HEAP[Max_Heap_Size];

EDGE pop(int* index);
int push(int* index, EDGE item);

#endif