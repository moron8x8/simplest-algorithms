#include <stdio.h>

int BinSearchRecursion(int *a, int left, int right, int searchednum){
    int middle;

    if (right < left) return -1;
    middle = left + (right - left) / 2;
    
    if(a[middle] == searchednum) return middle;

    if(a[middle] > searchednum) return BinSearchRecursion(a, left, middle - 1, searchednum);
    else return BinSearchRecursion(a, middle + 1, right, searchednum);
}

int BinSearchLeftRight(int size, int *a, int searchednum){
    int left, right, middle;

    left = 0;
    right = size - 1;

    while(left <= right){
        middle = left + (right - left) / 2;

        if(a[middle] == searchednum) return middle;

        if(a[middle] > searchednum) right = middle - 1;
        else left = middle + 1;
        
    }
    return -1;

}


int main(void){
    int n;
    if(scanf("%d", &n) != 1 || n <=0) return 0;

    int a[n];
    for (int i = 0; i < n; i++){
        if(scanf("%d", &a[i]) != 1) return 0;
    }

    int searchednum;
    if(scanf("%d", &searchednum) != 1) return 0;

    int recursion = BinSearchRecursion(a, 0, n - 1, searchednum);
    int leftright = BinSearchLeftRight(n, a, searchednum);
    printf("%d\n%d\n", recursion, leftright);


    return 0;
}