/*  
    Polynomial addition and multiplication using linked list
    @JIYO P V   16 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <stdlib.h>

// structure for polynomial term
typedef struct node {
    int coeff;          // coefficient
    int pow;            // power of x
    struct node *next;  // pointer to next term
} node;

node *createNode(int c, int p) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->coeff = c;
    newNode->pow = p;
    newNode->next = NULL;
    return newNode;
}

// function to insert term in decreasing order of power
node *insertTerm(node *head, int c, int p) {
    node *newNode = createNode(c, p);
    if (head == NULL || head->pow < p) {
        newNode->next = head;
        head = newNode;
    } else {
        node *temp = head;
        while (temp->next != NULL && temp->next->pow >= p)
            temp = temp->next;
        if (temp->pow == p) {
            temp->coeff += c;
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

// function to display polynomial
void displayPoly(node *head) {
    if (head == NULL) {
        printf("0");
        return;
    }

    node *temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->pow);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
}

// function to create polynomial
node *createPolynomial() {
    node *head = NULL;
    int n,i, coeff, pow;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        head = insertTerm(head, coeff, pow);
    }
    return head;
}

// function to add two polynomials
node *addPoly(node *p1, node *p2) {
    node *result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->pow > p2->pow) {
            result = insertTerm(result, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            result = insertTerm(result, p2->coeff, p2->pow);
            p2 = p2->next;
        } else {
            result = insertTerm(result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        result = insertTerm(result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insertTerm(result, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return result;
}

// function to multiply two polynomials
node *multiplyPoly(node *p1, node *p2) {
    node *result = NULL;
    node *t1, *t2;

    for (t1 = p1; t1 != NULL; t1 = t1->next) {
        for (t2 = p2; t2 != NULL; t2 = t2->next) {
            int coeff = t1->coeff * t2->coeff;
            int pow = t1->pow + t2->pow;
            result = insertTerm(result, coeff, pow);
        }
    }
    return result;
}

// function to display menu
int menu() {
    int choice;
    printf("\nPOLYNOMIAL OPERATIONS\n");
    printf("1. Create Polynomial 1\n");
    printf("2. Create Polynomial 2\n");
    printf("3. Display Polynomials\n");
    printf("4. Add Polynomials\n");
    printf("5. Multiply Polynomials\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// function to process menu
void process() {
    int choice;
    node *poly1 = NULL, *poly2 = NULL, *result = NULL;

    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                printf("\nCreating Polynomial 1\n");
                poly1 = createPolynomial();
                break;
            case 2:
                printf("\nCreating Polynomial 2\n");
                poly2 = createPolynomial();
                break;
            case 3:
                printf("\nPolynomial 1: ");
                displayPoly(poly1);
                printf("\nPolynomial 2: ");
                displayPoly(poly2);
                printf("\n");
                break;
            case 4:
                result = addPoly(poly1, poly2);
                printf("\nResult (Addition): ");
                displayPoly(result);
                printf("\n");
                break;
            case 5:
                result = multiplyPoly(poly1, poly2);
                printf("\nResult (Multiplication): ");
                displayPoly(result);
                printf("\n");
                break;
            case 6:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}

// main function
int main() {
    process();
    return 0;
}

