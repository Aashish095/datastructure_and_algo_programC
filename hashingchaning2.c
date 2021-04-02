#include<stdio.h>
#include "chains.h"

int hash(int key){
    return key%10;
}

void insert(struct node *h[],int key){
    int index = hash(key);
    sortedinsert(&h[index],key);

} 

int main(){
    struct node *ht[10];
    struct node *temp;
    int i;

    for(i=0;i<10;i++){
        ht[i]=NULL;
    }
    insert(ht,12);
    insert(ht,22);
    insert(ht,42);

    temp = search(ht[hash(21)],21);
    printf("%d ",temp->data);

    return 0;

}