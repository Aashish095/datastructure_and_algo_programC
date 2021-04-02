#include<stdio.h>

void insertion(int a[],int n){
    int i,j,x;
    for(i=0;i<n;i++){
        j=i-1;
        x=a[i];
        while(j>-1 && a[j]>x){
            a[j+1]=a[j];
            j--;

        }
        a[j+1]=x;
    }
}

int main()
{
int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
insertion(A,n);
for(i=0;i<10;i++)
printf("%d ",A[i]);
printf("\n");
return 0;
}