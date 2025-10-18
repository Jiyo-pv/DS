/*  
    Binary Search in a Sorted Array
    @JIYO P V   16 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>

int main() {
    int n, i, key, low, high, mid, found = 0;

    // input array size
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int arr[n];

    // input sorted array elements
    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // input element to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    // binary search
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            printf("Element %d found at position %d\n", key, mid + 1);
            found = 1;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found)
        printf("Element %d not found in the array\n", key);

    return 0;
}

