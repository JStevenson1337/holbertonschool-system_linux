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

Here is the image used in the example, before and after execution:

Original image

Blured image

![](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/medias/2020/3/462bb86d1318dfaef9b17eb33d63bc51aef9863e.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20230113%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20230113T061959Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=3d3df62f9447804d0d03151dfd8a980fb3ee534882fdf88fbcb81494db679444)

![](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/medias/2020/3/6350801e008f1c38bc3860c368892485808ad62e.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20230113%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20230113T061959Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=6e2902df397835bfc964449d02871bd212b4f346b75df64ace8e0db5c3635d1b)

[car.pbm](/rltoken/51T5tSRP7kZZKiFqQ7-UEA "car.pbm")

[car\_blured.pbm](/rltoken/YHE94HNnrey7as5e1ihlwg "car_blured.pbm")

![](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/medias/2020/6/015db16205d7525e1eb27ed3e7714d21be3522fd.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20230113%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20230113T061959Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=7fc9e4cb72dc457aff97032ada817133dd8a2c2f337e78c2f1b5d9788eb00e18)

![](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/medias/2020/6/bd3ec2782e968044fdcd67c3fde456314b6f5add.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20230113%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20230113T061959Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=cb3e699fef0149f0c87977758201bec3147a45aaee60e50deda5f6f58686184f)

[small.pbm](/rltoken/C4DEnkWEAJnjHouxarM9iA "small.pbm")

[small\_blured.pbm](/rltoken/K2zIGU21cCFr0XZ9yp2hqg "small_blured.pbm")

**Repo:**

*   GitHub repository: `holbertonschool-system_linux`
*   Directory: `0x01-multithreading`
*   File: `10-blur_portion.c`

#### Students who are done with "2. Blur portion of an image"


#### Correction of "2. Blur portion of an image"


### 3\. Blur entire image

mandatory

Write a method that blurs the entirety of an image using a [Gaussian Blur](/rltoken/HpOAwSwYRejSSLUG0SoyAQ "Gaussian Blur").

*   Prototype: `void blur_image(img_t *img_blur, img_t const *img, kernel_t const *kernel);`, where:
    *   `img_blur` holds the address at which the blured image is stored,
    *   `img` points to the source image,
    *   `kernel` points to the convolution kernel to use
*   You will have to use threads in order to blur the full image.
*   Each thread should blur a portion of the image.
*   You may use up to 16 threads. Keep in mind that too many threads can make your program inefficient.
*   You are free to divide the source image in portions of your choice.
*   The main goal of this task is to demonstrate that using threads make the process faster.
```
    alex@~/0x01-multithreading$ cat 11-main.c
    #include <stdio.h>
    #include <pthread.h>
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
        img_t img;
        img_t img_blur;
        kernel_t kernel;
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
        blur_image(&img_blur, &img, &kernel);
    
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
    alex@~/0x01-multithreading$ gcc -Wall -Wextra -Werror -pedantic -g3 11-main.c 11-blur_image.c 10-blur_portion.c -o 11-blur_image -pthread
    alex@~/0x01-multithreading$ time ./11-blur_image images/car.pbm images/kernel_0.knl
    Image size -> 960 * 540
    Kernel size -> 5
    
    real    0m0.143s
    user    0m0.197s
    sys 0m0.076s
    alex@~/0x01-multithreading$
    
```
Here is the image used in the example, before and after execution:

Original image

Blured image

![](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/medias/2020/3/462bb86d1318dfaef9b17eb33d63bc51aef9863e.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20230113%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20230113T061959Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=3d3df62f9447804d0d03151dfd8a980fb3ee534882fdf88fbcb81494db679444)

![](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/medias/2020/3/66c9e02b6a18cf3481464d92a4c537c73df62458.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20230113%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20230113T061959Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=0427b198ce853d6d15132bce3df6abe4e45765b3face4e53c3d09e720c43acd1)

[car.pbm](/rltoken/51T5tSRP7kZZKiFqQ7-UEA "car.pbm")

[car\_blured\_full.pbm](/rltoken/sLMQwib7GPYv1frJrY7S8Q "car_blured_full.pbm")

**Repo:**

*   GitHub repository: `holbertonschool-system_linux`
*   Directory: `0x01-multithreading`
*   File: `11-blur_image.c`


#### Students who are done with "3. Blur entire image"

### 4\. Thread logger v2

mandatory

Write a function that uses the `printf` family to print out a given formatted string.

This time, you will also have to use a `mutex` to avoid race conditions. As you know, a mutex needs to be initialized, and destroyed, but we don’t want to have to do that ourselves in our `main.c` program. Please read about [Constructors and Destructors with GCC](/rltoken/UAdi7xb4WEj2ni8yZHIgbA "Constructors and Destructors with GCC") and it should all make sense :).

*   Prototype: `int tprintf(char const *format, ...);`
*   The output must be preceded by the calling thread ID, as the following output shows.
*   Tip: You are allowed to use global variables - Don’t forget to run Betty with the option `--allow-global-variables`

**NOTE**: In the following example, we first compile with our first version of `tprintf` to show the consequence of the race condition.
```
    alex@~/0x01-multithreading$ cat 20-main.c
    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>
    #include "multithreading.h"
    
    #define NB_THREADS  10
    
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
        pthread_t tid[NB_THREADS];
        int i;
    
        for (i = 0; i < NB_THREADS; i++)
            pthread_create(&tid[i], NULL, &_thread_entry, NULL);
    
        tprintf("Hello from main thread\n");
    
        for (i = 0; i < NB_THREADS; i++)
            pthread_join(tid[i], NULL);
    
        return (EXIT_SUCCESS);
    }
    alex@~/0x01-multithreading$ gcc -Wall -Wextra -Werror -pedantic -g3 20-main.c 1-tprintf.c -o 20-tprintf -pthread
    alex@~/0x01-multithreading$ ./20-tprintf
    [139996670035712] [139996678428416] [139996686821120] [139996695197504] Hello from thread
    [139996644857600] Hello from thread
    [139996628072192] Hello from thread
    [139996619679488] Hello from thread
    Hello from main thread
    Hello from thread
    Hello from thread
    [139996611286784] Hello from thread
    [139996661643008] Hello from thread
    [139996636464896] Hello from thread
    [139996653250304] Hello from thread
    alex@~/0x01-multithreading$ gcc -Wall -Wextra -Werror -pedantic -g3 20-main.c 20-tprintf.c -o 20-tprintf -pthread
    alex@~/0x01-multithreading$ ./20-tprintf
    [140146877490944] Hello from thread
    [140146852312832] Hello from thread
    [140146843920128] Hello from thread
    [140146860705536] Hello from thread
    [140146835527424] Hello from thread
    [140146869098240] Hello from thread
    [140146818742016] Hello from thread
    [140146885867328] Hello from main thread
    [140146810349312] Hello from thread
    [140146801956608] Hello from thread
    [140146827134720] Hello from thread
    alex@~/0x01-multithreading$
```

**Repo:**

*   GitHub repository: `holbertonschool-system_linux`
*   Directory: `0x01-multithreading`
*   File: `20-tprintf.c`



#### Students who are done with "4. Thread logger v2"

#### Correction of "4. Thread logger v2"

### 5\. Number to prime factors

mandatory

Write a function that factorizes a number into a list of prime factors.

*   Prototype: `list_t *prime_factors(char const *s);`, where
    *   `s` is the string representation of the number to factorize.
    *   This number will be positive and fit into an `unsigned long`
*   Your code will be compiled with the file `list.c`
    *   [list.h](/rltoken/6w425zOFamKwqWFtI_yh4A "list.h")
    *   [list.c](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/text/2020/6/876fd3ce1c3a690faa56139f88efd28a0561fbf9.c?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20230113%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20230113T061959Z&X-Amz-Expires=345600&X-Amz-SignedHeaders=host&X-Amz-Signature=07a277a068d611175c53d60e4b75ea7693f8e85f9e9e1ed8febfca8cf321692a "list.c")
*   **NOTE**: This task does not require multithreading, and will not be linked to the pthread library.
```
    alex@~/0x01-multithreading$ cat 21-main.c
    #include <stdlib.h>
    #include <stdio.h>
    #include "multithreading.h"
    
    /**
     * print_factors - Print a nmber and its prime factorization
     *
     * @s:       Number as string
     * @factors: List of prime factors
     */
    static void print_factors(char const *s, list_t const *factors)
    {
        node_t const *factor;
    
        printf("%s =", s);
        for (factor = factors->head; factor; factor = factor->next)
        {
            unsigned long n = *((unsigned long *)factor->content);
    
            printf("%s %lu", factor->prev ? " *" : "", n);
        }
        printf("\n");
    }
    
    /**
     * main - Entry point
     *
     * @ac: Arguments count
     * @av: Arguments vector
     *
     * Return: EXIT_SUCCESS upon success, EXIT_FAILURE otherwise
     */
    int main(int ac, char **av)
    {
        size_t i;
    
        if (ac < 2)
        {
            fprintf(stderr, "Usage: %s n\n", av[0]);
            return (EXIT_FAILURE);
        }
    
        for (i = 1; i < (size_t)ac; i++)
        {
            list_t *factors;
    
            factors = prime_factors(av[i]);
            print_factors(av[i], factors);
            list_destroy(factors, free);
            free(factors);
        }
    
        return (EXIT_SUCCESS);
    }
    alex@~/0x01-multithreading$ gcc -Wall -Wextra -Werror -pedantic -g3 21-main.c 21-prime_factors.c list.c -o 21-prime_factors
    alex@~/0x01-multithreading$ ./21-prime_factors 745 872346 79283472974
    745 = 5 * 149
    872346 = 2 * 3 * 145391
    79283472974 = 2 * 757 * 52366891
    alex@~/0x01-multithreading$ ./21-prime_factors 1048576
    1048576 = 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2
    alex@~/0x01-multithreading$ ./21-prime_factors 18446744073709551612 18446744073709551609 18446744073709551608
    18446744073709551612 = 2 * 2 * 3 * 715827883 * 2147483647
    18446744073709551609 = 3 * 3 * 818923289 * 2502845209
    18446744073709551608 = 2 * 2 * 2 * 2305843009213693951
    alex@~/0x01-multithreading$
```

**Repo:**

*   GitHub repository: `holbertonschool-system_linux`
*   Directory: `0x01-multithreading`
*   File: `21-prime_factors.c`
*   
#### Students who are done with "5. Number to prime factors"


#### Correction of "5. Number to prime factors"


### 6\. Number to prime factors v2

mandatory

The goal of this task is to reproduce the previous task, and to improve it using a thread pool. The tread pool will have for purpose to execute a list of tasks.

For this task, you will have to write **3 functions** (all in the same file):

*   **Create task**
    
    *   Prototype: `task_t *create_task(task_entry_t entry, void *param);`, where
        *   `entry` is a pointer to the entry function of the task,
        *   `param` is the parameter that will later be passed to the entry function
    *   This function must return a pointer to the created task structure
*   **Destroy task**
    
    *   Prototype: `void destroy_task(task_t *task);`, where
        *   `task` is a pointer to the task to destroy
*   **Execute task list - Thread entry**
    
    *   Prototype: `void *exec_tasks(list_t const *tasks);`, where
        *   `tasks` is a pointer to the list of tasks to be executed
    *   This function serves as a thread entry
    *   This function can safely return NULL as its return value will not be retrieved
    *   This function must go through the list of tasks and execute them, but there’s a challenge:
        *   Multiple thread will be going through the list of tasks, and a task must only be executed once
    *   You must use `tprintf` to print when a task is started, and completed

**Structures**
```
    typedef void *(*task_entry_t)(void *);
    
    /**
     * enum task_status_e - Task statuses
     *
     * @PENDING: Task is pending
     * @STARTED: Task has been started
     * @SUCCESS: Task has completed successfully
     * @FAILURE: Task has completed with issues
     */
    typedef enum task_status_e
    {
        PENDING = 0,
        STARTED,
        SUCCESS,
        FAILURE
    } task_status_t;
    
    /**
     * struct task_s - Executable task structure
     *
     * @entry:  Pointer to a function to serve as the task entry
     * @param:  Address to a custom content to be passed to the entry function
     * @status: Task status, default to PENDING
     * @result: Stores the return value of the entry function
     * @lock:   Task mutex
     */
    typedef struct task_s
    {
        task_entry_t    entry;
        void        *param;
        task_status_t   status;
        void        *result;
        pthread_mutex_t lock;
    } task_t;
```

**Example**
```
    alex@~/0x01-multithreading$ cat 22-main.c
    #include <pthread.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include "multithreading.h"
    
    #define NB_THREADS  8
    
    /**
     * print_task_result - Print the result of a task
     *
     * @task: Pointer to the task to print the result of
     */
    void print_task_result(task_t *task)
    {
    
        list_t *factors = (list_t *)task->result;
        node_t *factor;
    
        printf("%s =", (char *)task->param);
        for (factor = factors->head; factor; factor = factor->next)
        {
            unsigned long n = *((unsigned long *)factor->content);
    
            printf("%s %lu", factor->prev ? " *" : "", n);
        }
        printf("\n");
    }
    
    /**
     * main - Entry point
     *
     * @ac: Arguments count
     * @av: Arguments vector
     *
     * Return: EXIT_SUCCESS upon success, EXIT_FAILURE otherwise
     */
    int main(int ac, char **av)
    {
        list_t tasks;
        pthread_t threads[NB_THREADS];
        size_t i;
    
        if (ac < 2)
        {
            fprintf(stderr, "Usage: %s n\n", av[0]);
            return (EXIT_FAILURE);
        }
    
        if (!list_init(&tasks))
            return (EXIT_FAILURE);
    
        for (i = 1; i < (size_t)ac; i++)
            list_add(&tasks,
                create_task((task_entry_t)prime_factors, av[i]));
    
        printf("Executing %lu tasks on %u threads\n", tasks.size, NB_THREADS);
    
        for (i = 0; i < NB_THREADS; i++)
            pthread_create(&threads[i], NULL,
                (void *(*) (void *))exec_tasks, &tasks);
        for (i = 0; i < NB_THREADS; i++)
            pthread_join(threads[i], NULL);
    
        list_each(&tasks, (node_func_t)print_task_result);
    
        list_destroy(&tasks, (node_func_t)destroy_task);
    
        return (EXIT_SUCCESS);
    }
    alex@~/0x01-multithreading$ gcc -Wall -Wextra -Werror -pedantic -g3 22-main.c 22-prime_factors.c 21-prime_factors.c list.c 20-tprintf.c -o 22-prime_factors -pthread
    alex@~/0x01-multithreading$ ./22-prime_factors 234 23456 908345 9803475893 389475 9384 7538 4753876348956746 4985 39485734 9587398 7938475839 324 3453450
    Executing 14 tasks on 8 threads
    [139770218567424] [00] Started
    [139770218567424] [00] Success
    [139770218567424] [08] Started
    [139770218567424] [08] Success
    [139770218567424] [09] Started
    [139770218567424] [09] Success
    [139770218567424] [10] Started
    [139770218567424] [10] Success
    [139770218567424] [11] Started
    [139770218567424] [11] Success
    [139770218567424] [12] Started
    [139770218567424] [12] Success
    [139770218567424] [13] Started
    [139770218567424] [13] Success
    [139770159818496] [07] Started
    [139770159818496] [07] Success
    [139770201782016] [02] Started
    [139770201782016] [02] Success
    [139770184996608] [04] Started
    [139770184996608] [04] Success
    [139770168211200] [06] Started
    [139770168211200] [06] Success
    [139770193389312] [03] Started
    [139770193389312] [03] Success
    [139770176603904] [05] Started
    [139770176603904] [05] Success
    [139770210174720] [01] Started
    [139770210174720] [01] Success
    234 = 2 * 3 * 3 * 13
    23456 = 2 * 2 * 2 * 2 * 2 * 733
    908345 = 5 * 181669
    9803475893 = 1153 * 8502581
    389475 = 3 * 3 * 3 * 5 * 5 * 577
    9384 = 2 * 2 * 2 * 3 * 17 * 23
    7538 = 2 * 3769
    4753876348956746 = 2 * 11 * 67 * 89 * 89 * 3373 * 120713
    4985 = 5 * 997
    39485734 = 2 * 37 * 47 * 11353
    9587398 = 2 * 2141 * 2239
    7938475839 = 3 * 3 * 7 * 7 * 17 * 53 * 19979
    324 = 2 * 2 * 3 * 3 * 3 * 3
    3453450 = 2 * 3 * 5 * 5 * 7 * 11 * 13 * 23
    alex@~/0x01-multithreading$
```

**Repo:**

*   GitHub repository: `holbertonschool-system_linux`
*   Directory: `0x01-multithreading`
*   File: `22-prime_factors.c`

