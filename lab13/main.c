#include <stdio.h>
#include <ctype.h>

int main(void) {
    const unsigned int lu = 1;
    const unsigned int vowels = lu << ('a' - 'a') | lu << ('e' - 'a') | \
    lu << ('i' - 'a') | lu << ('o' - 'a') | lu << ('u' - 'a');

    unsigned int first_set = 0, second_set = 0;
    char low;
    int res = 0;

    for (char ch = getchar(); ch != EOF; ch = getchar()) {
        if ((ch != ' ') && (ch != '\t') && (ch != '\n') && (ch != '\0' && (ch != ','))) {
            low = tolower(ch);
            if ((low >= 'a') && (low <= 'z')) {
                first_set = first_set | (lu << (low - 'a'));
            }
        } else {
            if ((first_set & second_set) > 0) {
                res = 1;
            }
            first_set = first_set & vowels;
            second_set = first_set;
            first_set = 0;
        }
    }

    printf("%d\n", res);
}