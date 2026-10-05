#include <stdio.h>
#include <string.h>

void rle(char str[], int size, char res[]){
    char previos = str[0];
    int freeIndex = 0;
    int count = 0;
    int lencount;
    for (int i = 0; i < size; i++) {
        if (previos == str[i]){
            count += 1;
        }else{
            res[freeIndex] = str[i - 1];
            freeIndex += 1;
            lencount = sprintf(&res[freeIndex], "%d", count);
            freeIndex += lencount;
            previos = str[i];
            count = 1;
        }
    }
    res[freeIndex] = previos;
    freeIndex += 1;
    lencount = sprintf(&res[freeIndex], "%d", count);
    freeIndex += lencount;
    res[freeIndex] = '\0';
}

int main(void){
    char str [100];
    if (scanf("%99s", str) == 1){
        int len = strlen(str);
        char res [len * 2 + 1];
        rle(str, len, res);
        printf("%s", res);
    }
    return 0;
}