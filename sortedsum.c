#include<stdio.h>

int main(int argc, char const *argv[])
{
    int i=0,j,k=12,n;
    int a[20]={1,3,4,5,6,8,9,10,12,14};
     printf("enter size of array");
     scanf("%d",&n);
    // printf("enter array elements");
    // for(i=0;i<n;i++)
    //     scanf(" %d ",&a[i]);
    // printf("enter element whose sum is ");
    // scanf("%d",&k);
    j=n-1;
    while(i<j){
        if(a[i]+a[j]==k){
            printf("%d + %d = %d",a[i],a[j],k);
            j--;
            i++;
        }
        else if(a[i]+a[j]<k){
            i++;
        }
        else
        {
            j--;
        }
        
    }
    

    return 0;
}
