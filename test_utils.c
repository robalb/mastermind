#include <stdio.h>

#include "utils.h"

void test_redWhite() {
    uint8_t states[][PIN_AMOUNT] = {
        {0,1,2,3}, {0,1,2,3},
        {0,1,2,3}, {4,5,6,7},
        {0,1,2,3}, {2,1,0,3},
        {0,1,2,3}, {1,2,3,0}
    };
    int red;
    int white;

    // exact same states
    redWhite(states[0], states[1], &red, &white);
    assert_true("Exact same", red == 4 && white == 4);
    
    // only the fist one
    redWhite(states[2], states[3], &red, &white);
    assert_true("All different", red == 0 && white == 0);

    // two equals, two different
    redWhite(states[4], states[5], &red, &white);
    assert_true("Pairs", red == 4 && white == 2);

    // all colors, no positions
    redWhite(states[6], states[7], &red, &white);
    assert_true("all colors, no positions", red == 4 && white == 0);
}

int main() {
    test_redWhite();
    print_test_results();
    return 0;
}


