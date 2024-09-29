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
#define MAX_ARR_SIZE 15

/****** STRUCTS ******/

/**
 * struct MemNode - linked list for holding dynamic memory
 * @tokens: the tokenized version of buffer
 * @buffer: the buffer in question
 * @next: the pointer to the next node in the list
 *
 * Description: This structure holds all dynamically allocated memory
 */
typedef struct MemNode
{
	char **tokens;
	char *buffer;
	struct MemNode *next;
} MemNode;

/**
 * struct Shellstate - global variable holding structure
 * @environ: holds the environmental varialbe
 * @program_name: holds the program name
 *
 * Description: holds everything needed about the state of the shell
 */
typedef struct Shellstate
{
	char **environ;
	char *program_name;
} Shellstate;

/****** PROTOTYPES ******/

/* MAIN.C */

int prompt(MemNode **);
void graceful_exit(MemNode **, const char *, const char *);

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
unsigned int _strlen(char *);

/* BUILTINS.C */

void print_env(void);
void print_pwd(void);
void _cd_handler (char **);
void _cd(char *);
void _echo(char *);

/* UTILS.C */

void error_handler(char *);
unsigned int _strspn(char *, char *);
char *create_sanitized_buffer(char *buffer);

/* ENVIRONMENT.C */

char *_getenv(const char *);
int _setenv(const char *, const char *);
int _unsetenv(const char *);

extern Shellstate shell_state;

/* STRINGS.C */

char *_strdup(char *);
char *_str_char_concat(char *, char,  char *);
char *_strstr(char *, char *);
int _strcmp(char *, char *);
int _strncmp(char*, char *, int);

#endif
