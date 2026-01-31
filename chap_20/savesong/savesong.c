/* File SAVESONG.C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TMAX 30
#define SMAX 15
#define AMAX 40

int main(void)
{
    struct {
        char title[TMAX];
        char singer[SMAX];
        char album[AMAX];
        long date;
    } library;
    FILE *data, *binarydata;

    if ((data = fopen("song.in", "r+")) == NULL) {
        fprintf(stderr, "\nSONG.IN not found !\n");
        exit(EXIT_FAILURE);
    }

    if ((binarydata = fopen("song.dat", "wb")) == NULL) {
        fprintf(stderr, "\nSONG.DAT can't be created !\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(library.title, TMAX, data) != NULL) {
        *strchr(library.title, '\n') = '\0';
        fgets(library.singer, SMAX, data);
        *strchr(library.singer, '\n') = '\0';
        fgets(library.album, AMAX, data);
        *strchr(library.album, '\n') = '\0';
        fscanf(data, "%ld\n", &library.date);

        if (fwrite(&library, sizeof(library), 1, binarydata) != 1) {
            fprintf(stderr, "\nDisk full !\n");

            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
