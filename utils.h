#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

//max frogs in the game
#define PIN_AMOUNT 4
#define PIN_COLORS 8

#define POOL_SIZE (factorial(PIN_COLORS) / factorial(PIN_COLORS - PIN_AMOUNT) )

//dot symbol
#define DOT "\u25cf"

//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
//High intensty text
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"
//Reset
#define reset "\e[0m"
#define CRESET "\e[0m"
#define COLOR_RESET "\e[0m"

struct state {
  bool enabled;
  uint8_t pins[PIN_AMOUNT];
};


int factorial(int N);

/**
* red: number of correct colors
* white: number of correct positions
*/
void redWhite(uint8_t secret[], uint8_t state[], int *red, int *white);

/**
* Generates all the partial permutations of colors in pins
*/
void generatePool(struct state *pool);

void printState(uint8_t state[]);

void printRedWhite(int red, int white);

void debugPrintState(uint8_t state[], int red, int white);

/*
 * Homemade test framework
 */
#define MAX_FAIL 100
#define MAX_TEST_NAME 30
void assert_true(char *name, bool test);
void assert_false(char *name, bool test);
void print_test_results();

#endif
