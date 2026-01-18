#include <stdio.h>
#include <string.h>

#define MAX 100

struct book {
    char title[50];
    char author[40];
    size_t number;
} library[MAX];

struct book store_book(char *title, char *author, size_t number);
void list_book(size_t index, struct book library);

int main(void)
{
    library[33] =
        store_book("Turbo C Reference Guide", "Borland International", 3);

    list_book(33, library[33]);

    return 0;
}

struct book store_book(char *title, char *author, size_t number)
{
    struct book temp;

    strcpy(temp.title, title);
    strcpy(temp.author, author);
    temp.number = number;

    return temp;
}

void list_book(size_t index, struct book library)
{
    printf("Book %u\n", index);
    printf("Title: %s\n", library.title);
    printf("Author: %s\n", library.author);
    printf("Number of books: %u\n", library.number);
}
