
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int i,j,n,a[20]={8,3,6,4,6,5,6,8,2,7};

    for(i=0;i<9;i++){
        n=1;
        if(a[i]!= -1){
            for(j=i+1;j<10;j++){
                if(a[i]==a[j]){
                    n++;
                    a[j]=-1;

            }

        }
        if(n>1)
            printf("%d %d",a[i],n);
        }
    }
    return 0;
}


