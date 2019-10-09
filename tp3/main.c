#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include "tas.h"




int main(int argc, char ** argv){

  // Tas .
  tasbinaire_t * t = tasbinaire_create();

  tas_push(t,5);
  tas_push(t,8);
  tas_push(t,10);
  tas_push(t,3);
  tas_push(t,1);




  return EXIT_SUCCESS;
}
