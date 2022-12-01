#include "simple.h"

int launch(char **args)
{
    pid_t pid;
    int status = 0;

    pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("hsh");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("hsh2");
    }
    else
    {
        while (!WIFEXITED(status) && !WIFSIGNALED(status))
        {
            waitpid(pid, &status, WUNTRACED);
        }
    }
    return (1);
}