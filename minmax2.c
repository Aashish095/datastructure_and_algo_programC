#include<stdio.h>

int main(int argc, char const *argv[])
{
    int i,a[20]={5,8,3,9,6,2,10,7,-1,4};
    int min=a[0],max=a[0];
    for(i=1;i<10;i++){
        if(a[i]<min){
            min=a[i];
        }
        else if(a[i]>max)
        {
           max=a[i];
        }
        
    } 
    printf("max=%d min=%d",min,max);   
    return 0;
}
