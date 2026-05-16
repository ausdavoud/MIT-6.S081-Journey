#include "kernel/types.h"
#include "user/user.h"
#include "kernel/stat.h"
#include "kernel/fs.h"

void find(char *path, char *name)
{
    int fd;
    struct stat st;
    struct dirent de;
    char buf[512], *p;
    if ((fd = open(path, 0)) < 0)
    {
        fprintf(2, "find: cannot open %s\n", path);
        return;
    }

    if (fstat(fd, &st) < 0)
    {
        fprintf(2, "find: cannot stat %s\n", path);
        close(fd);
        return;
    }
    switch (st.type)
    {
    case T_FILE:
        // Didn't check for strlen(filename) >= DIRSIZ
        char *n;
        for (n = path + strlen(path); n >= path && *n != '/'; n--)
            ;
        n++;
        if (!strcmp(name, n))
            fprintf(1, "%s\n", path);

        break;

    case T_DIR:
        strcpy(buf, path);
        p = buf + strlen(buf);
        *p++ = '/';
        while (read(fd, &de, sizeof(de)) == sizeof(de))
        {
            if (de.inum == 0 || !strcmp(de.name, ".") || !strcmp(de.name, ".."))
                continue;

            memmove(p, de.name, DIRSIZ);

            p[DIRSIZ] = 0;
            find(buf, name);
        }
        break;
    }

    close(fd);
    return;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(2, "Usage: find <filename> <path>\n");
        exit(1);
    }

    char *path = argv[1];
    char *name = argv[2];

    find(path, name);
    exit(1);
}