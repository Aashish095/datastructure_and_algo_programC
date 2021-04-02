#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a[]={73,67,38,33};
    int i,n=4,b[8],x;
    for(i=0;i<n;i++){
        if(a[i]>38){
            if(a[i]%5==0)
                printf(" %d ",a[i]);
            else
            {   x=a[i];
                while(a[i]%5!=0){
                    a[i]=a[i]+1;
                }
                
                if(a[i]-x<3)
                    printf(" %d ",a[i]);
                else
                    printf(" %d ",x);
            }
            
        }
        else{
            printf(" %d ",a[i]);
        }
    }

    return 0;
}
