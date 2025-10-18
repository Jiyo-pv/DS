/*  
    Insert new nodes in a singly linked list
    (a) At the beginning
    (b) At the end
    (c) After a specified element
    @JIYO P V   15 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <stdlib.h>

// structure for linked list node
typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;  // head pointer

// function to insert node at beginning
void insertAtBeginning(int value) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("%d inserted at the beginning\n", value);
}

// function to insert node at end
void insertAtEnd(int value) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d inserted at the end\n", value);
}

// function to insert node after a given element
void insertAfterElement(int key, int value) {
    node *temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }

    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted after %d\n", value, key);
}

// function to display the linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// function to display menu
int menu() {
    int choice;
    printf("\nLINKED LIST MENU\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert After Element\n");
    printf("4. Display List\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// function to process menu
void process() {
    int choice, value, key;

    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter the element after which to insert: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAfterElement(key, value);
                break;
            case 4:
                displayList();
                break;
            case 5:
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

