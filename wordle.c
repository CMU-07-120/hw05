#include "contracts.h"
#include "wordlist.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test_me(int x) {
  REQUIRES(x > INT_MIN);
  int res = x < 0 ? -x : x;
  ENSURES(res >= 0);
  return res;
}

int wordle_game(void) {
  char g1[100] = "";
  char g2[100] = "";
  char g3[100] = "";
  char g4[100] = "";
  char g5[100] = "";
  char g6[100] = "";
  char r1[100] = "";
  char r2[100] = "";
  char r3[100] = "";
  char r4[100] = "";
  char r5[100] = "";
  char r6[100] = "";
  char *gs[6] = {g1, g2, g3, g4, g5, g6};
  char *rs[6] = {r1, r2, r3, r4, r5, r6};
  char lets[27] = "";
  int wi = -1;
  printf("Please enter a valid word number between 0 and %d\n", wl_len - 1);
  int r = scanf("%d", &wi);
  if (r != 1 || wi < 0 || wi >= wl_len) {
    printf("INVALID WORD NUMBER\n");
    exit(1);
  }
  char *sw = wl[wi];
  int ng = 0;
  while (1) {
    char *cw = gs[ng];
    printf("----------------------------------------------------\n");
    for (int i = 0; i < ng; ++i) {
      printf("  [%d] %s => %s\n", i + 1, gs[i], rs[i]);
    }
    for (int i = 0; i < 26; i++) {
      lets[i] = 'a' + i;
    }
    for (int i = 0; i < ng; i++) { // loop each guess
      int len_guess = strlen(gs[i]);
      int len = len_guess;
      for (int j = 0; j < len; j++) {
        if (rs[i][j] == '.') {
          lets[gs[i][j] - 'a'] = '.';
        } else {
          lets[gs[i][j] - 'a'] = gs[i][j] - 'a' + 'A';
        }
      }
    }
    lets[26] = '\0';
    printf("  %s\n", lets);
    printf("Enter your guess #%d:\n", ng + 1);
    r = scanf("%s", cw);
    if (r == EOF) {
      printf("Exiting (EOF detected)\n");
      exit(1);
    }
    if (strlen(cw) != 5) {
      printf("WRONG NUMBER OF LETTERS\n");
      continue;
    }
    int len = wl_len;
    int l = 0;
    int h = len - 1;
    int in_res = -1;
    while (l <= h) {
      int m = (l + h) / 2;
      int is_equal = strcmp(cw, wl[m]);
      if (is_equal == 0) {
        in_res = m;
        break;
      } else if (is_equal > 0) {
        l = m + 1;
      } else {
        h = m - 1;
      }
    }
    if (in_res == -1) {
      printf("WORD NOT IN DICTIONARY\n");
      continue;
    }
    int ln_sec = strlen(sw);
    int c_sec[30] = {0};
    int c_guess[30] = {0};
    int common[30] = {0};
    int ln = ln_sec;
    char *eval_r = rs[ng];
    for (int i = 0; i < ln; i++) {
      char cur_s = sw[i];
      c_sec[cur_s - 'a'] += 1;
    }
    for (int j = 0; j < ln; j++) {
      char cur_g = cw[j];
      c_guess[cur_g - 'a'] += 1;
    }
    for (int k = 0; k < 30; k++) {
      if ((c_sec[k] >= 1) && (c_guess[k] >= 1)) {
        common[k] = c_sec[k];
      }
    }
    for (int m = 0; m < ln; m++) {
      int cur_index = cw[m] - 'a';
      if (sw[m] == cw[m]) {
        eval_r[m] = cw[m] - 'a' + 'A';
      } else if (common[cur_index] != 0) {
        eval_r[m] = cw[m];
      } else {
        eval_r[m] = '.';
      }
    }
    if (strcmp(sw, cw) == 0) {
      printf("YOU WIN! The word was: %s\n", sw);
      exit(0);
    } else {
      ++ng;
      if (ng == 6) {
        printf("YOU LOSE! The word was: %s\n", sw);
        exit(0);
      }
    }
  }
}
