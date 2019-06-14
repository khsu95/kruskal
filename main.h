#include"set.h" /*ROOT 타입 구조체*/
#define MAX_VERTICAL 10000

#ifndef EDGE_H
#define EDGE_H
typedef struct EDGE
{
	char v, w;
	int key;
}EDGE;

extern EDGE MST[MAX_VERTICAL];

#endif

