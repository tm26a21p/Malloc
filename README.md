# Custom Memory Allocation Library

## Overview

The Custom Memory Allocation Library project, coded in C, aims to delve deeper into the intricacies of memory management in programming. The primary objective is to develop a set of functions that can emulate the behavior of `malloc`, `calloc`, `realloc`, `reallocarray`, and `free`, providing a deeper understanding of these commonly used system functions.

## Repository Details

- Binary Name: `libmalloc.so`
- Group Size: 1
- Language: C
- Compilation: Managed via a Makefile, including `re`, `clean`, and `fclean` rules.

## Key Objectives

- **Memory Management**: The project involves the development of a set of functions to emulate the behavior of memory management functions in the standard C library.
- **Understanding Memory Allocation**: The project provides a deeper understanding of how memory allocation works in programming, including the allocation, reallocation, and freeing of memory.

## Implemented Functions

The project successfully implements the following memory management functions:

- `my_malloc`
- `calloc`
- `free`
- `realloc`
- `reallocarray`

## Conclusion

The Custom Memory Allocation Library project is a challenging yet rewarding experience that provides a deeper understanding of memory management in programming. The project also helps in honing C programming skills and exploring the intricacies of memory allocation, reallocation, and freeing (free is just a datapoint that can be stored on one bit. amazing simplicity.)

## Building

To build the project, navigate to the project directory and run the following command:

```sh
make
```

To run the project, use the following command:

```sh
make ls
```