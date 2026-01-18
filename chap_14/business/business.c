/* File BUSINESS.C */

#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } boolean;

#define GETS_MAX_SIZE 128
#define MAXLONG 0x7fffffffL
#define MINLONG ((long)0x80000000L)

long getvalue(size_t width, char prefix);
void putvalue(long value, char prefix, boolean plussign);
char *strdel(char *s, const char *delstr);

#define reversevideo() textattr(0x70)

int main(void)
{
    long value;

    do {
        cputs("Enter value: ");
        reversevideo();
        cputs("|          |\r");
        gotoxy(15, wherey());

        value = getvalue(10, '$');

        normvideo();

        if ((value != MAXLONG) && (value != MINLONG)) {
            cputs("\r\nInput value: ");

            putvalue(value, '$', true);
        } else if (value != MINLONG) {
            cputs("\r\nInput error !");
        }

        cputs("\r\n\r\n");
    } while (value != MINLONG);

    return 0;
}

long getvalue(size_t width, char prefix)
{
    char s[GETS_MAX_SIZE + 2], *ps, *tempptr;
    long value, sign = 1L;

    if (width > GETS_MAX_SIZE) {
        return MAXLONG;
    }

    s[0] = (char)width + 1;
    cgets(s);

    if (*(s + 2) == '\0') {
        return MINLONG;
    }

    for (ps = s + 2; isspace(*ps); ps++) {
    }

    if (*ps == '+') {
        ps++;
    } else if (*ps == '-') {
        ps++, sign *= -1;
    }

    if (*ps == prefix) {
        ps++;
    }

    for (tempptr = ps; tempptr != NULL;) {
        tempptr = strdel(tempptr, ",");
    }

    value = strtol(ps, &tempptr, 10) * sign;

    if (*tempptr != '\0') {
        return MAXLONG;
    } else if (value != 0L) {
        return value;
    } else if ((*ps++ == '0') && (*ps == '\0')) {
        return 0L;
    } else {
        return MAXLONG;
    }
}

void putvalue(long value, char prefix, boolean plussign)
{
    char s[33], *ps;
    size_t len;

    ltoa(value, s, 10);

    len = strlen(s);
    ps = s;

    if (*ps == '-') {
        ps++, len--, putch('-');
    } else if (plussign) {
        putch('+');
    }

    if (prefix != '\0') {
        putch(prefix);
    }

    for (; *ps; ps++) {
        putch(*ps);

        if ((--len % 3 == 0) && (len != 0)) {
            putch(',');
        }
    }
}

char *strdel(char *s, const char *delstr)
{
    char *start, *end;

    if ((start = strstr(s, delstr)) == NULL) {
        return NULL;
    }

    end = start + strlen(delstr);

    memcpy(start, end, strlen(s) - (end - s) + 1);

    return start;
}
