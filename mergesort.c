#include<stdio.h>

void merge(int a[],int l,int mid,int h){
    int i=l,j=mid+1,k=l;
    int b[100];
    while(i<=mid && j<=h){
        if(a[i]<a[j])
            b[k++]=a[i++];
        else 
            b[k++]=a[j++];
    }
        for(;i<=mid;i++)
            b[k++]=a[i];
        for(;j<=h;j++)
            b[k++]=a[j];
        for(i=l;i<=h;i++)
            a[i]=b[i];
    
}

void imergesort(int a[],int n){
    int p,l,h,mid,i;
    for(p=2;p<=n;p=p*2){
        for(i=0;i+p-1<n;i=i+p){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(a,l,mid,h);
        }
        if(n-i>p/2){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(a,l,mid,n-1);
        }
    }
    if(p/2<n){
        merge(a,0,p/2-1,n-1);
    }
}
int main()
{
int A[]={11,5,14,2,6,3,1},n=7,i;
imergesort(A, n);
for(i=0;i<n;i++)
printf("%d ",A[i]);
printf("\n");
return 0;
}