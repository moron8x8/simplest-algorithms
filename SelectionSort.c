#include <stdio.h>

void SelectionSort(int n, int *a){
    int min;
    int temp;
    for (int i = 0; i < n - 1; i ++){
        min = i;
        for (int j = i; j < n; j ++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        
        if(min != i){
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}


int main(void){
    int n;
    if(scanf("%d", &n) != 1 || n <= 0) return 1;
    int a[n];
    for(int i = 0; i < n; i ++){
        if(scanf("%d", &a[i]) != 1) return 1;
    }
    for(int i = 0; i < n; i ++){
        printf("%d ", a[i]);
    }
    printf("\n");
    SelectionSort(n, a);
    for(int i = 0; i < n; i ++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
