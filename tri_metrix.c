#include<stdio.h>
#include<stdlib.h>

void Set(int a[],int i,int j,int x){
    if(i>=j){
        a[i*(i-1)/2+j-1]=x;
    }

}

int get(int a[],int i,int j){
    if(i>=j){
        return a[i*(i-1)/2+j-1];
    }
    else
    {
        return 0;
    }
    
}

void display(int a[]){
    int i,j,n=4;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
                if(i>=j)
                    printf("%d",a[i*(i-1)/2+j-1]);
                else
                {
                        printf("0 ");
                }
            
                
        }
        printf("\n");
    }
    

}




int main()
{
    int i,j,x,n,*a;
    printf("enter dimensions");
    scanf("%d",n);
    a=(int *)malloc(n*(n-1)/2*sizeof(int));

    printf("enter all elements"); 
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&x);
            //  Set(a,i,j,x);

        }
    }
    printf("\n\n"); 
    display(a); 
    return 0;
}
