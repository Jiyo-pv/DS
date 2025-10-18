/*  
    Demonstrate Heap Sort
    @JIYO P V   08 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>

// Function to heapify a subtree rooted with node i
void heapify(int a[], int n, int i)
{
    int largest, left, right, temp;

    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && a[left] > a[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && a[right] > a[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(a, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int a[], int n)
{
    int i, temp;

    // Build max heap
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // Extract elements from heap one by one
    for (i = n - 1; i >= 0; i--)
    {
        // Move current root to end
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        // Call max heapify on the reduced heap
        heapify(a, i, 0);
    }
}

// Function to display array elements
void display(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Main function
int main()
{
    int n, i;
    int a[50];  // static size array for simplicity

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nOriginal array:\n");
    display(a, n);

    heapSort(a, n);

    printf("\nSorted array (Heap Sort):\n");
    display(a, n);

    return 0;
}

