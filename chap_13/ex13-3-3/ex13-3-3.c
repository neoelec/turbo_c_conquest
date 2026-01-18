#include <stdio.h>

int main(void)
{
    char s[9];
    int num = 0;

    printf("s = %p, anum = %p\n", s, &num);

    do {
        printf("Enter telephone number: ");
        gets(s);
        printf("[No. %2d] Tel: %s\n", ++num, s);
    } while (*s);

    return 0;
}
