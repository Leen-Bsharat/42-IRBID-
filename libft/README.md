*This activity has been created as part of the 42 curriculum by lbsharat.*

# Libft - Your Very First C Library

## Description
**Libft** is the first individual project in the 42 school curriculum. The goal of this project is to create a custom C library consisting of standard C library functions (`libc`), useful utility functions for string and memory manipulation, and a set of functions for handling singly linked lists.

Since standard functions are often forbidden in subsequent 42 projects, this library serves as a fundamental toolbox that will be reused and expanded throughout the curriculum. Implementing these functions from scratch provides an in-depth understanding of memory allocation, pointer manipulation, and data structures in C.

---

## Instructions

### Compilation
The library is compiled using the provided `Makefile`. To build `libft.a`, run the following command in the root of the repository:

```bash
make
```

This compiles all source files with the flags `-Wall -Wextra -Werror` using `cc` and generates the static library `libft.a` using `ar rcs`.

### Available Makefile Rules
- `make` or `make all`: Compiles the mandatory parts and generates `libft.a`.
- `make clean`: Removes all compiled object files (`.o`).
- `make fclean`: Removes all compiled object files and the library archive `libft.a`.
- `make re`: Performs a complete rebuild (`fclean` followed by `make`).

### Usage in Another Project
To use `libft` in your C programs:
1. Include the header file in your source code:
   ```c
   #include "libft.h"
   ```
2. Compile your program by linking the library:
   ```bash
   cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
   ```

---

## Library Overview & Functions

### 1. Libc Re-implementations (Part 1)
Functions that replicate standard `libc` behavior (prefixed with `ft_`):

| Category | Functions | Description |
| :--- | :--- | :--- |
| **Character Checks** | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` | Check character class (returns `1` if true, `0` if false). |
| **Character Conversion** | `ft_toupper`, `ft_tolower` | Convert letter case. |
| **String Examination** | `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr` | Measure length, locate characters, compare, and search substrings. |
| **String Copy/Cat** | `ft_strlcpy`, `ft_strlcat` | Size-bounded string copy and concatenation. |
| **Memory Operations** | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` | Fill, clear, copy, compare, and scan byte memory areas. |
| **Conversions & Allocations** | `ft_atoi`, `ft_calloc`, `ft_strdup` | String to integer conversion, zero-initialized heap allocation, string duplication. |

### 2. Additional Functions (Part 2)
Functions either not present in standard libc or adapted for practical use:

- `ft_substr`: Extracts a substring from a string.
- `ft_strjoin`: Concatenates two strings into a newly allocated string.
- `ft_strtrim`: Trims leading and trailing characters matching a specified set.
- `ft_split`: Splits a string into an array of strings based on a delimiter character.
- `ft_itoa`: Converts an integer into its string representation.
- `ft_strmapi`: Applies a function to each character of a string to create a new string.
- `ft_striteri`: Applies a function to each character of a string in-place.
- `ft_putchar_fd`: Outputs a single character to a given file descriptor.
- `ft_putstr_fd`: Outputs a string to a given file descriptor.
- `ft_putendl_fd`: Outputs a string followed by a newline to a given file descriptor.
- `ft_putnbr_fd`: Outputs an integer to a given file descriptor.

### 3. Linked List Functions (Part 3)
A suite of functions to create and manipulate singly linked lists based on the `t_list` structure:
```c
typedef struct s_list
{
    void          *content;
    struct s_list *next;
}   t_list;
```

- `ft_lstnew`: Allocates and initializes a new list element.
- `ft_lstadd_front`: Prepends an element to the front of the list.
- `ft_lstsize`: Counts the number of elements in the list.
- `ft_lstlast`: Retrieves the last element of the list.
- `ft_lstadd_back`: Appends an element to the end of the list.
- `ft_lstdelone`: Deletes a single element's content using a `del` function and frees the node.
- `ft_lstclear`: Deletes and frees an entire list and sets its head pointer to `NULL`.
- `ft_lstiter`: Iterates over a list and applies a function to each node's content.
- `ft_lstmap`: Maps a function across a list to produce a new modified list.

---

## Resources

### References & Documentation
- [Linux Programmer's Manual (man pages)]: For standard function specifications (`man 3 strlen`, `man 3 memcpy`, etc.).
- [Apple Open Source Libc](https://opensource.apple.com/): Reference implementations of BSD standard functions like `strlcpy` and `strlcat`.
- *The C Programming Language* (K&R): Essential guide for pointers, memory layouts, and data structures.

### AI Usage Disclaimer
In accordance with the 42 AI policy:
- **Scope of AI Assistance:** AI tools were used solely as a conceptual aid and documentation assistant (e.g., generating README structure, clarifying edge cases in man page definitions, and understanding memory alignment / pointer arithmetic).
- **Core Implementation:** All code logic, memory management, testing, and debugging were designed, reasoned through, and implemented directly by the author without automated code generation, ensuring genuine learning and exam readiness.
