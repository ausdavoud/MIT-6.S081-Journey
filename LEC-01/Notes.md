Disclaimer: All the material included in this page are derived from https://pdos.csail.mit.edu/6.828/2021/xv6/book-riscv-rev2.pdf


I've noted out some points throughout the first chapter.

1. Each file descriptor also has an offset. `read()` reads from the offset and `write()` writes at the current offset. It seems that among all the things shared between parents and children processes, offset is also shared.
2. A newly allocated file descriptor is always the lowest-
numbered unused descriptor of the current process
3. Ever wondered how to open a file and immediately wipe out its content? Use `O_TRUNC` flag!
4. `cd` runs within the shell; meaning that, shell does not create a child process to run it. Because if it did, then `cd` would change the directory for that child process, not the shell itself

I also have some findings regarding filesystem, file descriptors and file inode.

I'm ranting. So you might as well ignore what I type in here. 

`inode`: Each file has an inode. It's unique. I think it's a struct that holds some sort of metadata for the file, e.g. size, type, where it is on the disk. Oh I almost forgot, it's a number, like 42. 
So up to now, we know that every file on our system has a unique number associated with it called 42. 

`file descriptor (fd)`: It's just a number in RAM. The process has a table in which it maps this number to a file, or more accurately, an inode. Each process has its own table of file descriptors. Typically, 0 is the fd for stdin, 1 for stdout and 2 for stderr. You can close a fd by `close(1)` (for file descriptor 1) and as soon as you use a function like `open()`, `dup()`, etc, it assigns the opened file to the lowest unmapped number (in this case, 1).

`filesystem`: One of its jobs is to keep a table of filenames and their inode. So when we use `int fd = open("myfile.txt", O_RWONLY)`, it's `filesystems`' job to go find the inode of `myfile.txt`, return it, and then map the fd number to the inode number, or more precisely, map fd number to an struct that has a parameter called inode.


Oh I almost forgot this one, too!
What is an anonymous file?
Here it is
```c
int fd = open("/tmp/xyz, O_CREAT|O_RWONLY");
unlink("tmp/xyz")
```
Once unlinked, it becomes invisible to everyone, as if it were deleted (as a matter of fact, `rm` is a wrapper around `unlink`), but since the current process hasn't called `close()` yet, it can. read and write to it, being sure it will be dumped at the end of the execution.

> When is a file completely deleted?

I hear you asking...
Well, each file has two counters associated with it: `nlink` and `opens`
- `open()`: `opens++` and `nlink++`
- `close()`: only `opens--`
- `link()`: only `lnink++`
- `unlink()`: only `nlink--`

A file is only deleted from disk (apparently deleted, since the data block are still there, waiting to be overwritten in the future) when both `opens` and `nlink` are `0`.

