# CS 348 Assignment 3
## Group 38
### Group Member1 :

*Name: Pranjal Baranwal*

_Roll Number: 200101083_

### Group Mmeber 2:
*Name: Satvik Tiwari*

_Roll Number: 200101091_

---
## Lexical Analyzer for Nano C using Flex

The nanoC language is designed after C99 by substantially stripping it, but maintaining the key flavours.

This contains various lexical tokens:

* Keyword
* Identifier
* Constant
* String Literal
* Punctuator
---

## About the Assignment files and Commands for running the same

### Files
This folder contains four files:

1. `A3_38.l`: The lex file with the grammars for the lexical tokens in nanoC specification.
2. `A3_38.c`: The main file for testing the lexer.
3. `A3_38.nc`: The testing file having various statements to test different lexical rules of the lexer.
4. `makefile`: Makefile with commands for compiling the lex file, generating the output on test and cleaning the repository.

### Commands:

To generate the lex file:
```bash
    make lex.yy.c
```
To get the executable:
```bash
    make a.out
```
To generate the output based on the test file
```bash
    make output
```
To clean the folder:
```bash
    make clean
```