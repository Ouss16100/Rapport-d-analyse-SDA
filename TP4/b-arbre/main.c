#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<time.h>
#include "barbre.h"
#include "analyzer.h"



int main(int argc, char ** argv){
  int i;
  // b arbre
  btree_t *B;
  B = create_btree();
  node_t *t;
  // Analyse du temps pris par les opérations.
  analyzer_t * time_analysis = analyzer_create();
  // Analyse de l'espace mémoire inutilisé.
  analyzer_t * memory_analysis = analyzer_create(); 
  // Mesure de la durée d'une opération.
  struct timespec before, after;
  clockid_t clk_id = CLOCK_REALTIME;
  // utilisé comme booléen pour savoir si une allocation a été effectuée.
  char memory_allocation; 

for(i = 0; i < 1000000  ; i++){


    //Generer des cles aleatoire entre 1 et 1000000
    //int r = rand()%1000000;
    //float p = rand()/(float)RAND_MAX ;
    //float k = 0.5;
    // Ajout d'un élément et mesure du temps pris par l'opération.
    
    clock_gettime(clk_id, &before);
    t = insert(i,B);
    clock_gettime(clk_id, &after);

    // Enregistrement du temps pris par l'opération
   analyzer_append(time_analysis, after.tv_nsec - before.tv_nsec);
    // Enregistrement du nombre de copies efféctuées par l'opération.
    // S'il y a eu réallocation de mémoire, il a fallu recopier tout le tableau.
   //analyzer_append(copy_analysis, (memory_allocation)? i:1 );
    // Enregistrement de l'espace mémoire non-utilisé.
   analyzer_append(memory_analysis,B->capacity - B->count);
   }
  // Affichage de quelques statistiques sur l'expérience.
  fprintf(stderr, "Total cost: %Lf\n", get_total_cost(time_analysis));
  fprintf(stderr, "Average cost: %Lf\n", get_average_cost(time_analysis));
  fprintf(stderr, "Variance: %Lf\n", get_variance(time_analysis));
  fprintf(stderr, "Standard deviation: %Lf\n", get_standard_deviation(time_analysis));

  // Sauvegarde les données de l'expérience.
  save_values(time_analysis, "plot/barbre_time_c.plot");
  save_values(memory_analysis, "plot/barbre_memory_c.plot");
    // Sauvegarde les données de l'expérience.


  // Nettoyage de la mémoire avant la sortie du programme
  analyzer_destroy(time_analysis);
  analyzer_destroy(memory_analysis);

  return EXIT_SUCCESS;
}
