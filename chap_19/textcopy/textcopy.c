/* File TEXTCOPY.C */

#include <stdio.h>
#include <stdlib.h>

#define BUFMAX 256 /* Max: 255 characters per line */

int main(int argc, char *argv[])
{
    char s[BUFMAX];
    FILE *source, *destin;

    if (argc <= 2) {
        puts("Usage: textcopy source destin");
        exit(EXIT_FAILURE);
    }

    if ((source = fopen(argv[1], "rt")) == NULL) {
        perror("Source");
        exit(EXIT_FAILURE);
    }

    if ((destin = fopen(argv[2], "wt")) == NULL) {
        perror("Destin");
        exit(EXIT_FAILURE);
    }

    while (fgets(s, BUFMAX, source) != NULL) {
        if (fputs(s, destin) == EOF) {
            break;
        }
    }

    if (ferror(source) || ferror(destin)) {
        perror("Copying");
        exit(EXIT_FAILURE);
    } else {
        fputc('\x1a', destin);
    }

    if (fclose(destin) == EOF) {
        perror("Destin");
        exit(EXIT_FAILURE);
    } else {
        printf("Text file \"%s\" copied to \"%s\"\n", argv[1], argv[2]);
        exit(EXIT_SUCCESS);
    }

    return 0;
}
