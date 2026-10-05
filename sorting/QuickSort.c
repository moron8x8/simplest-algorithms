#include <stdio.h>

static void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

static int partition(int *a, int low, int hight)
{
  int mid = low + (hight - low) / 2;
  swap(&a[mid], &a[hight]);
  int pivot = a[hight];
  int i = low;
  for (int j = low; j < hight; j++){
    if (a[j] < pivot){
      swap(&a[i], &a[j]);
      i++;
    }
  }
  swap(&a[hight], &a[i]);
  
  return i;
}

static void qs(int *a, int low, int hight)
{
  while (low < hight) {
    if (low >= hight) return;
    int p = partition(a, low, hight);
    if (p - low < hight - p){
      qs(a, low, p - 1);
      low = p + 1;
    }
    else {
      qs(a, p + 1, hight);
      hight = p - 1;
    }
  }
}

void QuickSort(int n, int *a){
  qs(a, 0, n - 1);
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
    QuickSort(n, arr);

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}