#include <stdio.h>


int isprime(int num)
{
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void prime_divider(int num)
{

    while (num % 2 == 0) {
        num /= 2;
        printf("2 ");
    }

    for (int i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            num /= i;
            printf("%d ", i);
        }
        
    }


    if (num > 1){
        printf("%d", num);
    }

    printf("\n");
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 1) return 0;

    printf("%d\n", isprime(n));
    prime_divider(n);

    return 0;
}