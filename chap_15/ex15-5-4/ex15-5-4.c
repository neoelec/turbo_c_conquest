#include <stdio.h>
#include <string.h>

#define MAX 100

struct book {
    char title[50];
    char author[40];
    size_t number;
};

struct book library[MAX];

const struct book lib0 = {
    "Title : ",
    "Author : ",
    1,
};

int main(void)
{
    size_t i;

    for (i = 0; i < MAX; i++) {
        library[i] = lib0;
    }

    strcat(library[33].title, "Turbo C Reference Guide");
    strcat(library[33].author, "Borland International");
    library[33].number = 3;

    puts("Book 33");
    puts(library[33].title);
    puts(library[33].author);
    printf("Number of books: %u\n", library[33].number);

    return 0;
}
