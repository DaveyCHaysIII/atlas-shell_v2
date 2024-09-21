#include "hsh.h"

/**
 * main - entrypoint for hsh executable
 * @argc: number of CL inputs
 * @argv: matrix of CL inputs
 * @env: hsh evironment variables
 *
 * Return: 'EXIT_SUCCESS' or 'EXIT_FAILURE'
 */

int main(int argc, char **argv, char **env)
{
    (void)env;

    printf("%d\n", argc);
    while (*argv)
    {
        printf("%s ", *argv);
        argv++;
    }
    printf("\n");
    return (EXIT_SUCCESS);
}