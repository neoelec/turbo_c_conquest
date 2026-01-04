#include <stdio.h>

struct point1 {
    int x, y;
};

struct point1 a;

int main(void)
{
    struct point2 {
        int x, y;
    };
    struct point1 b;
    struct point2 c;

    printf("a.x = %d\n", a.x);
    printf("b.x = %d\n", b.x);
    printf("c.x = %d\n", c.x);

    return 0;
}
