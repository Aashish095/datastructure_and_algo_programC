#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int i,j,n=4,a[20]={1,5,7,1};
    int hash[20]={0};
    // for(i=0;i<n-1;i++){
    //     for(j=i+1;j<n;j++){
    //         if(a[i]+a[j]==10){
    //             printf("%d %d",a[i],a[j]);
    //         }

    //     }
 
    for(i=0;i<n;i++){
        if(hash[6-a[i]]!=0 && 6-a[i]>0){
            printf("%d + %d = %d ",a[i],6-a[i],6);
        }
        hash[a[i]]++;

    }
    
    return 0;
}
