#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node ));
    if(p==NULL)
        printf("queue is Full\n");
    else
    {
        p->data=x;
        p->next=NULL;
        if(front==NULL)
            front=rear=p;
        else
        {
            rear->next=p;
            rear=p;
        }
    }
}

int dequeue(){
    int x=-1;
    struct node *t;
    if(front == NULL)
        printf("queue is empty\n");
    else
    {
        x=front->data;
        t=front;
        front=front->next;
        free(t);

    }
    return x;

}

int isEmpty()
{
    return front == NULL;
}