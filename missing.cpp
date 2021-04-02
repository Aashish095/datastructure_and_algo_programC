#include<iostream>
using namespace std;

int main(){
    int n,i,a[100];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    
    int diff=a[0];
    for(i=0;i<n;i++){
        if(a[i]-i!=diff){
            while (diff<a[i]-i)
            {
                cout<<i+diff<<" ";
                diff++;
            }
            
        }
    }
}