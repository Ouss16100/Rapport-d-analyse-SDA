#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> 



struct node {

    int n;

    int degree;

    struct node* parent;

    struct node* child;

    struct node* sibling;

    int capacity;
   
    int count;

};



struct node* MAKE_bin_HEAP();

int bin_LINK(struct node*, struct node*);

struct node* CREATE_NODE(int);

struct node* bin_HEAP_UNION(struct node*, struct node*);

struct node* bin_HEAP_INSERT(struct node*, struct node*);

struct node* bin_HEAP_MERGE(struct node*, struct node*);

void bin_HEAP_EXTRACT_MIN(struct node*);

int REVERT_LIST(struct node* y);
