0x19. C - Stacks, Queues - LIFO, FIFO
=====================================

-   By Samuel Victor

![](https://pbs.twimg.com/media/CFYYWy6UEAE9Ow-.png)

# Monty Bytecode Interpreter
This repository contains a simple interpreter for Monty bytecode files. It reads bytecode instructions from a file and executes them using a stack or queue data structure.

## Supported Operations

The following operations are supported by the interpreter:

| Opcode | Description |
|--------|-------------|
| push   | Pushes an element to the stack. |
| pall   | Prints all elements in the stack. |
| pint   | Prints the value at the top of the stack. |
| pop    | Removes the top element of the stack. |
| swap   | Swaps the top two elements of the stack. |
| add    | Adds the top two elements of the stack. |
| nop    | Does nothing. |
| sub    | Subtracts the second top element from the top element. |
| div    | Divides the second top element by the top element. |
| mul    | Multiplies the second top element with the top element. |
| mod    | Computes the remainder of division of the second top by the top element. |
| comment| Allows adding comments in bytecode using '#'. |
| pchar  | Prints the character at the top of the stack. |
| pstr   | Prints the string starting from the top of the stack. |
| rotl   | Moves the top element to the bottom of the stack. |
| rotr   | Moves the bottom element to the top of the stack. |
| queue, stack | Toggles the implementation style between doubly linked list and stack. |

## Tasks

### 0. push, pall
- Implement the push and pall opcodes. (100% done)

### 1. pint
- Implement the pint opcode. (100% done)

### 2. pop
- Implement the pop opcode. (100% done)

### 3. swap
- Implement the swap opcode. (100% done)

### 4. add
- Implement the add opcode. (100% done)

### 5. nop
- Implement the nop opcode. (100% done)

### 6. sub
- Implement the sub opcode. (100% done)

### 7. div
- Implement the div opcode. (100% done)

### 8. mul
- Implement the mul opcode. (100% done)

### 9. mod
- Implement the mod opcode. (100% done)

### 10. comments
- Implement the capability to add comments using # at the beginning of a line. (100% done)

### 11. pchar
- Implement the pchar opcode. (100% done)

### 12. pstr
- Implement the pstr opcode. (100% done)

