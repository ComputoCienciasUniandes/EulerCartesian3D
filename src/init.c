#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

void init_to_zero(FLOAT *p, int n_points){
  int i;
  for(i=0;i<n_points;i++){
    p[i] = 0.0;
  }
}


physics_grid * create_physics_grid(void){
  physics_grid *G;
  if(!(G = malloc(sizeof(physics_grid)))){
    fprintf(stderr, "Problem with data allocation\n");fflush(stdout);
    exit(0);
  } 
  
  G->L_x=0.0;
  G->L_y=0.0;
  G->L_z=0.0;
  G->delta_x=0.0;
  G->delta_y=0.0;
  G->delta_z=0.0;
  G->N_x=0;
  G->N_y=0;
  G->N_z=0;
  G->N_cells=0;
  G->P=NULL;
  return G;
}


U_grid * create_U_grid(void){
  U_grid *G;
  if(!(G = malloc(sizeof(U_grid)))){
    fprintf(stderr, "Problem with data allocation\n");fflush(stdout);
    exit(0);
  } 
  G->N_x=0.0;
  G->N_y=0.0;
  G->N_z=0.0;
  G->N_cells=0.0;
  G->U=NULL;
  return G;
}

F_grid * create_F_grid(void){
  F_grid *G;
  if(!(G = malloc(sizeof(F_grid)))){
    fprintf(stderr, "Problem with data allocation\n");fflush(stdout);
    exit(0);
  } 
  G->N_x=0.0;
  G->N_y=0.0;
  G->N_z=0.0;
  G->N_cells=0.0;
  G->F=NULL;
  return G;
}


void init_problem(physics_grid *P, U_grid *U, F_grid *F, int problem){
  
  P->L_x = 250.0;
  P->L_y = 250.0;
  P->L_z = 250.0;    
  P->delta_x = 5.0;
  P->delta_y = 5.0;
  P->delta_z = 5.0;
  P->N_x = (int)(P->L_x/P->delta_x);
  P->N_y = (int)(P->L_y/P->delta_y);
  P->N_z = (int)(P->L_z/P->delta_z);
  P->N_cells = P->N_x * P->N_y * P->N_z;
  
  U->N_x = P->N_x;
  U->N_y = P->N_y;
  U->N_z = P->N_z;
  U->N_cells = P->N_cells;
  
  F->N_x = P->N_x;
  F->N_y = P->N_y;
  F->N_z = P->N_z;
  F->N_cells = P->N_cells;
  
  if(!(P->P = malloc(P->N_cells * (NDIM +2) * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with pressure allocation");
    exit(1);
  }
  init_to_zero(P->P, P->N_cells * (NDIM +2));
  
  if(!(U->U = malloc(U->N_cells * (NDIM +2) * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with U_1 allocation");
    exit(1);
  }
  init_to_zero(U->U, U->N_cells * (NDIM +2));
  
  if(!(F->F = malloc(F->N_cells * (NDIM) * (NDIM + 2) * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F allocation");
    exit(1);
  }
  init_to_zero(F->F, F->N_cells * NDIM * (NDIM +2));
}
