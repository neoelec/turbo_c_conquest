/* File DUMP.C: File Dump Utility */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } boolean;

#define printerrmsg(s)              \
    do {                            \
        fputs("\n" s "\n", stderr); \
        exit(EXIT_FAILURE);         \
    } while (0);

void dump(FILE *stream, boolean asciimode);

int main(int argc, char *argv[])
{
    boolean asciimode = false;
    FILE *stream;

    if (argc < 2) {
        puts("Usage: dump filename [-a]");
        exit(EXIT_FAILURE);
    }

    if ((stream = fopen(argv[1], "rb")) == NULL) {
        printerrmsg("File not found !");
    }

    if ((argc >= 3) && (argv[2][0] == '-') && (tolower(argv[2][1]) == 'a')) {
        asciimode = true;
    }

    fprintf(stdout, "\n Dump List of File \"%s\"\n\n", argv[1]);

    dump(stream, asciimode);

    return 0;
}

void dump(FILE *stream, boolean asciimode)
{
    int c[16];
    unsigned int i, eof_pos;
    fpos_t fpos = 0L;

    do {
        if ((c[0] = fgetc(stream)) == EOF) {
            break;
        }

        fprintf(stdout, " %06lX:", fpos);
        fprintf(stdout, " %02X", c[0]);

        for (i = eof_pos = 1; i < 8; i++, eof_pos++) {
            if ((c[i] = fgetc(stream)) == EOF) {
                break;
            }

            fprintf(stdout, " %02X", c[i]);
        }

        fputc(' ', stdout);

        for (; i < 16; i++, eof_pos++) {
            if ((c[i] = fgetc(stream)) == EOF) {
                break;
            }

            fprintf(stdout, " %02X", c[i]);
        }

        if (eof_pos != 16) {
            for (i = 0; i < (16 - eof_pos) * 3; i++) {
                fputc(' ', stdout);
            }
        }

        fprintf(stdout, "   ");

        for (i = 0; i < eof_pos; i++) {
            if (asciimode && !isascii(c[i])) {
                c[i] = '.';
            }

            if (iscntrl(c[i])) {
                c[i] = '.';
            }

            fputc(c[i], stdout);
        }

        fputc('\n', stdout);

        fpos += 16L;
    } while (eof_pos == 16);

    if (ferror(stream)) {
        printerrmsg("\nFile reading error !");
    } else {
        fputc('\x1a', stdout);
    }
}
