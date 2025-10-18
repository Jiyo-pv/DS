/*
    Read a polynomial and display it; use structure array
    @JIYO P V   12 OCTOBER 2025   Roll no:33
*/

#include <stdio.h>

//define structure to store polynomial terms
struct Term {
    int coeff;
    int exp;
};

int main() {
    int n,i;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    struct Term poly[n];

    // Read polynomial terms
    for (i = 0; i < n; i++) {
        printf("Enter coefficient of term %d: ", i + 1);
        scanf("%d", &poly[i].coeff);
        printf("Enter exponent of term %d: ", i + 1);
        scanf("%d", &poly[i].exp);
    }

    // Display the polynomial
    printf("The polynomial is: ");
    for (i = 0; i < n; i++) {
        if (i > 0 && poly[i].coeff >= 0) {
            printf("+");
        }
        printf("%dx^%d", poly[i].coeff, poly[i].exp);
    }
    printf("\n");
    return 0;
}

