#include "../include/minishell.h"

int main()
{
    char *input;

    while (1)
    {
        input = readline("Minishell> ");
        add_history(input);
        print_input_after_formating(input);
        printf ("-------------------\n");
        parse_input(input);
    }
}
