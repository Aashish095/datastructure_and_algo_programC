#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
}*head;

void create(int a[],int n){
    int i;
    struct node *last,*t;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=a[0];
    head->prev=head->next=head;
    last=head;
    for(i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=last->next;
        head->prev=t;
        last->next=t;
        t->prev=last;
        last=t;

    }
}

void display(struct node *p){
    do{
        printf("%d ",p->data);
        p=p->next;
        
    }while(p!=head);
}

int count(struct node *p){
    int count=0;
    do{
        count++;
        p=p->next;
    }while(p!=head);
    return count;
}

void insert(struct node *p,int index,int x){
    int i;
    if(index<0 || index>count(p)){
        return;
    }
    struct node *t;
    if(index==0){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->prev=head->prev;
        t->prev->next=t;
        head->prev=t;
        t->next=head;
        head=t;

    }
    else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->next=p->next;
        if(p->next)
            p->next->prev=t->next;
        p->next=t;
        t->prev=p;
    }
}

int delete(struct node *p,int index){
    int x=-1,i;
    if(index<0 && index>count(p)){
        return -1;
    }
    if(index==0){
        // head=head->next;
        head->prev->next=head->next;
        head->next->prev=head->prev;
        x=head->data;
        head=p->next;
        
        free(p);
        
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        x=p->data;
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        free(p);
    }
    return x;

}

int main(int argc, char const *argv[])
{
    int arr[]={1,2,3,4,5};
    create(arr,5);
    // insert(head,5,1);
    delete(head,1);
    display(head); 
    return 0;
}
