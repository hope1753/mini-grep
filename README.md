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
```
## Example
```
$./main -n -c than poem.txt
1. Things to be thankful for
10. Are things we should be thankful for...
11. And most of all our thankful prayers
Found : 3

$./main -n -c than poem.txt
1. Things to be thankful for
10. Are things we should be thankful for...
11. And most of all our thankful prayers
Found : 3
PS C:\mini-grep> ./main -n -v -c than poem.txt
2                              - Helen Steiner Rice
3The good, green earth beneath our feet,
4The air we breath, the food we eat,
5Some work to do, a goal to win,
6A hidden longing deep within
7That spurs us on to bigger things
8And helps us meet what each day brings
9All these things and many more
12Should rise to God because He cares.
Found : 9
