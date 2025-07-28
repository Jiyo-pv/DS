// Program to find the Determinant of a matrix (2x2 and 3x3) @JIYO P V
//24 July 2025
#include <stdio.h>

// Function to read matrix elements
void readMatrix(int a[3][3], int size) {
    int i, j;
    printf("Enter matrix elements:\n");
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to display the matrix
void showMatrix(int a[3][3], int size) {
    int i, j;
    printf("Matrix:\n");
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate determinant
int determinant(int a[3][3], int size) {
    int det = 0;

    if(size == 2) {
        // For 2x2 matrix: |A| = ad - bc
        det = a[0][0]*a[1][1] - a[0][1]*a[1][0];
    }
    else if(size == 3) {
        // For 3x3 matrix using cofactor expansion
        det = a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1])
				- a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0])
            	+ a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);
    }
    return det;
}

int main() {
    int matrix[3][3], size, det;

    // Ask user for size of matrix
    printf("Enter the size of the square matrix (2 or 3): ");
    scanf("%d", &size);

    if(size != 2 && size != 3) {
        printf("Error: Only 2x2 or 3x3 matrices are supported.\n");
        return 1;
    }

    readMatrix(matrix, size);      // Input matrix
    showMatrix(matrix, size);      // Display matrix

    det = determinant(matrix, size);  // Calculate determinant

    printf("Determinant of the matrix = %d\n", det);

    return 0;
}

