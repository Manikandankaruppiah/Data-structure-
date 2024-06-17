Write a C program to take n numbers and sort the numbers in ascending order. Try to implement the same using following sorting techniques.
1.	Quick Sort
2.	Merge Sort

Aim:
To write a C program to take n numbers and sort the numbers in ascending order. To implement the same using following sorting techniques:
 
1.Quick Sort
2.Merge Sort

Algorithm:

Quick Sort:
Step 1: Start the program
Step 2: Provide void swap
Step 3: Accept integer partition 
Step 4: Provide void quicksort
Step 5: Accept int n = sizeof (arr) /sizeof  (arr[0])
Step 6: Print original array
Step 7: Print sorted array
Step 8: Stop the program

Merge Sort:
Step 1: Start the program
Step 2: Provide void merge
Step 3: Provide void merge sort
Step 4: Provide void print array
Step 5: Print the given array
Step 6: Print the sorted array
Step 7: Stop the program
 
Program:

MERGE SORT:

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    i = 0; 
    j = 0; 
    k = l; 

    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids 
        // overflow for large l and r 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    
    printf("\nEnter array elements:\n");
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
    }   
    printf("Given array is \n"); 
    printArray(arr, n); 
  
    mergeSort(arr, 0, n - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, n); 
    return 0; 
}
 
Output:

Enter the size of the array: 6

Enter array elements:
12
11
13
5
7
6
Given array is 
12 11 13 5 7 6 

Sorted array is 
5 6 7 11 12 13



QUICK SORT:

#include <stdio.h>
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
   
int partition(int arr[], int low, int high) 
{ 
  
    int pivot = arr[low]; 
    int i = low; 
    int j = high; 
  
    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) { 
            i++; 
        } 
        while (arr[j] > pivot && j >= low + 1) { 
            j--; 
        } 
        if (i < j) { 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[low], &arr[j]); 
    return j; 
} 
  
 
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) { 
        int partitionIndex = partition(arr, low, high); 
        quickSort(arr, low, partitionIndex - 1); 
        quickSort(arr, partitionIndex + 1, high); 
    } 
} 
   
int main() 
{ 
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    
    printf("\nEnter array elements:\n");
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
    } 
   
    printf("Original array: "); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
  
    quickSort(arr, 0, n - 1); 
  
    // printing the sorted array 
    printf("\nSorted array: "); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    }
    return 0; 
}
 
Output :

Enter the size of the array: 9

Enter the elements: 9
19
17
15
12
16
18
4
11
13

Original array:
 19 17 15 12 16 18 4 11 13

Sorted array using quick sort:
4 11 12 13 15 16 17 18 19





