#include <stdio.h>
#include "struct.h"
#include "init.h"
#include "io.h"


int main(int argc, char **argv){
  physics_grid state;
  
  init_problem(&state, SEDOV);
  print_L(&state);
  
  return 0;
}
