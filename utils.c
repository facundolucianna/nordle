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

#include "utils.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Convert a string to lowercase in-place
static void lower_string(char *input) {
  if (input == NULL) {
    return;
  }
  while (*input != '\0') {
    *input = (char)tolower((unsigned char)*input);
    input++;
  }
}

// Check if the string contains only alphabetic characters
static bool is_alpha_string(char *input) {
  while (*input != '\0') {
    if (!isalpha(*input)) {
      return false;
    }
    input++;
  }
  return true;
}

bool is_valid_input(char *input) {
  if (input == NULL) {
    return false;
  }

  input[strcspn(input, "\r\n")] = '\0';

  if (!is_alpha_string(input)) {
    return false;
  }

  lower_string(input);

  return (strlen(input) == WORD_LENGTH);
}

void generate_colors_in_word(char *input, letter_status_t results[WORD_LENGTH],
                             char *output) {

  int offset = 0;
  for (int i = 0; i < WORD_LENGTH; i++) {
    switch (results[i]) {
    case LETTER_CORRECT:
      offset += sprintf(output + offset, "\033[1;32m%c\033[0m", input[i]);
      break;
    case LETTER_MISPLACED:
      offset += sprintf(output + offset, "\033[38;5;208m%c\033[0m", input[i]);
      break;
    default:
      offset += sprintf(output + offset, "%c", input[i]);
      break;
    }
  }
  output[offset] = '\0';
}