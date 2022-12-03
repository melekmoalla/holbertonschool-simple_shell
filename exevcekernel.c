#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#ifndef TEST

#else
#include <stdio.h>
#define um_kmalloc malloc
#endif

/* Execute FILE, searching in the `PATH' environment variable if it contains
   no slashes, with arguments ARGV and environment from `environ'.  */
int execvp_noalloc(char *buf, const char *file, char *const argv[])
{
    if (*file == '\0')
    {
        return -ENOENT;
    }
    if (strchr(file, '/') != NULL)
    {
        /* Don't search when it contains a slash.  */
        execv(file, argv);
    }
    else
    {
        int got_eacces;
        size_t len, pathlen;
        char *name, *p;
        char *path = getenv("PATH");
        if (path == NULL)
            path = ":/bin:/usr/bin";
        len = strlen(file) + 1;
        pathlen = strlen(path);
        /* Copy the file name at the top.  */
        name = memcpy(buf + pathlen + 1, file, len);
        /* And add the slash.  */
        *--name = '/';
        got_eacces = 0;
        p = path;
        do
        {
            char *startp;
            path = p;

            p = strchr(path, ':');
            if (!p)
                p = strchr(path, '\0');
            if (p == path)
                /* Two adjacent colons, or a colon at the beginning or the end
                   of `PATH' means to search the current directory.  */
                startp = name + 1;
            else
                startp = memcpy(name - (p - path), path, p - path);
            /* Try to execute this name.  If it works, execv will not return.  */
            execv(startp, argv);
            /*
            if (errno == ENOEXEC) {
            }
            */
            switch (errno)
            {
            case EACCES:
                /* Record the we got a `Permission denied' error.  If we end
                   up finding no executable we can use, we want to diagnose
                   that we did find one but were denied access.  */
                got_eacces = 1;
                break;
            case ENOENT:
            case ESTALE:
            case ENOTDIR:
                /* Those errors indicate the file is missing or not executable
                   by us, in which case we want to just try the next path
                   directory.  */
            case ENODEV:
            case ETIMEDOUT:
                /* Some strange filesystems like AFS return even
                   stranger error numbers.  They cannot reasonably mean
                   anything else so ignore those, too.  */
            case ENOEXEC:
                /* We won't go searching for the shell
                 * if it is not executable - the Linux
                 * kernel already handles this enough,
                 * for us. */
                break;
            default:
                /* Some other error means we found an executable file, but
                   something went wrong executing it; return the error to our
                   caller.  */
                return -errno;
            }
        } while (*p++ != '\0');
        /* We tried every element and none of them worked.  */
        if (got_eacces)
            /* At least one failure was due to permissions, so report that
               error.  */
            return -EACCES;
    }
    /* Return the error from the last attempt (probably ENOENT).  */
    return -errno;
}
