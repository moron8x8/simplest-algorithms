#include <stdio.h>

void caesar_cipher(int n, int shift, char *str){

  shift %= 26;
  if (shift < 0) shift += 26;

  for (int i = 0; i < n; i++){
    if (*(str + i) >= 'A' && *(str + i) <= 'Z') {
      *(str + i) = 'A' + (*(str + i) - 'A' + shift) % 26;
    }
    else if (*(str + i) >= 'a' && *(str + i) <= 'z') {
      *(str + i) = 'a' + (*(str + i) - 'a' + shift) % 26;
    }
  }
}

int main (void)
{
  int n, shift;

  char str[] = "The Quick Brown Fox Jumps Over The Lazy Dog";
  n = sizeof(str) / sizeof(str[0]) - 1;

  if (scanf("%d", &shift) != 1) return 0;

  caesar_cipher(n, shift, str);


  printf("%s\n", str);

  return 0;
  
}