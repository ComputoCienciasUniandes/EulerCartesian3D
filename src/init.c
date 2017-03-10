#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

void init_problem(physics_grid *state, int problem){
  if(problem==SEDOV){
    state->L_x = 250.0;
    state->L_y = 250.0;
    state->L_z = 250.0;    
    state->delta_x = 5.0;
    state->delta_y = 5.0;
    state->delta_z = 5.0;
    state->N_x = (int)(state->L_x/state->delta_x);
    state->N_y = (int)(state->L_y/state->delta_y);
    state->N_z = (int)(state->L_z/state->delta_z);
    state->N_cells = state->N_x * state->N_y & state->N_z;

    if(!(state->p=malloc(state->N_cells * sizeof(FLOAT)))){
      fprintf(stderr, "Problem with pressure allocation");
      exit(1);
    }

    if(!(state->rho=malloc(state->N_cells * sizeof(FLOAT)))){
      fprintf(stderr, "Problem with pressure allocation");
      exit(1);
    }
    
    if(!(state->vx=malloc(state->N_cells * sizeof(FLOAT)))){
      fprintf(stderr, "Problem with vx allocation");
      exit(1);
    }
    
    if(!(state->vy=malloc(state->N_cells * sizeof(FLOAT)))){
      fprintf(stderr, "Problem with vy allocation");
      exit(1);
    }

    if(!(state->vz=malloc(state->N_cells * sizeof(FLOAT)))){
      fprintf(stderr, "Problem with vz allocation");
      exit(1);
    }    
   
  }
}
