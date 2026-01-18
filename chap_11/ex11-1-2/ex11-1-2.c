#include <conio.h>
#include <stdio.h>

#define printexprp(expr) printf(#expr " == %p\n", expr)
#define printexpri(expr) printf(#expr " == %d\n", expr)
#define printexprz(expr) printf(#expr " == %u\n", expr)

int main(void)
{
    int z[3][2][2] = {
        { { 1, 2 }, { 3, 4 } },
        { { 5, 6 }, { 7, 8 } },
        { { 9, 10 }, { 11, 12 } },
    };

    printexprp(z);

    printexprp(z[0]);
    printexprp(z[1]);
    printexprp(z[2]);

    printexprp(z[0][0]);
    printexprp(z[0][1]);
    printexprp(z[1][0]);
    printexprp(z[1][1]);
    printexprp(z[2][0]);
    printexprp(z[2][1]);

    printf("Strike a key when ready . . .");
    getch();
    printf("\n\n");

    printexpri(z[0][0][0]);
    printexpri(z[0][0][1]);
    printexpri(z[0][1][0]);
    printexpri(z[0][1][1]);
    printexpri(z[1][0][0]);
    printexpri(z[1][0][1]);
    printexpri(z[1][1][0]);
    printexpri(z[1][1][1]);
    printexpri(z[2][0][0]);
    printexpri(z[2][0][1]);
    printexpri(z[2][1][0]);
    printexpri(z[2][1][1]);

    printf("\n");
    printexprz(sizeof(z));
    printexprz(sizeof(z[0]));
    printexprz(sizeof(z[1]));
    printexprz(sizeof(z[2]));
    printexprz(sizeof(z[0][0]));
    printexprz(sizeof(z[0][1]));
    printexprz(sizeof(z[1][0]));
    printexprz(sizeof(z[1][1]));
    printexprz(sizeof(z[2][0]));
    printexprz(sizeof(z[2][1]));
    printf("\nsize of an element is %u bytes.\n", sizeof z[2][1][1]);

    return 0;
}
