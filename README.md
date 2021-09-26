# My malloc

Using only brk/sbrk, rewrite the 5 following C library functions:
- malloc
- calloc
- realloc
- reallocarray
- free.

## Allocation strategy

- The memory is aligned to a power of 2.
- The break is aligned to a power of 2 pages.
- Best fit algorithm is used.

## Prototype

``` C
void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb , size_t size);
void *realloc(void *ptr , size_t size);
void *reallocarray(void *ptr , size_t nmemb , size_t size);
```

## Compile

The project compile with *Makefile*:

For compile the project use the commande:

```console
foo@bar:~/malloc$ make re
```
It will compile a shared library, which you can now use for your project (a nice tutorial [here](https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html))

For clean the project use:

```console
foo@bar:~/malloc$ make fclean
```