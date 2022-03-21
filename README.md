## Libasm

### Description ✨
Libasm is a project 42 written in ASM and C aiming to discover the assembler by coding a small library of some functions.
Here is the list of functions:
- read
- strcmp
- strcpy
- strdup
- strlen
- write

In the `test/` folder, a `main.c` is there to compare the result of the functions coded in assembler with the functions coming from the libC.

### Main purpose :page_facing_up:
The goal of the project was to discover the subtleties of the assembler and to go a little deeper into the depth of C via the discovery of an even lower level language.
To discover the usefulness and management of registers.

The code is written in **64 bits ASM**, not inline ASM.

The syntax used is **Intel** and not AT&T.

The code is compiled with **nasm**.


### How to use :rocket:

If you want to check the behavior or these functions,
Run ``test/tester.sh``
```
./tester.sh
```
then run:
```
./run_test
```
