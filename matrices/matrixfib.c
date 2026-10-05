#include <stdio.h>


typedef struct {
    long long m[2][2];
} Matrix;

Matrix mult(Matrix left, Matrix right){
    Matrix res = {{{0, 0}, {0, 0}}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res.m[i][j] += left.m[i][k] * right.m[k][j];
            }
        }
    }
    return res;
}



int main(void){
    Matrix res = {{{1, 0}, {0, 1}}};
    Matrix p = {{{0, 1}, {1, 1}}};
    long long n; // 0 <= n <= 91
    if (scanf("%lld", &n) == 1 && n < 92 && n >= 0) {
        while (n > 0) {
            if (n % 2 != 0) {
                res = mult(res, p);
            }
            n /= 2;
            if (n > 0) {
                p = mult(p, p);
            }
        }
        printf("%lld\n", res.m[1][0]);
    }
    return 0;
}
