/* File DISKSONG.C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long item_t;

#define TMAX 30
#define SMAX 15
#define AMAX 40
#define GETS_MAX_SIZE 128

#define isnull(s) (*(s) == '\0')
#define printerrmsg(s)              \
    do {                            \
        fputs("\n" s "\n", stderr); \
        exit(EXIT_FAILURE);         \
    } while (0);

struct song {
    char title[TMAX];
    char singer[SMAX];
    char album[AMAX];
    long date;
};

FILE *binarydata;

item_t calc_num(void)
{
    item_t num;
    struct song library;

    if ((binarydata = fopen("song.dat", "r+b")) == NULL) {
        printerrmsg("SONG.DAT not found !");
    }

    for (num = 0L;; num++) {
        if (fread(&library, sizeof(struct song), 1, binarydata) != 1) {
            break;
        }
    }

    return num;
}

void diskswap(FILE *stream, item_t i, item_t j)
{
    struct song library1, library2;

    fseek(stream, sizeof(struct song) * i, SEEK_SET);

    if (fread(&library1, sizeof(struct song), 1, stream) != 1) {
        printerrmsg("File reading error !");
    }

    fseek(stream, sizeof(struct song) * j, SEEK_SET);

    if (fread(&library2, sizeof(struct song), 1, stream) != 1) {
        printerrmsg("File reading error !");
    }

    fseek(stream, sizeof(struct song) * i, SEEK_SET);

    if (fwrite(&library2, sizeof(struct song), 1, stream) != 1) {
        printerrmsg("File writing error !");
    }

    fseek(stream, sizeof(struct song) * j, SEEK_SET);

    if (fwrite(&library1, sizeof(struct song), 1, stream) != 1) {
        printerrmsg("File writing error !");
    }
}

int diskcmp(FILE *stream, item_t i, item_t j)
{
    struct song library1, library2;

    fseek(stream, sizeof(struct song) * i, SEEK_SET);

    if (fread(&library1, sizeof(struct song), 1, stream) != 1) {
        printerrmsg("File reading error !");
    }

    fseek(stream, sizeof(struct song) * j, SEEK_SET);

    if (fread(&library2, sizeof(struct song), 1, stream) != 1) {
        printerrmsg("File reading error !");
    }

    return strcmp(library1.title, library2.title);
}

void quicksort(FILE *stream, item_t left, item_t right)
{
    item_t i, last;

    if (left >= right) {
        return;
    }

    diskswap(stream, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++) {
        if (diskcmp(stream, i, left) < 0) {
            diskswap(stream, ++last, i);
        }
    }

    diskswap(stream, left, last);
    quicksort(stream, left, last - 1);
    quicksort(stream, last + 1, right);
}

item_t binsearch(const char *key, item_t n, FILE *stream)
{
    int cond;
    item_t low = 0L, high = n, mid;
    struct song library;

    while (low < high) {
        mid = (low + high) / 2L;

        fseek(stream, sizeof(struct song) * mid, SEEK_SET);

        if (fread(&library, sizeof(struct song), 1, stream) != 1) {
            printerrmsg("File reading error !");
        }

        cond = strcmp(key, library.title);

        if (cond < 0) {
            high = mid;
        } else if (cond > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return EOF;
}

void print_song(struct song *ps)
{
    char d[9];

    fprintf(stdout, "%-23s", ps->title);
    fprintf(stdout, "%-15s", ps->singer);
    fprintf(stdout, "%-24s", ps->album);
    ltoa(ps->date, d, 10);
    fprintf(stdout, "%c%c.%c%c.%c%c\n", d[0], d[1], d[2], d[3], d[4], d[5]);
}

int main(void)
{
    item_t i, max, item;
    char *header = "\nTitle                  Singer     "
                   "    Album                   Date\n";
    char title[GETS_MAX_SIZE];
    struct song library;

    max = calc_num();

    fprintf(stdout, "\n--- Song list -.------------------"
                    "------------------------------------\n");
    fprintf(stdout, header);
    rewind(binarydata);

    for (i = 0; i < max; i++) {
        if (fread(&library, sizeof(struct song), 1, binarydata) != 1) {
            printerrmsg("File reading error !");
        }

        print_song(&library);
    }

    fprintf(stdout, "\n\nDisk sorting. Please wait a moment......\n");

    quicksort(binarydata, 0, max - 1);

    fprintf(stdout, "\nDisk sorting complete. \n\n");
    fprintf(stdout, "\n--- Song by title ----------------"
                    "------------------------------------\n");
    fprintf(stdout, header);
    rewind(binarydata);

    for (i = 0; i < max; i++) {
        if (fread(&library, sizeof(struct song), 1, binarydata) != 1) {
            printerrmsg("File reading error !");
        }

        print_song(&library);
    }

    fprintf(stdout, "\n----------------------------------"
                    "------------------------------------\n");

    do {
        fprintf(stdout, "\nEnter the title: ");

        if (isnull(gets(title))) {
            break;
        }

        if ((item = binsearch(title, max, binarydata)) != EOF) {
            fprintf(stdout, header),
                fseek(binarydata, sizeof(struct song) * item, SEEK_SET);

            if (fread(&library, sizeof(struct song), 1, binarydata) != 1) {
                printerrmsg("File reading error !");
            }

            print_song(&library);
        } else {
            fprintf(stderr, "Song not found !\n");
        }
    } while (1);

    if (fclose(binarydata) == EOF) {
        printerrmsg("SONG.DAT closing error");
    }

    fprintf(stdout, "\nThe End. \n\x0a");

    return 0;
}
