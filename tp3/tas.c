#include<stdio.h>
#include<stdlib.h>
#include "tas.h"


#define COMPARE(a, b) ((a) >= (b))

static const unsigned int base_capacity = 5;





tasbinaire_t * tasbinaire_create(){

  tasbinaire_t * tas = (tasbinaire_t *) malloc( sizeof(tasbinaire_t) );

  tas->data =  malloc( sizeof(int) * base_capacity );

  tas->capacity = base_capacity;

  tas->size = 0;

  return tas;

}



void tas_push(tasbinaire_t *h, int valeur)
{
	unsigned int i, parent;

	if( h->size == h->capacity){

                printf("Erreur: tas plein");
                exit(0);
        }
  else{
       	// Trouver ou ajouter l'élément
	for(i = h->size++; i ; i= parent)
	{
                // Parent(i) = (i-1)/2
                parent = (i - 1) >> 1;

		if COMPARE(h->data[parent], valeur) break; // if( h->data[parent] > = valeur)

		h->data[i] = h->data[parent];
	}
	h->data[i] = valeur;
    }
}
