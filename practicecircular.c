#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;

void create(int a[],int n){
    struct node *t,*last;
    int i;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=a[0];
    head->next=head;
    last=head;
    for(i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        last=t;
        
    }
}

int count(struct node *p){
    int count=0;
    do{
        count++;
        p=p->next;
    }while(p!=head);
    return count;
}

void display(struct node *p){
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);
    printf("\n");
}

void recdisplay(struct node *p){
    static int flag=0;
    if(p!=head || flag==0){
        flag=1;
        printf("%d ",p->data);
        
        display(p->next);
    }
    flag=0;
}

void display2(struct node *p){
    int flag=0;
    while(1){
        if(p==head && flag)
            break;
        flag=1;
        printf("%d ",p->data);
        p=p->next;
    }
}

void insert(struct node *p,int index,int x){
    if(index<0 && index>count(p))
        return;
    if(index==0){
        struct node *t;
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        if(head==NULL){
            head=t;
            head->next=head;
        }
        else{
            while(p->next!=head){
               p=p->next;
            }
            t->next=p->next;
            p->next=t;
            head=t;
        }
    }
    else{
        
        for(int i=0;i<index-1;i++){
           p=p->next;
        }
        struct node *t;
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->next=p->next;
        p->next=t;

    }
}

int delete(struct node *p,int index){
    int x,i;
    struct node *q;
    if(index<0 || index>count(p)){
        return -1;
    }
    if(index==0){
        while(p->next!=head)p=p->next;
        x=head->data;
        if(head==p){
            free(head);
            head=NULL;
        }
        else{
            p->next=head->next;
            free(head);
            head=p->next;
        }
    }
    else{
        for(i=0;i<index-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->next;
        free(q);
    }
    return x;
}



int main(int argc, char const *argv[])
{
    int arr[]={1,2,3,4,5};
    /* code */
    create(arr,5);
    // insert(head,1,4);
    delete(head,5);
    display(head);
    // recdisplay(head);

    return 0;
}
