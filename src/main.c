/* hello.c */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int from = 1970;
    int to = 0, month = 0, day = 0;

    printf("year, month and day:\n");

    scanf("%d %d %d", &to, &month, &day);
    if (to < 1970 || 12 < month || month < 1 || 31 < day|| day < 1) {
        return 0;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && (day == 31)) {
        return 0;
    }
    if (((to % 4 == 0 && to % 100 != 0) || (to % 400 == 0)) && (month == 2 && day >29)) {
        return 0;
    }
    else if (((to % 4 != 0) || (to % 400 != 0)) && (month == 2 && day > 28)) {
        return 0;
    }
    int ans = 0;
    int usual[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31,30,31 };
    int unusual[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31,30,31 };
    for (int i = from; i < to; ++i) {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            ans += 366;
        }
        else {
            ans += 365;
        }
    }
    if ((to % 4 == 0 && to % 100 != 0) ||(to % 400 == 0)) { 
        for (int i = 0; i < month - 1; ++i) {
            ans += unusual[i];
        }
        ans += day - 1;
    }
    else {
     
        for (int i = 0; i < month - 1; ++i) {
            ans += usual[i];
        }
        ans += day - 1;
    }

    printf("%d \n", ans);

    return 0;
}

