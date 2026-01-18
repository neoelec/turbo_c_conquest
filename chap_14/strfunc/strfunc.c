#include <conio.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

char *multistrcat(char *dest, ...);
char *strdel(char *s, const char *delstr);
char *strndel(char *s, size_t start, size_t n);
char *strins(char *dest, size_t pos, const char *src);
char *strnins(char *dest, size_t pos, const char *src, size_t n);

char *multistrcat(char *dest, ...)
{
    const char *argp;
    va_list arglist;

    va_start(arglist, dest);

    while ((argp = va_arg(arglist, const char *)) != NULL) {
        strcat(dest, argp);
    }

    va_end(arglist);

    return dest;
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

char *strndel(char *s, size_t start, size_t n)
{
    memcpy(s + start, s + start + n, strlen(s) - (start + n) + 1);

    return s + start;
}

char *strins(char *dest, size_t pos, const char *src)
{
    size_t i, j, len;

    len = strlen(src);

    for (i = strlen(dest); i >= pos; i--) {
        dest[i + len] = dest[i];
    }

    for (i = pos, j = 0; i < pos + len; i++, j++) {
        dest[i] = src[j];
    }

    return dest;
}

char *strnins(char *dest, size_t pos, const char *src, size_t n)
{
    size_t i, j, len;

    len = strlen(src);

    if (len > n) {
        len = n;
    }

    for (i = strlen(dest); i >= pos; i--) {
        dest[i + len] = dest[i];
    }

    for (i = pos, j = 0; i < pos + len; i++, j++) {
        dest[i] = src[j];
    }

    return dest;
}

int main(void)
{
    char dest[255] = "Wow! ";

    clrscr();

    puts(multistrcat(dest, "I", "am", "Rambo III.", NULL));
    strins(dest, 10, "not ");
    strndel(dest, 0, 5);
    puts(strins(dest, 0, "Sorry. "));
    strins(strdel(dest, "I am"), 0, "Yes. ");
    strdel(dest, "Sorry, ");
    puts(strnins(dest, 5, "You are a student.", 8));

    return 0;
}
