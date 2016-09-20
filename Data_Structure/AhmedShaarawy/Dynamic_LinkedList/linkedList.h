

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<stdio.h>
#include<stdlib.h>


/****************
** node status	*
*****************/
typedef enum{
	LIST_EMPTY,
	NODE_NOT_FOUND,
	NODE_FIRST_ONE,
	NODE_NOT_FIRST
	}Status;


struct Node{
	int data;
	struct Node *next;
	};

char addNode( struct Node **list, int data );
struct Node* searchNode( struct Node *list, int data, struct Node **ptrPrevious );
Status changeNodeData( struct Node *list, int data, int newData );
Status deleteNode( struct Node **list, int data );
char deleteAll( struct Node **list );
char viewNode( struct Node *list, int data );
char viewAll( struct Node *list );

#endif



