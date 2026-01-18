#include <stdio.h>

int main(void)
{
    int x[5], *px, *py;
    size_t relative_position, relative_address;

    px = x;
    py = x + 4;

    printf("px = x\npy = x + 4\n\n");
    /* printf("%p\n", px + py); */

    relative_position = py - px;
    relative_address = relative_position * sizeof(*px);
    printf("Relative position == %u element\n", relative_position);
    printf("Relative address  == %u byte\n", relative_address);

    return 0;
}
