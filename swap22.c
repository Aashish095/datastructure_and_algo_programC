#include<stdio.h>

void swap(int arr[],int l,int h,int n){
    int temp;
    while(l<h){
        temp=arr[l];
        arr[l]=arr[h];
        arr[h]=temp;
        l++;
        h--;

    }
}



int main(int argc, char const *argv[])
{
    int n,i;
    int arr[10];
    int l,h;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d %d",&l,&h);
    // printf("%d\n",n);
    //  for(i=0;i<n;i++){
    //     printf("%d ",arr[i]);
    // }
    // printf("\n%d %d",l,h);
    swap(arr,l,h,n);
    for(i=0;i<n;i++){
         printf("%d ",arr[i]);
    
    }
    return 0;
}
