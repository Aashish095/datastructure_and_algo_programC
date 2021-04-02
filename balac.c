#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node *next;

}*top=NULL;

void push(int x){
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

int pop(){
    int x=-1;
    struct node *t;
    if(top==NULL){
        printf("stack is empty\n");
    }
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void display(){
    struct node *p;
    p=top;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int ispair(char x,char y){
    if(x=='(' && y==')'){
        return 1;
    }
    else if(x=='[' && y==']')
        return 1;
    else if(x=='{' && y=='}') 
        return 1;
    else
        return 0;

}

int isbalanced(char *exp){
    int i;
    int flag=0;

    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(top!=NULL && ispair(top->data,exp[i]))
                pop();
            else{
                flag++;
                break;
            }
        }
    }
    if(top!=NULL ||flag==1){
        return 0;
    }
    else
        return 1;
}

int pre(char x){
    if(x=='+' || x=='-'){
        return 1;
    }
    else if(x=='*' || x=='/')
        return 2;
    return 0;
}

int isoperand(char x){
    if(x=='+' || x=='*'|| x=='/' || x=='-')
        return 0;
    else
        return 1;
}

char *intpost(char *infix){
    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+1)*sizeof(char ));
    while(infix[i]!='\0'){
        if(isoperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(pre(infix[i]>pre(top->data))){
                push(infix[i++]);
            }
            else{
                postfix[j++]=pop();
            }
        }
    }
    while(top!=NULL){
        postfix[j++]=pop();
        postfix[j]='\0';
        return postfix;
    }
}

int main(){
    char *infix="a+b*c-s";
    char *postfix=intpost(infix);
    printf("%s",postfix);
    display();

    return 0;
}