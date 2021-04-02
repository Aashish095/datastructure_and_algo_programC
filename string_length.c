#include<stdio.h>
int main(int argc, char const *argv[])
{
    char *s="welcome to the news  of the ashish   challen";
    int i,word=0,vcount=0,ccount=0;
    // for(i=0;s[i]!='\0';i++){
    //     if(s[i]==' ' && s[i-1]!=' ')
    //         word++;
    // }
    // printf("total word %d ",word+1);


    //find vowel and consonents
    for(i=0;s[i]!='\0';i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            vcount++;
        }
        else if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
            ccount++;
        }
    }
    printf("vowel=%d",vcount);
    printf("consonents=%d",ccount);

    
    return 0;
}
