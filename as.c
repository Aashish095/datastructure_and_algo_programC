#include<stdio.h>
int main(int argc, char const *argv[])

{  
    int arr[100],n;
    int i,r,j=0;
    char c;
    
    scanf("%d",&n);
    
    while(n!=0){
        r=n%10;
        arr[j]=r;
        j++;
        n=n/10;
    }

    for(i=j-1;i>=0;i--){
        printf("%c",arr[i]+97);
    }
    
    
    return 0;
}
