// find occurrences of an element in an array   @JIYO P V
//24 July 2025
#include<stdio.h>

int main()
{
    int n, a[10], i; // Declare array and variables

    // Input the size of the array
    printf("enter n->");
    scanf("%d", &n);

    // Input array elements
    printf("enter array:");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int num, flag = 0; // 'num' is the element to search, 'flag' tracks if found

    // Input the number to search for
    printf("enter no to search:");
    scanf("%d", &num);

    // Search through the array
    for(i = 0; i < n; i++)
    {
        if(a[i] == num) // If current element matches the search number
        {
            flag = 1; // Set flag to indicate it's found
            printf("%d at index %d\n", num, i); // Print occurrence
        }
    }

    // If flag is still 0, the element was not found
    if(!flag)
    {
        printf("error:not found");
    }

    return 0;
}

