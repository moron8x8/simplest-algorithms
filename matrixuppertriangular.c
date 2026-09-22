#include <stdio.h>

void gauss_method(int len, double arr[len][len]){
  int row, i, j;
  double k;
  for (row = 0; row < len; row++){
    for (i = row + 1; i < len; i++){
      k = arr[i][row] / arr[row][row];
      for (j = 0; j < len; j++){
        arr[i][j] -= k * arr[row][j];
      }
    }
  }
}
      





int main (void)
{
  int len, row, column;
  if (scanf("%d", &len) != 1 || len <= 1) return 0;
  
  double arr[len][len];
  
  for (row = 0; row < len; row++)
    for (column = 0; column < len; column++)
      if (scanf("%lf", &arr[row][column]) != 1) return 0;


  gauss_method(len, arr);
  
  for (row = 0; row < len; row++){
    for (column = 0; column < len; column++){
      printf("%.2f ", arr[row][column]);
    }
    printf("\n");
  }


  return 0;

}    
