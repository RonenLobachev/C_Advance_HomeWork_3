#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
	if ((q->head == NULL) && (q->head == q->tail))
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
		return;
	}
	intNode* pNewHead = NULL;
	unsigned int u32RetData = 0;
	//If queue is not empty
	if (q->head != NULL)
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
	return (q->head == NULL) ? 1 : 0;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	// add your code here
}

void cutAndReplace(Queue* q)
{
	// add your code here
}

void sortKidsFirst(Queue* q)
{
	// add your code here
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