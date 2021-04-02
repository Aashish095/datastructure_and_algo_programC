#include<stdio.h>
#include<stdlib.h>
struct Array{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    printf("\n element are \n");
    for(i=0;i<arr.length;i++){
            printf("%d ",arr.A[i]);
    }
 

}

int main(int argc, char const *argv[])
{
    struct Array arr;
    int n,i;
    printf("enter size of array");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size*sizeof(int));
    arr.length=0;

    printf("enter the number of number");
    scanf("%d",&n);

    printf("enter all elementdnumber");
    for(i=0;i<n;i++)
        scanf("%d",&arr.A[i]);
    
    arr.length=n;
    Display(arr);
}
