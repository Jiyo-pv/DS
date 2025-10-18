#include <stdio.h>

#define MAX_TERMS 10

struct Term {
    int coeff;
    int exp;
};

// Function to input a polynomial
void inputPolynomial(struct Term poly[], int *n) {
    int i;
	printf("Enter number of terms: ");
    scanf("%d", n);

    for( i = 0; i < *n; i++) {
        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%d", &poly[i].coeff);
        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &poly[i].exp);
    }

    // Display polynomial after input
    printf("Polynomial entered: ");
    
	for(i = 0; i < *n; i++) {
        printf("%dx^%d", poly[i].coeff, poly[i].exp);
        if(i < *n - 1) printf(" + ");
    }
    printf("\n");
}

// Function to subtract two polynomials (poly1 - poly2)
int subtractPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term result[]) {
    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2) {
        if(poly1[i].exp > poly2[j].exp) {
            result[k++] = poly1[i++];
        } else if(poly1[i].exp < poly2[j].exp) {
            // Subtracting a missing term in poly1 is negative
            result[k].exp = poly2[j].exp;
            result[k].coeff = -poly2[j].coeff;
            k++; j++;
        } else {
            result[k].exp = poly1[i].exp;
            result[k].coeff = poly1[i].coeff - poly2[j].coeff;
            i++; j++; k++;
        }
    }

    // Copy remaining terms
    while(i < n1) result[k++] = poly1[i++];
    while(j < n2) {
        result[k].exp = poly2[j].exp;
        result[k].coeff = -poly2[j].coeff;
        k++; j++;
    }

    return k;
}

// Function to display a polynomial
void displayPolynomial(struct Term poly[], int n) {
    int i;
	for( i = 0; i < n; i++) {
        printf("%dx^%d", poly[i].coeff, poly[i].exp);
        if(i < n - 1) printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Term poly1[MAX_TERMS], poly2[MAX_TERMS], result[2*MAX_TERMS];
    int n1, n2, nResult;

    // Input first polynomial
    printf("First Polynomial:\n");
    inputPolynomial(poly1, &n1);

    // Input second polynomial
    printf("Second Polynomial:\n");
    inputPolynomial(poly2, &n2);

    // Subtract polynomials
    nResult = subtractPolynomials(poly1, n1, poly2, n2, result);

    // Display result
    printf("Result of subtraction (First - Second): ");
    displayPolynomial(result, nResult);

    return 0;
}

