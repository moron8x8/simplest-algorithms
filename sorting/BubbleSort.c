#include <stdio.h>

void BubbleSort(int n, int *a){
    int flag;
    int t;
    for (int j = 0; j < n; j++){
        flag = 1;
        
        for (int i = 0; i < n - j - 1; i++){
            if (a[i] > a[i + 1]){
                t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
                flag = 0;
            }
        }
        if (flag){
            break;
        }

    }
}


int main(void){
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\nSorted: ");
    BubbleSort(n, arr);
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}