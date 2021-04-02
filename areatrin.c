#include<stdio.h>
int main(int argc, char const *argv[])
{
    int b1,h1,b2,h2;
    double t1,t2;
    scanf("%d %d\n",&b1,&h1);
    scanf("%d %d",&b2,&h2);
    t1=(h1*b1)/2;
    t2=(h2*b2)/2;
    if(t1>t2)
        printf("%f",t1);
    else
        printf("%f",t2);
 
    return 0;
}
