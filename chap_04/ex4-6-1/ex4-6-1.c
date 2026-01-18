#include <stdio.h>

int main(void)
{
    char *format;
    int x;

    format = "%d\n";

    /* EX1: */
    x = 5;                    /* Result */
    printf(format, -x + x++); /* (-5) + 5 == 0  */
    x = 5;                    /*                */
    printf(format, x++ + -x); /* 5 + (-6) == -1 */

    /* EX2: */
    x = 5;
    printf(format, ++x + x + x); /* (6 + 6) + 6 == 18  */
    x = 5;                       /*                    */
    printf(format, x + ++x + x); /* (6 + 6) + 6 == 18  */
    x = 5;                       /*                    */
    printf(format, x + x + ++x); /*# (5 + 5) + 6 == 16 */

    /* EX3: */
    x = 5;
    printf(format, (x - 1) * x++);     /* 4 * 5 == 20             */
    x = 5;                             /*                         */
    printf(format, x * x++ - 1 * x++); /* (6 * 5) - (1 * 6) == 24 */

    /* EX4: */
    /* EX4.1 */
    x = 5;
    printf(format, x + x * ++x); /* 6 + (6 * 6) == 42 */
    x = 5;
    printf(format, x + ++x * x); /* 6 + (6 * 6) == 42 */
    /* EX4,2: */
    x = 5;
    printf(format, ++x + x * x); /*6 + (5 * 5) == 31 */

    /* EX5: */
    x = 5;
    printf(format, x - (x++ - x)); /* 6 - (5 - 6) == 7 */
    x = 5;                         /*                  */
    printf(format, x - x++ + x);   /* (6 - 5) + 6 == 7 */
    x = 5;                         /*                  */
    printf(format, x - (++x - x)); /* (6 - 6) + 6 == 6 */
    x = 5;                         /*                  */
    printf(format, x - ++x + x);   /* (6 - 6) + 6 == 6 */

    /* EX6: */
    x = 5;
    printf(format, x - (x - x++)); /* 6 - (6 - 5) == 5 */
    x = 5;                         /*                   */
    printf(format, x - x + x++);   /* (6 - 6) + 5 == 5 */

    /* EX7: */
    x = 5;
    printf(format, x + x++ + ++x);   /* (6 + 5) + 7 == 18 */
    x = 5;                           /*                   */
    printf(format, (x + x++) + ++x); /* (6 + 5) + 7 == 18 */
    x = 5;                           /*                   */
    printf(format, x + (x++ + ++x)); /* 7 + (5 + 7) == 19 */
    x = 5;                           /*                   */
    printf(format, x++ + ++x + x);   /* (5 + 7) + 7 == 19 */

    /* EX8: */
    x = 5;
    printf(format, x + x++); /* 6 + 5 == 11 */
    x = 5;                   /*             */
    printf(format, x - x++); /* 6 - 5== 1 */
    x = 5;                   /*             */
    printf(format, x + ++x); /* 6 + 6 == 12 */
    x = 5;                   /*             */
    printf(format, x++ + x); /* 5 + 6 == 11 */
    x = 5;                   /*             */
    printf(format, ++x + x); /* 6 + 6 == 12 */

    /* EX9: */
    x = 5;
    printf(format, x++ + x++); /* 5 + 6 == 11 */
    x = 5;                     /*             */
    printf(format, ++x + ++x); /* 6 + 7 == 13 */
    x = 5;                     /*             */
    printf(format, x++ + ++x); /* 5 + 7 == 12 */
    x = 5;                     /*             */
    printf(format, ++x + x++); /* 6 + 6 == 12 */

    /* EX10: */
    x = 5;
    printf(format, x++ * x++ + x++); /* (5 * 6) + 7 == 37 */
    x = 5;                           /*                   */
    printf(format, x++ * x++ + x);   /* (5 * 6) + 7 == 37 */
    x = 5;                           /*                   */
    printf(format, x++ * x + x++);   /* (5 * 6) + 6 == 36 */
    x = 5;                           /*                   */
    printf(format, x * x++ + x++);   /* (6 * 5) + 6 == 36 */
    x = 5;                           /*                   */
    printf(format, x++ + x++ * x++); /* 7 + (5 * 6) == 37 */
    x = 5;                           /*                   */
    printf(format, x++ + x++ * x);   /* 6 + (5 * 6) == 36 */
    x = 5;                           /*                   */
    printf(format, x++ + x * x++);   /* 6 + (5 * 6) == 36 */
    x = 5;                           /*                   */
    printf(format, x + x++ * x++);   /* (5 * 6) == 37     */

    /* EX11: */
    x = 5;
    printf(format, x++ + x);   /* (x++) + (x) == 11   */
    x = 5;                     /*                     */
    printf(format, x++ + +x);  /* (x++) + (+x) == 11  */
    x = 5;                     /*                     */
    printf(format, x++ + ++x); /* (x++) + (++x) == 12 */

    return 0;
}
