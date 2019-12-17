


#include <stddef.h>





/**
tas binomial
**/

struct node {

    int n;

    int degree;

    struct node* parent;

    struct node* child;

    struct node* sibling;

}node_s;

void entasser_bas_haus(tasbinaire_t *h,int index);
tasbinaire_t * tasbinaire_create();
void insert(tasbinaire_t *h, int valeur);
void entasser_haus_bas(tasbinaire_t *h, int parent_node);
int Extract_Min(tasbinaire_t *h);


tasbinaire_t * show( tasbinaire_t *h );
void tas_destroy(tasbinaire_t * h);








//void heap_pop(tasbinaire_t * h);
