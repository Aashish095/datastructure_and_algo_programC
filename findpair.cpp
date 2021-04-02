#include<iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    int a[]={1,5,10,20,40,80};
    int b[]={6,7,20,80,100};
    int c[]={3,4,15,20,30,70,80,120};
    int n1=sizeof(a)/sizeof(a[0]);
    int n2=sizeof(b)/sizeof(b[0]);
    int n3=sizeof(c)/sizeof(c[0]);
    int i,j,k;;
    i=j=k=0;
    while(i<n1 && j<n2 && k<n3){
        if(a[i]==b[j] && b[j]==c[k]){
            cout<<a[i]<<" ";i++;j++;k++;
        }
        else if(a[i]<b[j])
            i++;
        else if(b[j]<c[k])
            j++;
        else
            k++; 
    }
    
    return 0;
}
