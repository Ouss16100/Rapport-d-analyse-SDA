#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include "tas.h"
#include "analyzer.h"



int main(int argc, char ** argv){
  int i;
  // Tas Binaire
  tasbinaire_t * t = tasbinaire_create();

  // Analyse du temps pris par les opérations.
  analyzer_t * time_analysis = analyzer_create();
  // Analyse de l'espace mémoire inutilisé.
  analyzer_t * memory_analysis = analyzer_create(); 
  // Mesure de la durée d'une opération.
  struct timespec before, after;
  clockid_t clk_id = CLOCK_REALTIME;
  // utilisé comme booléen pour savoir si une allocation a été effectuée.
  char memory_allocation; 

for(i = 0; i < 1000000 ; i++){
    // Ajout d'un élément et mesure du temps pris par l'opération.
    clock_gettime(clk_id, &before);
    insert(t, i);
    clock_gettime(clk_id, &after);

    
    // Enregistrement du temps pris par l'opération
    analyzer_append(time_analysis, after.tv_nsec - before.tv_nsec);
    // Enregistrement du nombre de copies efféctuées par l'opération.
    // S'il y a eu réallocation de mémoire, il a fallu recopier tout le tableau.
   // analyzer_append(copy_analysis, (memory_allocation)? i:1 );
    // Enregistrement de l'espace mémoire non-utilisé.
    analyzer_append(memory_analysis,t->capacity - t->count);
   }
  // Affichage de quelques statistiques sur l'expérience.
  fprintf(stderr, "Total cost: %Lf\n", get_total_cost(time_analysis));
  fprintf(stderr, "Average cost: %Lf\n", get_average_cost(time_analysis));
  fprintf(stderr, "Variance: %Lf\n", get_variance(time_analysis));
  fprintf(stderr, "Standard deviation: %Lf\n", get_standard_deviation(time_analysis));

  // Sauvegarde les données de l'expérience.
  save_values(time_analysis, "plot/tas_time_c.plot");
  save_values(memory_analysis, "plot/tas_memory_c.plot");
    // Sauvegarde les données de l'expérience.


  // Nettoyage de la mémoire avant la sortie du programme
  tas_destroy(t);
  analyzer_destroy(time_analysis);
  analyzer_destroy(memory_analysis);

  return EXIT_SUCCESS;
}
