#include "struct.h"
#include <stdio.h>

void print_L(physics_grid *G){
  fprintf(stdout, "L_x = %f\n", G->L_x);  
  fprintf(stdout, "L_y = %f\n", G->L_y);
  fprintf(stdout, "L_z = %f\n", G->L_z); 
}
