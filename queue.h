#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct queue{
    int size;
    int rear;
    int front;
    struct node **Q;
};

void create(struct queue *q,int size){
    q->size=size;
    q->rear=q->front=0;
    q->Q=(struct node **)malloc(q->size*sizeof(struct node * ));

}

void enqueue(struct queue *q,struct node *x){
    if((q->rear+1)%q->size==q->front){
        printf("queue is full\n");
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

struct node * dequeue(struct queue *q){
    struct node* x=NULL;
    if(q->rear==q->front){
        printf("queue is empty\n");
    }
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int isempty(struct queue *q){
    return q->front==q->rear;
}

