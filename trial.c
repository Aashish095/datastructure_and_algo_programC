#include<stdio.h>

// int sum(int arr[],int n){
//     int sum,i;
//     for(i=0;i<n;i++){
//         sum+=arr[i]*i;
//     }
//     return sum;
    
// }

// void rotatebyone(int arr[],int n){
//     int i;
//     int temp=arr[0];
//     for(i=0;i<n-1;i++){
//         arr[i]=arr[i+1];
//     }
//     arr[i]=temp;
// }

// void rotate(int arr[],int n){
//     int i;
//     int b[10];
    
//     for(i=0;i<4;i++){
        
//         int temp=arr[0];
//         for(i=0;i<n-1;i++){
//             b[i]=arr[i+1];
//         }
//         b[i]=temp;
//         for(i=0;i<n;i++){
//             printf("%d ",b[i]);
//     }
        
//     }

    
   
// }
// void breaking_record(int arr[],int n){
//     int max,min,i,maxcount=0,mincount=0;
//     max=arr[0];
//     min=arr[0];
//     for(i=1;i<n;i++){
//         if(max<arr[i]){
//             max=arr[i];
//             maxcount++;
            
//         }
//         if(min>arr[i]) {
//             min=arr[i];
//             mincount++;
//         }
        
        
//     }
//     printf("%d %d ",maxcount,mincount);
// }
void birthday(int arr[],int n,int d,int m){
    int i,count=0,j;
    for(j=0;j<n;j++){
        int add=0;
        for(i=0;i<m;i++){
            add+=arr[j+i];
        
        }
        if(add==d)
             count++;
        
    }
    printf("%d",count);
   
    
}
int main(int argc, char const *argv[])
{
    int arr[100],i,n,d,m;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d %d",&d,&m);
    birthday(arr,n,d,m);
    

    return 0;
}
