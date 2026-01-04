#include <conio.h>
#include <graphics.h>

void outtextdemo(void);
void ascii(void);
void measurexy(void);
void newline(int space);
void cpgotoxy(int x, int y, int space);

int main(void)
{
    int graphdrive = DETECT, graphmode;

    initgraph(&graphdrive, &graphmode, "C:/BORLANDC/BGI");
    rectangle(0, 0, getmaxx(), getmaxy());
    outtextdemo();

    ascii();
    measurexy();

    getch();
    closegraph();

    return 0;
}

void outtextdemo(void)
{
    outtext("Here is home, (0, 0).");
    outtextxy(0, 30, "Here is (0, 50).");
    moveto(0, 60);
    outtext("Here is (0, 60) and CP. --->");
    outtextxy(400, 90, "Here is (400, 90).*****&&&&&&%%%%%%#####1*");
    outtextxy(0, 90, "This is the 1st line.\nThis is the 2nd line.\n");
    outtext("This is the 3rd line.");
    moveto(0, 120);
    outtext(" This is the new 1st line. Line space = 0");
    newline(0);
    outtext(" This is the new 2nd line.");
    newline(0);
    outtext(" This is the new 3rd line,");

    cpgotoxy(50, 30, 0);
    outtext("Here is Col: 50. Row: 30");
    cpgotoxy(51, 31, 0);
    outtext("Here is Col: 51. Row: 31");
}

void ascii(void)
{
    char str[2];
    int c;

    outtextxy(10, 180, "< ASCII characters >");

    str[1] = '\0';
    moveto(18, 200);

    for (c = 1; c < 128;) {
        str[0] = c;
        outtext(str);

        if (++c % 32 == 0) {
            newline(5);
            moverel(10, 0);
        }
    }
}

void measurexy(void)
{
    char str[2];
    int i;

    str[1] = '\0';
    cpgotoxy(0, 2, 0);

    for (i = 0; i < 90; i++) {
        str[0] = i % 10 + '0';
        outtext(str);
    }

    for (i = 0; i < 50; i++) {
        cpgotoxy(45, i, 0);
        str[0] = i % 10 + '0';
        outtext(str);
    }
}

void newline(int space)
{
    moveto(0, gety() + textheight("H") + space);
}

void cpgotoxy(int x, int y, int space)
{
    moveto(textwidth("W") * x, (textheight("H") + space) * y);
}
