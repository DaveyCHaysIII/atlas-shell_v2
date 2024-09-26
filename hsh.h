#ifndef HSH_H
#define HSH_H

/****** LIBRARIES ******/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/****** MACROS *******/

#define ERROR_MALLOC 77
#define EXIT_F_STAT 23
#define EXIT_F_ACCESS 24
#define PROMPT "($)"
#define WHITESPACE " \n\t\r"
#define PATH_DELIM ":"
#define BUFF_SIZE 1024

/****** STRUCTS ******/

typedef struct MemNode
{
	char **commands;
	char *buffer;
	struct MemNode *next;
} MemNode;

/****** PROTOTYPES ******/

/* MAIN.C */

int prompt(MemNode *);
int get_pipe_count(char *);
int graceful_exit(MemNode *);

/* MEMNODE.C */

MemNode *createList();
MemNode *createNode(char **, char *);
MemNode *addNode(MemNode *, char **, char *);
void free_memlist(MemNode **);

/* EXEC_HANDLERS.C */

void execute_command(char *);
void execute_pipe_command(MemNode *, int);

/* PARSERS.C */

// some kinda tokenizer
// some kinda path validator
// some kinda builtin handler

/* BUILTINS.C */

// exit
// cd
// env
// setenv
// unsetenv

/* UTILS.C */

// some kinda error handler

#endif
