#include<stdio.h>

void reverse(int arr[],int start,int end){
    int temp;
    while(start<end){
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

void leftrotate(int arr[],int d,int n){
    if(d==0){
        return;
    }
    d=d%n;
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}
void print(int arr[],int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}

int main(int argc, char const *argv[])
{
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    leftrotate(arr,2,n);
    print(arr,n);
    return 0;
}
