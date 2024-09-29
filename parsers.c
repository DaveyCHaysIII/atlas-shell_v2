#include "hsh.h"

/**
 * parse_input - parses a string into tokens
 * @str_input: string that needs to be parsed
 * @delimiter: delimiters to use
 *
 * Return: matrix of tokens, otherwise NULL
 */

const char **parse_input(char *str_input, const char *delimiter)
{
    const char **new_tok_arr = NULL;
    char *tok = NULL;
    int i = 0;

    printf("in parser\n");
    printf("buffer in parser = %s\n", str_input);
    new_tok_arr = malloc(sizeof(char *));
    if (!new_tok_arr)
    {
        free(new_tok_arr);
        return (NULL);
    }
    tok = strtok(str_input, delimiter);
    while (tok)
    {
        new_tok_arr[i] = strdup(tok);
        tok = strtok(NULL, delimiter);
        i++;
    }
    new_tok_arr[i] = '\0'; /* set final pointer to null*/
    free(tok);
    printf("exiting parser\n");
    return (new_tok_arr);
}
