/* File MOVBLOCK.C: Block Extract/Replace Utility */

#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define printerrmsg(s)              \
    do {                            \
        fputs("\n" s "\n", stderr); \
        exit(EXIT_FAILURE);         \
    } while (0);

void move_block(FILE *destin, FILE *source, long size);
char getyesno(void);

int main(int argc, char *argv[])
{
    char mode;
    long size;
    fpos_t offset;
    FILE *file, *block;

    if (argc < 5) {
        puts("Usage: moveblock filename [+|-]blockfile offset size ");
        exit(EXIT_FAILURE);
    }

    mode = argv[2][0];

    if ((mode != '+') && (mode != '-')) {
        printerrmsg("Illegal mode !");
    }

    if (mode == '+') {
        if ((file = fopen(argv[1], "r+b")) == NULL) {
            printerrmsg("File not found or file read-only !");
        }
    } else {
        if ((fopen(argv[1], "rb")) == NULL) {
            printerrmsg("File not found !");
        }
    }

    if (mode == '+') {
        if ((block = fopen(argv[2] + 1, "rb")) == NULL) {
            printerrmsg("Blockfile not found !");
        }
    } else {
        if ((block = fopen(argv[2] + 1, "wb")) == NULL) {
            printerrmsg("Invalid blockfile name !");
        }
    }

    if ((sscanf(argv[3], "%li", &offset) != 1) || (offset < 0L)) {
        printerrmsg("Illegal offset !");
    }

    if ((sscanf(argv[4], "%li", &size) != 1) || (size < 0L)) {
        printerrmsg("Illegal size !");
    }

    fseek(file, offset, SEEK_SET);

    if (mode == '+') {
        printf("Replacing %s(offset %ld, size %ld) by %s\n", argv[1], offset,
               size, argv[2] + 1);

        if (getyesno() == 'y') {
            move_block(file, block, size);
        }
    } else {
        printf("Extracting %s from %s(offset %ld, size %ld)\n", argv[2] + 1,
               argv[1], offset, size);

        if (getyesno() == 'y') {
            move_block(block, file, size);
        }
    }

    printf("\n");

    if (ferror(file) || ferror(block)) {
        printerrmsg("File I/O error !");
    }

    if (feof(file) || feof(block)) {
        printerrmsg("Unexpected EOF !");
    }

    return 0;
}

void move_block(FILE *destin, FILE *source, long size)
{
    int c;

    while (size-- > 0L) {
        if ((c = fgetc(source)) == EOF) {
            return;
        }

        if (fputc(c, destin) == EOF) {
            return;
        }
    }

    fclose(destin);
}

char getyesno(void)
{
    printf("\nContinue (y/n) ? ");

    return tolower(getche());
}
