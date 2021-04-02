#include<stdio.h>

int union1(int a[], int n, int b[], int m)  {
    //code here
   int i=0,j=0,count=0;

   
   
   while(i<n && j<m){
       
       if(a[i]!=a[i+1]){
           
           if(a[i]<b[j]){
               i++;
               count++;
            }
        else if(a[i]>b[j]){
            
               j++;
               count++;
        }
        else if(a[i]==b[j]){
            
            i++;j++;count++;
            }
       }
    }
   
   while(i<n){
       i++;count++;
   }
   while(j<m){
       j++;count++;
    }
   
   
   return count;
}

int main(int argc, char const *argv[])
{
    int c;
    int a[]={1,2,2,2,3};
    int b[]={2,3,4,5};
    c=union1(a,5,b,4);
    printf("%d",c);

    return 0;
}
