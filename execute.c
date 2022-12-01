#include "simple.h"

int my_exit(__attribute__((unused)) char **args)
{
    return (0);
}

int my_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "hsh: expected argument to \"cd\" \n");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("hsh: cd");
        }
    }
    return (1);
}

int my_exit_ls(__attribute__((unused)) char **args)
{

    fprintf(stderr, "/hsh: No such file or directory \n");
    return (1);
}

int execute(char **args)
{
    op_t ops[] = {
        {"cd", my_cd},
        {"exit", my_exit},
        {"ls", my_exit_ls}};

    int i;
    if (args[0] == NULL)
    {
        return (1);
    }
    for (i = 0; i < 2; i++)
    {
        if (strcmp(args[0], ops[i].opp) == 0)
        {
            return (ops[i].f(args));
        }
    }
    return (launch(args));
}
