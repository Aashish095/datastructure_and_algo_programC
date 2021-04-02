#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char data;
    struct node *next;
}*top=NULL;

void push(char x){

    if(top==NULL){
        printf("stack is full");
    }
    else{
        struct node *t;
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop(){
    struct node *t;
    char x=-1;
    if(top==NULL){
        printf("stack is not full");
    }
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return t;
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

int isbalanced(char *exp){
    int i;
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(exp[i]);
        }
        else
        {
            if(top==NULL)
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

int pre(char x){
    if(x=='+' || x =='-')
        return 1;
    else if(x=='/' || x=='*')
        return 2;
    return 0;
}

int isoperand(char x){
    if(x=='+' || x=='-' || x=='*' || x== '/')
        return 0;
    else
         return 1;
    
}

char * intopost(char *infix){
    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+1)*sizeof(char));
    while(infix[i]!='\0'){
        if(isoperand(infix[i]))
            postfix[j++]=infix[i++];
        else
        {
            if(pre(infix[i])>pre(infix[top->data]))
                push(infix[i++]);
            else
            {
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


int main(int argc, char const *argv[])
{
    char *infix='a+b*c-d/e';
    char *postfix = intopost(infix);
    printf("%s ",postfix );
    return 0;
}
