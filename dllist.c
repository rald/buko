#include "dllist.h"

static int sgn(int x);

DLList *DLList_New(void *data,DLList *prev,DLList *next) {
	DLList *node=malloc(sizeof(*node));
	if(node) {
		node->data=data;
		node->prev=prev;
		node->next=next;
	}
	return node;
}

void DLList_Delete(DLList **head,void(*delete)(void*)) {
	DLList *next,*iter=(*head);
	while(iter) {
		next=iter->next;
    delete(iter->data);
    free(iter);
    iter=next;
  }
}

void DLList_Append(DLList **head,void *data) {
  DLList *node=DLList_New(data,NULL,NULL);
  DLList *last=(*head);
  if(!(*head)) {
    (*head)=node;
    return;
  }
  while(last->next) {
    last=last->next;
  }
  last->next=node;
  node->prev=last;
}

void DLList_Prepend(DLList **head,void *data) {
  DLList *node=DLList_New(data,NULL,*head);
	DLList *last=(*head);
  if(*head) {
  	(*head)->prev=node;
    last=last->next;
  }
  last->next=node;
  node->prev=last;
}

DLList *DLList_Get(DLList *head,int index) {
  int i=0;
  DLList *iter=head;
  while(iter && i!=index) {
    i++;
    iter=iter->next;
  }
  return iter;
}

DLList *DLList_RGet(DLList *head,int index) {
  int i=0,j=0;
  DLList *iter=head;
  while(iter || i!=index) {
    j=sgn(index);
    i+=j;
    if(j==1) iter=iter->next;
		else if(j==-1) iter=iter->prev;
  }
  return iter;
}

void DLList_Remove(DLList **head,DLList *node,void (*destroy)(void*)) {
  if(!(*head) && !node) return;
  if((*head)==node) (*head)=node->next;
  if(!node->next) node->next->prev=node->prev;
  if(!node->prev) node->prev->next=node->next;
  destroy(node->data);
  free(node);
  node=NULL;
}

static int sgn(int x) {
  return x<0?-1:x>0?1:0;
}
