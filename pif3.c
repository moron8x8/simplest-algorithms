#include <stdio.h>

typedef struct{
    long long m[3][3];
}Matrix3x3;

typedef struct{
    long long m[3][1];
}Matrix3x1;

static const Matrix3x3 trans[3] = {
        {{{1, -2, 2}, {2, -1, 2}, {2, -2, 3}}},
        {{{1, 2, 2}, {2, 1, 2}, {2, 2, 3}}},
        {{{-1, 2, 2}, {-2, 1, 2}, {-2, 2, 3}}}
};

Matrix3x1 mult(Matrix3x3 A, Matrix3x1 v){
    Matrix3x1 res;
    res.m[0][0] = A.m[0][0] * v.m[0][0] + A.m[0][1] * v.m[1][0] + A.m[0][2] * v.m[2][0];
    res.m[1][0] = A.m[1][0] * v.m[0][0] + A.m[1][1] * v.m[1][0] + A.m[1][2] * v.m[2][0];
    res.m[2][0] = A.m[2][0] * v.m[0][0] + A.m[2][1] * v.m[1][0] + A.m[2][2] * v.m[2][0];
    return res;
}


void deepMatrix(Matrix3x1 parent, int nowdepth, int maxdepth){
    if(nowdepth >= maxdepth){
        return;
    }

    for (int i = 0; i < 3; i++){
        Matrix3x1 child = mult(trans[i], parent);
        printf("%lld,%lld,%lld;%lld,%lld,%lld\n",
            parent.m[0][0], parent.m[1][0], parent.m[2][0],
            child.m[0][0], child.m[1][0], child.m[2][0]);
        deepMatrix(child, nowdepth + 1, maxdepth);
    }

}

int main(void){
    Matrix3x1 base = {{{3}, {4}, {5}}};
    int n;
    scanf("%d", &n);
    deepMatrix(base, 0, n);

    return 0;
}