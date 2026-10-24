#include <stdio.h>
#include <stdlib.h>


void deRLE(const char *str, char *res)
{
  if (str == NULL || res == NULL) return;
    
  size_t i = 0;
  size_t pos = 0;

  while (*(str + i) != '\0') {
    char cur_char = *(str + i);
    i++;

    size_t count = 0;

    while (*(str + i) >= '0' && *(str + i) <= '9') {
      count = count * 10 + (size_t)(*(str + i) - '0');
      i++;
    }

    for (size_t j = 0; j < count; j++) {
      *(res + pos) = cur_char;
      pos++;
    }
  }
  *(res + pos) = '\0';
}


size_t len_RLE(const char *str)
{
  if (str == NULL) return 0;
  size_t len = 0;

  size_t i = 0;
  while (*(str + i) != '\0') {

    i++;

    size_t count = 0;

    while (*(str + i) >= '0' && *(str + i) <= '9') {
      count = count * 10 + (size_t)(*(str + i) - '0');
      i++;
    }

    len += count;
  }

  return len;
}

int main(void)
{
  char str[] = "A3B10S3";

  size_t len_res = len_RLE(str);

  char *res = malloc(len_res + 1);
  if (res == NULL) return 0;


  deRLE(str, res);

  printf("%s\n", res);

  free(res);


  return 0;
}