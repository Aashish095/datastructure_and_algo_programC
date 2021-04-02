#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;

void create(int a[],int n){
    int i;
    struct node *t,*last;
    head=(struct node*)malloc(sizeof(struct node));
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
void display(struct node *h){
    do{
        printf("%d ",h->data);
        h=h->next;
    }
    while(h!=head);
}

void recdisplay(struct node *h){
    static int flag=0;
    if(h!=head||flag==0){
        flag=1;
        printf("%d ",h->data);
        recdisplay(h->next);       
    }
    
}
int length(struct node *p){
    int count=0;
    do{
        count++;
        p=p->next;
        
    }while(p!=head);
    return count;
}

void insert(struct node *p,int index,int x){
    struct node *t;
    if(index<0 || index>length(p)){
        return;
    }
    if(index==0){
        t=(struct node *)malloc(sizeof(struct node ));
        t->data=x;
        if(head==NULL){
            head=t;
            head->next=head;
        }
        else{
            while(p->next!=head)p=p->next;
            p->next=t;
            t->next=p->next;
            head=t;
        }
    }   
    
    else
    {
        for(int i=0;i<index-1;i++)p=p->next;
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->next=p->next;
        p->next=t;

    }
}

int delete(struct node *p,int index){
    struct node *q;
    int i,x;
    if(index<0 || index>length(p)){
        return -1;
    }
    if(index==1){
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
    int arr[]={1,2,5,4,5};
    create(arr,5);
    // insert(head,2,10);
    delete(head,1);
    recdisplay(head);

    return 0;
}
