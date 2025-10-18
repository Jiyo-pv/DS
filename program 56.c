/*  
    Circular Doubly Linked List with String Data
    Insert, Delete, Display Forward and Backward
    @JIYO P V   16 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50  // max string length

// structure for CDLL node
typedef struct node {
    char data[MAX];
    struct node *prev;
    struct node *next;
} node;

node *head = NULL;

// insert at end
void insertEnd(char value[]) {
    node *newNode = (node *)malloc(sizeof(node));
    strcpy(newNode->data, value);

    if (head == NULL) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
    } else {
        node *last = head->prev;

        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }

    printf("\"%s\" inserted at end\n", value);
}

// delete from beginning
void deleteBegin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = head;
    char value[MAX];
    strcpy(value, temp->data);

    if (head->next == head) { // only one node
        head = NULL;
    } else {
        node *last = head->prev;
        head = head->next;
        head->prev = last;
        last->next = head;
    }

    free(temp);
    printf("\"%s\" deleted from beginning\n", value);
}

// display forward
void displayForward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = head;
    printf("CDLL (forward): ");
    do {
        printf("\"%s\" -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// display backward
void displayBackward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = head->prev; // start from last node
    printf("CDLL (backward): ");
    node *start = temp;
    do {
        printf("\"%s\" -> ", temp->data);
        temp = temp->prev;
    } while (temp != start);
    printf("(back to last)\n");
}

// menu
int menu() {
    int choice;
    printf("\nCIRCULAR DOUBLY LINKED LIST MENU\n");
    printf("1. Insert at End\n");
    printf("2. Delete from Beginning\n");
    printf("3. Display Forward\n");
    printf("4. Display Backward\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// process menu
void process() {
    int choice;
    char value[MAX];

    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Enter string to insert: ");
                scanf(" %[^\n]", value); // read string with spaces
                insertEnd(value);
                break;
            case 2:
                deleteBegin();
                break;
            case 3:
                displayForward();
                break;
            case 4:
                displayBackward();
                break;
            case 5:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}

// main
int main() {
    process();
    return 0;
}

