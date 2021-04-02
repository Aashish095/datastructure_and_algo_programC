#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *lchild;
    int height;
    int data;
    struct node *rchild;
}*root=NULL;

int nodeheight(struct node *p){
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->lchild->height:0;
    return hl>hr?hl+1:hr+1;
}

int balancefector(struct node *p){
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    return hl-hr;
}

struct node *LLrotation(struct node *p){
    struct node *pl=p->lchild;
    struct node *plr=pl->lchild;

    pl->lchild=p;
    p->rchild=plr;

    p->height=nodeheight(p);
    pl->height=nodeheight(pl);
    if(root==p){
        root=pl;
    }
    return pl;
}

struct node *LRrotation(struct node *p){
    struct node *pl=p->lchild;
    struct node *plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;

    p->height=nodeheight(p);
    pl->height=nodeheight(pl);
    plr->height=nodeheight(plr);
    if(root==p)
        root=plr;
    return plr;
}

struct node *RRrotation(struct node *p){
    struct node *pr=p->rchild;
    struct node *prl=pr->lchild;

    pr->lchild=p;
    p->rchild=prl;

    p->height=nodeheight(p);
    pr->height=nodeheight(pr);
    if(root==p)
        root=pr;
    return pr;
}

struct node *RLrotation(struct node *p){
    struct node *pr=p->rchild;
    struct node* prl=p->lchild;

    p->rchild=prl->lchild;
    pr->lchild=prl->rchild;
    prl->lchild=pr;
    prl->rchild=p;

    p->height=nodeheight(p);
    pr->height=nodeheight(pr);
    prl->height=nodeheight(prl);
    if(root==p)
        root=prl;
    return prl;
}

struct node *insert(struct node *p,int key){
    struct node *t=NULL;
    if(p==NULL){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        root=t;
        return t;
    }
    if(key<p->data)
        p->lchild=insert(p->lchild,key);
    else if(key>p->data)
        p->rchild=insert(p->rchild,key);
    p->height=nodeheight(p);
    if(balancefector(p)==2 && balancefector(p->lchild)==1)
        return LLrotation(p);
    else if(balancefector(p)==2 && balancefector(p->lchild)==-1)
        return LRrotation(p);
    else if(balancefector(p)==-2 && balancefector(p->rchild)==-1)
        return RRrotation(p);
    else if(balancefector(p)==-2 && balancefector(p->rchild)==1)
        return RLrotation(p);
    return p;
}

void inorder(struct node *p){
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
    
}

int main(){
    insert(root,50);
    insert(root,10);
    insert(root,5);
    inorder(root);
    return 0;
}
