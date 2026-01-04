#include <stdio.h>

#define pr1(s, macro) printf("%-7s == %u\n", #s, macro)
#define pr2(s, macro) printf("%-7s == %#06x\n", #s, macro)
#define pr3(s, macro) printf("%-7s == %s\n", #s, macro)

int main(void)
{
    pr1(Line, __LINE__);
    pr2(Turbo C, __TURBOC__);
    pr3(Date, __DATE__);
    pr3(Time, __TIME__);
    pr3(File, __FILE__);

#if defined(__SMALL__)
    printf("Small memory model\n");
#elif defined(__TINY__)
    printf("Tiny memory model \n");
#else
    printf("Other memory model\n");
#endif
    pr1(Line, __LINE__);

    return 0;
}
