#include <stdio.h>

#include "utils.h"


int factorial(int N) {
    int product = 1;
    for (int j = 1; j <= N; j++)
        product *= j;
    return product;
}

void redWhite(uint8_t secret[], uint8_t state[], int *red, int *white){
  *red = 0;
  *white = 0;

  for(int i = 0; i < PIN_AMOUNT; i++) {
    for(int j = 0; j < PIN_AMOUNT; j++) {
      // if colors are the same, add 1 to red count
      if(secret[i] == state[j]) {
        (*red)++;
        // if positions are the same, add 1 to white count  
        if(i == j) {
          (*white)++;
        }
        break;
      }
    }
  }
}

void generatePool(struct state *pool){

}

void printState(uint8_t state[]){
  const char* colors[] = {BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT, HBLK, HRED, HGRN, HYEL, HBLU, HMAG, HCYN, HWHT};
  const int numColors = sizeof(colors) / sizeof(colors[0]);
  for(int i=0; i < PIN_AMOUNT; i++){
    //print a dot
    //printf("%s" DOT CRESET, colors[3]);
    //print a debug integer
    printf(" %s%d" CRESET, colors[i+1], state[i]);
  }
  printf(" \n");
}

void printRedWhite(int red, int white) {
  printf("Red: %d\n", red);
  printf("White: %d\n", white);
}

void debugPrintState(uint8_t state[], int red, int white) {
  printf("---------\n");
  printState(state);
  printRedWhite(red, white);
}

/*
* test suite globals
*/
char failed_assert_descr[MAX_FAIL][MAX_TEST_NAME];
int test_count = 0;
int test_fail = 0;

void assert_true(char *name, bool test){
  if(!test){
    //save the test name if there is enough space
    if(test_fail < MAX_FAIL){
      strncpy(failed_assert_descr[test_fail], name, MAX_TEST_NAME-1);
    }
    test_fail++;
  }
  test_count++;
}
void assert_false(char *name, bool test){
  assert_true(name, !test);
}

void print_test_results(){
  printf("==== FAILING =====\n");
  for(int i=0; i< MAX_FAIL; i++){
    if(strlen(failed_assert_descr[i]) == 0)
      break;
    printf("%s... FAILED\n", failed_assert_descr[i]);
  }
  if(test_fail > MAX_FAIL){
    printf("%d more FAILED (not enough space to store their name)\n", test_fail - MAX_FAIL);
  }
  printf("==================\n");
  printf("%d/%d passed\n", test_count-test_fail, test_count);
}


/*
* test suite globals
*/
char failed_assert_descr[MAX_FAIL][MAX_TEST_NAME];
int test_count = 0;
int test_fail = 0;

void assert_true(char *name, bool test){
  if(!test){
    //save the test name if there is enough space
    if(test_fail < MAX_FAIL){
      strncpy(failed_assert_descr[test_fail], name, MAX_TEST_NAME-1);
    }
    test_fail++;
  }
  test_count++;
}
void assert_false(char *name, bool test){
  assert_true(name, !test);
}

void print_test_results(){
  printf("==== FAILING =====\n");
  for(int i=0; i< MAX_FAIL; i++){
    if(strlen(failed_assert_descr[i]) == 0)
      break;
    printf("%s... FAILED\n", failed_assert_descr[i]);
  }
  if(test_fail > MAX_FAIL){
    printf("%d more FAILED (not enough space to store their name)\n", test_fail - MAX_FAIL);
  }
  printf("==================\n");
  printf("%d/%d passed\n", test_count-test_fail, test_count);
}

