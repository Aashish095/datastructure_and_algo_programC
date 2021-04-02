#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int a[],int l,int h){
    int pivot = a[l];
    int i=l,j=h;

    do{
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if(i<j)swap(&a[i],&a[j]);
    }while(i<j);

    swap(&a[l],&a[j]);
    return j;
}


void quicksort(int a[],int l,int h){
    int j;
    if(l<h){
        j=partition(a,l,h);
        quicksort(a,l,j);
        quicksort(a,j+1,h);
    }
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
    quicksort(A,0,n);
    for(i=0;i<10;i++)
        printf("%d ",A[i]);
    printf("\n");
return 0;
}