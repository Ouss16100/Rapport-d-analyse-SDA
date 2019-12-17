


#include <stddef.h>





/**
tas binaire
**/

typedef struct tasbinaire_s {
        // Capacity du stockage
        unsigned int capacity;
        // Taille de la mémoire alloué ou le nombre d'élément
        unsigned int count;
        // Pointeur vers
        int *data;



}tasbinaire_t;

void entasser_bas_haus(tasbinaire_t *h,int index);
tasbinaire_t * tasbinaire_create();
void insert(tasbinaire_t *h, int valeur);
void entasser_haus_bas(tasbinaire_t *h, int parent_node);
int Extract_Min(tasbinaire_t *h);


tasbinaire_t * show( tasbinaire_t *h );
void tas_destroy(tasbinaire_t * h);








//void heap_pop(tasbinaire_t * h);
