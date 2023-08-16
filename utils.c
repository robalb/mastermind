#include <stdio.h>

#include "utils.h"


int factorial(int N) {
    int product = 1;
    for (int j = 1; j <= N; j++)
        product *= j;
    return product;
}

void redGreen(uint8_t state[], int *red, int *green){
  
}

void printState(uint8_t state[]){
  const char* colors[] = {BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT, HBLK, HRED, HGRN, HYEL, HBLU, HMAG, HCYN, HWHT};
  const int numColors = sizeof(colors) / sizeof(colors[0]);
  for(int i=0; i < PIN_AMOUNT; i++){
    //print a dot
    //printf("%s" DOT CRESET, colors[3]);
    //print a debug integer
    printf(" %s%d" CRESET, colors[i+1], i);
  }
  printf(" \n");
}
