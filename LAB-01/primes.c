#include "kernel/types.h"
#include "user/user.h"

#define MAX_PRIME 35
#define ARRAY_SIZE MAX_PRIME - 1

void primer(int lp[])
{
  int prime;
  read(lp[0], &prime, sizeof(prime));
  fprintf(1, "prime %d\n", prime);

  int next_pipe_first_element;
  int r = read(lp[0], &next_pipe_first_element, sizeof(next_pipe_first_element));
  if (r == 0)
  {
    exit(0);
  }
  int rp[2];
  pipe(rp);
  if (fork() == 0)
  {
    close(rp[1]);
    primer(rp);
    exit(0);
  }
  write(rp[1], &next_pipe_first_element, sizeof(next_pipe_first_element));

  int n;
  while (read(lp[0], &n, sizeof(n)) != 0)
  {
    if (n % prime == 0)
    {
      continue;
    }
    write(rp[1], &n, sizeof(n));
  }
  close(lp[0]);
  close(rp[1]);
  close(rp[0]);
  wait(0);
  exit(0);
}

int main()
{
  int nums[ARRAY_SIZE];

  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    nums[i] = i + 2; // Start from 2
  }
  int lp[2];
  pipe(lp);

  if (fork() == 0)
  {
    close(lp[1]);
    primer(lp);
    exit(0);
  }

  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    write(lp[1], &nums[i], sizeof(nums[i]));
  }
  close(lp[1]);
  close(lp[0]);
  wait(0);
  exit(0);
}
