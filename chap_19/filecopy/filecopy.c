/* File FILECOPY.C */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int c;
    FILE *source, *destin;

    if (argc <= 2) {
        puts("Usage: filecopy source destin");
        exit(EXIT_FAILURE);
    }

    if ((source = fopen(argv[1], "rb")) == NULL) {
        perror("Source");
        exit(EXIT_FAILURE);
    }

    if ((destin = fopen(argv[2], "wb")) == NULL) {
        perror("Destin");
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(source)) != EOF) {
        if (fputc(c, destin) == EOF) {
            break;
        }
    }

    if (ferror(source) || ferror(destin)) {
        perror("Copying");
        exit(EXIT_FAILURE);
    } else if (fclose(destin) == EOF) {
        perror("Destin");
        exit(EXIT_FAILURE);
    } else {
        printf("%s copied to %s\n", argv[1], argv[2]);
        exit(EXIT_SUCCESS);
    }

    return 0;
}
