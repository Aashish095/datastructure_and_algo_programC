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

int get(struct Array arr,int index){
    if(index>=0 && index<=arr.lenght)
        return arr.A[index];
    return -1;
}
int set(struct Array *arr,int index,int x){
    if(index>=0 &&index<=arr->lenght)
        return arr->A[index]=x;
}
int max(struct Array arr){
    int i,max=arr.A[0];
    for(i=1;i<arr.lenght;i++){
        if(arr.A[i]>max){
            max=arr.A[i];
        }
    

    }
    return max;
}
int min(struct Array arr){
    int i,min=arr.A[0];

    for(i=1;i<arr.lenght;i++){
        if(arr.A[i]<min){
            min=arr.A[i];
        }
    return min;
        
    }
    return min;
}

int sum(struct Array arr){
    int s=0;
    int i;
    for(i=0;i<arr.lenght;i++)
        s+=arr.A[i];
    return s;
    
}

int avg(struct Array arr){
    return sum(arr)/arr.lenght;    

}
  
int main(int argc, char const *argv[])
{
    struct Array arr ={{2,3,4,5,6},20,5};
    printf("%dget is\n",get(arr,5));
    printf("%dset is\n",set(&arr,3,8));
    printf("%dmax is\n",max(arr));
    printf("%dmin is\n",min(arr));
    printf("%dsum is\n",sum(arr));
    printf("%davg is\n",avg(arr));
    Display(arr);

    
    return 0;
}