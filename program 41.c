/*  
    Read n integers using calloc and find their mode
    @JIYO P V   12 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <stdlib.h>   // for calloc() and free()

int main()
{
    int n, i, j;
    int *arr;          // pointer to dynamically allocated array
    int mode;          // variable to store the mode
    int maxCount = 0;  // variable to store the highest frequency count
    int count;         // to count occurrences of each number

    // Ask the user for number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for 'n' integers using calloc
    arr = (int *)calloc(n, sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;   // exit if allocation fails
    }

    // Read 'n' integers from the user
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Find the mode (the value that appears most frequently)
    for (i = 0; i < n; i++)
    {
        count = 0; // reset count for each element

        for (j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
                count++;
        }

        // Update mode if current element occurs more times than previous max
        if (count > maxCount)
        {
            maxCount = count;
            mode = arr[i];
        }
    }

    // Display the mode
    printf("Mode = %d\n", mode);

    // Free the allocated memory
    free(arr);

    return 0;
}

