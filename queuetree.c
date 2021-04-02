#include "queue.h"
#include "stacktree.h"

struct node *root;
void createtree(){
    struct node *p,*t;
    struct queue q;
    int x;
    create(&q,100);
    printf("enter root node ");
    scanf("%d",&x);
    root=(struct node *)malloc(sizeof(struct node));

    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isempty(&q)){
        p=dequeue(&q);
        printf("enter lchild of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct node *)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("enter rchild of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct node *)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }

}

void preorder(struct node *p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct node *p){
    if(p){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void postorder(struct node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

int count(struct node *root){
    if(root){
        return count(root->lchild)+count(root->rchild)+1;
    }
    return 0;
}

int height(struct node *root){
    int x=0,y=0;
    if(root==0){
        return 0;
    }
    x=height(root->lchild);
    y=height(root->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}

void levelorder(struct node *p){
    struct queue q;
    create(&q,100);

    printf("%d ",p->data);
    enqueue(&q,p);

    while(!isempty(&q)){
        p=dequeue(&q);
        if(p->lchild){
            printf("%d ",p->lchild->data);
            enqueue(&q,p->lchild);
        }
        if(p->rchild){
            printf("%d ",p->rchild->data);
            enqueue(&q,p->rchild);
        }
    }
}

void ipreorder(struct node *t){
    struct stack st;
    stackcreate(&st,100);
    while(t!=NULL || !isemptystack(st)){
        if(t!=NULL){
            printf("%d ",t->data);
            push(&st,t);
            t=t->lchild;
        }
        else{
            t=pop(&st);
            t=t->rchild;
        }
    }
}

void iinorder(struct node *t){
    struct stack st;
    stackcreate(&st,100);
    while(t!=NULL || !isemptystack(st)){
        if(t!=NULL){
            push(&st,t);
            t=t->lchild;
        }
        else{
            t=pop(&st);
            printf("%d ",t->data);
            t=t->rchild;
        }
    }
}

// void ipostorder(struct node *t){
//     struct stack st;
//     long int temp;
//     stackcreate(&st,100);
//     while(t!=NULL || isemptystack(st)){
//         if(t!=NULL){
//             push(&st,t);
//             t=t->lchild;
//         }
//         else{
//             temp=pop(&st);
//             if(temp>0){
//                 push(&st,(struct node*)temp);
//                 t=((struct node *)temp)->rchild;
//             }
//             else{
//                 printf("%d ",((struct node *)temp)->data);
//                 t=NULL;
//             }
//         }
//     }
// }

//error occer in postorder traversal

int main(){
    createtree();
    // printf("%d ",count(root));   
    // printf("%d ",height(root));
    //preorder(root);
    ipostorder(root);
}