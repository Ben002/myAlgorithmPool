#pragma once

typedef unsigned int seqNode;
#define TRUE   1
#define FALSE  0
#define MAXSIZE 5
typedef struct 
{
	int len;//���� 
	int cap;//����
	seqNode* node;//�б�ָ��
}SeqList_t,*p_SeqList;


void seqlist_print(SeqList_t* L);
int seqlist_insert(SeqList_t* list, seqNode* node, int iPos, int iLen);
p_SeqList seqlist_Create(int cap);
void seqlist_Destroy(SeqList_t* list);








