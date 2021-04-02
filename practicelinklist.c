#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int a[],int n){
    struct node *t,*last;
    int i;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void create1(int a[],int n){
    struct node *t,*last;
    int i;
    
    second=(struct node *)malloc(sizeof(struct node));
    second->data=a[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
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

void recdisplay(struct node *p){
    if(p!=NULL){
        printf("%d ",p->data);
        recdisplay(p->next);
    }
}

int count(struct node *p){
    int count=0;
    while(p!=NULL){
        p=p->next;
        count++;
    }
    return count;
}

int add(struct node *p){
    int add=0;
    while(p!=NULL){
        add+=p->data;
        p=p->next;
    }
    return add;
}

int recadd(struct node *p){
    
    if(p==0){
        return 0;
    }
    else{
        return add(p->next)+p->data;
    }
   
}

int max(struct node *p){
    int max=INT_MIN;
    while(p){
        if(max<p->data){
            max=p->data;
        }
        p=p->next;
    }
    return max;
}

int recmax(struct node *p){
    int x;
    if(p==NULL){
        return INT_MIN;
    }
    else{
        x=max(p->next);
        return x>p->data?x:p->data;
    }
}

int linksort(struct node *p){
    int x=INT_MIN;
    while(p!=NULL){
        if(p->data<x){
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}

struct node *lsearch(struct node *p,int key){
    while(p!=NULL){
        if(p->data==key){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

struct node *recsearch(struct node *p,int key){
    if(p==NULL){
        return NULL;
    }
    if(p->data==key){
        return p;
    }
    return recsearch(p->next,key);
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

void insert(struct node *p,int index,int x){
    struct node *t,*q=NULL;
    int i;
    if(index<1 ||index >count(p)){
        return;
    }
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
   if(index==0){
        t->next=first;
        first=t;
    }
    else{
        for(i=0;i<index-1 && p;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;

    }
}

void insertlast(struct node *p,int x){
    struct node *last,*t;
    int i;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(first=NULL){
        first=last=t;
    }
    else{
        while(last!=NULL){
            last=last->next;
        }
        last->next=t;
        last=t;
    }
}

void sortinsert(struct node *p,int x){
    struct node *t,*q=NULL;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    if(first==NULL){
        first=t;
    }
    else
    {
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
   
    
}

int delete(struct node *p,int index){
    struct node *q=NULL;
    int x=-1,i;
    if(index<0 && index>count(p)){
        return -1;
    }
    if(index==1){
        x=p->data;
        first=first->next;
        free(p);
    }
    else{
        for(i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        if(p){
            q->next=p->next;
            x=p->data;
            free(p);
        }
    }
    return x;    
}

void duplicate(struct node *p){
    struct node *q=p->next;
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
    int *a,i=0;
    a=(int *)malloc(sizeof(int)*count(p));
    while(p!=NULL){
        a[i]=p->data;
        p=p->next;
        i++;
    }
    p=first;
    i--;
    while(p!=NULL){
        p->data=a[i--];
        p=p->next;
    }
}

void reverse3(struct node *p){
    struct node *q=NULL,*r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void revser2(struct node *q,struct node *p){
    if(p!=NULL){
        revser2(p,p->next);
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
    if(p->data<q->data){
        third=last=p;
        p=p->next;
        last->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        last->next=NULL;
    }
    while(p && q){
        if(p->data<q->data){
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
        else{
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
    }
    if(p)last->next=p;
    if(q)last->next=q;
}
int isloop(struct node *f){
     struct node *p,*q;
     p=q=f;
     do{
         p=p->next;
         q=q->next;
         q=q!=NULL?q->next:NULL;
     }while(p && q && p!=q);
     if(p==q){
         return 1;
     }
     else{
         return 0;
     }
 }

int main(int argc, char const *argv[])
{
    struct node *t1,*t2;
    int arr[]={1,2,3,4,5};
    // int arr1[]={4,5,6,5};
    create(arr,5);
    // create1(arr1,4);
    // t1=first->next->next;
    // t2=first->next->next->next->next;
    // t2->next=t1;
    int loopis=isloop(first);
    if(loopis){
        printf("loop exist");
    }
    else{
        printf("not exist");
    }
    // recdisplay(first);
    // printf("\n%d",count(first));
    // printf("\n%d",add(first));
    // printf("\n%d",recadd(first));
    // printf("\n%d",recmax(first));
    // t1=lsearch1(first,1);
    // if(t1){
    //     printf("data found %d",t1->data);
    // }
    // else
    // {
    //     printf("NO DATA FOUND IN LINEAR SEARCH");
    // }
    // int t;
    // t=linksort(first);
    // if(t){
    //     printf("sorted %d \n",t);
    // }
    // else{
    //     printf("not sorted %d\n",t);
    // }
    // duplicate(first);
    // revser2(0,first);
    //  concat(first,second);
    //  merge(first,second);
    // insert(first,3,5);
    // sortinsert(first,3);
    // delete(first,5);
    // display(third);
    // printf("\n\n");
    // display(second);
    return 0;
}

