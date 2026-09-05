# Lab 2: systemcalls

## trace

It seemed terrifying to work with system calls but by looking at `hints` I almost one-shotted it! Kinda proud of myself now :), though the professor mentioned the simplicity of this lab compared to the upcoming ones.

## sysinfo

Still struggling. I don't know how to retrieve a user-space struct once I'm in the kernel-mode. Use argadd? Then how am I supposed to convert this pointer back to a struct? He'b :(

Day 09:
Okay. I think I got it. Now I know how to use `argadd()` to get a pointer to the struct that user has passed. 
Also, reading `user/sysinfotest.c` helped a lot in understanding what's being passed to the systemcall. However, I still don't feel comfortable describing how a user-called func is linked to a kernel-level func. You know, there's like a lot of places where you should put your syscall func name, and I'm a bit confused about where things should go. 
Overall, now I user `argadd()` and then `copyout()` to copy to the user-space struct (whose pointer I got from `argadd()`).

Now we're stuck at finding the amount of free memory. I simply used PHYSTOP - kmem.freelist but it mistakenly gave nonzero values when there was no memory. So I had to use
```c
if (r)
```
to catch that. Then I came to realize than acquire and release of `kmem.lock` is necessary. But I still announce more than actual free memory and that's an issue.

Update:
I came up with this, instead of counting the free memory bytes I count the number of free pages and multiply it by PGSIZE. 
```c
uint64
fmem(void)
{
  struct run *r;
  uint64 fm = 0;
  acquire(&kmem.lock);
  r = kmem.freelist;
  for(; r; r=r->next)
    fm++;
  release(&kmem.lock);
  return fm * PGSIZE;
}
```