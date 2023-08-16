#include <stdio.h>

#include "utils.h"

int main(){
  printf(RED DOT GRN DOT CYN DOT CRESET);
  printf("\nMastermind \ninitial states: %d\n", POOL_SIZE);

  uint8_t secret[] = {0,1,2,3};

  printState(secret);

  struct state *states_pool = (struct state*)calloc(POOL_SIZE, sizeof(struct state));
  if(states_pool == NULL){
    printf("failed to allocate memory for the states pool\n");
    return 0;
  }
  printf("pool space allocated\n");

  generatePool(states_pool);

  printf("pool generated\n");

  return 0;
}

