#include<stdio.h>
int main(int argc, char const *argv[])
{
  int i,hash[12]={0};
  int a[10]={3,7,4,9,12,6,1,11,2,10};
  for(i=0;i<10;i++){
      hash[a[i]]++;
  }
  for(i=1;i<=12;i++){
      if(hash[i]==0)
        printf("%d",i);
        printf(" ");
  }
    
}
    