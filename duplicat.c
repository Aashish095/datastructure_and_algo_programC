#include<stdio.h>
 int largest(int arr[],int n){
    int i;
    int max=arr[0];
    for(i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}
int main(int argc, char const *argv[])
{
    int i,n,j,a[]={3,6,8,8,10,12,15,15,15,20};
    // int lastdup=0;
    // for(i=0;i<10;i++){
    // //     if(a[i]==a[i+1] && a[i]!=lastdup){
    // //         printf("%d\n",a[i]);
    // //         j++;
    // //         lastdup=a[i];
            
    // //     }
    //     if(a[i]==a[i+1]){
    //         j=i+1;
    //         while(a[j]==a[i])j++;
    //             printf("%d is appearing %d times ",a[i],j-i);
    //             i=j-1;
        // }
    // /using hashing 
   

    
    int hash[21]={0};
    for(i=0;i<10;i++){
        hash[a[i]]++;
     }
    
    for(i=0;i<=20;i++){
        if(hash[i]>1){
            printf("%d %d ",i,hash[i]);
        }

    }
    
    return 0;
}
