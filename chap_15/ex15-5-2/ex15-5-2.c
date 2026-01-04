#include <stdio.h>
#include <string.h>

struct book {
    char title[50];
    char author[40];
    size_t number;
};

struct book library[] = {
    { "Title : ", "Author =", 1 },
    { "Title : ", "Author =", 1 },
    { "Title : ", "Author =", 1 },
    { "Title : ", "Author =", 1 },
};

int main(void)
{
    strcat(library[0].title, "Turbo C Reference Guide");
    strcat(library[0].author, "Borland International");
    library[0].number = 3;

    puts("Book 0");
    puts(library[0].title);
    puts(library[0].author);
    printf("Number of books: %u\n", library[0].number);

    return 0;
}
