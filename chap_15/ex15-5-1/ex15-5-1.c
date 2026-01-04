#include <math.h>
#include <stdio.h>

struct point {
    int x, y;
} pt1;

struct rect {
    struct point pt1, pt2;
};

struct address {
    char name[20];
    char addr[60];
    char tel[14];
    unsigned int age;
} addr_book = {
    "Lim Y.K.",
    "Seoul Mido Apart",
    { '7', '7', '8', '-', '7', '7', '8', '8', '\0' },
    21,
};

int main(void)
{
    struct complex z1 = { 3., 4. }, z2 = { 100. };
    static struct rect r = {
        { 3., 4. },
        { 1., 2. },
    };

    puts("That's all right !");

    return 0;
}
