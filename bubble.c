#include<stdio.h>

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;

}

void bubble(int a[],int n){
    int i,j,flag=0;
    for(i=0;i<n-1;i++){
        flag=0;
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                flag=1;
            }
        }
    
        if(flag==0)
            break;
    }
}

int main(){
    int a[]={11,13,7,12,16,9,24,5,10,4},n=10,i;
    bubble(a,n);
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}



