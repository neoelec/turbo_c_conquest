#include <stdio.h>

typedef unsigned char byte;

#define hg(han, i, m, f)                                               \
    ((han).ph.flag = 1, (han).ph.initial = (i), (han).ph.medial = (m), \
     (han).ph.final = (f), (han).code)

union hangul {
    unsigned int code; /* syllable */
    struct             /* phoneme */
    {
        unsigned int final : 5;
        unsigned int medial : 5;
        unsigned int initial : 5;
        unsigned int flag : 1;
    } ph;
} han = { 0xaa97 };

int main(void)
{
    char s[128];

    printf("Initial value: %#6x\n\n", han.code);

    printf("Bit-fields test:\n");
    han.ph.flag = 1;
    han.ph.initial = 0x0a;
    han.ph.medial = 0x14;
    han.ph.final = 0x17;

    printf("Combined Hangul code: %#06x\n\n", han.code);

    printf("Combination test:\n");
    printf("Combined Hangul code: %#06x\n", hg(han, 0x0a, 0x14, 0x17));

    do {
        printf("\nEnter one Korean syllable: ");

        if (*gets(s) == '\0') {
            break;
        }

        printf("Ist byte: %#04x, 2nd byte: %#04x\n", (byte)s[0], (byte)s[1]);
        han.code = (byte)s[0] << 8 | (byte)s[1];

        if (han.ph.flag != 1) {
            printf("\nNot Korean !\n");
        } else {
            printf("Combined Hangul code: %#06x\n", han.code);
            printf("Initial code: %#04x ", han.ph.initial);
            printf("Medial code: %#04x ", han.ph.medial);
            printf("Final code: %#04x\n", han.ph.final);
        }
    } while (1);

    printf("\nThe End.\n");

    return 0;
}
