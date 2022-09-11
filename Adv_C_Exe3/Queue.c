#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/***************** Queue ADT Implementation *****************/
static unsigned int calcAvg(Queue* q);
static unsigned int getQueueLen(Queue* q);
static void sortEnqueue(Queue* q, unsigned int u32Data);

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	if (q == NULL)
	{
		printf("ERROR: Queue manage struct are not defined\n");
		return;
	}
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	unsigned int u32Junk = 0;
	if (q == NULL)
	{
		printf("ERROR: Queue manage struct are not defined\n");
		return;
	}
	while (q->head != NULL)
	{
		u32Junk = dequeue(q);
	}
}

void enqueue(Queue* q, unsigned int data)
{
	if (q == NULL)
	{
		printf("ERROR: Queue manage struct are not defined\n");
		return;
	}
	intNode* pNewNode = malloc(sizeof(intNode));
	if (pNewNode == NULL)
	{
		printf("ERROR: Allocation failed\n");
		return;
	}

	pNewNode->data = data;
	pNewNode->next = NULL;

	//Queue is empty
	if (isEmptyQueue(q))
	{
		q->head = q->tail = pNewNode;
	}
	else
	{
		q->tail->next = pNewNode;
		q->tail = pNewNode;
	}
}

unsigned int dequeue(Queue* q)
{
	if (q == NULL)
	{
		printf("ERROR: Queue manage struct are not defined\n");
		return 0;
	}
	intNode* pNewHead = NULL;
	unsigned int u32RetData = 0;
	//If queue is not empty
	if (!isEmptyQueue(q))
	{
		pNewHead = q->head->next;
		u32RetData = q->head->data;
		free(q->head);

		//If it was last node - upd tail
		if (pNewHead == NULL)
		{
			q->head = q->tail = NULL;
		}
		else
		{
			q->head = pNewHead;
		}
	}
	return u32RetData;
}

int isEmptyQueue(const Queue* q)
{
	if (q == NULL)
	{
		printf("ERROR: Queue manage struct are not defined\n");
		return 1;
	}
	return (q->head == NULL) ? 1 : 0;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	intNode *pTmp = NULL;
	if (q == NULL)
	{
		printf("ERROR: Queue manage struct are not defined\n");
		return;
	}
	//If queue is empty
	if (isEmptyQueue(q))
	{
		printf("Empty queue\n");
		return;
	}
	//If queue contatins only one node
	if (q->head == q->tail)
	{
		return;
	}

	//Find one node before tail
	pTmp = q->head;
	while (pTmp->next != q->tail) { pTmp = pTmp->next; }
	pTmp->next->next = q->head;
	q->head = pTmp->next;
	pTmp->next = NULL;
	q->tail = pTmp;
}

void cutAndReplace(Queue* q)
{
	unsigned int u32QueueLen = 0, u32StepCnt = 0;
	intNode* pTmp = NULL, *pTmp1 = NULL;
	if (q == NULL)
	{
		printf("ERROR: Queue manage struct are not defined\n");
		return;
	}
	//If queue is empty
	if (isEmptyQueue(q))
	{
		printf("Empty queue\n");
		return;
	}

	//If queue contatins not-even node count
	u32QueueLen = getQueueLen(q);
	if (u32QueueLen % 2)
	{
		enqueue(q, calcAvg(q));
		u32QueueLen++;
	}

	u32QueueLen /= 2;//get count of steps until we arived to he midle of list

	//"Walk" in list until middle
	pTmp = q->head;
	while (u32StepCnt < (u32QueueLen - 1)) { u32StepCnt++; pTmp = pTmp->next; }
	//Set new tail
	q->tail = pTmp;
	pTmp = pTmp->next;
	q->tail->next = NULL;
	//Reorder list
	while (pTmp != NULL)
	{
		pTmp1 = pTmp->next;
		pTmp->next = q->head;
		q->head = pTmp;
		pTmp = pTmp1;
	}
}

void sortKidsFirst(Queue* q)
{
	if (q == NULL)
	{
		printf("ERROR: Queue manage struct are not defined\n");
		return;
	}
	unsigned int u32Q_Len = getQueueLen(q);
	Queue sTmpQ;
	initQueue(&sTmpQ);

	for (unsigned int u32Index = 0; u32Index < u32Q_Len; u32Index++)
	{
		sortEnqueue(&sTmpQ, dequeue(q));
	}
	q->head = sTmpQ.head;
	q->tail = sTmpQ.tail;
}

void printQueue(Queue* q)
{
	if (q == NULL)
	{
		printf("ERROR: Queue manage struct are not defined\n");
		return;
	}
	intNode* pTmp = q->head;
	if (pTmp == NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("Current data in queue is:\n");
	}
	while (pTmp != NULL)
	{
		printf(" %d\n", pTmp->data);
		pTmp = pTmp->next;
	}
}

static unsigned int calcAvg(Queue* q)
{
	unsigned int u32Sum = 0, u32Cnt = 0;
	intNode* pTmp = q->head;
	while (pTmp != NULL)
	{
		u32Sum += pTmp->data;
		u32Cnt++;
		pTmp = pTmp->next;
	}

	if (u32Cnt != 0)
	{
		return (u32Sum / u32Cnt);
	}
	else
	{
		return 0;
	}
}

static unsigned int getQueueLen(Queue* q)
{
	unsigned int u32Cnt = 0;
	intNode* pTmp = q->head;
	while (pTmp != NULL)
	{
		u32Cnt++;
		pTmp = pTmp->next;
	}
	return u32Cnt;
}

static void sortEnqueue(Queue* q, unsigned int u32Data)
{
	intNode *pTmp, *pTmp1;
	intNode* pNewNode = malloc(sizeof(intNode));
	if (pNewNode == NULL)
	{
		printf("ERROR: Allocation failed\n");
		return;
	}

	pNewNode->data = u32Data;
	pNewNode->next = NULL;

	//Queue is empty
	if (isEmptyQueue(q))
	{
		q->head = q->tail = pNewNode;
	}
	else
	{
		//Insert before head
		if (q->head->data > u32Data)
		{
			pNewNode->next = q->head;
			q->head = pNewNode;
		}
		else
		{
			pTmp = q->head;
			while ((pTmp->next != NULL) && (pTmp->next->data < u32Data)) { pTmp = pTmp->next; }
			if (pTmp->next == NULL)
			{
				pTmp->next = pNewNode;
				q->tail = pNewNode;
			}
			else
			{
				pTmp1 = pTmp->next;
				pTmp->next = pNewNode;
				pNewNode->next = pTmp1;
			}
		}
	}
}