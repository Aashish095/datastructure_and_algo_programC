#include<stdio.h>

void reverse(int arr[],int i,int j){
    int temp;
    while(i<j){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
}
}
int main()
{
    int i,arr[]={4,5,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("original array\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    reverse(arr,0,n-1);
    printf("reverse array\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}
