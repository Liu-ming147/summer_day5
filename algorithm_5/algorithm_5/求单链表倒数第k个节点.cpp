#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
}ListNode;

ListNode * reverseList(ListNode * L)
{
	ListNode * pp = L;
	ListNode * p = L->m_pNext;
	pp->m_pNext = NULL;
	while (p != NULL)
	{
		ListNode * p3 = p->m_pNext;
		p->m_pNext = pp;
		pp = p;
		p = p3;
	}

	return pp;
}

ListNode * getKthNodeFromBack(ListNode * L, int k)
{
	if (k == 0)
		return NULL;
	ListNode * rL = reverseList(L);
	ListNode * p = rL;
	for (int i = 0; p != NULL && i < k - 1; i++) //注意检测k不能超过链表长度，否则返回NULL
	{
		p = p->m_pNext;
	}
	reverseList(rL);
	return p;
}

void displayList(ListNode * L)
{
	ListNode * p = L;
	while (p != NULL)
	{
		printf("%d ", p->m_nKey);
		p = p->m_pNext;
	}
	printf("\n");
}

void createList(ListNode * &L)
{
	int d;
	scanf("%d", &d);
	if (d != 0)
	{
		L = (ListNode *)malloc(sizeof(ListNode));
		L->m_nKey = d;
		L->m_pNext = NULL;
		createList(L->m_pNext);
	}
}

int main()
{
	ListNode * L = NULL;
	createList(L);
	ListNode * pk = getKthNodeFromBack(L, 3);
	displayList(L);

	return 0;
}