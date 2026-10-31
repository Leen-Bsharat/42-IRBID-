*This activity has been created as part of the 42 curriculum by Leen Bsharat.*

# ft_printf

## Description
The **ft_printf** project is an essential milestone in the 42 curriculum. Its primary objective is to recode the standard C library's `printf()` function from scratch, focusing on the handling of variadic functions using `<stdarg.h>`. 

Unlike the standard libc implementation, this version does not implement buffer management, but accurately reproduces the formatting behavior and return value (total count of printed characters) of the original function.

### Supported Conversions
- `%c`: Prints a single character.
- `%s`: Prints a string of characters (prints `(null)` if pointer is `NULL`).
- `%p`: Prints a `void *` pointer argument in hexadecimal format prefixed with `0x` (prints `(nil)` if pointer is `NULL`).
- `%d` / `%i`: Prints a signed decimal integer.
- `%u`: Prints an unsigned decimal number.
- `%x`: Prints an unsigned number in lowercase hexadecimal format (`base 16`).
- `%X`: Prints an unsigned number in uppercase hexadecimal format (`base 16`).
- `%%`: Prints a literal percent sign.

---

## Instructions

### Compilation
The library is compiled using `cc` with the mandatory compilation flags `-Wall -Wextra -Werror`.

To compile the library, run:
```bash
make
```
This rule compiles the source files, and generates the static library file `libftprintf.a` at the root of the repository using `ar rcs`.

### Available Makefile Rules
- `make` or `make all`: Compiles the library `libftprintf.a`.
- `make clean`: Removes all compiled object files (`.o`).
- `make fclean`: Removes object files as well as the compiled library `libftprintf.a`.
- `make re`: Performs a clean rebuild (`fclean` followed by `all`).

### Usage Example
Include the header file `ft_printf.h` in your C code and link against `libftprintf.a`:

```c
#include "ft_printf.h"

int	main(void)
{
	int	len;

	len = ft_printf("Hello, %s! Value: %d, Hex: %x\n", "42", 42, 42);
	ft_printf("Printed %d characters.\n", len);
	return (0);
}
```

Compile with your test file:
```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test_printf
./test_printf
```

---

## Algorithm and Data Structure Rationale

### Data Structures
Due to the specific constraints of the project and the prohibition of buffer management:
- **`va_list` (from `<stdarg.h>`)**: Used as the primary data structure to traverse and retrieve variable arguments passed across the stack.
- **Fixed-size Stack Buffers & Direct Output**: Complex dynamic data structures were intentionally avoided. Instead, functions write directly to the standard output using `write(1, ...)`, minimizing memory footprint and eliminating potential memory leaks.

### Algorithmic Approach
The parsing process operates via a single-pass stream interpreter:
1. **Dispatcher Pattern**: The format string is traversed character-by-character. Non-format characters are output directly via `write(1, &format[i], 1)` while incrementing the global counter.
2. **Format Recognition**: When a `%` token is encountered, the subsequent character is evaluated by an argument dispatcher (`ft_formats`) which delegates to specialized conversion handlers based on the specifier.
3. **Decoupled Output and Length Calculation**: 
   - For recursive conversions (e.g., base-10 integers, unsigned integers, and hexadecimal values), output generation is kept separate from character counting.
   - Dedicated length-calculation functions determine the exact number of characters printed before returning back to the caller, preventing redundant recalculations during recursive stack unwinding.
4. **Pointer Handling**: Memory addresses are cast to `unsigned long` to guarantee support across 64-bit architectures, explicitly handling the `NULL` edge case as defined by system conventions.

---

## Resources

### References
- `man 3 printf`
- `man 3 stdarg`, `man va_start`, `man va_arg`, `man va_end`
- 42 Norminette V4 guidelines

### AI Usage Disclosure
In accordance with 42 AI usage guidelines:
- **Pedagogical Support**: AI was consulted to clarify the theoretical mechanisms of variadic arguments in C (`va_start`, `va_arg`, `va_end`) and the standard promotion rules (e.g., `char` promoting to `int`).
- **Code Review & Edge Case Analysis**: AI was used as a code reviewer to detect recursion side-effects in length counting functions, identify variable name collisions across compilation units, and verify boundary behaviors (such as `NULL` pointer representations on Linux).
- **Implementation**: All final code, refactoring decisions, Makefile rules, and algorithmic designs were implemented, integrated, and validated directly by the author.
