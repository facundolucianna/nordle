# NORDLE

> **NORDLE** (*Nordle's Not Wordle*) is a lightweight, terminal-based CLI clone of the popular Wordle game written in C11.

> [!NOTE]
> This is a **toy / educational project** created to explore C programming, C11 toolchain configuration, CLI color formatting, and algorithm design.

---

## 🎮 How to Play

The goal of the game is to guess a secret 5-letter English word within **6 attempts**.

After each guess, the terminal provides feedback using ANSI color formatting:

- 🟩 **Green**: The letter is in the word and in the **correct position**.
- 🟧 **Orange / Yellow**: The letter is in the word, but in the **wrong position**.
- ⬛ **Standard / Normal**: The letter is **not in the word**.

NORDLE enforces official Wordle evaluation rules for duplicate letters.

---

## 🚀 Features

- **Random Word Selection**: Picks a random 5-letter secret word at the start of each game session.
- **ANSI Terminal Colors**: Color-coded feedback for guesses directly in your terminal.
- **Input Validation**: Automatically validates inputs to ensure they are 5-letter alphabetic words, converting uppercase inputs to lowercase seamlessly.
- **Clean & Modular Architecture**:
  - `main.c`: CLI interface and main game loop.
  - `game_logic.c` / `game_logic.h`: Core Wordle evaluation engine.
  - `utils.c` / `utils.h`: Input validation, sanitization, and ANSI color buffer formatting.
  - `words.c` / `words.h`: Word list repository and random word picker.
  - `nordle.h`: Global game constants and type definitions.

---

## 🛠️ Requirements

- **C Compiler**: `clang` (recommended on macOS) or `gcc` with C11 support.
- **Build System**: `make`.

---

## 📦 Building and Running

### Compile the project
```bash
make
```

### Run the game
```bash
./nordle
```

### Clean build artifacts
```bash
make clean
```

---

## 📄 License

Copyright (C) 2026 Facundo Lucianna.

This project is open-source software licensed under the terms of the **GNU General Public License v2.0 (GPL-2.0)**. See the [LICENSE](LICENSE) file for complete license text.
