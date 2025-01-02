#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *Header;
typedef void (*op_func)(stack_t **, unsigned int);

void opn_fle(char *fileOFname);
int ln_parse(char *, int, int);
void rd_fle(FILE *);
int len_chars(FILE *);
void find(char *, char *, int, int);
stack_t *crt_Node(int n);
void freeNods(void);
void prnt_stck(stack_t **, unsigned int);
void append_to_stack(stack_t **, unsigned int);
void add2queue(stack_t **, unsigned int);
void fun_call(op_func, char *, char *, int, int);
void pop(stack_t **, unsigned int);
void push(stack_t **, unsigned int);
void Donothing(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void divNode(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);
void prntchar(stack_t **, unsigned int);
void prntstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void errorr(int error_code, ...);
void errorrExtra(int error_code, ...);
void err_strn(int error_code, ...);
void rotr(stack_t **, unsigned int);
#endif
