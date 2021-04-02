#include<stdio.h>


void set(int *a[],int i,int j,int x){
    if(i==j){
        a[i-1]=x;
    }
}

int get(int a[],int i,int j){
    if(i==j){
        return a[i-1];
    
    }
    else
    {
        return 0;
    }
    
}

void display(int a[]){
    int i,j,n=4;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)
                printf("%d ",a[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int a[10];
    int n=4;
    set(&a,1,1,5);set(&a,2,2,8);set(&a,3,3,9);set(&a,4,4,12);
    printf("%d\n",get(a,2,2));
    display(a);
    return 0;
}
