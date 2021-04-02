#include<stdio.h>
int gcd(int d,int n){
    if(n==0){
        return d;
    }
    else
    {
        return gcd(n,d%n);
    }
}

void print(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void leftrotate(int arr[],int d,int n){
    int i,j,k,temp;
    d=d%n;
    int g_c_d=gcd(d,n);

    for(i=0;i<g_c_d;i++){
        j=i;
        temp=arr[i];
        while(1){
            k=j+d;
            if(k>=n)
                k=k-n;
            if(k==i)
                break;
            arr[j]=arr[k];
            j=k;

        }
        arr[j]=temp;
    }
}


int main(int argc, char const *argv[])
{
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    leftrotate(arr,2,n);
    print(arr,n);

    return 0;
}
