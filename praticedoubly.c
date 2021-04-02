#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;


void create(int a[],int n){
    int i;
    struct node *last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->prev=first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        struct node *t;
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }


}
void display(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int count(struct node *p){
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

void insert(struct node *p,int index,int x){
    if(index<0 || index>count(p)){
        return;
    }
    if(index==0){
        struct node *t;
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->next=first;
        t->prev=NULL;
        first->prev=t;
        first=t;
        
    }
    else{
        struct node *t;
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        t->prev=p;
        if(p->next)
            p->next->prev=t;
        p->next=t;

    }
}

int delete(struct node *p,int index){
    int x=-1,i;
    if(index<0 || index>count(p)){
        return -1;
    }
    if(index==0){
        first=first->next;
        x=p->data;
        if(first){
            first->prev=NULL;
        }
        free(p);
    }
    else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next){
            p->next->prev=p->prev;
        }
        x=p->data;
        free(p);

    }
    return x;
}

void reverse(struct node *p){
    struct node *temp;
    while(p!=NULL){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL){
            first=p;
        }
    }
}



int main(int argc, char const *argv[])
{
    int arr[]={1,2,3,4,5};
    create(arr,5);
    // insert(first,0,2);
    // delete(first,5);
    reverse(first);
    display(first);

    /* code */
    return 0; 
}

