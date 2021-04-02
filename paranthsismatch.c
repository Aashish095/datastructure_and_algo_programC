#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node *next;
}*top=NULL;

void push(char x){
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL){
        printf("stack is full\n");
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
    
}

char pop(){
    struct node *t;
    int x;
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL){
        printf("stack is empty");
    }
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

int isempty(){
    if(top==NULL){
        return 1;
    }
    return 0;
}


isbalanced(char *exp){
    int i;
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(exp[i]);
        }
        else if(exp[i]==')'){
            if(isempty(exp))
                return 0;
            pop();
        }
    }
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}



void display(){
    struct node *t;
    t=top;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    /* code */
    char *exp = "((a+b)*(c-d))";
    printf("%d ",isbalanced(exp));
    return 0;
}
