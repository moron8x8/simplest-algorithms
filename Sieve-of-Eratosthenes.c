#include <stdio.h>

void Sieve_of_Eratosthenes (int n){ // Решето Эратосфена
    int arr [n];
    int num, count = 0;
    for (int i = 0; i <= n - 2; i ++){
        arr[i] = 1;
    }

    for (int i = 0; (i + 2) * (i + 2) <= n; i ++) {
        if (arr[i] == 0) continue; 
        num = i + 2;
        for (int j = num * num - 2; j <= n - 2; j += num){
            arr [j] = 0;
        }
    }

    for (int i = 0; i <= n - 2; i ++) {
        if (arr[i] == 1) {
            printf("%d\n", i + 2);
            count ++;
        }
    }
    printf("Count: %d\n", count);
}

int main(void){
    int n;
    scanf("%d", &n);
    Sieve_of_Eratosthenes(n);
    return 0;
}