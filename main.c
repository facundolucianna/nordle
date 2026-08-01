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
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  init_game();

  printf("=== Welcome to NORDLE! ===\n\n");

  printf("\033[31mDEBUG: The secret word is %s\033[0m\n", get_secret_word());
  printf("\033[1;32mDEBUG: The secret word is %s\033[0m\n", get_secret_word());
  printf("\033[38;5;208mDEBUG: The secret word is %s\033[0m\n",
         get_secret_word());
  char buffer[256];
  char input_buffer[WORD_LENGTH + 1];
  letter_status_t results[WORD_LENGTH];
  GameStatus game_status = GAME_LOST;

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

    // Copy only the word_length characters to input_buffer
    strncpy(input_buffer, buffer, WORD_LENGTH);
    input_buffer[WORD_LENGTH] = '\0';

    if (check_word_letter(input_buffer, results)) {
      printf("\n**************************************\n");
      printf("Congratulations! You guessed the word.\n");
      printf("**************************************\n");
      game_status = GAME_WON;
      break;
    }

    for (int i = 0; i < WORD_LENGTH; i++) {
      printf("SOL: %c: %d\n", input_buffer[i], results[i]);
    }
  }

  if (game_status == GAME_LOST) {
    printf("\n*************************************\n");
    printf("You lost! The secret word was: %s\n", get_secret_word());
    printf("*************************************\n");
  }

  return 0;
}
