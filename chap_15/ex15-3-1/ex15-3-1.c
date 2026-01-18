#include <math.h>
#include <stdio.h>

int main(void)
{
    double z2abs;
    struct complex z1 = { 2.0, 1.0 }, z2 = { 3.0, 4.0 }, z3;

    printf("z1 = (%lg, %lg)\nz2 = (%lg, %lg)\n\n", z1.x, z1.y, z2.x, z2.y);
    printf("|z1| = %lg, |z2| = %lg\n", cabs(z1), z2abs = cabs(z2));
    z3.x = z1.x + z2.x;
    z3.y = z1.y + z2.y;
    printf("z1 + z2 = (%lg, %lg)\n", z3.x, z3.y);
    z3.x = z1.x - z2.x;
    z3.y = z1.y - z2.y;
    printf("z1 - z2 = (%lg, %lg)\n", z3.x, z3.y);
    z3.x = z1.x * z2.x - z1.y * z2.y;
    z3.y = z1.x * z2.y + z1.y * z2.x;
    printf("z1 * z2 = (%lg, %lg)\n", z3.x, z3.y);
    z3.x = (z1.x * z2.x + z1.y * z2.y) / z2abs;
    z3.y = (z1.y * z2.x - z1.x * z2.y) / z2abs;
    printf("z1 / 22 = (%lg, %lg)\n", z3.x, z3.y);

    return 0;
}
