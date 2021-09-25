#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "linked_list.h"

void create_list(NODE **head)
{

    int i, num_of_nodes, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_of_nodes);

    do
    {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        addatbeg(head, data);
    } while (--num_of_nodes);
}

void addatbeg(NODE **head, int data)
{

    NODE *new_node = malloc(sizeof(NODE));
    NODE *tail = (*head)->prev;

    /* if list is empty*/
    if (*head == NULL)
    {
        new_node->data = data;
        new_node->next = new_node->prev = new_node;
        *head = new_node;
        return;
    }
    /*if list isn't empty*/
    else
    {
        new_node->data = data;
        new_node->next = *head;
        new_node->prev = tail;
        tail->next = (*head)->prev = new_node;
        *head = new_node;
    }
}

void addatend(NODE **head, int data)
{

    NODE *new_node = malloc(sizeof(NODE));
    NODE *tail = (*head)->prev;

    /*case of empty list*/
    if (*head == NULL)
    {
        new_node->data = data;
        new_node->next = new_node->prev = new_node;
        *head = new_node;
        return;
    }

    new_node->data = data;
    new_node->next = *head;
    new_node->prev = tail;
    (*head)->prev = tail->next = new_node;
}

void del(NODE **head, int data)
{
    NODE *tail = (*head)->prev, *ptr = *head;
    if (*head == NULL)
    {
        printf("The list is empty!\n\n");
        return;
    }
    int count = 0;

    /*case for when list only has one node*/
    if (ptr->next == *head && ptr->data == data)
    {
        free(ptr);
        *head = NULL;
        return;
    }
    /*case for when deleting first node */
    if (ptr->data == data)
    {
        ptr->next->prev = tail;
        tail->next = *head = ptr->next;
        free(ptr);
        return;
    }
    /*case for deleting last node*/
    else if (tail->data == data)
    {
        tail->prev->next = *head;
        (*head)->prev = tail->prev;
        free(tail);
        return;
    }
    /*case for deleting all other nodes*/
    else
    {
        while (ptr != tail)
        {
            if (ptr->data == data)
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                free(ptr);
                return;
            }
            ptr = ptr->next;
        }

        printf("Element %d, not found!\n\n", data);
    }
}

void addafter(NODE **head, int data, int item)
{

    NODE *new_node = malloc(sizeof(NODE)), *ptr = *head, *tail = (*head)->prev;

    do
    {
        if (ptr->data == item)
        {
            /* if tail is getting replaced*/
            if (ptr == tail)
            {
                addatend(head, data);
                return;
            }
            new_node->data = data;
            new_node->next = ptr->next;
            ptr->next = ptr->next->prev = new_node;
            ptr = new_node;
            return;
        }
        ptr = ptr->next;

    } while (ptr != *head);

    printf("%d is not present in the list\n\n", item);
}

void addbefore(NODE **head, int data, int item)
{

    NODE *new_node = malloc(sizeof(NODE)), *ptr = *head;
    int element = 1;
    do
    {
        if (ptr->data == item)
        {
            /* if head is getting replaced */
            if (element == 1)
            {
                addatbeg(head, data);
                return;
            }
            new_node->data = data;
            new_node->prev = ptr->prev;
            ptr->prev = ptr->prev->next = new_node;
            new_node->next = ptr;
            return;
        }
        ptr = ptr->next;
        element++;
    } while (ptr != *head);

    printf("Node not found\n\n");
}

void addatpos(NODE **head, int data, int pos)
{

    NODE *ptr = *head, *prev;
    int element = 1;

    do
    {
        if (element == pos)
        {
            addbefore(head, data, ptr->next->data);
            del(head, ptr->data);
            return;
        }
        ptr = ptr->next;
        element++;
    } while (ptr != (*head));
}

NODE *reverse(NODE *head)
{

    NODE *tail = head->prev, *new_head = NULL, *prev, *ptr = tail;

    if (head == NULL)
    {
        printf("List is empty\n\n");
        return NULL;
    }

    while (ptr->prev != tail)
    {
        prev = ptr->prev;

        addatend(&new_head, ptr->data);
        ptr = prev;
    }
    addatend(&new_head, ptr->data);
    return new_head;
}

void destroy_list(NODE **head)
{

    if (*head == NULL)
    {
        printf("List is empty\n\n");
        return;
    }
    while (*head != NULL)
        del(head, (*head)->data);
}

void search(NODE *head, int data)
{

    NODE *ptr = head;
    int element = 1;

    if (head == NULL)
    {
        printf("List is empty\n\n");
        return;
    }

    do
    {
        if (ptr->data == data)
        {
            printf("Node %d was found at position %d\n\n", data, element);
            return;
        }
        element++;
        ptr = ptr->next;
    } while (ptr != head);

    printf("element was not found\n\n");
}

void display(NODE *head)
{

    NODE *ptr = head;

    if (head == NULL)
    {
        printf("List is empty\n\n");
        return;
    }

    printf("list is");
    /* iterate at least once to pass the first node*/
    do
    {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);

    printf("\n\n");
}

void count(NODE *head)
{

    NODE *ptr = head->next;
    int counter = 1;

    if (head == NULL)
    {
        printf("List is empty\n\n");
        return;
    }

    while (ptr != head)
    {
        counter++;
        ptr = ptr->next;
    }
    printf("number of nodes is %d\n\n", counter);
}
