#include<stdio.h>
#include<stdlib.h>

struct Array {
    int A[10];
    int size;
    int lenght;

};
void Display(struct Array arr){
    int i;
    printf("elements are\n");
    for(i=0;i<arr.lenght;i++)
        printf("%d\n",arr.A[i]);
}
int swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int linearsearch(struct Array arr,int key){
    int i;
    for(i=0;i<arr.lenght;i++){
        if(key == arr.A[i])
            return i;
    }
    return -1;
}
int linear2(struct Array *arr,int key){
    int i;
    for(i=0;i<arr->lenght;i++){
        if(key==arr->A[i]){
            swap(&arr->A[i],&arr->A[i+1]);
            return i;
        }

    }
    return -1;
}
int binary(struct Array arr,int key){
    int l,h,mid;
    l=0;
    h=arr.lenght-1;
    while(l<=h){
        mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
}
int Rbin(int a[],int l,int h,int key){
    int mid;
    while (l<=h)
    {
        mid=(l+h)/2;
        if (key==a[mid])
        {
            return mid;
        }
        else if(key<a[mid])
            return Rbin(a,l,mid-1,key);
        else
            return Rbin(a,mid+1,h,key);
        
    }
    
}


int main(int argc, char const *argv[])
{
    struct Array arr ={{2,3,4,5,6},20,5};
    // printf("%d\n",linearsearch(arr,5));
    // printf("%d\n",linear2(&arr,5));
    // printf("%d\n",binary(arr,2));
    printf("%d\n",Rbin(arr.A,0,arr.lenght,2));

    Display(arr);

    
    return 0;
}
