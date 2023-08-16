#include <stdio.h>

#include "utils.h"

int main(){
  printf(RED DOT GRN DOT CYN DOT CRESET);
  printf("\nMastermind \ninitial states: %d\n", INITIAL_STATES);

  uint8_t secret[] = {0,1,2,3};
  printState(secret);
  return 0;
}

