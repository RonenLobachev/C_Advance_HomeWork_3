#pragma once

//*************STRUCTS**********************
typedef struct {
	void* pHead;
	void* pTail;
	unsigned int u32NodeSize;
}ADT_BaseList;

//***********DECLARATIONS******************
/* 
	Description:
				Function for initilaze linked list
	Parameters:  
				ADT_BaseList** pBaseList - p-to-p struct of base list(head,tail,node size)
	Return value:
				void - none
	*/
void init_list(ADT_BaseList** pBaseList);

/*
	Description:
				Function for add data to head
	Parameters:
				ADT_BaseList** pBaseList - p-to-p struct of base list(head,tail,node size)
				void* pData - data to add
	Return value:
				void - none
	*/
void push_to_head(ADT_BaseList* pBaseList, void* pData);

/*
	Description:
				Function for add data to tail
	Parameters:
				ADT_BaseList** pBaseList - p-to-p struct of base list(head,tail,node size)
				void* pData - data to add
	Return value:
				void - none
	*/
void push_to_tail(ADT_BaseList* pBaseList, void* pData);

/*
	Description:
				Function for get data from head
	Parameters:
				ADT_BaseList** pBaseList - p-to-p struct of base list(head,tail,node size)
	Return value:
				void* - address to poped node
	*/
void* pop_from_head(ADT_BaseList* pBaseList);

/*
	Description:
				Function for get data from tail
	Parameters:
				ADT_BaseList** pBaseList - p-to-p struct of base list(head,tail,node size)
	Return value:
				void* - address to poped node
	*/
void* pop_from_tail(ADT_BaseList* pBaseList);

/*
	Description:
				Function for get list lenght
	Parameters:
				ADT_BaseList** pBaseList - p-to-p struct of base list(head,tail,node size)
	Return value:
				int - length of list
	*/
int get_list_len(ADT_BaseList* pBaseList);