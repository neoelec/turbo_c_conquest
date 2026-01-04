/* File LIST.C */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char buffer[74 + 1];
    unsigned int line = 1;
    FILE *stream;

    if (argc <= 1) {
        puts("Usage: list filename.ext");
        exit(EXIT_FAILURE);
    }

    if ((stream = fopen(argv[1], "rt")) == NULL) {
        puts("File not found !");
        exit(EXIT_FAILURE);
    }

    while (!feof(stream)) {
        if (fgets(buffer, 74 + 1, stream) == NULL) {
            break;
        }

        printf("%u: %s", line++, buffer);
    }

    return 0;
}
