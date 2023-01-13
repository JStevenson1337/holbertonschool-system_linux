0x01. Multithreading
====================

### Concepts

_For this project, we expect you to look at this concept:_

*   [EYNTK - Multithreading](/concepts/772)

Resources
---------

**Read or watch**:

*   [pthread.h](/rltoken/tWwZa4S_4Q22_Z9NqW_Kbg "pthread.h")
*   [Concurrency vs. Parallelism](/rltoken/3OiJw1Erj7u7loOmTezADg "Concurrency vs. Parallelism")

Learning Objectives
-------------------

At the end of this project, you are expected to be able to [explain to anyone](/rltoken/2oeA8d4PD_II2F9zVO9qrA "explain to anyone"), **without the help of Google**:

*   What is a thread
*   What are the differences between a thread and a process
*   What is the difference between Concurrency and Parallelism
*   How to create a thread
*   How to properly exit a thread
*   How to handle mutual execution
*   What is a deadlock
*   What is a race condition

Requirements
------------

### General

*   Allowed editors: `vi`, `vim`, `emacs`
*   All your files will be compiled on Ubuntu 14.04 LTS
*   Your C programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` `and -pedantic`
*   All your files should end with a new line
*   A `README.md` file, at the root of the folder of the project, is mandatory
*   Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl "betty-doc.pl")
*   You are not allowed to have more than 5 functions per file
*   The prototypes of all your functions should be included in your header file called `multithreading.h`
*   Don’t forget to push your header files
*   All your header files should be include guarded
*   You are allowed to use `global` variables
*   You are allowed to use `static` functions and variables

### Betty Compliance

*   All the C source files in your directory and subdirectories must be [Betty-compliant](/rltoken/q3YrZ-42tio-aoWbMVW0lw "Betty-compliant")

### Allowed Functions and System Calls

*   Unless specified otherwise, you are allowed to use the C standard library

### Data structures

Here are the data structures used throughout this project, make sure to include them in your header file `multithreading.h`.
```
    #include <stddef.h>
    #include <stdint.h>
    
    /**
     * struct pixel_s - RGB pixel
     *
     * @r: Red component
     * @g: Green component
     * @b: Blue component
     */
    typedef struct pixel_s
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
    } pixel_t;
    
    /**
     * struct img_s - Image
     *
     * @w:      Image width
     * @h:      Image height
     * @pixels: Array of pixels
     */
    typedef struct img_s
    {
        size_t w;
        size_t h;
        pixel_t *pixels;
    } img_t;
    
    /**
     * struct kernel_s - Convolution kernel
     *
     * @size:   Size of the matrix (both width and height)
     * @matrix: Kernel matrix
     */
    typedef struct kernel_s
    {
        size_t size;
        float **matrix;
    } kernel_t;
    
    /**
     * struct blur_portion_s - Information needed to blur a portion of an image
     *
     * @img:      Source image
     * @img_blur: Destination image
     * @x:        X position of the portion in the image
     * @y:        Y position of the portion in the image
     * @w:        Width of the portion
     * @h:        Height of the portion
     * @kernel:   Convolution kernel to use
     */
    typedef struct blur_portion_s
    {
        img_t const *img;
        img_t *img_blur;
        size_t x;
        size_t y;
        size_t w;
        size_t h;
        kernel_t const *kernel;
    } blur_portion_t;
```

### Manual QA Review

**It is your responsibility to request a review for your work on the Task #3 from a peer before the project’s deadline. If no peers have been reviewed, you should request a review from a TA or staff member.**

Tasks
-----

### 0\. Thread entry point

mandatory

Write a function that will serve as the entry point to a new thread.

*   Prototype: `void *thread_entry(void *arg);`, where:
    *   `arg` holds the address of a string that must be printed and followed by a new line.
*   Make sure to respect the order in which strings are printed out in the following example:
```
    alex@~/0x01-multithreading$ cat 0-main.c
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <pthread.h>
    #include "multithreading.h"
    
    /**
     * main - Entry point
     *
     * Return: EXIT_SUCCESS
     */
    int main(void)
    {
        pthread_t tid;
    
        pthread_create(&tid, NULL, &thread_entry, "Holberton School");
    
        sleep(1);
        printf("Created thread ID -> %lu\n", tid);
    
        thread_entry("C is fun");
        printf("Should not be printed\n");
        return (EXIT_SUCCESS);
    }
    alex@~/0x01-multithreading$ gcc -Wall -Wextra -Werror -pedantic -g3 0-main.c 0-thread_entry.c -o 0-thread_entry -pthread
    alex@~/0x01-multithreading$ ./0-thread_entry
    Holberton School
    Created thread ID -> 139851772159744
    C is fun
    alex@~/0x01-multithreading$
```

**Repo:**

*   GitHub repository: `holbertonschool-system_linux`
*   Directory: `0x01-multithreading`
*   File: `0-thread_entry.c`

### 1\. Thread Logger

mandatory

Write a function that uses the `printf` family to print out a given formatted string.

*   Prototype: `int tprintf(char const *format, ...);`
*   The output must be preceded by the calling thread ID, as the following output shows.
```
    alex@~/0x01-multithreading$ cat 1-main.c
    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>
    #include "multithreading.h"
    
    /**
     * _thread_entry - Thread entry point. Prints out a string
     *
     * @arg: Unused
     *
     * Return: NULL
     */
    void *_thread_entry(__attribute__((unused))void *arg)
    {
        tprintf("Hello from thread\n");
        return (NULL);
    }
    
    /**
     * main - Entry point
     *
     * Return: EXIT_SUCCESS
     */
    int main(void)
    {
        pthread_t tid;
    
        pthread_create(&tid, NULL, &_thread_entry, NULL);
        pthread_join(tid, NULL);
    
        tprintf("Hello from main thread\n");
    
        return (EXIT_SUCCESS);
    }
    alex@~/0x01-multithreading$ gcc -Wall -Wextra -Werror -pedantic -g3 1-main.c 1-tprintf.c -o 1-tprintf -pthread
    alex@~/0x01-multithreading$ ./1-tprintf
    [140095003338496] Hello from thread
    [140095011714880] Hello from main thread
    alex@~/0x01-multithreading$ ./1-tprintf
    [139794647717632] Hello from thread
    [139794656094016] Hello from main thread
    alex@~/0x01-multithreading$
```

**Repo:**

*   GitHub repository: `holbertonschool-system_linux`
*   Directory: `0x01-multithreading`
*   File: `1-tprintf.c`


### 2\. Blur portion of an image

mandatory

Write a method that blurs a portion of an image using a [Gaussian Blur](/rltoken/HpOAwSwYRejSSLUG0SoyAQ "Gaussian Blur").

*   Prototype: `void blur_portion(blur_portion_t const *portion);`, where:
    *   `portion` points to a data structure described in the project requirements
```
    alex@~/0x01-multithreading$ cat 10-main.c
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "multithreading.h"
    
    /**
     * load_kernel - Load convolution kernel from a file
     *
     * @kernel: Pointer to the kernel structure to fill in
     * @file:   Path to the file to parse
     */
    void load_kernel(kernel_t *kernel, char const *file)
    {
        FILE *f;
        size_t i, j;
    
        f = fopen(file, "r");
        fscanf(f, "%lu\n", &kernel->size);
        printf("Kernel size -> %lu\n", kernel->size);
        kernel->matrix = malloc(kernel->size * sizeof(float *));
        for (i = 0; i < kernel->size; i++)
        {
            kernel->matrix[i] = malloc(kernel->size * sizeof(float));
            for (j = 0; j < kernel->size; j++)
                fscanf(f, "%f", &kernel->matrix[i][j]);
        }
        fclose(f);
    }
    
    /**
     * load_image - Load an image from a PBM file
     *
     * @img:  Pointer to the image structure to fill in
     * @file: Path to the file to parse
     */
    void load_image(img_t *img, char const *file)
    {
        FILE *f;
        size_t i;
    
        f = fopen(file, "r");
        fscanf(f, "P6\n %lu %lu 255\n", &img->w, &img->h);
        printf("Image size -> %lu * %lu\n", img->w, img->h);
        img->pixels = malloc(img->w * img->h * sizeof(*img->pixels));
    
        for (i = 0; i < img->w * img->h; i++)
            fscanf(f, "%c%c%c", &img->pixels[i].r, &img->pixels[i].g, &img->pixels[i].b);
        fclose(f);
    }
    
    /**
     * img_copy - Copy an image structure
     *
     * @dest: Pointer to the image structure to fill in
     * @src:  Pointer to the image structure to copy
     */
    void img_copy(img_t *dest, img_t const *src)
    {
        size_t nb_pixels = src->w * src->h;
    
        dest->w = src->w;
        dest->h = src->h;
        dest->pixels = malloc(nb_pixels * sizeof(pixel_t));
        memcpy(dest->pixels, src->pixels, nb_pixels * sizeof(pixel_t));
    }
    
    /**
     * write_image - Write an image into a PBM file
     *
     * @img:  Pointer to the image structure to write into a file
     * @file: Path to the file to write the image into
     */
    void write_image(img_t const *img, char const *file)
    {
        FILE *f;
        size_t i;
    
        f = fopen(file, "w");
        fprintf(f, "P6\n %lu %lu 255\n", img->w, img->h);
        for (i = 0; i < img->w * img->h; i++)
            fprintf(f, "%c%c%c", img->pixels[i].r, img->pixels[i].g, img->pixels[i].b);
        fclose(f);
    }
    
    /**
     * main - Entry point
     *
     * @ac: Arguments counter
     * @av: Arguments vector
     *
     * Return: EXIT_SUCCESS upon success, error code upon failure
     */
    int main(int ac, char **av)
    {
        img_t img, img_blur;
        kernel_t kernel;
        blur_portion_t portion;
        size_t i;
    
        if (ac < 3)
        {
            printf("Usage: %s image.ppm kernel.knl\n", av[0]);
            return (EXIT_FAILURE);
        }
    
        load_image(&img, av[1]);
        img_copy(&img_blur, &img);
        load_kernel(&kernel, av[2]);
    
        /* Execute blur */
        portion.img = &img;
        portion.img_blur = &img_blur;
        portion.kernel = &kernel;
        portion.w = img.w / 2;
        portion.h = img.h / 2;
        portion.x = img.w / 4;
        portion.y = img.h / 4;
        blur_portion(&portion);
    
        write_image(&img_blur, "output.pbm");
    
        /* Cleanup */
        free(img.pixels);
        free(img_blur.pixels);
        for (i = 0; i < kernel.size; i++)
            free(kernel.matrix[i]);
        free(kernel.matrix);
    
        return (EXIT_SUCCESS);
    }
    alex@~/0x01-multithreading$ cat images/kernel_0.knl
    5
    0.1 0.25 0.5 0.25 0.1
    0.25 0.5 0.85 0.5 0.25
    0.5 0.85 1.0 0.85 0.5
    0.25 0.5 0.85 0.5 0.25
    0.1 0.25 0.5 0.25 0.1
    alex@~/0x01-multithreading$ gcc -Wall -Wextra -Werror -pedantic -g3 10-main.c 10-blur_portion.c -o 10-blur_portion
    alex@~/0x01-multithreading$ ./10-blur_portion images/car.pbm images/kernel_0.knl
    Image size -> 960 * 540
    Kernel size -> 5
    alex@~/0x01-multithreading$
```
