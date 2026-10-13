#include <stdio.h>

long long bin_power(long long base, int exp)
{
  long long res = 1;

  while (exp > 0) {
    if (exp % 2 == 0) {
      base *= base;
      exp /= 2;
    } else {
      res *= base;
      exp--;
    }
  }
  return res;
}

int main(void)
{
  long long base;
  int exp;

  if (scanf("%lld", &base) != 1) return 0; 
  if (scanf("%d", &exp) != 1 || exp < 0) return 0;

  printf("%lld\n", bin_power(base, exp)); 
  
  return 0;
}
