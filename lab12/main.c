#include <stdio.h>
#include <math.h>

int main(void) {
    int a = 0, n = 0, save;
    char ch;
    for (char ch = getchar(); ch != EOF; ch = getchar()) {
        if ((ch != ' ') && (ch != '\n') && (ch != '\t')) {
            ++n;
            a = a*10 + (int) (ch -  '0'); 
        } else {
            if (n > 1) {
                save = a % (int)pow(10, n - 1) / (int)pow(10, n - 2);
                a = a - save * (int)pow(10, n - 2) + (a % 100 / 10) * (int)pow(10, n - 2);
                a = a - (a % 100 / 10)*10 + save * 10;
            }
            printf("%d\n", a);
            a = 0;
            n = 0;
        }
    }
}