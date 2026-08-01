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
#include <string.h>

static const char *example_world = "apple";

bool check_world_is_solution(const char *input) {
  return strcmp(input, example_world) == 0;
}

void initialize_letter_solution(const char *input, letter_solution_t *letters) {

  int empty_pos = 0;
  int counter = 0;

  for (int i = 0; i < WORD_LENGTH; i++) {
    letters[i].letter = '\0';
    letters[i].repeats = 0;
  }

  for (int i = 0; i < WORD_LENGTH; i++) {
    counter = 0;
    for (int j = 0; j < WORD_LENGTH; j++) {
      if (input[i] == letters[j].letter) {
        letters[j].repeats++;
        break;
      }
      counter++;
    }

    if (counter == WORD_LENGTH) {
      letters[empty_pos].letter = input[i];
      letters[empty_pos].repeats = 1;
      empty_pos++;
    }
  }
}

void check_word_letter(const char *input,
                       letter_status_t results[WORD_LENGTH]) {

  letter_solution_t letters[WORD_LENGTH];

  initialize_letter_solution(example_world, letters);

  // initialize results array
  for (int i = 0; i < WORD_LENGTH; i++) {
    results[i] = LETTER_ABSENT;
  }

  // First check all the LETTER_CORRECT and update the results array
  for (int i = 0; i < WORD_LENGTH; i++) {
    if (input[i] == example_world[i]) {
      results[i] = LETTER_CORRECT;
    }
  }

  // Now check LETTER_MISPLACED and update the results array
  for (int i = 0; i < WORD_LENGTH; i++) {
    for (int j = 0; j < WORD_LENGTH; j++) {
      if (i == j)
        continue;
      if (input[i] == example_world[j]) {
        if (results[i] != LETTER_CORRECT) {
          results[i] = LETTER_MISPLACED;
        }
      }
    }
  }
}
