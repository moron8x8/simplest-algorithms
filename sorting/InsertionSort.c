#include <stdio.h>

void InsertionSort(int n, int *a){
    int j;
    for(int i = 0; i < n; i++){
        int nonsorted = a[i];
        j = i - 1;

        while(j >= 0 && nonsorted < a[j]){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = nonsorted;
    }
}

int main(void){
    int n;
    if(scanf("%d", &n) != 1 || n <= 0) return 0;

    int a[n];

    for(int i = 0; i < n; i++){
        if(scanf("%d", &a[i]) != 1) return 0;
    }

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    InsertionSort(n, a);

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}