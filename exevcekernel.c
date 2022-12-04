#include "simple.h"
#ifndef TEST
#else
#include <stdio.h>
#define um_kmalloc malloc
#endif

int execvekernel(char *buf, const char *file, char *const argv[])
{
	if (*file == '\0')
		return -ENOENT;
	if (strchr(file, '/') != NULL)
		execv(file, argv);
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
		name = memcpy(buf + pathlen + 1, file, len);
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
				startp = name + 1;
			else
				startp = memcpy(name - (p - path), path, p - path);
			execv(startp, argv);
			switch (errno)
			{
			case EACCES:
				got_eacces = 1;
				break;
			case ENOENT:
			case ESTALE:
			case ENOTDIR:
			case ENODEV:
			case ETIMEDOUT:
			case ENOEXEC:
				break;
			default:
				return -errno;
			}
		} while (*p++ != '\0');
		if (got_eacces)
			return -EACCES;
	}
	return (-errno);
}
