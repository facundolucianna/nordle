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

#include <stdio.h>
#include <stdbool.h>
#include "nordle.h"
#include "utils.h"

int main(void) {
  printf("=== Welcome to NORDLE! ===\n\n");

  char buffer[256];

  for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++) {
    bool valid = false;

    while (!valid) {
      printf("Attempt %d/%d - Enter a %d-letter word: ", attempt, MAX_ATTEMPTS,
             WORD_LENGTH);

      if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("\nError or EOF reached.\n");
        return 0;
      }

      if (is_valid_input(buffer)) {
        valid = true;
      } else {
        printf("Invalid input! Please enter a valid %d-letter word.\n\n",
               WORD_LENGTH);
      }
    }

    printf("You entered: %s\n\n", buffer);
  }

  printf("Game loop completed.\n");
  return 0;
}
