#include<stdio.h>
#include<stdlib.h>

struct node {
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct node *q,int size){
    q->size=size;
    q->rear=q->front=-1;
    q->Q=(int *)malloc(q->size*sizeof(int ));

}

void enque(struct node *q,int x){
    if((q->rear+1)%q->size==q->front){
        printf("queue is full\n");
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

int deque(struct node *q){
    int x=-1;
    if(q->rear==q->front){
        printf("queue is empty\n");
    }
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];

    }
    return x;
}

void display(struct node q){
    int i=q.front+1;
    do{
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    printf("\n");
}

int main(){
    struct node q;
    create(&q,5);
    enque(&q,10);
    enque(&q,20);
    enque(&q,30);
    enque(&q,50);
    enque(&q,40);
   enque(&q,70);
    display(q);
    // printf("%d ",deque(&q));
    // printf("%d ",deque(&q));
    // printf("%d ",deque(&q));
    // printf("%d ",deque(&q));
    
}