#include<stdio.h>
#include<stdlib.h>

struct element{
    int i;
    int j;
    int x;

};

struct sparse{
    int m;
    int n;
    int num;
    struct element *ele;
};

void create(struct sparse *s){
    int i;
    printf("enter dimensions");
    scanf("%d%d",&s->m,&s->n);
    printf("number of non-zero");
    scanf("%d",&s->num);

    s->ele=(struct element *)malloc(s->num*sizeof(struct element));
    printf("enter non-zero elements"); 
    for(i=0;i<s->num;i++){
        scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
    }
} 

void display(struct sparse s){
    int i,j,k=0;

    for(i=0;i<s.m;i++){
        for(j=0;j<s.n;j++){
            if(i==s.ele[k].i && j==s.ele[k].j)
                printf("%d ",s.ele[k++].x);
            else
            {
                printf("0 ");
            }
            

        }
        printf("\n");
    }
}  
 
int main()
{
    struct sparse s;
    create(&s);
    display(s);
    
    return 0;
}
