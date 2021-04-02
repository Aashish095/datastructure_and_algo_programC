#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;

void create(int arr[],int n){
    struct node *t,*last;
    int i;
    first=(struct node *)malloc(sizeof(struct node));
    first->prev=first->next=NULL;
    first->data=arr[0];
    last=first;
    for(i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=arr[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;

    }

}
int length(struct node *p){
     int count=0;
     while(p!=NULL){
         p=p->next;
         count++;
     }
     return count;
 }
void display(struct node *p){
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void recdisplay(struct node *p){
    if(p!=NULL){
        printf("%d ",p->data);
        recdisplay(p->next);
    }
}

void insert(struct node *p,int index,int x){
    struct node *t;
    int i;
    if(index<0 || index>length(p)){
        return;
    }
    if(index==0){
        
        t=(struct node *)malloc(sizeof(struct node ));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else{
        t=(struct node *)malloc(sizeof(struct node ));
        t->data=x;
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        t->prev=p;
        if(p->next)p->next->prev=t;
        p->next=t;
    }
}

int delete(struct node *p,int index){
    int x,i;
    if(index<1|| index>length(p)){
        return -1;
    }
    if(index==1){
        
        first=first->next;
        x=p->data;
        free(p);
        if(first){
            first->prev=NULL;
        }
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
    // insert(first,1,25);
    // delete(first,2);
    reverse(first);
    recdisplay(first);
    return 0;
}
