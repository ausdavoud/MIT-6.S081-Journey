# Journey

## Lecture 1

Going through lecture 1 materials
- [X] [Video](https://youtu.be/L6YqHxYHa7A)
- [X] [Introduction](https://pdos.csail.mit.edu/6.828/2021/slides/6s081-lec-intro.pdf) 
- [ ] [Example](https://pdos.csail.mit.edu/6.828/2021/lec/l-overview/)
- [X] chapter 1 of [xv6 book](https://pdos.csail.mit.edu/6.828/2021/xv6/book-riscv-rev2.pdf)
- [X] [Notes](https://pdos.csail.mit.edu/6.828/2021/lec/l-overview.txt)
- [X] [Unix video](https://www.youtube.com/watch?v=tc4ROCJYbm0) for my amusement

- [My Notes](./LEC-01/Notes.md)


Let's do our first lab

- [ ] [Lab Guidelines](https://pdos.csail.mit.edu/6.828/2021/labs/guidance.html)
    - >Only when you have a firm grasp of the assignment and solution, then start coding
    
    Oops!

    - >If you do not really understand pointers in C, you will suffer untold pain and misery in the labs.

    LMAO. The "Untold pain and misery" part got me. XD
    
    - [X] [Pointers Exercise](https://pdos.csail.mit.edu/6.828/2019/lec/pointers.c). So interesting. Evaluating part 5 by pen and paper is so recommended.
    - [X] Learn about `script` command in Unix
    - [ ] [Git for Computer Scientists](https://eagain.net/articles/git-for-computer-scientists/) - A bit hard to grasp
    - [ ] gdb Guides in Lab
    - [ ] [gdb slides](https://pdos.csail.mit.edu/6.828/2019/lec/gdb_slides.pdf)

- [ ] [Course Reference Materials](https://pdos.csail.mit.edu/6.828/2021/reference.html)
    - [ ] [The UNIX Time-Sharing System](https://pdos.csail.mit.edu/6.828/2021/readings/ritchie78unix.pdf)

- [ ] [Lab 1: util](https://pdos.csail.mit.edu/6.828/2021/labs/util.html)
    - [X] [Setup tools for doing labs](https://pdos.csail.mit.edu/6.828/2021/tools.html) + Compile xv6 successfully

    - [X] Clone git://g.csail.mit.edu/xv6-labs-2021
        - [X] Had to add `CFLAGS += -Wno-error=infinite-recursion` and `CFLAGS +=-Wno-incompatible-pointer-types` to makefile to compile.

    - [X] [My Notes](./LAB-01/Notes.md)
    - [X] [sleep](./LAB-01/sleep.c)
    - [X] [pingpong](./LAB-01/pingpong.c)
    - [X] [primes](./LAB-01/primes.c)
        - [X] [Nik's answer for making .nanorc work on mac](https://stackoverflow.com/questions/73150633/nano-settings-are-not-adopted-from-nanorc-file)
        - [X] optimize code
    - [X] find
        - [X] C book, Section 5.5
        - [X] Suffer untold pain and misery
    - [X] [xargs](./LAB-01/xargs.c)
        - [X] Hit my head to the wall
        - [X] Clean it up!

- [X] [Lecture question (a random question)](./LEC-01/sq1.txt)