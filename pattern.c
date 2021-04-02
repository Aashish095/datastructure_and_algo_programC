#include<stdio.h>

int main()
{
    int i,j,n;
    printf("enter number ");
    scanf("%d",&n);

    // for(i=0;i<n;i++){
    //     for(j=0;j<n;j++){
    //         if(i>=j){
    //             printf("* ");
    //         }

    //     }
    //     printf("\n");
        
    // }

    // for(i=1;i<=n;i++){
    //     for(j=1;j<=n;j++){
    //         if(i+j<=n+1){
    //             printf("* ");
    //         }

    //     }
    //     printf("\n");
        
    // }

    // for(i=1;i<=n;i++){
    //     for(j=1;j<=n;j++){
    //         if(i+j<=n+1){
    //             printf("* ");
    //         }
    //     }
    //     printf("\n");
    // }

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i+j>n+1){
                printf(" ");
            }
            else{
                printf("#");
            }
        }
        printf("\n");
    }

    return 0;
}
