#include<stdio.h>
int merge(int a[],int b[],int n,int m){
    int i=0,j=0,k=0;
    int c[100];
    while(i<n && j<m){
        if(a[i]<b[j])
            c[k++]=a[i++];
        else {
            c[k++]=b[j++];
        }
    }
    for(;i<n;i++){
        c[k++]=a[i];
    }
    for(;j<m;j++){
        c[k++]=b[j];
    }
    int mid=k/2;
    if(k%2==0){
        return (c[mid]+c[mid-1])/2;
    }
    else
    {
        return c[mid];
    }
    
}

int main(){
    int a[]={2,3,4,6};
    int b[]={10,12,14,16,18,20};
    int median=merge(a,b,4,6);
    printf("%d ",median);
     
}