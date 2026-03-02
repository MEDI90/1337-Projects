*This project has been created as part of the 42 curriculum by mboubaza.*

# Get Next Line

## Description
**Get Next Line** is a project at 42 School that involves writing a function capable of reading a text file pointed to by a file descriptor, one line at a time. The goal is to learn about static variables in C and how to manage memory dynamically when the size of the input is unknown.

The function `get_next_line` reads from a file descriptor (or standard input) and returns the next line, including the newline character (`\n`), until the end of the file is reached.

## Instructions

### Compilation
To compile the project, you must include the source files and define the `BUFFER_SIZE` flag. You will need a `main.c` (not included in the mandatory submission) to test the function.

Example compilation command:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

```

You can change the `BUFFER_SIZE` to test different read sizes:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c -o gnl

```

### Execution

After compiling with your own `main.c`, run the executable:

```bash
./gnl

```

## Algorithm Explanation

The core challenge of this project is reading a line of unknown length using a fixed-size buffer. The selected algorithm relies on a **static variable** to persist data between function calls.

1. **Reading Loop (`new_line`):**
* The function reads `BUFFER_SIZE` bytes from the file descriptor into a temporary buffer.
* This buffer is immediately joined (`ft_strjoin`) to a **static string** (`tmp`) that accumulates the read data.
* This process repeats until a newline character (`\n`) is found in the accumulated string or the End Of File (EOF) is reached.


2. **Line Extraction (`the_line`):**
* Once a newline is detected (or reading finishes), the function iterates through the static string to find the index of the newline.
* It allocates memory and copies the characters from the start of the static string up to and including the newline into a new string, which will be returned.


3. **State Update (`the_rest`):**
* Before returning the line, the function calculates the remaining characters in the static string (everything after the newline).
* It allocates a new string for these remaining characters, frees the old static string, and updates the static pointer to this new "leftover" string.
* This ensures that the next call to `get_next_line` starts reading exactly where the previous call left off.



### Bonus Part

The bonus implementation supports **multiple file descriptors** simultaneously. Instead of a single static string, an array of static strings (`static char *tmp[1024]`) is used, where the index corresponds to the file descriptor (`fd`). This allows the program to switch between different files without losing the reading state of any of them.

## Resources

* **Documentation:**
* `man read`: For understanding the `read` system call and return values.
* `man malloc` / `man free`: For dynamic memory management.


* **AI Usage:**
* *Debugging:* AI was used to help identify memory leaks in the `ft_strjoin` helper function during the initial implementation.
