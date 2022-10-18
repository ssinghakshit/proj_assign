#include <stdio.h>
#include <stdlib.h>
#include <time.h>
  
  // Function to swap the the position of two elements
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  // Main function to do heap sort
  double heapSort(int arr[], int n) {
    // Build max heap
    clock_t start = clock();
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
    clock_t end = clock();
    return (((double)(end-start))/CLOCKS_PER_SEC);
  }
  
  // Print an array
  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  
  // Driver code
 int main()
{
     int choice, flag, l, a[50000], i, j, s;
    double cpurt;
      printf("0) Enter (0) to calculate the central processing unit (C.P.U) run time of rearanging the numbers in ascending order:");
    flag = 1;
    while(flag==1)
    {
        printf("Choose from the above given menu:\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 0:
            s = 0;
            printf("Analysis Table for Max Heap Sort Algorithm:\n\n");
            printf("Serial Number: |Length of List: |C.P.U Clock Time: (R-->Ascen): \n ");
            for(i=5000;i<=50000;i+=5000)
            {
                for(j=0;j<i;j++)
                {
                    a[j] = rand()%1000;
                }
                cpurt =   heapSort(a,i-1);
                
                printf("(%d)            |(%d)          |(%lf)\n", ++s, i, cpurt);
            }
            break;
            default:
            printf("Wrong Choice:");
            flag=0;
        }
    }
    return (0);
}

