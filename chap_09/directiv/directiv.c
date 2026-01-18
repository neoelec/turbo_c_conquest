int printf(const char *__format, ...);
#
#define MACRO
#
#ifdef MACRO
#line 0 "directiv.c"
#endif
#
int main(void)
{
    printf("Line: %u, Filename: [%s]\n", __LINE__, __FILE__);
#line 100 "main.c"
    printf("Line: %u, Filename: [%s]\n", __LINE__, __FILE__);
#line 200
    printf("Line: %u, Filename: [%s]\n", __LINE__, __FILE__);
#line 300 "directiv"
    printf("Line: %u, Filename: [%s]\n", __LINE__, __FILE__);

    return 0;
}
