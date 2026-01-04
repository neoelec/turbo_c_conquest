/* File ARGS.C */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    for (i = 0; i < argc; i++) {
        printf("argv[%u] == |%s|\n", i, argv[i]);
    }

    return 0;
}
