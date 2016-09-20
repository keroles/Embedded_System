

#include"linkedList.h"

unsigned long nodesNum= 0;

/****************************************************************************
**  => FUNCTION FEATURES:												    *
** (1) this function adds one node at the end of the list.				    *
** (2) it returns true if it succeeded or zero if there is no heep size.	*
*****************************************************************************/
char addNode( struct Node **list, int data )
{
	char check= 0;
	struct Node *ptr= *list, *new_node= (struct Node*)malloc( sizeof(struct Node) );
	if( new_node )
	{
		check= 1;
		new_node->data= data;
		if(!*list)
		{
			new_node->next= *list;
			*list= new_node;
		}
		else
		{
			for( ; ptr->next != NULL ; ptr= ptr->next );
			new_node->next= ptr->next;
			ptr->next= new_node;
		}
		nodesNum++;
	}
    return check ;
}

/************************************************************************************************************************
**  => FUNCTION FEATURES:																								*
** (1) this function searches for a specific node and returns it's address, and also holds the previous node address.	*
** (2) if the node is the first one the returned address will be equal to the previous address.							*
** (3) if it did n't find the node, or the list was empty, then it returns NULL pointer.								*
** (4) if the list is empty then the returned pointer will be NULL as well as the held previous node pointer. 			*
** (5) if the list is not empty and the node is not found then the held previous node pointer will be the last node.	*
*************************************************************************************************************************/
struct Node* searchNode( struct Node *list, int data, struct Node **ptrPrevious )
{
	struct Node *ptr= *ptrPrevious= list;
	if(list && list->data != data )
	{
        for( ptr= ptr->next; ptr != NULL ; ptr= ptr->next, *ptrPrevious= (*ptrPrevious)->next )
            if(ptr->data == data)
                break;
	}
	return ptr ;
}


/********************************************************************************************************************************
**  => FUNCTION FEATURES:																										*
** (1) this function use the function "searchNode" to find the node then delete it.												*
** (2) it also returns status that has 4-probabilities of enum ( NODE_NOT_FIRST, NODE_FIRST_ONE, NODE_NOT_FOUND, LIST_EMPTY).	*
*********************************************************************************************************************************/
Status deleteNode( struct Node **list, int data )
{
	Status state= LIST_EMPTY;			// initial by list empty.
	struct Node *ptrInstant= *list, *ptrPrevious= NULL ;
    ptrInstant= searchNode(*list, data, &ptrPrevious);
	if( ptrInstant )
	{
		if( ptrPrevious == ptrInstant ) // node is the first one.
		{
		    *list= (*list)->next;
			state= NODE_FIRST_ONE;
		}
		else							// is not the first one.
		{
			ptrPrevious->next= ptrInstant->next;
			state= NODE_NOT_FIRST ;
		}
		free(ptrInstant);
		nodesNum--;
	}
	else if( ptrPrevious )				// is not found.
		state= NODE_NOT_FOUND ;
	return state ;
}


/********************************************************************************************************************************
**  => FUNCTION FEATURES:																										*
** (1) this function use the function "searchNode" to find the node then change it's data.										*
** (2) it also returns status that has 4-probabilities of enum ( NODE_NOT_FIRST, NODE_FIRST_ONE, NODE_NOT_FOUND, LIST_EMPTY).	*
*********************************************************************************************************************************/
Status changeNodeData( struct Node *list, int data, int newData )
{
	Status state= LIST_EMPTY;			// initial by list empty.
	struct Node *ptrInstant= list, *ptrPrevious= NULL ;
	ptrInstant= searchNode(list, data, &ptrPrevious);
	if( ptrInstant )
	{
		if( ptrPrevious == ptrInstant ) // node is the first one.
			state= NODE_FIRST_ONE;
		else							// is not the first one.
			state= NODE_NOT_FIRST ;
		ptrInstant->data= newData ;
	}
	else if( ptrPrevious )				// is not found.
		state= NODE_NOT_FOUND ;
	return state ;
}


/****************************************************************************
**  => FUNCTION FEATURES:													*
** (1) this function frees All nodes pointers from first one to last one.	*
*****************************************************************************/
char deleteAll( struct Node **list )
{
	char check= 0;
	struct Node *ptrInstant= *list, *ptrNext= *list ;
    check= 1;
    while(ptrInstant)
    {
        ptrNext= ptrNext->next;
        free(ptrInstant);
        nodesNum--;
        ptrInstant= ptrNext;
    }
    *list= NULL;
	return check;
}


/****************************************************************************
**  => FUNCTION FEATURES:													*
** (1) this function prints the desired node then returns true 				*
** (2) if it didn't find the node or the list is empty it returns false.	*
*****************************************************************************/
char viewNode( struct Node *list, int data )
{
	char check= 0;
	struct Node *ptrInstant= list, *ptrPrevious= NULL ;
	ptrInstant= searchNode(list, data, ptrPrevious);
	if( ptrInstant )
		printf("Node Data= %d\n", ptrInstant->data );
	return check ;
}


/****************************************************************
**  => FUNCTION FEATURES:										*
** (1) this function prints all nodes then returns true 		*
** (2) if it the list is empty it returns false.				*
*****************************************************************/
char viewAll( struct Node *list )
{
    char check= 0;
	unsigned int count ;
	struct Node *ptr= list;
	if(ptr)
	{
		check= 1;
		count= 1;
		while(ptr)
		{
			printf("Node number(%d), node Data= %d\n",count , ptr->data );
			ptr= ptr->next;
			count++;
		}
	}
	return check;
}



