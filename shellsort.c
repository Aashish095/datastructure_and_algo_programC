#include<stdio.h>

void shellsort(int a[],int n){
    int gap,i,j,temp;

    for(gap=n/2;gap>=1;gap/2){
        for(i=gap;i<n;i++){
            temp=a[i];
            j=i-gap;
            while (j>=0 && a[j]>temp)
            {
                a[j+gap]=a[j];
                j=j-gap;
            }
            a[j+gap]=temp;
        }
    }
}