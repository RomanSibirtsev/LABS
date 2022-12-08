#include <stdio.h>
#include <string.h>

int result = 0;

int S(int *a, int n) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += a[i];
    }
    return res;
}

int solve(int n) {
    int chet[n], nechet[n];
    memset( chet, -1, n*sizeof(int) );
    memset( nechet, -1, n*sizeof(int) );
    int a = 0, b = 0;
    int id;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &id);
        if (id % 2 == 0) {
            chet[a] = id;
            ++a;
        } else {
            nechet[b] = id;
            ++b;
        }
    }

    while (S(chet, n) != -n) {
        for (int i = 0; i < n; ++i) {
            if ((chet[i] != -1) && (nechet[i] != -1)) {
                nechet[i] += chet[i];
                chet[i] = -1;
                ++result;
                //printf("one \n");
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            if ((chet[i] != -1) && (chet[i + 1] != -1)) {
                chet [i + 1] += chet[i];
                chet[i] = -1;
                ++result;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (chet[i] != -1) {
                chet[i] /= 2;
                ++result;
                //printf("two \n");
                if (chet[i] % 2 == 1) {
                    nechet[i] = chet[i];
                    chet[i] = -1;    
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (nechet[i] == -1) {
            continue;
        } 
        //printf("%d ", nechet[i]);
    }

}

int main(void) {
    int t, n;
    scanf("%d", &t);
    int otvet[t];
    for (int i = 0; i < t; ++i) {
        scanf("%d", &n);
        solve(n);
        //printf("%d\n", result);
        otvet[i] = result;
        result = 0;
    }
    for (int i = 0; i < t; ++i) {
        printf("%d\n", otvet[i]);
    }
    return 0;
}