#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int i, count;
    unsigned int strike, ball;
    unsigned int d[3], n[3];
    double play = 0., scoresum = 0.;

    randomize();

    printf("\nI have three digits(not 0). Guess what I have !");

    do {
        d[0] = random(9) + 1;

        do {
            d[1] = random(9) + 1;
        } while (d[1] == d[0]);

        do {
            d[2] = random(9) + 1;
        } while (d[2] == d[0] || d[2] == d[1]);

        count = 0;

        do {
            count++;

            do {
                printf("\n\nCount %u: "
                       "Enter three digits you guess : ",
                       count);
                scanf("%u %u %u", &n[0], &n[1], &n[2]);

                if ((n[0] == 0) || (n[1] == 0) || (n[2] == 0)) {
                    printf("\nDon't input 0 digit, Try Again.");
                } else if ((n[0] > 9) || (n[1] > 9) || (n[2] > 9)) {
                    printf("\nInput only digits from 1 to 9. Try Again.");
                }
            } while (n[0] == n[1] || n[1] == n[2] || n[2] == n[0] ||
                     n[0] == 0 || n[1] == 0 || n[2] == 0 || n[0] > 9 ||
                     n[1] > 9 || n[2] > 9);

            i = strike = ball = 0;

            while (i < 3) {
                if (n[i] == d[i]) {
                    strike++;
                } else if (n[(i + 1) % 3] == d[i]) {
                    ball++;
                } else if (n[(i + 2) % 3] == d[i]) {
                    ball++;
                }

                i++;
            }

            printf("(%u Strike %u Ball)", strike, ball);
        } while (strike < 3 && count < 11);

        printf("\n\n");

        (count <= 2)  ? printf("Great !") :
        (count <= 5)  ? printf("Very good !") :
        (count <= 9)  ? printf("Good.") :
        (strike == 3) ? printf("Chin-up.") :
                        0;

        if (strike == 3) {
            printf("\nYou guess my right digits "
                   "in %u times.\n",
                   count);
        } else {
            printf("\nYou couldn't guess my right digits. \n"
                   "My digits are %u %u %u.\n\n",
                   d[0], d[1], d[2]);
        }

        scoresum += count = 100 - --count * 10;
        printf("Your score is %u points.\n", count);

        printf("\nDo you want to play again (Y/N) ? ");
        play++;
    } while (toupper(getche()) == 'Y');

    printf("\n\nYour average score is %.1lf points. \n"
           "Thank you, Good-bye.",
           (double)scoresum / (double)play);
    getch();
    printf("\n");

    return 0;
}
