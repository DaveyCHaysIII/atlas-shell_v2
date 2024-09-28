#ifndef HSH_H
#define HSH_H

/****** LIBRARIES ******/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

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

typedef struct Shellstate
{
	char **environ;
	char *program_name;
	//potentially other static variables
} Shellstate;

/****** PROTOTYPES ******/

/* MAIN.C */

int prompt(MemNode **);
void graceful_exit(MemNode **, const char *, const char *)

/* MEMNODE.C */

MemNode *createList();
MemNode *addNode(MemNode **);
void free_memlist(MemNode **);

/* EXEC_HANDLERS.C */

void execute_command(char *);
void execute_pipe_command(MemNode *, int);

/* PARSERS.C */

const char **parse_input(char *str_input, const char *delimiter);
// some kinda tokenizer
// some kinda path validator
// some kinda builtin handler

/* COUNTERS.C */

int get_pipe_count(char *buffer);
int count_redirects(const char **cmd_tokens);

/* BUILTINS.C */

void print_env(void);
void print_pwd(void);
void _cd_handler (char **);
void _cd(char *);
void _echo(char *);

/* UTILS.C */

void error_handler(char *);

/* ENVIRONMENT.C */

char *_getenv(const char *);
int _setenv(const char *, const char *);
int _unsetenv(const char *);

extern Shellstate shell_state;

#endif
