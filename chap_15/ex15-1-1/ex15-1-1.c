#include <stddef.h>

#define MAX 50

struct address {
    char name[7];
    char addr[60];
    char tel[9];
    unsigned int birth;
} addr_book[MAX];

struct address function(struct address addr_book)
{
    return addr_book;
}

int main(void)
{
    size_t i = 1, j = 2;

    addr_book[i] = addr_book[j];
    addr_book[i] = function(addr_book[j]);

    return 0;
}
