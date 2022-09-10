#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Add value to the head of linked list
charNode* addToHead(charNode* head, charNode* toAdd);

////removeItem function
void removeItem(charNode** head);

//Print Stack values
void display(Stack* s);

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
}

void destroyStack(Stack* s)
{

	if (s == NULL)
	{
		return;
	}

	charNode* nodeTemp = s->head;
	charNode* next;

	while (nodeTemp)
	{
		next = nodeTemp->next;
		free(nodeTemp);
		nodeTemp = next;
	}
	s->head = NULL;
}

void push(Stack* s, char data)
{
	charNode* newNode = (charNode*)malloc(sizeof(charNode));

	if (newNode == NULL)
	{
		printf("memory allocation problem \n");
		return;
	}

	newNode->data = data;
	s->head = addToHead(s->head, newNode);

}

char pop(Stack* s)
{
	char ch = NULL;

	ch = s->head->data;
	removeItem(&(s->head));

	return (ch);
}


int isEmptyStack(const Stack* s)
{
	if (s->head == NULL)
	{
		return 1;
	}

	return 0;
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{

	int arrIndex = 0;
	int revindex = 0;
	int countMark = 0;
	char findMark = '#';
	char tmp = NULL;



	//Empty char array return false;
	if (sentence == NULL)
	{
		printf("Empty sentence!!");
		return 0;
	}


	for (arrIndex; arrIndex < strlen(sentence); arrIndex++)
	{

		if (sentence[arrIndex] == findMark)
		{
			Stack newStack;//create ptrStack in case symbol was found
			initStack(&newStack);// init stack


			revindex = ++arrIndex;

			while (sentence[revindex] != findMark && revindex < strlen(sentence))
			{
				push(&newStack, sentence[revindex]);
				revindex++;

			}

			//print stack
			display(&newStack);

			//if second symbol found increse index
			if (sentence[revindex] == findMark)
				revindex++;


			arrIndex = revindex;

			//delete stack
			destroyStack(&newStack);
		}

		printf("%c", sentence[arrIndex]);
	}

}

int isPalindrome(Stack* s)
{
	int size = 0;
	char ch = NULL;
	charNode* tmp;

	tmp = s->head;

	Stack* ptrStack = (Stack*)malloc(sizeof(Stack));
	if (ptrStack == NULL)
	{
		printf("Allocation memory fail");
		exit(0);
	}
	initStack(ptrStack);

	Stack* ptrStack2 = (Stack*)malloc(sizeof(Stack));
	if (ptrStack2 == NULL)
	{
		printf("Allocation memory fail");
		exit(0);
	}
	initStack(ptrStack2);


	if (isEmptyStack(s))
	{
		return 1;
	}

	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}


	for (int polIndex = 0; polIndex < size; polIndex++)
	{
		ch = pop(s);
		push(ptrStack, ch);
		push(ptrStack2, ch);
	}

	for (int polIndex = 0; polIndex < size; polIndex++)
	{
		ch = pop(ptrStack2);
		push(s, ch);
	}

	for (int polIndex = 0; polIndex < (size / 2); polIndex++)
	{

		if (pop(s) != (pop(ptrStack)))
		{
			return 0;
		}
	}

	destroyStack(ptrStack);
	destroyStack(ptrStack2);

	return 1;

}

void rotateStack(Stack* s, int n)
{
	char ch = NULL;

	if (n < 0)
	{
		return 0;
	}

	if (isEmptyStack(s))
	{

		printf("Empty Stack!!!");
		return;
	}

	charNode* tmp;
	tmp = s->head;
	int stackSize = 0;

	while (tmp != NULL)
	{
		stackSize++;
		tmp = tmp->next;
	}

	//check if the  input size bigger then the stack size 
	if (n > stackSize)
	{
		printf(" Size (%d)  bigger than the stack size (%d):\n ", n, stackSize);
		printf("Stack values: ");
		display(s);
		return 0;
	}



	Stack* ptrStack = (Stack*)malloc(sizeof(Stack));
	if (ptrStack == NULL)
	{
		printf("Allocation memory fail");
		exit(0);
	}

	initStack(ptrStack);

	//order the stack values when the size equal to the stack size
	if (n == stackSize)
	{

		//pop ( size ) elements from the stack and push to new stack
		for (int stackIndex = 0; stackIndex < n; stackIndex++)
		{
			ch = pop(s);
			push(ptrStack, ch);
		}


		printf("Stack values: ");
		display(ptrStack);
		destroyStack(ptrStack);
		return 0;


	}

	Stack* ptr2Stack = (Stack*)malloc(sizeof(Stack));
	if (ptr2Stack == NULL)
	{
		printf("Allocation memory fail");
		exit(0);
	}

	initStack(ptr2Stack);

	Stack* ptr3Stack = (Stack*)malloc(sizeof(Stack));
	if (ptr3Stack == NULL)
	{
		printf("Allocation memory fail");
		exit(0);
	}

	initStack(ptr3Stack);


	//pop ( size ) elements from the stack and push to new stack
	for (int stackIndex = 0; stackIndex < n; stackIndex++)
	{
		ch = pop(s);
		push(ptrStack, ch);

	}



	for (int stackIndex = 0; stackIndex < n; stackIndex++)
	{
		ch = pop(ptrStack);
		push(ptr3Stack, ch);
	}



	//pop all elements that are stay in  first stack to new stack
	for (int stackIndex = 0; stackIndex < stackSize - n; stackIndex++)
	{
		ch = pop(s);
		push(ptr2Stack, ch);
	}


	for (int stackIndex = 0; stackIndex < stackSize - n; stackIndex++)
	{
		ch = pop(ptr2Stack);
		push(ptr3Stack, ch);
	}


	//print stack after rotation
	printf("After Rotation: ");
	display(ptr3Stack);


	//free memory allocation
	destroyStack(ptrStack);
	destroyStack(ptr2Stack);
	destroyStack(ptr3Stack);
}


charNode* addToHead(charNode* head, charNode* toAdd)
{

	toAdd->next = head;
	head = toAdd;
	return head;

}

void removeItem(charNode** head)
{
	charNode* tmp = *head;
	*head = (*head)->next;
	free(tmp);

}


void display(Stack* s)
{

	charNode* tmp;

	tmp = s->head;

	while (tmp != NULL)
	{
		printf("%c", tmp->data);

		tmp = tmp->next;
	}

}