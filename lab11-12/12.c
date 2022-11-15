#include <stdio.h>
#include <stdlib.h>
int main() {
    char *str = NULL, c;
    int len = 1;
    str = (char*) malloc(sizeof(char));
    while((c = getchar()) != '\n') {
        str[len - 1] = c;
        len++;
        str = (char*) realloc(str, len);
    }

    for (int i = 0; i < len - 1; i++)
    {
      if (i == 1)
      {
        printf("%c", str[len - 3]);
        continue;
      }
      else if (i == len - 3)
      {
        printf("%c", str[1]);
        continue;
      }
      printf("%c", str[i]);
    }
    free(str);
    return 0;
}
