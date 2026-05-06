#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int p2c[2];
    int c2p[2];
    char buff[1];

    pipe(p2c);
    pipe(c2p);

    if (fork() == 0)
    {
        // child
        read(p2c[0], buff, sizeof(buff));
        fprintf(1, "%d: received ping\n", getpid());
        write(c2p[1], buff, sizeof(buff));
        exit(0);
    }
    // parent
    write(p2c[1], buff, sizeof(buff));
    read(c2p[0], buff, sizeof(buff));
    fprintf(1, "%d: received pong\n", getpid());
    exit(0);
}