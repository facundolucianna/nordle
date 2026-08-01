/*
 * Copyright (C) 2026 Facundo Lucianna
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "game_logic.h"
#include "nordle.h"
#include "words.h"
#include <string.h>

static char secret_word[WORD_LENGTH + 1] = "apple";

void init_game(void) {
  const char *word = get_random_word();
  strncpy(secret_word, word, WORD_LENGTH);
  secret_word[WORD_LENGTH] = '\0';
}

const char *get_secret_word(void) { return secret_word; }

// Check if the input is the solution word
static bool check_word_is_solution(const char *input) {
  return strcmp(input, secret_word) == 0;
}

// Initialize the letter counts
static void initialize_letter_counts(const char *word, int counts[256]) {
  memset(counts, 0, sizeof(int) * 256);
  for (int i = 0; i < WORD_LENGTH; i++) {
    unsigned char c = (unsigned char)word[i];
    counts[c]++;
  }
}

bool check_word_letter(const char *input,
                       letter_status_t results[WORD_LENGTH]) {

  // Check if the input is the solution word
  if (check_word_is_solution(input)) {
    return true;
  }

  int counts[256];
  initialize_letter_counts(secret_word, counts);

  // Initialize results array
  for (int i = 0; i < WORD_LENGTH; i++) {
    results[i] = LETTER_ABSENT;
  }

  // First check all the LETTER_CORRECT and update the results array
  for (int i = 0; i < WORD_LENGTH; i++) {
    if (input[i] == secret_word[i]) {
      results[i] = LETTER_CORRECT;
      counts[(unsigned char)input[i]]--;
    }
  }

  // Now check LETTER_MISPLACED and update the results array
  for (int i = 0; i < WORD_LENGTH; i++) {
    if (results[i] == LETTER_CORRECT)
      continue;
    if (counts[(unsigned char)input[i]] > 0) {
      results[i] = LETTER_MISPLACED;
      counts[(unsigned char)input[i]]--;
    }
  }
  return false;
}
