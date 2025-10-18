/*  
    Linked Stack Implementation using Linked List
    @JIYO P V   16 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <stdlib.h>

// structure for stack node
typedef struct node {
    int data;
    struct node *next;
} node;

node *top = NULL; // pointer to top of stack

// push operation
void push(int value) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto stack\n", value);
}

// pop operation
void pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return;
    }

    node *temp = top;
    printf("%d popped from stack\n", top->data);
    top = top->next;
    free(temp);
}

// peek operation (view top element)
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

// menu function
int menu() {
    int choice;
    printf("\nLINKED STACK MENU\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// process function
void process() {
    int choice, value;

    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
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

