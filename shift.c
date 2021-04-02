#include<stdio.h>
#include<stdlib.h>

struct Array {
    int A[10];
    int size;
    int length;

};

void display(struct Array arr){
    int i;
    for(i=0;i<arr.length;i++){
        printf("\n%d",arr.A[i]);
    }
}
void reverse(struct Array *arr){
    int i,j,*b;
    b=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++){
        b[j]=arr->A[i];
    }
    for(i=0;i<arr->length;i++){
        arr->A[i]=b[i];
    }
}

void reverse2(struct Array *arr){
    int i,j,temp;

    for(i=0,j=arr->length-1;i<j;i++,j--){
        temp=arr->A[i];
        arr->A[i]=arr->A[j];
        arr->A[j]=temp;

    }

}
void inserstion(struct Array *arr,int x){
    int i=arr->length-1;
    if(arr->length==arr->size)
        return;
    while(arr->A[i]>x && i>=0){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

int sorted(struct Array arr){
    int i;
    for(i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1]){
            return 1;
        }
        else
        {
            return 0;
        }
        
    }
}

void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void rearr(struct Array *arr){
    int i=0;
    int j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0)i++;
        while(arr->A[i]>=0)j--;
        if(i<j){
            swap(&arr->A[i],&arr->A[j]);
        }
    }
}


int main(int argc, char const *argv[])
{
    struct Array arr={{2,-3,25,10,-15,-7},10,6};
    // reverse2(&arr);
    // inserstion(&arr,20);
    // printf("%d",sorted(arr));
    rearr(&arr);
    display(arr);
    
    return 0;
}
