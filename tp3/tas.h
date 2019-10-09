


#include <stddef.h>





/**
tas binaire
**/

typedef struct tasbinaire_s {
        // Taille de la mémoire alloué ou le nombre d'élément
        unsigned int size;
        // Capacity du stockage
        unsigned int capacity;
        // Pointeur vers
        int *data;



}tasbinaire_t;


tasbinaire_t * tasbinaire_create();
void tas_push(tasbinaire_t *h, int valeur);
