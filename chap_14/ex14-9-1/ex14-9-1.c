#include <conio.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *talk, tel[8], *pt, *ps;

    clrscr();

    talk = "The TEL of my store is 52 - 4989. You know ?";

    pt = tel;
    ps = talk - 1;

    do {
        if ((ps = strpbrk(ps + 1, "1234567890-")) != NULL) {
            *pt++ = *ps;
        }
    } while (ps != NULL);

    *pt = '\0';

    printf("Someone say: '%s'\n", talk);
    printf("I say:       'I see your TEL is %s.'\n", tel);

    return 0;
}
