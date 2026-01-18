/* Function Declaration */

#include <dos.h>

void beep(unsigned int herz, unsigned int milisec);

int main(void)
{
    int herz = 400;

    for (; herz < 1800; herz += 20) {
        beep(herz, 30000 / herz);
    }

    return 0;
}

void beep(unsigned int herz, unsigned int milisec)
{
    sound(herz);
    delay(milisec);
    nosound();
}
