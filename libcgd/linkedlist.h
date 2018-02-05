//
// Created by andreas on 2018-02-04.
//

#ifndef CGD_LIB_LINKEDLIST_H
#define CGD_LIB_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct link_node {
    void *data;
    struct link_node *next;
} CGD_LinkNode;

typedef struct
{
    CGD_LinkNode *head, *last;
    int len;
} CGD_LinkedList;

CGD_LinkedList *cgd_linklist_create();
void cgd_linklist_push(CGD_LinkedList *list, void *data);
void *cgd_linklist_pop(CGD_LinkedList *list);




#endif //CGD_LIB_LINKEDLIST_H
