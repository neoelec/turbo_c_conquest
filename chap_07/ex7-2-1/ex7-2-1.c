#include <conio.h>
#include <ctype.h>
#include <stdio.h>

#define MAXLENGTH 40

void encode(char *s);
void decode(char *s);

int main(void)
{
    char c, str[MAXLENGTH + 3];

    do {
        do {
            printf("\n\nEncode or Decode or Quit (E/D/Q) ? ");
            c = toupper(getche());
        } while (c != 'E' && c != 'D' && c != 'Q');

        if (c == 'Q') {
            break;
        }

        printf("\nEnter number: ");
        str[0] = MAXLENGTH + 1;
        cgets(str);

        if (c == 'E') {
            encode(str + 2);
            printf("\nEncoded number: %s", str + 2);
        } else {
            decode(str + 2);
            printf("\nDecoded number: %s", str + 2);
        }
    } while (1);

    printf("\nGood luck to you !!!\n");

    return 0;
}

void encode(char *s)
{
    unsigned int i = -1;
    static char *code = "5792134608";

    while (s[++i]) {
        s[i] = code[s[i] - '0'];
    }
}

void decode(char *s)
{
    unsigned int i = -1;
    static char *code = "8435607192";

    while (s[++i]) {
        s[i] = code[s[i] - '0'];
    }
}
