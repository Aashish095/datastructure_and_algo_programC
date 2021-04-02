#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[20];
    int size;
    int length;

};
void Display(struct Array arr){
    int i;
    printf(" all elements \n");
    for(i=0;i<arr.length;i++)
        printf("%d\n",arr.A[i]);
}
void append(struct Array *arr,int x){
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
}

void insertion(struct Array *arr,int index,int x){
    int i;
    if(index>=0 && index<=arr->length){
        for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
        
    }
}

int delete(struct Array *arr,int index){
    int i,x=0;
    if(index>=0 && index<=arr->length){
        x=arr->A[index];
        for(i=index;i<=arr->length-1;i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
        return x;

    }
    return 0;
}
int main(int argc, char const *argv[])
{
    struct Array arr={{2,4,6,3,7},20,5};
    
    // append(&arr,8);
    // insertion(&arr,2,9);
    printf("%d\n",delete(&arr,3));
    Display(arr);
    /* code */
    return 0;
}
