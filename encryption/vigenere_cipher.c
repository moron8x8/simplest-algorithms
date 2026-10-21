#include <stdio.h>

void vigenere_cipher(size_t len_text, size_t key_len, const char *key, char *text){

  if (key_len == 0) return;
  int intkey[key_len];

  for (size_t i = 0; i < key_len; i++) {
    *(intkey + i) = *(key + i) - 'A';
  }

  size_t j = 0;
  for (size_t i = 0; i < len_text; i++) {
    int cur_key = intkey[j % key_len];

    if (text[i] >= 'A' && text[i] <= 'Z') {
      text[i] = 'A' + (text[i] - 'A' + cur_key) % 26;
      j++;
    }
    else if (text[i] >= 'a' && text[i] <= 'z') {
      text[i] = 'a' + (text[i] - 'a' + cur_key) % 26;
      j++;
    }
}

}

int main (void)
{
  size_t len_text, key_len;

  char text[] = "ATTACKATDAWN";
  const char key[] = "LEMON";
  len_text = sizeof(text) / sizeof(text[0]) - 1;
  key_len = sizeof(key) / sizeof(key[0]) - 1;

  vigenere_cipher(len_text, key_len, key, text);

  printf("%s\n", text);

  return 0;
  
}