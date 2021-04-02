#include <stdio.h>

void set(int a[],int b[],int n,int m){
    int x,i,j=1,p=0,k,number=0;
    int c[100];
    x=a[n-1];
    while(x<=b[0]){
        for(i=0;i<n;i++){
            if(x%a[i]==0){
                p=1; 
            }
            else {
                p=0;
                 break;
            }
            
        }
        if(p==1){
                c[j]=x;
                j++;
            }
        x++;
     }
     for(i=0;i<j;i++){
         for(k=0;k<m;k++){
             if(b[k]%c[i]==0)
                p=1;
            else{
                 p=0;
                 break;
             }
            
        }
        if(p==1)
            number++;
           
     }
     printf("%d",number);
     
    
}

int main(){
    int i,j,n,m,x;
    int a[50],b[50];
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
         scanf("%d",&a[i]);
    for(i=0;i<m;i++)
        scanf("%d",&b[i]);
    set(a,b,n,m);
    return 0;
    
    
}
