#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"main.h"
#include"Min_Heap.h"
#include"set.h"

EDGE MST[MAX_VERTICAL] = { 0 };

int main()
{
	EDGE temp;
	ROOT V_R, W_R;
	FILE* inout;
	int selected_edge = 0, num_edge = 0;
	int ret;
	char big = 0;
	
	inout = fopen("in.txt", "rt");
	
	while (1)
	{
		printf("Edge: ");
		ret = fscanf(inout, "%c %c %d", &temp.v, &temp.v, &temp.key);
		if (ret == EOF)		break; /*파일의 끝에 도착하면 EOF*/
		printf("\n");
		if (!('A' <= temp.v <= 'Z') || !('A' <= temp.w <= 'Z') || temp.key < 0) {
			printf("Wrong Input===========Node is Alphabet, Weight isn't minus \n");
			break;
		}
		push(&HEAP_INDEX, temp);/*간선과 노드 추가*/
		getchar();/*버퍼에 남은 데이터 초기화*/
		if (temp.v > big || temp.w > big)
		{
			if (temp.v > temp.w)	big = temp.v;
			else big = temp.w;
		}
	} //INPUT
	fclose(inout);

	for (int i = 0; i <= big - 64; i++)/*정점의 개수만큼 Set을 만든다.*/
		set[i] = 64 + i;

	num_edge = HEAP_INDEX;
	selected_edge = 1;

	while (selected_edge < num_edge)
	{
		if (num_edge == -1)
		{
			printf("EMPTY TREE \n");
			break;
		}

		temp = pop(&HEAP_INDEX);/*정렬된 MinHeap에서 최소 간선 꺼냄*/


		V_R = Find(temp.v);/*v정점의 집합을 찾음*/
		W_R = Find(temp.w);/*w정점의 집합을 찾음*/

		if (V_R.vertical != W_R.vertical)/*동성동본이 아니라면*/
		{
			Union(V_R, W_R);/*백년가약*/
			MST[selected_edge] = temp;/*선택 받은 i번째 간선*/
			selected_edge++;
		}
	}

	if (selected_edge != num_edge - 1){
		printf("No spaaning Tree \n");
		return 0;
	}
	inout = fopen("in.txt", "wt");/*바이너리 형식으로 저장할 것임*/
	for (int i = 1; i <= selected_edge; i++)
		//fread((void*)MST, sizeof(*MST), 1, inout);
		fprintf(inout,"%c---%c = %d\n", MST[i].v, MST[i].w, MST[i].key);
	fputs("End of Programm \n",inout);
	
	fclose(inout);
	return 0;
}