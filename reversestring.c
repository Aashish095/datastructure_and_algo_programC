#include<stdio.h>
int main(){
    char s[]="python";
    char b[7];
    int i,j,l;
    // for(i=0;s[i]!='\0';i++){}
    // i=i-1;

    // for(j=0;i>=0;i--,j++){
    //     b[j]=s[i];
    // }
    
    // b[j]='\0';
    // printf("revser string is %s",b);
    for(i=0;s[i]!='\0';i++){
    }
    l=i-1;
    for(i=l;i>=0;i--){
        for(j=0;j<=l;j++){
            s[i]=s[j];
        }
    }
    s[j]='\0';
    printf("revser string is %s",s);

    return 0;
}