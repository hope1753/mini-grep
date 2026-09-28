# mini-grep

A lightweight CLI file pattern search utility written in C, inspired by the pointer mechanics and command-line argument parsing concepts in **K&R C (Chapter 5)**.

---

## 🔍 Overview

`mini-grep` is a simple text search tool that scans a file line-by-line for a specified string pattern. It features option flag parsing using pointer arithmetic, basic file stream processing (`fopen`, `fgets`), and string search logic (`strstr`).

---

## ✨ Features & Options

- **Option Parsing**: Parse concatenated or individual command-line option flags using pointer arithmetic (`*++argv`).
- **`-n` (Line Number)**: Print the corresponding line numbers alongside matching lines.
- **`-v` (Invert Match)**: Invert the search condition to print lines that **do not** contain the pattern.
- **`-c` (Count)**: Display the total count of matched lines at the end of execution.

---

## 🚀 Getting Started

### Prerequisites
- C Compiler (`GCC`, `Clang`, or `MinGW`)

### Build
Compile the source file using `gcc`:

```bash
gcc -o mini_grep main.c
