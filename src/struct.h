#ifndef STRUCT_H
#define STRUCT_H

#define GAMMA 1.4

#define FLOAT double
typedef struct grid_str
{
  FLOAT L_x;
  FLOAT L_y;
  FLOAT L_z;
  int N_x;
  int N_y;
  int N_z;
  int N_cells;
  FLOAT *p;
  FLOAT *rho;
  FLOAT *vx;
  FLOAT *vy;
  FLOAT *vz;
} grid;

#endif
