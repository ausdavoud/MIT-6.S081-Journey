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
    - [X] gdb Guides in Lab
    - [X] [gdb slides](https://pdos.csail.mit.edu/6.828/2019/lec/gdb_slides.pdf)

- [ ] [Course Reference Materials](https://pdos.csail.mit.edu/6.828/2021/reference.html)
    - [ ] [The UNIX Time-Sharing System](https://pdos.csail.mit.edu/6.828/2021/readings/ritchie78unix.pdf)

- [X] [Lab 1: util](https://pdos.csail.mit.edu/6.828/2021/labs/util.html)
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


## Lecture 2

- [X] [C Slides](https://pdos.csail.mit.edu/6.828/2021/lec/6S081-Intro-to-C-Fa21.pdf)
- [X] [gdb](https://pdos.csail.mit.edu/6.828/2021/lec/gdb_slides.pdf)
- [X] The C Book, 2.9: Bitwise operations
    - [X] [Exercise 2.6: setbits](./LEC-02/EXERCISES/2.6.c)
    - [X] [Exercise 2.7: invert](./LEC-02/EXERCISES/2.7.c)
    - [X] [Exercise 2.8: rightrot](./LEC-02/EXERCISES/2.8.c)
    - [X] Read through 5.1 to 5.6, 6.4

## Lecture 3

- [X] Chapter 2 xv6
- [X] [Video](https://youtu.be/o44d---Dk4o)

- [X] [Lab 2: syscall](https://pdos.csail.mit.edu/6.828/2021/labs/syscall.html)
  - [X] lab 1: trace
  - [X] lab 2: sysinfo


## Lecture 4

- [X] Chapter 3 xv6
- [X] [Video](https://youtu.be/f1Hpjty3TT8)

Honestly, didn't get much out of it. It was kinda hard to grasp the whys behinds the memeory numberings. I also have some problems understanding page layout. That feeling when you'v learned something but you can't talk about it (so you actaully don't know it). I'll get better once I get to labs.


## Lecture 5

- [ ] [GDB PDF](https://pdos.csail.mit.edu/6.828/2021/lec/gdb_slides.pdf)
- [ ] [RISC-V Calling Conventions](https://pdos.csail.mit.edu/6.828/2021/readings/riscv-calling.pdf) or [here](https://riscv.org/wp-content/uploads/2024/12/riscv-calling.pdf)
- [ ] [Video](https://youtu.be/s-Z5t_yTyTM)
  - [My Notes](./LEC-05/Notes.md) 

- [ ] [Lab 3: pgtbl](https://pdos.csail.mit.edu/6.828/2021/labs/pgtbl.html)
  - [ ] Speed up system calls (easy)
  - [ ] Print a page table (easy)
  - [ ] Detecting which pages have been accessed (hard)