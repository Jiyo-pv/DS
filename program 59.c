/*  
    Binary Search on an Array of Strings (No Spaces)
    @JIYO P V   16 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <string.h>

#define MAX 50  // maximum length of each string

int main() {
    int n, low, high, mid, found = 0;
    char key[MAX];

    // input number of strings
    printf("Enter number of strings: ");
    scanf("%d", &n);

    char arr[n][MAX];
	int i;
    // input strings in sorted order (no spaces)
    printf("Enter %d strings in sorted order (no spaces):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    // input string to search
    printf("Enter string to search: ");
    scanf("%s", key);

    // binary search
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        int cmp = strcmp(arr[mid], key);

        if (cmp == 0) {
            printf("String \"%s\" found at position %d\n", key, mid + 1);
            found = 1;
            break;
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found)
        printf("String \"%s\" not found in the array\n", key);

    return 0;
}

