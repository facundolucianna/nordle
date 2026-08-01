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

void check_word_letter(const char *input, LetterStatus results[WORD_LENGTH]) {
  (void)input;

  for (int i = 0; i < WORD_LENGTH; i++) {
    results[i] = LETTER_CORRECT;
  }
}
