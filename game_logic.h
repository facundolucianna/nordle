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

#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "nordle.h"
#include <stdbool.h>

bool check_word_letter(const char *input, letter_status_t results[WORD_LENGTH]);

#endif /* GAME_LOGIC_H */
