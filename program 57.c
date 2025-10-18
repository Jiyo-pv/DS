/*  
    Linear Search in an Array
    @JIYO P V   16 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>

int main() {
    int n, i,input, found = 0;

    // input array size
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int arr[n];

    // input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // input element to search
    printf("Enter element to search: ");
    scanf("%d", &input);

    // linear search
    for (i = 0; i < n; i++) {
        if (arr[i] == input) {
            printf("Element %d found at position %d\n", input, i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element %d not found in the array\n", input);

    return 0;
}

