#include <stdio.h>

#define MAX_TERMS 10

struct Term {
    int coeff;
    int exp;
};

// Function to input a polynomial
void inputPolynomial(struct Term poly[], int *n) {
    int i;  // Declare loop variable at top
    printf("Enter number of terms: ");
    scanf("%d", n);

    for(i = 0; i < *n; i++) {
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

// Function to multiply two polynomials
int multiplyPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term result[]) {
    int i, j, r;  // Declare all loop variables at top
    int k = 0;

    // Initialize result array
    for(i = 0; i < n1 * n2; i++) {
        result[i].coeff = 0;
        result[i].exp = 0;
    }

    // Multiply each term of poly1 with each term of poly2
    for(i = 0; i < n1; i++) {
        for(j = 0; j < n2; j++) {
            int exp = poly1[i].exp + poly2[j].exp;
            int coeff = poly1[i].coeff * poly2[j].coeff;

            // Check if this exponent already exists in result
            int found = 0;
            for(r = 0; r < k; r++) {
                if(result[r].exp == exp) {
                    result[r].coeff += coeff;
                    found = 1;
                    break;
                }
            }
            if(!found) {
                result[k].exp = exp;
                result[k].coeff = coeff;
                k++;
            }
        }
    }

    return k;  // Number of terms in result
}

// Function to display a polynomial
void displayPolynomial(struct Term poly[], int n) {
    int i;  // Declare loop variable at top
    for(i = 0; i < n; i++) {
        if(poly[i].coeff != 0) {
            printf("%dx^%d", poly[i].coeff, poly[i].exp);
            if(i < n - 1) printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Term poly1[MAX_TERMS], poly2[MAX_TERMS], result[MAX_TERMS*MAX_TERMS];
    int n1, n2, nResult;
    
    printf("First Polynomial:\n");
    inputPolynomial(poly1, &n1);

    printf("Second Polynomial:\n");
    inputPolynomial(poly2, &n2);

    nResult = multiplyPolynomials(poly1, n1, poly2, n2, result);

    printf("Product of polynomials: ");
    displayPolynomial(result, nResult);

    return 0;
}

