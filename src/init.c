#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

void init_to_zero(FLOAT *p, int n_points){
  int i;
  for(i=0;i<n_points;i++){
    p[i] = 0.0;
  }
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
  P->N_cells = P->N_x * P->N_y & P->N_z;
  
  U->N_x = P->N_x;
  U->N_y = P->N_y;
  U->N_z = P->N_z;
  U->N_cells = P->N_cells;
  
  F->N_x = P->N_x;
  F->N_y = P->N_y;
  F->N_z = P->N_z;
  F->N_cells = P->N_cells;
  
  if(!(P->p=malloc(P->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with pressure allocation");
    exit(1);
  }
  init_to_zero(P->p, P->N_cells);
  
  if(!(P->rho=malloc(P->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with pressure allocation");
    exit(1);
  }
  init_to_zero(P->rho, P->N_cells);
  
  if(!(P->vx=malloc(P->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with vx allocation");
    exit(1);
  }
  init_to_zero(P->vx, P->N_cells);
  
  if(!(P->vy=malloc(P->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with vy allocation");
    exit(1);
  }
  init_to_zero(P->vy, P->N_cells);
  
  if(!(P->vz=malloc(P->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with vz allocation");
    exit(1);
  }    
  init_to_zero(P->vz, P->N_cells);
  
  if(!(U->U_1=malloc(U->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with U_1 allocation");
    exit(1);
  }
  init_to_zero(U->U_1, U->N_cells);
  
  if(!(U->U_2=malloc(U->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with U_2 allocation");
    exit(1);
  }
  init_to_zero(U->U_2, U->N_cells);
  
  if(!(U->U_3=malloc(U->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with U_2 allocation");
    exit(1);
  }
  init_to_zero(U->U_3, U->N_cells);
  
  if(!(U->U_4=malloc(U->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with U_2 allocation");
    exit(1);
  }
  init_to_zero(U->U_4, U->N_cells);
  
  if(!(U->U_5=malloc(U->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with U_2 allocation");
    exit(1);
  }
  init_to_zero(U->U_5, U->N_cells);
  
  if(!(F->F_1_X=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_1_X allocation");
    exit(1);
  }
  init_to_zero(F->F_1_X, F->N_cells);
  
  if(!(F->F_2_X=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_2_X allocation");
    exit(1);
  }
  init_to_zero(F->F_2_X, F->N_cells);
  
  if(!(F->F_3_X=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_3_X allocation");
    exit(1);
  }
  init_to_zero(F->F_3_X, F->N_cells);
  
  if(!(F->F_4_X=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_4_X allocation");
    exit(1);
  }
  init_to_zero(F->F_4_X, F->N_cells);
  
  if(!(F->F_5_X=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_5_X allocation");
    exit(1);
  }
  init_to_zero(F->F_5_X, F->N_cells);
  
  if(!(F->F_1_Y=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_1_Y allocation");
    exit(1);
  }
  init_to_zero(F->F_1_Y, F->N_cells);
  
  if(!(F->F_2_Y=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_2_Y allocation");
    exit(1);
  }
  init_to_zero(F->F_2_Y, F->N_cells);
  
  if(!(F->F_3_Y=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_3_Y allocation");
    exit(1);
  }
  init_to_zero(F->F_3_Y, F->N_cells);
  
  if(!(F->F_4_Y=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_4_Y allocation");
    exit(1);
  }
  init_to_zero(F->F_4_Y, F->N_cells);
  
  if(!(F->F_5_Y=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_5_Y allocation");
    exit(1);
  }
  init_to_zero(F->F_5_Y, F->N_cells);
  
  if(!(F->F_1_Z=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_1_Z allocation");
    exit(1);
  }
  init_to_zero(F->F_1_Z, F->N_cells);
  
  if(!(F->F_2_Z=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_2_Z allocation");
    exit(1);
  }
  init_to_zero(F->F_2_Z, F->N_cells);
  
  if(!(F->F_3_Z=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_3_Z allocation");
    exit(1);
  }
  init_to_zero(F->F_3_Z, F->N_cells);
  
  if(!(F->F_4_Z=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_4_Z allocation");
    exit(1);
  }
  init_to_zero(F->F_4_Z, F->N_cells);
  
  if(!(F->F_5_Z=malloc(F->N_cells * sizeof(FLOAT)))){
    fprintf(stderr, "Problem with F_5_Z allocation");
    exit(1);
  }
  init_to_zero(F->F_5_Z, F->N_cells);
}
