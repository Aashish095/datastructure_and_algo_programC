#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n1 = 6; 
    int A[] = {1, 5, 10, 20, 40, 80};
    int n2 = 5; 
    int B[] = {6, 7, 20, 80, 100};
    int n3 = 8; 
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};

    int  i=0,j=0,k=0;
            while(i<n1){
                if(A[i]<B[j]){
                    i++;
                }
                if(A[i]>B[j]){
                    j++;
                }
                if(A[i]==B[j]){
                    if(B[j]>C[k]){
                        k++;
                    }
                    else if(B[j]==C[k]){
                        printf("%d ",C[k]);
                        i++;j++;k++;
                    }
                }
            }
    return 0;
}
