#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[]={1,2,3,4,5};
    int n=5;
    int i,j,current_price=0;
    int profit=0;

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]<a[j]){
                current_price=a[j]-a[i];
                profit=max(profit,current_price);

            }
        }
    }
    cout<<profit<<" ";
    
    return 0;
}