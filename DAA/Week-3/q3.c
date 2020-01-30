#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
bool findPartiion(int arr[], int n)
{
  int sum = 0;
  int i, j;
  for (i = 0; i < n; i++)
    sum += arr[i];
  if (sum % 2 != 0)
    return false;
  bool part[sum / 2 + 1][n + 1];
  for (i = 0; i <= n; i++)
    part[0][i] = 1;
  for (i = 1; i <= sum / 2; i++)
    part[i][0] = 0;
    int opcount=0;
  for (i = 1; i <= sum / 2; i++)
  {
    for (j = 1; j <= n; j++)
    { 
      opcount++;
      printf("%d",part[i][j]);
      part[i][j] = part[i][j - 1];
      if (i >= arr[j - 1])
        part[i][j] = part[i][j] || part[i - arr[j - 1]][j - 1];
    }
    printf("%d",part[i][j]);
    printf("\n");
  }
  printf("%d",opcount);
  return part[sum / 2][n];
}
void main()
{
  int n, i;

  printf("Enter the Size : \n");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the Elements : \n");
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  if (findPartiion(arr, n) == true)
    printf("Can be divided into two subsets of equal sum\n");
  else
    printf("Can not be divided into two subsets of equal sum\n");
}
