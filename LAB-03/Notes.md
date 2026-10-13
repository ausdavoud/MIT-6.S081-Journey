# Lab 3: Page tables


## ugetpid

I'm dead bro. This was supposed to be a simple one but I've wasted my entire life on it. Never mind. Let's see what I learned.

The lab told us to use a struct. Then I saw that the pid is a part of the `proc` struct in `kernel/proc.h`. That's why I added `struct usyscall *usyscall` there.

Then I just copycat what the current code was doing. 

> Hint 1: You can perform the mapping in proc_pagetable() in kernel/proc.c.

So I went to `kernel/proc.c` and wrote the same code as `TRAPFRAME`, as it also happens to be a struct.

> Hint 4: Don't forget to allocate and initialize the page in allocproc().

So I went there and saw how they've done it for `trapframe` and did the same for my `usyscall`. The part I'm proud of myself about, is that I added an else statement and initialized the struct there.


> Hint 5: Make sure to free the page in freeproc().
I
I did this just like it was done for `trapframe`.



But the goddamn kernel panicked on startup! So I turned gdb on and used a bunch of `bt`, `list`, `frame 1`, `lay spl` commands only to realize that it panicked on `panic("freewalk: leaf")`. It's in vm.c:freewalk. Comments say all lead mapping must already have been removed. And, the panic happens when `pte & PTE_V`. So the pte must be in the leaf or something. I'm not sure. Anyway. It gave me an idea that this must be related to cleaning things up. It took me a hundred years to realize that only one line above `uvmfree` (the caller of `freewalk`), I should've called `uvmunmap` to unmap `USYSCALL`. GOD DAMN IT!

Ok. men write code, test pass, men happy.


## pte printout

I learned that if a pte has `PTE_R`, `PTE_W` or `PTE_X` flag on it, it's in the last level (level 0) of the hierarchy, meaning that it points to a real pa, not another page table. We use these flags to identify such ptes. Let's go. Easy Lab. I'm a legend. Legend of easy labs. lol. talking to much. happy. inspired. yeah...