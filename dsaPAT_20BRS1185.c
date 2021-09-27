#include <stdio.h>
#include <stdbool.h>
#define SIZE 5

//declaration
int queue[SIZE], front = -1, rear = -1;

//enqueuing function
void enqueue(int item)
{
    if (rear == SIZE - 1)
    {
        printf("Can't enqueue as the queue is full\n");
    }
    else
    {
        //checking if the element is the first element
        if (front == -1)
        {
            front = 0;
        }

        rear = rear + 1;
        queue[rear] = item;
        printf("We have enqueued %d\n", item);
    }
}

//dequeuing function
void dequeue()
{
    if (front == -1)
    {
        printf("Can't dequeue as the queue is empty\n");
    }
    else
    {
        printf("We have dequeued : %d\n", queue[front]);
        front = front + 1;

        //Only happens when the last element was dequeued
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

//extra function, not asked in the question. Used to verify IsEmpty()
//print queue
void printQueue()
{
    if (rear == -1)
        printf("\nUnable to display as queue is empty");
    else
    {
        int i;
        printf("\nThe queue after enqueue & dequeue ops looks like :");

        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

bool isEmpty()
{
    if (front == -1)
        printf("\nTrue");
    else
    {
        printf("\nFalse");
    }
    return 0;
}

int main()
{
    //enqueue begins here
    enqueue(2);
    enqueue(4);
    enqueue(6);
    enqueue(8);

    //dequeue beings here
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    isEmpty();

    printQueue();
    return 0;
}