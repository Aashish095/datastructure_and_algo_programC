#include<stdio.h>
void display(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

void insertion(int a[],int n,int index,int x){
    int i;
    if(index>=0 && index<=n){
        for(i=n;i>index;i--){
            a[n]=a[n-1];
        }
        a[index]=x;
        n++;

    }

}

void append(int a[],int n,int x){
    int i;
    if(n<50){
        a[n++]=x;
    }
    display(a,n);
}
int main(int argc, char const *argv[])
{
    int a[50];
    int n,i;
    printf("enter array size");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d ",&a[i]);
    }
    
    // insertion(&a,n,5,10);
    append(a,n,190);
    // display(a,n);



    return 0;
}
