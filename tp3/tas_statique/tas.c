#include<stdio.h>
#include<stdlib.h>
#include "tas.h"


#define COMPARE(a, b) ((a) <= (b))

static const unsigned int base_capacity = 1000000;





tasbinaire_t * tasbinaire_create(){

  tasbinaire_t * tas = (tasbinaire_t *) malloc( sizeof(tasbinaire_t) );

  tas->data =  malloc( sizeof(int) * base_capacity );

  tas->capacity = base_capacity;

  tas->count = 0;

  return tas;

}

void entasser_bas_haus(tasbinaire_t *h,int index){
    int temp;
    int parent_node = index/2;

    if(h->data[parent_node] > h->data[index]){
        //echanger et appel recurssive
        temp = h->data[parent_node];
        h->data[parent_node] = h->data[index];
        h->data[index] = temp;
        entasser_bas_haus(h,parent_node);
    }
}


void insert(tasbinaire_t *h, int valeur){
        if( h->count < h->capacity){
                h->data[h->count] = valeur;
                entasser_bas_haus(h, h->count);
                h->count++;

            }
        else{

                printf("Erreur: tas plein\n");
                exit(0);
        }
        
}
tasbinaire_t * show( tasbinaire_t *h ){

        unsigned int i;
        for(i=0; i <= h->count -1 ; i++){
                printf("[%d]",h->data[i]);
        }
        printf("\n");

}







void entasser_haus_bas(tasbinaire_t *h, int parent_node){
    int left = parent_node*2+1;
    int right = parent_node*2+2;
    int min;
    int temp;

    if(left >= h->count || left <0)
        left = -1;
    if(right >= h->count || right <0)
        right = -1;

    if(left != -1 && h->data[left] < h->data[parent_node])
        min=left;
    else
        min =parent_node;
    if(right != -1 && h->data[right] < h->data[min])
        min = right;

    if(min != parent_node){
        temp = h->data[min];
        h->data[min] = h->data[parent_node];
        h->data[parent_node] = temp;

        // appel recurssive
        entasser_haus_bas(h, min);
    }
}



int Extract_Min(tasbinaire_t *h){
    int pop;
    if(h->count==0){
        printf("\n__Tas est vide__\n");
        return -1;
    }
// remplacer le premier node pars le dernier est suprimmer le dernier
    pop = h->data[0];
    h->data[0] = h->data[h->count-1];
    h->count--;
    entasser_haus_bas(h, 0);
    return pop;
}

void tas_destroy(tasbinaire_t * h){
  if( h != NULL ){
    if( h->data != NULL )
      free( h->data );
    free( h );
  }
}



/*void tas_push(tasbinaire_t *h, int valeur)
{
	unsigned int i, parent;

	if( h->size == h->capacity){

                printf("Erreur: tas plein\n");
                exit(0);
        }
  else{
       	// Trouver ou ajouter l'élément
	for(i = h->size++; i ; i= parent)
	{
                // Parent(i) = (i-1)/2
                parent = (i - 1)/ 2;

		if COMPARE(h->data[parent], valeur) break; // if( h->data[parent]  <= valeur)

		h->data[i] = h->data[parent];
	}
	h->data[i] = valeur;
    }
} 


// Supprimer l'élement le plus petit
void heap_pop(tasbinaire_t * h)
{
	unsigned int index, swap, other;
	int temp = h->data[--h->size];
	// Reordoner
	for(index = 0; 1; index = swap)
	{

		swap = (index*2 ) + 1;
		if (swap >= h->size) break; 
		other = swap + 1;
		if ((other < h->size) && COMPARE(h->data[other], h->data[swap])) swap = other;
		if COMPARE(temp, h->data[swap]) break; 
		h->data[index] = h->data[swap];
	}
	h->data[index] = temp;
}

*/










