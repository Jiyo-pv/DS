/*  
    Delete nodes from a singly linked list
    (a) From the beginning
    (b) From the end
    (c) With a specified data element
    @JIYO P V   16 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <stdlib.h>

// structure for linked list node
typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;  // head pointer

// function to insert node at end (for testing)
void insertAtEnd(int value) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// function to delete node from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    node *temp = head;
    printf("%d deleted from beginning\n", head->data);
    head = head->next;
    free(temp);
}

// function to delete node from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    node *temp = head, *prev = NULL;

    // if only one node
    if (head->next == NULL) {
        printf("%d deleted from end\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    // move to last node
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("%d deleted from end\n", temp->data);
    prev->next = NULL;
    free(temp);
}

// function to delete node with specific data
void deleteByValue(int key) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    node *temp = head, *prev = NULL;

    // if head node holds the key
    if (head->data == key) {
        head = head->next;
        printf("%d deleted from the list\n", key);
        free(temp);
        return;
    }

    // search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }

    prev->next = temp->next;
    printf("%d deleted from the list\n", key);
    free(temp);
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
    printf("1. Insert Node at End\n");
    printf("2. Delete from Beginning\n");
    printf("3. Delete from End\n");
    printf("4. Delete by Value\n");
    printf("5. Display List\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// function to process menu
void process() {
    int choice, value;

    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 2:
                deleteFromBeginning();
                displayList();
                break;
            case 3:
                deleteFromEnd();
                displayList();
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                displayList();
                break;
            case 5:
                displayList();
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

