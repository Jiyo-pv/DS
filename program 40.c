/*  
    Read n integers using malloc and find their mean
    @JIYO P V   12 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <stdlib.h>   // for malloc() and free()

int main()
{
    int n, i;          // variables for number of elements and loop counter
    int *arr;          // pointer to hold the address of dynamically allocated array
    int sum = 0;       // variable to store the sum of all integers
    float mean;        // variable to store the calculated mean

    // Ask the user for the number of integers to read
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for 'n' integers using malloc
    arr = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;   // exit the program with an error code
    }

    // Read 'n' integers from the user
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);  // store input in dynamically allocated array
        sum += arr[i];         // add each number to the sum
    }

    // Calculate mean (convert sum to float to get decimal result)
    mean = (float)sum / n;

    // Display the calculated mean
    printf("Mean = %.2f\n", mean);

    // Release the dynamically allocated memory
    free(arr);

    return 0;   // successful program termination
}

