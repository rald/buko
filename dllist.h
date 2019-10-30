#ifndef DLLIST_H
#define DLLIST_H

#include <stdlib.h>

typedef struct DLList DLList;

struct DLList {
	void *data;
	DLList *prev;
	DLList *next;
};

DLList *DLList_New(void *data,DLList *prev,DLList *next);

void DLList_Delete(DLList **head,void(*delete)(void*));

void DLList_Append(DLList **head,void *data);

void DLList_Prepend(DLList **head,void *data);

DLList *DLList_Get(DLList *head,int index);

DLList *DLList_RGet(DLList *head,int index);

void DLList_Remove(DLList **head,DLList *node,void (*destroy)(void*));


#endif
