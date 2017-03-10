#include <stdio.h>
#include "struct.h"
#include "init.h"
#include "io.h"


int main(int argc, char **argv){
  physics_grid P_state;
  U_grid U_state;
  F_grid F_state;
  
  init_problem(&P_state, &U_state, &F_state, SEDOV);
  print_L(&P_state);
  
  return 0;
}
