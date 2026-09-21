#include <stdio.h>

typedef struct {
  int value, index;
} element;

void merge(int size, int mid, element *a){

    element temp[size];

    int i = 0;
    int j = mid;
    int k = 0;

    while(i < mid && j < size){
        if(a[i].value <= a[j].value){
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



void MergeSort(int size, element *a){
    
    if (size <= 1) return;

    int mid = size / 2;

    MergeSort(mid, a); // left part
    MergeSort(size - mid, a + mid); // right part

    merge(size, mid, a);
}


int main(void)
{

    int n, i, right, left, target;
    if(scanf("%d", &n) != 1 || n <= 0) return 0;
    if(scanf("%d", &target) != 1) return 0;
    element arr[n];
    for(i = 0; i < n; i++){
        if(scanf("%d", &arr[i].value) != 1) return 0;
        arr[i].index = i;
    }
    MergeSort(n, arr);

    right = 0;
    left = n - 1;
    
    while(arr[right].value + arr[left].value != target){
        if (right >= left) return 0;
        if (arr[right].value + arr[left].value > target) left -= 1;
        else right += 1;
    }
    if (right == left) return 0;
    printf("%d + %d = %d\n", arr[right].value, arr[left].value, target);
    printf("%d %d\n", arr[right].index, arr[left].index);

    return 0;
}
  
    
