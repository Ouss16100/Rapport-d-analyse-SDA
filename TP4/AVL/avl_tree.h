#define _XOPEN_SOURCE 500


struct Node 
{ 
    int key; 
    struct Node *left; 
    struct Node *right; 
    int height; 
    int capacity;
    int count;
}; 

int max(int a, int b);
int height(struct Node *N);
struct Node* newNode(int key) ;
struct Node *rightRotate(struct Node *y) ;
struct Node *leftRotate(struct Node *x) ;
int getBalance(struct Node *N);
struct Node* insert(struct Node* node, int key);
struct Node * minValueNode(struct Node* node);
struct Node* deleteNode(struct Node* root, int key);
void preOrder(struct Node *root) ;
