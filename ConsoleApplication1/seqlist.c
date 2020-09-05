#include "seqlist.h"
#include <stdio.h>
#include <stdlib.h>



//创建顺序链表
p_SeqList seqlist_Create(int cap ) {
	p_SeqList pList = NULL;
	pList = (p_SeqList)malloc(sizeof(SeqList_t));
	if (pList == NULL) {
		printf("seqlistCreate err:malloc fail #1 ");
		return NULL;
	}

	pList->node = (unsigned int*)malloc(sizeof(unsigned int*) * cap);
	if (pList->node == NULL) {
		printf("seqlistCreate err:malloc fail #2 ");
		return NULL;
	}
	memset(pList, 0, sizeof(SeqList_t));
	pList->len = 0;
	pList->cap = cap;
	return pList;
}


void seqlist_Destroy(SeqList_t* list) {
	p_SeqList pList = NULL;
	if (list == NULL) {
		return;
	}
	pList = (p_SeqList)list;
	if (pList->node != NULL) {
		free(pList->node);
	}
	free(pList);
}


void seqlist_Clear(SeqList_t* list) {
	p_SeqList pList = NULL;
	if (list == NULL) {
		return;
	}
	pList = (p_SeqList)list;
	pList->len = 0;
}

int seqlist_len(SeqList_t* list) {
	p_SeqList pList = NULL;
	if (list == NULL) {
		return 0;
	}
	pList = (p_SeqList)list;
	return pList->len;
}

int seqlist_cap(SeqList_t* list) {
	p_SeqList pList = NULL;
	if (list == NULL) {
		return 0;
	}
	pList = (p_SeqList)list;
	return pList->cap;
}

int seqlist_insert(SeqList_t* list, seqNode* node,int iPos,int iLen) {
	p_SeqList pList = NULL;
	int offset = iPos + iLen;
	if (list == NULL|| node==NULL) {
		return FALSE;
	}
	pList = (p_SeqList)list;
	
	if ((offset > pList->len)||pList->len==pList->cap){
		return FALSE;
	}

	
	for (int i = pList->len; i > offset; i--) {
		pList->node[i] = pList->node[i-1];
	}

	memcpy(&pList->node[iPos], node, iLen);
	return TRUE;
}



void seqlist_print(SeqList_t* L) {
	
	if (L == NULL) {
		return;
	}
	int i = 0;
	while (i<L->len&&L->node[i]!=NULL)
	{
		printf("%d \n", L->node[i]);
		i++;
	}

	printf("表长度：%d\n", L->len);
	printf("=======================\n");
}

















