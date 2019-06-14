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
		if (ret == EOF)		break; /*������ ���� �����ϸ� EOF*/
		printf("\n");
		if (!('A' <= temp.v <= 'Z') || !('A' <= temp.w <= 'Z') || temp.key < 0) {
			printf("Wrong Input===========Node is Alphabet, Weight isn't minus \n");
			break;
		}
		push(&HEAP_INDEX, temp);/*������ ��� �߰�*/
		getchar();/*���ۿ� ���� ������ �ʱ�ȭ*/
		if (temp.v > big || temp.w > big)
		{
			if (temp.v > temp.w)	big = temp.v;
			else big = temp.w;
		}
	} //INPUT
	fclose(inout);

	for (int i = 0; i <= big - 64; i++)/*������ ������ŭ Set�� �����.*/
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

		temp = pop(&HEAP_INDEX);/*���ĵ� MinHeap���� �ּ� ���� ����*/


		V_R = Find(temp.v);/*v������ ������ ã��*/
		W_R = Find(temp.w);/*w������ ������ ã��*/

		if (V_R.vertical != W_R.vertical)/*���������� �ƴ϶��*/
		{
			Union(V_R, W_R);/*��Ⱑ��*/
			MST[selected_edge] = temp;/*���� ���� i��° ����*/
			selected_edge++;
		}
	}

	if (selected_edge != num_edge - 1){
		printf("No spaaning Tree \n");
		return 0;
	}
	inout = fopen("in.txt", "wt");/*���̳ʸ� �������� ������ ����*/
	for (int i = 1; i <= selected_edge; i++)
		//fread((void*)MST, sizeof(*MST), 1, inout);
		fprintf(inout,"%c---%c = %d\n", MST[i].v, MST[i].w, MST[i].key);
	fputs("End of Programm \n",inout);
	
	fclose(inout);
	return 0;
}