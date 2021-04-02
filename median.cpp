#include<bits/stdc++.h>

using namespace std;
int merge(int a[],int b[],int n,int m){
    int i=0;
    while(i<n){
        if(a[i]>b[0]){
            swap(a[i],b[0]);
            sort(b,b+m);
        }
        i++;
    }
    for(j=0;i<n;i)
}

int main(){
    int a[]={2,3,4,6};
    int b[]={10,12,14,16,18,20};
    int median=merge(a,b,4,6);
    printf("%d ",median);
     
}