#include <stdio.h>


void merge(int size, int mid, int *a){

    int temp[size];

    int i = 0;
    int j = mid;
    int k = 0;

    while(i < mid && j < size){
        if(a[i] <= a[j]){
            temp[k] = a[i];
            k++;
            i++;
        }else{
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    while(i < mid) temp[k++] = a[i++];
    while(j < size) temp[k++] = a[j++];

    for(int i = 0; i < size; i++){
        a[i] = temp[i];
    }

}



void MergeSort(int size, int *a){
    
    if (size <= 1) return;

    int mid = size / 2;

    MergeSort(mid, a); // left part
    MergeSort(size - mid, a + mid); // right part

    merge(size, mid, a);
}


int main(void){

    int n;
    if(scanf("%d", &n) != 1 || n <= 0) return 0;
    int arr[n];
    for(int i = 0; i < n; i++){
        if(scanf("%d", &arr[i]) != 1) return 0;
    }
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    MergeSort(n, arr);

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}