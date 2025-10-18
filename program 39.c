/*  
    implement malloc calloc free
    @JIYO P V   12 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <stdlib.h>   // for malloc, calloc, free

int main() {
    int n;           // number of integers
    int i;           // loop variable
    int *arr1;       // pointer for malloc
    int *arr2;       // pointer for calloc

    n = 5;

    printf("===== DEMONSTRATION OF MALLOC AND CALLOC =====\n\n");

    /* ----------- Using malloc() ----------- */
    printf("---- Using malloc() ----\n");

    arr1 = (int*) malloc(n * sizeof(int));  // allocate memory

    if (arr1 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Values just after malloc (garbage values):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);  // garbage values
    }
    printf("\n");

    // assign values
    for (i = 0; i < n; i++) {
        arr1[i] = i + 1;
    }

    printf("Values after assigning data using malloc:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    free(arr1);
    printf("Memory freed after malloc.\n\n");

    /* ----------- Using calloc() ----------- */
    printf("---- Using calloc() ----\n");

    arr2 = (int*) calloc(n, sizeof(int));  // allocate memory

    if (arr2 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Values just after calloc (all zeros):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // assign values
    for (i = 0; i < n; i++) {
        arr2[i] = (i + 1) * 10;
    }

    printf("Values after assigning data using calloc:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    free(arr2);
    printf("Memory freed after calloc.\n");
    return 0;
}

