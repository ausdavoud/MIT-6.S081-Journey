#include "kernel/types.h"
#include "user/user.h"
#include "kernel/param.h"

int main(int argc, char *argv[])
{
    char *ch_argv[argc];
    char buf[512], *p;
    p = buf;

    for (int k = 1; k < argc; k++)
        ch_argv[k - 1] = argv[k];

    while (read(0, p, 1) > 0)
    {
        if (*p == '\n')
        {
            *p = '\0';
            ch_argv[argc - 1] = buf;
            if (fork() == 0)
            {
                exec(ch_argv[0], ch_argv);
                fprintf(2, "exec: failed");
                exit(0);
            }
            wait(0);
            p = buf;
        }
        p++;
    }
    exit(0);
}