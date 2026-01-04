#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[18 + 1], temp;
    size_t i, j, len;

    strcpy(s, "I scream icecream.");
    printf("%s\n\n", s);
    len = strlen(s);

    for (i = 0, j = len - 1; i < j && len != 0; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    printf("%s\n", s);

    return 0;
}
