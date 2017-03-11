#ifndef STRUCT_H
#define STRUCT_H

#define GAMMA 1.4

#define SEDOV 1
#define NDIM 3

#define PRESSURE 0 
#define RHO 1
#define VX 2
#define VY 3
#define VZ 4

#define FLOAT double
typedef struct physics_grid_str
{
  FLOAT L_x;
  FLOAT L_y;
  FLOAT L_z;
  FLOAT delta_x;
  FLOAT delta_y;
  FLOAT delta_z;
  int N_x;
  int N_y;
  int N_z;
  int N_cells;
  FLOAT *P;
} physics_grid;

typedef struct U_grid_str{
  int N_x;
  int N_y;
  int N_z;
  int N_cells;
  FLOAT *U;
} U_grid;


typedef struct F_grid_str{
  int N_x;
  int N_y;
  int N_z;
  int N_cells;
  FLOAT *F;
} F_grid;


#endif
