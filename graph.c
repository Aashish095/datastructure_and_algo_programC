#include<stdio.h>
#include "queuegraph.h"

void BFS(int g[][7],int start,int n)
{
   int i=start,j;
   int visited[7]={0};
   
   printf("%d ",i);
   visited[i]=1;
   enqueue(i);
   while(!isEmpty()){
       i=dequeue();
       for(j=1;j<n;j++)
       {
           if(g[i][j]==1 && visited[j]==0)
           {
               printf("%d ",j);
               visited[j]=1;
                enqueue(j);
           }
       }
   }
}

void DFS(int g[][7],int start,int n)
{
    static int visited[7]={0};
    int j;
    if(visited[start]==0)
    {
        printf("%d ",start);
        visited[start]=1;
        for(j=1;j<n;j++)
        {
            if(g[start][j]==1 && visited[j]==0)
            {
                DFS(g,j,n);
            }
        }  
    }
}

int main(){
    int g[7][7] = {{0,0,0,0,0,0,0},
                   {0,0,1,1,0,0,0},                        
                   {0,1,0,0,1,0,0},                        
                   {0,1,0,0,1,0,0},                         
                   {0,0,1,1,0,1,1},
                   {0,0,0,0,1,0,0},
                   {0,0,0,0,1,0,0}};
    DFS(g,4,7);
    return 0;
} 