/*  
    Circular Linked List Implementation
    @JIYO P V   16 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <stdlib.h>

// structure for CLL node
typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

// insert at end
void insertEnd(int value) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        head->next = head; // circular
    } else {
        node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    printf("%d inserted at end\n", value);
}

// delete from beginning
void deleteBegin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = head;

    if (head->next == head) { // only one node
        head = NULL;
        free(temp);
        printf("Node deleted\n");
        return;
    }

    node *last = head;
    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;
    printf("%d deleted from beginning\n", temp->data);
    free(temp);
}

// display CLL
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// menu
int menu() {
    int choice;
    printf("\nCIRCULAR LINKED LIST\n");
    printf("1. Insert\n");
    printf("2. Delete \n");
    printf("3. Display List\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// process menu
void process() {
    int choice, value;

    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 2:
                deleteBegin();
                break;
            case 3:
                display();
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

