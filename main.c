#include <stdio.h>

#include "utils.h"

int main(){
  //welcome
  printf(RED DOT GRN DOT CYN DOT CRESET);
  printf("\nMastermind \ninitial states: %d\n", POOL_SIZE);

  //hardcoded secret
  uint8_t secret[] = {0,1,2,3};
  printState(secret);

  //pool init
  struct state *states_pool = (struct state*)calloc(POOL_SIZE, sizeof(struct state));
  if(states_pool == NULL){
    printf("failed to allocate memory for the states pool\n");
    return 0;
  }
  printf("pool space allocated\n");
  generatePool(states_pool);
  printf("pool generated\n");

  //iterate solutions
  

  //free and quit
  free(states_pool);
  return 0;
}

