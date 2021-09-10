#include<stdio.h>
#define SIZE 5

//Basic value initialisation
int queue[SIZE], front = -1, rear = -1;

//Function created to handle enqueue
void enqueue(int item){
    if(rear == SIZE-1){
        printf("Can't enqueue as the queue is full\n");
    }
    else{
        //The first element condition
        if(front == -1){
            front = 0;
        }
        
        rear = rear + 1;
        queue[rear] = item;
        printf("We have enqueued %d\n",item);
   }
}

//Function created to handle dequeue
void dequeue(){
    if(front == -1){
        printf("Can't dequeue as the queue is empty\n");
    }
    else{
        printf("We have dequeued : %d\n", queue[front]);
        front = front + 1;
        
        //Only happens when the last element was dequeued
        if(front > rear){
	        front = -1;
	        rear = -1;
        }
   }
}

//function to print the queue
void printQueue(){
    if(rear == -1)
        printf("\nUnable to display as queue is empty");
    else{
        int i;
        printf("\nThe queue after enqueue & dequeue ops looks like :");
        
        for(i = front; i <= rear; i++)
	        printf("%d ",queue[i]);
   }
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
   
    printQueue();
    return 0;
}