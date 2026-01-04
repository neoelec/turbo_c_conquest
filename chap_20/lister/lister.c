/* File LISTER.C: 80 Column lister */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCOLUMN 79
#define FGETS_MAX_SIZE (127 + 2)
#define MAXLENGTH (MAXCOLUMN - 5)

/* The parameter s must be a string constant. */
#define printerrmsg(s)              \
    do {                            \
        fputs("\n" s "\n", stderr); \
        exit(EXIT_FAILURE);         \
    } while (0);

int main(int argc, char *argv[])
{
    char buffer[FGETS_MAX_SIZE], *bufp, temp;
    unsigned int line = 1, longlines = 0, len;
    FILE *stream;

    if (argc <= 1) {
        puts("Usage: lister filename.ext");
        exit(EXIT_FAILURE);
    }

    if ((stream = fopen(argv[1], "rt")) == NULL) {
        printerrmsg("File not found !");
    }

    while (fgets(buffer, FGETS_MAX_SIZE, stream) != NULL) {
        if ((bufp = strchr(buffer, '\n')) != NULL) {
            *bufp = '\0';
        } else {
            printerrmsg("Line too long");
        }

        if ((len = strlen(buffer)) > MAXLENGTH) {
            temp = buffer[MAXLENGTH + 1];
            buffer[MAXLENGTH + 1] = '\0';
            bufp = strrchr(buffer, ' ');

            if ((bufp != NULL) && (len - (bufp - buffer) <= MAXLENGTH)) {
                *bufp = '\0';
                buffer[MAXLENGTH + 1] = temp;
            } else {
                printerrmsg("Word too long");
            }

            longlines++;
        }

        fprintf(stdout, "%4u %s\n", line++, buffer);

        if (len > MAXLENGTH) {
            fprintf(stdout, "     %*s\n", MAXLENGTH, ++bufp);
        }

        if (line >= 10000) {
            printerrmsg("File too long");
        }
    }

    if (ferror(stream)) {
        printerrmsg("File reading error !");
    } else {
        fprintf(stdout, "\n\nTotal %u lines.\n", --line);
        fprintf(stdout, "Total %u long lines.\n", longlines);
        exit(EXIT_SUCCESS);
    }

    return 0;
}
