#include <stdio.h>
#include <string.h>

#define MAX 100

struct book {
    char title[50];
    char author[40];
    size_t number;
} library[MAX];

void store_book(struct book *libp, char *title, char *author, size_t number);
void list_book(size_t index, struct book *libp);

int main(void)
{
    store_book(&library[33], "Turbo C Reference Guide", "Borland International",
               3);

    list_book(33, &library[33]);

    return 0;
}

void store_book(struct book *libp, char *title, char *author, size_t number)
{
    strcpy(libp->title, title);
    strcpy(libp->author, author);
    libp->number = number;
}

void list_book(size_t index, struct book *libp)

{
    printf("Book %u\n", index);
    printf("Title: %s\n", libp->title);
    printf("Author: %s\n", libp->author);
    printf("Number of books: %d\n", libp->number);
}
