//Evan Stacharczyk lab assignment 7 due 3/7/24

#include <stdio.h>

void bubbleSort(int arr[], int n, int swapCount[])
{
  int i, j, temp;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
//Swaping and counting
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        
        swapCount[j]++;
        swapCount[j + 1]++;
      }
    }
  }
}

void selectionSort(int arr[], int n, int swapCount[])
{
  int i, j, min, temp;
  for (i = 0; i < n - 1; i++)
  {
    min = i;
    for (j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min])
      {
        min = j;
      }
    }
    
    temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
    
    swapCount[i]++;
    swapCount[min]++;
  }
}

void printSwapCounts(int arr[], int swapCount[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d: # of times %d is swapped\n", swapCount[i], arr[i]);
  }
}

int main()
{
  int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
  int n = 9;
  
  int totalSwaps1 = 0, totalSwaps2 = 0;
  int swapCount1[9], swapCount2[9];
  
  for (int i = 0; i < n; i++)
  {
    swapCount1[i] = 0;
    swapCount2[i] = 0;
  }

//Sorting/printing array1
  printf("array1:\n");
  bubbleSort(array1, n, swapCount1);
  printSwapCounts(array1, swapCount1, n);
  
  for (int i = 0; i < n; i++)
  {
    totalSwaps1 += swapCount1[i];
  }
  printf("\ntotal # of swaps: %d\n", totalSwaps1);

//Sorting/printing array2
  printf("\narray2:\n");
  selectionSort(array2, n, swapCount2);
  printSwapCounts(array2, swapCount2, n);
  
  for (int i = 0; i < n; i++)
  {
    totalSwaps2 += swapCount2[i];
  }
  printf("\ntotal # of swaps: %d\n", totalSwaps2);
  
  return 0;
}
