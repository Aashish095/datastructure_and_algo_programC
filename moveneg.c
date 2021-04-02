#include<stdio.h>

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void rearrange(int arr[],int n){
    int i=0,j=n-1;
    while(i<j){
        while(arr[i]<0){i++;}
        while(arr[j]>=0){j--;}
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    // int i;
    // int j=0;
    // for(i=0;i<n;i++){
    //     if(arr[i]<0){
    //         if(i!=j){
    //             swap(&arr[i],&arr[j]);
    //         }
    //         j++;
    //     }
    // }
}

int main(){
    int arr[]={-12,11,-13,-5,6,-7,5,-3,-6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i;
    rearrange(arr,n);
    
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}