// VAR 17
#include <stdio.h>
#include <math.h>

typedef struct {
  double res;
  int N;
} result;



double macheps(void) {
	double e = 1.0f;

	while (1.0f + e / 2.0f > 1.0f)
		e /= 2.0f;
	return e;
}

int kolvo(double x) {
    int k = 0;
    while ((int) x == 0) {
        k += 1;
        x *= 10;
    }
    return k;
}

result teylor(double x, int n, double eps) {
    double res = 0.0, res_old;
    double r, r2 ;
    result A;

    for (int i = 0; i < n; ++i) {
        r = (2 * i + 1);
        r = 1 / r;
        r = r * pow(((x - 1) / (x + 1)), (2 * i + 1));
        res_old = res;
        res = res + r;
        if (res_old - res < eps) {
            A.res = res;
            A.N = i;
            printf("%.20f", res - res_old);
            return A;
        }
    }
    A.res = res;
    A.N = n;
    return A;
}

double count(double x) {
    double res;

    res = 0.5 * log(x);
    return res;
}

int main(void) {
    double eps = macheps();
    double k;
    int n = 100;
    double a = 0.2, b = 0.7;
    int z = kolvo(eps);
    double shag = 0.05;
    double res1, res2;
    eps *= 0.5;

    for (double x = a; b - x + shag >= eps; x = x + shag) {  
    result res1 = teylor(x, n, eps);
    double res2 = count(x);
    printf("%.2f %.*f %.*f %d\n",x,  z, res1.res, z, res2, res1.N);
    }
    return 0;
}