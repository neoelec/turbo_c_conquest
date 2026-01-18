#include <stdio.h>

#define INT 1
#define FLOAT 2
#define POINTER 3

union u_tag {
    int ival;
    float fval;
    char *pval;
} uval = { 9138 };

union {
    unsigned long longword;
    unsigned char byte[4];
} lim = { 0x5495735 };

void set_uval(union u_tag *pu, int type);
void print_uval(union u_tag uval);

int main(void)
{
    printf("%8lX\n", lim.longword);
    lim.longword = 0xfedcba98;
    lim.byte[1] = 0x37;
    printf("%8lX\n", lim.longword);
    print_uval(uval);
}

void print_uval(union u_tag uval)
{
    set_uval(&uval, INT);
    printf("My birthday is %d.\n", uval.ival);
    set_uval(&uval, FLOAT);
    printf("My birthday is %.4lf.\n", uval.fval);
    set_uval(&uval, POINTER);
    printf("My birthday is %s.\n", uval.pval);
}

void set_uval(union u_tag *pu, int type)
{
    switch (type) {
    case INT:
        pu->ival = 626;
        break;

    case FLOAT:
        pu->fval = 1969.0626;
        break;

    case POINTER:
        pu->pval = "1969.6.26";
        break;
    }
}
