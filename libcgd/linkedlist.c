//
// Created by andreas on 2018-02-04.
//

#include "linkedlist.h"

CGD_LinkedList *cgd_linklist_create()
{
    CGD_LinkedList *list = malloc(sizeof(CGD_LinkedList));
    list->head->data = NULL;
    list->head->next = NULL;
    list->last = list->head;

    return list;
}

void cgd_linklist_push(CGD_LinkedList *list, void *data)
{
    CGD_LinkNode *node = malloc(sizeof(CGD_LinkNode));
    node->data = data;
    node->next = NULL;
    list->last->next = node;
    list->len++;
}

void *cgd_linklist_pop(CGD_LinkedList *list)
{
    if (list->len <= 0)
    {
        printf("CGD_LIST_ERROR:\n Cannot pop list without items.\n");
        return NULL;
    }
    CGD_LinkNode *node = list->head;
    for (int i = 0; i < list->len-1; i++)
        node = node->next;

    list->last = node;
    list->len--;
    void *data = node->next->data;
    free(node->next);
    return data;
}
