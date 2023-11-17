#include "wordle.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // Test 1
  test_me(0);

  // NOTE: Comment this out when you're ready to test your game!
  wordle_game();

  // If the test passes, print a success message
  printf("Test passed!\n");

  return 0;
}
