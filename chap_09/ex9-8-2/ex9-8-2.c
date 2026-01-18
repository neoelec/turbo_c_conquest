#include <stdio.h>

int main(void)
{
    typedef enum { sun, mon, tue, wed, thu, fri, sat } days;
    enum { dog, boy, girl } friend;
    days today;
    int itoday, ifriend;

    friend = girl;
    today = sat;
    printf("Friend = %d, Today = %d\n", friend, today);
    ifriend = friend;
    itoday = today;
    printf("Friend = %d, Today = %d\n", ifriend, itoday);
    today = girl;
    printf("Today = %d\n", today);

    return 0;
}
