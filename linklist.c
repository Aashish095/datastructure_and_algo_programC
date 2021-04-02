#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int arr[],int n){
    int i;
    struct node *t,*last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

}

void create2(int arr[],int n){
    int i;
    struct node *t,*last;
    second=(struct node *)malloc(sizeof(struct node));
    second->data=arr[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=arr[i];
        t->next=NULL;
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
void redisplay(struct node *p){
    if(p!=NULL){
        printf("%d ",p->data);
        display(p->next);
    }
}

int count (struct node *p){
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}
int sort(struct node *p){
    int x=INT_MIN;
    while(p!=NULL){
        if(p->data <x){
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}

int add(struct node *p)
{
    int sum=0;
    while(p!=NULL){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int max(struct node *p){
    int max=INT_MIN;
    while(p){
        if(p->data>max)
            max=p->data;
        p=p->next;

        
    }
    return(max);
}

struct node * lsearch(struct node *p,int key){
    while(p!=NULL){
        if(key==p->data)
            return p;
        p=p->next;

    }
    return NULL;
}

struct node *lsearch1(struct node *p,int key){
    struct node *q=NULL;
    while(p!=NULL){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;

        }
        q=p;
        p=p->next;

    }
    return NULL;
}

struct node *rsearch(struct node *p,int key){
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return rsearch(p->next,key);
}

void insert(struct node *p,int index,int x){
        struct node *t;
        if(index < 0 || index > count(p)){
            return;
        }
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        if(index==0){
            t->next=first;
            first=t;
        }
        else{
            int i;
            for(i=0;i<index-1;i++){
                p=p->next;
            }
            t->next=p->next;
            p->next=t;
        }
        
}

void insertlast(struct node *p,int x){
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    while(p->next!=NULL){
        p=p->next;
    }
    t->next=NULL;
    p->next=t;
}
 
void sortedinsert(struct node *p,int x){
    struct node *t,*q=NULL;
    
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    while(p && p->data<x){
        q=p;
        p=p->next;
    }
    if(p==first){
        t->next=first;
        first=t;
    }
    else{
    t->next=q->next;
    q->next=t;
    }
}

int deleted(struct node *p,int index){
     struct node *q=NULL;
     int x=-1,i;
     if(index < 1 || index > count(p)){
         return -1;
     }
     if(index==1){
         q=first;
         x=first->data;
         first=first->next;
         free(q);
         return x;
     }
     else
     {
        for(i=0;i<index-1;i++){
             q=p;
             p=p->next;
         }
         q->next=p->next;
         x=p->data;
         free(p);
         return x;
     }
}
void duplicate(struct node *p){
   struct node *q= p->next;
   while(q!=NULL){
       if(p->data!=q->data){
           p=q;
           q=q->next;
       }
       else{
           p->next=q->next;
           free(q);
           q=p->next;

       }
   }
}

void reverse(struct node *p){
    int *A,i=0;
    struct node *q;

    A=(int *)malloc(sizeof(int)*count(p));

    while(q!=NULL){
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL){
        q->data=A[i];
        q=q->next;
        i--;
    }

}

void reverse2(struct node *p){
    struct node *q=NULL,*r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void reverse3(struct node *q,struct node *p){
    if(p!=NULL){
        reverse3(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}

void concat(struct node *p,struct node *q){
    third=p;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
   
}

void merge(struct node *p,struct node *q){
    struct node *last;
    if(p->data <q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q){
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }

    }
    if(p){
        last->next=p;
    }
    if(q){
        last->next=q;
    }
}



int isloop(struct node *f){
    struct node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p &&q && p!=q);
    if(p==q){
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}




int main(){
    struct node *t1,*t2;
    int arr[]= {10,20,30,40,50};
    create(arr,5);
    // t1=first->next->next;
    // t2=first->next->next->next->next;
    // t2->next=t1;
    // printf("isloop %d\n",isloop(first));

    insertlast(first,100);


    // int arr1[]={5,15,25,35,45};
    
    // create2(arr1,5);
    // insert(first,0,10);
    // insert(first,1,20);
    // insert(first,2,30);
    // insert(first,4,30);
    // sortedinsert(first,7);
    // printf("deleted elements %d\n",deleted(first,1));
    // printf("%d\n",sort(first));

    // duplicate(first);
    // reverse(first);

    // concat(second,first);
    // printf("concatinated\n");
    // merge(first,second);
    display(first);
    
    printf("\n\n");
    // printf("First\n");
    // display(first);
    // printf("\n\n");
    // printf("second\n");
    // display(second);
    // printf("\n\n");
    // temp=lsearch1(first,7 );
    // if(temp)
    //     printf("key is found%d \n ",temp->data);
    // else
    //     printf("key not found\n");
    
    
    return 0;
}