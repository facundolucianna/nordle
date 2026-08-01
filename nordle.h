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

#ifndef NORDLE_H
#define NORDLE_H

#define MAX_ATTEMPTS 6
#define WORD_LENGTH 5

/* Feedback status for each letter in a guess */
typedef enum LetterStatus {
  LETTER_ABSENT = 0, /* Letter is not in the word (Gray) */
  LETTER_MISPLACED,  /* Letter is in the word, wrong position (Yellow) */
  LETTER_CORRECT     /* Letter is in the word, correct position (Green) */
} letter_status_t;

/* Overall game state */
typedef enum { GAME_PLAYING = 0, GAME_WON, GAME_LOST } GameStatus;

#endif /* NORDLE_H */
