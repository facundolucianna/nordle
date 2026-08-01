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
#include "nordle.h"
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

// Check if the input is a valid WORD_LENGTH alphabetic word
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
