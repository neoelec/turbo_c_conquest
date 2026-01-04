#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SONG_MAX 100
#define TMAX 30
#define SMAX 15
#define AMAX 40

#define TITLE 0
#define SINGER 1
#define isnull(s) (*(s) == '\0')

struct song {
    char title[TMAX];
    char singer[SMAX];
    char album[AMAX];
    long date;
} library[SONG_MAX];

struct song *ti[SONG_MAX];
struct song *si[SONG_MAX];

int read_data(struct song ps[])
{
    int i;
    FILE *data;

    if ((data = fopen("song.in", "rt")) == NULL) {
        printf("File SONG. IN can't be read. Program aborted !");
        exit(EXIT_SUCCESS);
    }

    for (i = 0; i < SONG_MAX; i++, ps++) {
        if (fgets(ps->title, TMAX, data) == NULL) {
            break;
        }

        *strchr(ps->title, '\n') = '\0';
        fgets(ps->singer, SMAX, data);
        *strchr(ps->singer, '\n') = '\0';
        fgets(ps->album, AMAX, data);
        *strchr(ps->album, '\n') = '\0';
        fscanf(data, "%ld\n", &ps->date);
    }

    return i;
}

void swap(struct song *ps[], int i, int j)
{
    struct song *temp;

    temp = ps[i];
    ps[i] = ps[j];
    ps[j] = temp;
}

void quicksort(struct song *ps[], int left, int right, int member)
{
    int i, last, cond;

    if (left >= right) {
        return;
    }

    swap(ps, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++) {
        cond = (member == TITLE) ? strcmp(ps[i]->title, ps[left]->title) :
                                   strcmp(ps[i]->singer, ps[left]->singer);

        if (cond < 0) {
            swap(ps, ++last, i);
        }
    }

    swap(ps, left, last);
    quicksort(ps, left, last - 1, member);
    quicksort(ps, last + 1, right, member);
}

struct song *binsearch(char *key, struct song *ps[], unsigned int n, int member)
{
    int cond;
    struct song **low = &ps[0];
    struct song **high = &ps[n];
    struct song **mid;

    while (low < high) {
        mid = low + (high - low) / 2;

        cond = (member == TITLE) ? strcmp(key, (*mid)->title) :
                                   strcmp(key, (*mid)->singer);

        if (cond < 0) {
            high = mid;
        } else if (cond > 0) {
            low = mid + 1;
        } else {
            return *mid;
        }
    }

    return NULL;
}

int song_sort(void)
{
    int i, max;

    max = read_data(library);

    for (i = 0; i < SONG_MAX; i++) {
        ti[i] = si[i] = &library[i];
    }

    quicksort(ti, 0, max - 1, TITLE);
    quicksort(si, 0, max - 1, SINGER);

    return max;
}

void print_song(struct song *ps)
{
    char d[9];

    printf("%-23s", ps->title);
    printf("%-15s", ps->singer);
    printf("%-24s", ps->album);
    ltoa(ps->date, d, 10);
    printf("%c%c.%c%c.%c%c\n", d[0], d[1], d[2], d[3], d[4], d[5]);
}

int main(void)
{
    int i, max;
    char *header = "\nTitle                  Singer     "
                   "    Album                   Date";
    char title[128];
    struct song *ps;

    max = song_sort();

    puts("\n--- Song list --------------------"
         "------------------------------------");
    puts(header);

    for (i = 0; i < max; i++) {
        print_song(&library[i]);
    }

    puts("\n--- Song by title ----------------"
         "------------------------------------");
    puts(header);

    for (i = 0; i < max; i++) {
        print_song(ti[i]);
    }

    puts("\n--- Song by singer ---------------"
         "------------------------------------");
    puts(header);

    for (i = 0; i < max; i++) {
        print_song(si[i]);
    }

    puts("\n----------------------------------"
         "------------------------------------");

    do {
        printf("\nEnter the title: ");

        if (isnull(gets(title))) {
            break;
        }

        ps = binsearch(title, ti, max, TITLE);

        if (ps != NULL) {
            puts(header), print_song(ps);
        } else {
            puts("Song not found !");
        }
    } while (1);

    puts("\nThe End.");

    return 0;
}
