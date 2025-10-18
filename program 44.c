/*  
    Demonstrate Linked List creation and display using menu
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

// function to insert node at end
void insertNode(int value) {
    node *newNode = (node *)malloc(sizeof(node));  // create new node
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;  // first node
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;  // move to last node
        }
        temp->next = newNode;  // link new node at end
    }
    printf("%d inserted into the list\n", value);
}

// function to display linked list
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

// function to show menu and get choice
int menu() {
    int choice;
    printf("\nLINKED LIST MENU\n");
    printf("1. Insert Node\n");
    printf("2. Display List\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// function to process menu options
void process() {
    int choice, value;
    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertNode(value);
                break;
            case 2:
                displayList();
                break;
            case 3:
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

