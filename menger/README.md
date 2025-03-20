Menger sponge
=============

*   Amateur
*   By: Alexandre Gautier, Software Engineer at Holberton School
*   Weight: 1
*   Your score will be updated as you progress.

*   [Description](#description)

[Go to tasks](#)

![](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/medias/2018/6/970692c4e47bd0546db8.jpg?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20250320%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20250320T083901Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=ad0afca4535d4c455ca82f584e4747211ab728e9b6a3f4479071890c3eaf4e3b)

Requirements
------------

### General

*   Allowed editors: `vi`, `vim`, `emacs`
*   All your files will be compiled on Ubuntu 14.04 LTS
*   Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
*   All your files should end with a new line
*   Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl "betty-doc.pl")
*   You are not allowed to use global variables
*   No more than 5 functions per file
*   In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
*   The prototypes of all your functions should be included in your header file called `menger.h`
*   Don’t forget to push your header file
*   All your header files should be include guarded

Tasks
-----

### 0\. 2D Menger sponge

mandatory

Write a function that draws a 2D Menger Sponge

*   Prototype: `void menger(int level);`
*   Where `level` is the level of the Menger Sponge to draw
*   If `level` is lower than `0`, your function must do nothing
*   You’re allowed to use the `math` library. Your program will be compiled using the `ld` flag `-lm`

Format:

*   First, read [Menger sponge](/rltoken/sioblGPmPzed-nSWynGpQw "Menger sponge")
*   Here, we will only draw a 2D version of the Menger sponge, but the principle is the same
*   A level `N` sponge is a 3x3 square of level `N-1` sponges, except for the center one, which is left empty
*   A level 0 sponge is represented by the `#` character
*   Examples:
    *   A level 0 sponge is a simple 1x1 square
    *   A level 1 sponge is a 3x3 square of level 0 sponges, except for the center one, which is left empty
    *   A level 2 sponge is a 3x3 square of level 1 sponges, except for the center one, which is left empty
    *   …
*   TIP: The size of a level `N` Menger sponge is calculated as follows: `3^N`

    alex@~/menger$ cat 0-main.c
    #include <stdio.h>
    #include <stdlib.h>

    #include "menger.h"

    /**
     * main - Entry point
     *
     * @ac: Arguments counter
     * @av: Arguments vector
     *
     * Return: EXIT_SUCCESS or EXIT_FAILURE
     */
    int main(int ac, char **av)
    {
        int level;

        if (ac < 2)
        {
            fprintf(stderr, "Usage: %s level\n", av[0]);
            return (EXIT_FAILURE);
        }

        level = atoi(av[1]);
        menger(level);

        return (EXIT_SUCCESS);
    }
    alex@~/menger$ gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm
    alex@~/menger$ ./0-menger 0
    #
    alex@~/menger$ ./0-menger 1
    ###
    # #
    ###
    alex@~/menger$ ./0-menger 2
    #########
    # ## ## #
    #########
    ###   ###
    # #   # #
    ###   ###
    #########
    # ## ## #
    #########
    alex@~/menger$ ./0-menger 3
    ###########################
    # ## ## ## ## ## ## ## ## #
    ###########################
    ###   ######   ######   ###
    # #   # ## #   # ## #   # #
    ###   ######   ######   ###
    ###########################
    # ## ## ## ## ## ## ## ## #
    ###########################
    #########         #########
    # ## ## #         # ## ## #
    #########         #########
    ###   ###         ###   ###
    # #   # #         # #   # #
    ###   ###         ###   ###
    #########         #########
    # ## ## #         # ## ## #
    #########         #########
    ###########################
    # ## ## ## ## ## ## ## ## #
    ###########################
    ###   ######   ######   ###
    # #   # ## #   # ## #   # #
    ###   ######   ######   ###
    ###########################
    # ## ## ## ## ## ## ## ## #
    ###########################
    alex@~/menger$ ./0-menger 4
    #################################################################################
    # ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## #
    #################################################################################
    ###   ######   ######   ######   ######   ######   ######   ######   ######   ###
    # #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # #
    ###   ######   ######   ######   ######   ######   ######   ######   ######   ###
    #################################################################################
    # ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## #
    #################################################################################
    #########         ##################         ##################         #########
    # ## ## #         # ## ## ## ## ## #         # ## ## ## ## ## #         # ## ## #
    #########         ##################         ##################         #########
    ###   ###         ###   ######   ###         ###   ######   ###         ###   ###
    # #   # #         # #   # ## #   # #         # #   # ## #   # #         # #   # #
    ###   ###         ###   ######   ###         ###   ######   ###         ###   ###
    #########         ##################         ##################         #########
    # ## ## #         # ## ## ## ## ## #         # ## ## ## ## ## #         # ## ## #
    #########         ##################         ##################         #########
    #################################################################################
    # ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## #
    #################################################################################
    ###   ######   ######   ######   ######   ######   ######   ######   ######   ###
    # #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # #
    ###   ######   ######   ######   ######   ######   ######   ######   ######   ###
    #################################################################################
    # ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## #
    #################################################################################
    ###########################                           ###########################
    # ## ## ## ## ## ## ## ## #                           # ## ## ## ## ## ## ## ## #
    ###########################                           ###########################
    ###   ######   ######   ###                           ###   ######   ######   ###
    # #   # ## #   # ## #   # #                           # #   # ## #   # ## #   # #
    ###   ######   ######   ###                           ###   ######   ######   ###
    ###########################                           ###########################
    # ## ## ## ## ## ## ## ## #                           # ## ## ## ## ## ## ## ## #
    ###########################                           ###########################
    #########         #########                           #########         #########
    # ## ## #         # ## ## #                           # ## ## #         # ## ## #
    #########         #########                           #########         #########
    ###   ###         ###   ###                           ###   ###         ###   ###
    # #   # #         # #   # #                           # #   # #         # #   # #
    ###   ###         ###   ###                           ###   ###         ###   ###
    #########         #########                           #########         #########
    # ## ## #         # ## ## #                           # ## ## #         # ## ## #
    #########         #########                           #########         #########
    ###########################                           ###########################
    # ## ## ## ## ## ## ## ## #                           # ## ## ## ## ## ## ## ## #
    ###########################                           ###########################
    ###   ######   ######   ###                           ###   ######   ######   ###
    # #   # ## #   # ## #   # #                           # #   # ## #   # ## #   # #
    ###   ######   ######   ###                           ###   ######   ######   ###
    ###########################                           ###########################
    # ## ## ## ## ## ## ## ## #                           # ## ## ## ## ## ## ## ## #
    ###########################                           ###########################
    #################################################################################
    # ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## #
    #################################################################################
    ###   ######   ######   ######   ######   ######   ######   ######   ######   ###
    # #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # #
    ###   ######   ######   ######   ######   ######   ######   ######   ######   ###
    #################################################################################
    # ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## #
    #################################################################################
    #########         ##################         ##################         #########
    # ## ## #         # ## ## ## ## ## #         # ## ## ## ## ## #         # ## ## #
    #########         ##################         ##################         #########
    ###   ###         ###   ######   ###         ###   ######   ###         ###   ###
    # #   # #         # #   # ## #   # #         # #   # ## #   # #         # #   # #
    ###   ###         ###   ######   ###         ###   ######   ###         ###   ###
    #########         ##################         ##################         #########
    # ## ## #         # ## ## ## ## ## #         # ## ## ## ## ## #         # ## ## #
    #########         ##################         ##################         #########
    #################################################################################
    # ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## #
    #################################################################################
    ###   ######   ######   ######   ######   ######   ######   ######   ######   ###
    # #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # ## #   # #
    ###   ######   ######   ######   ######   ######   ######   ######   ######   ###
    #################################################################################
    # ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## ## #
    #################################################################################
    alex@~/menger$ ./0-menger -1
    alex@~/menger$


**Repo:**

*   GitHub repository: `holbertonschool-interview`
*   Directory: `menger`
*   File: `0-menger.c, menger.h`
