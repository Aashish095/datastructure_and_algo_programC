#include<stdio.h>

int duplicate(int a[],int n){
    int h[26]={0};
    int count=0;
    for(int i;a[i]!='\0';i++){
        h[a[i]-'a']++;
    }
    for(i=0;i<26;i++){
        if(h[i]==1){
            count++;
        }
    }
    return count;
}
int main(){
    char A[]='alphaadida';
    int c=duplicate(a,10);
    printf("%d",c);
}