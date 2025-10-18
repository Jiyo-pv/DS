/*  
    Sort the elements in a singly linked list
    (a) By swapping the values
    (b) By changing the addresses
    @JIYO P V   16 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <stdlib.h>

// structure for linked list node
typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL; // head pointer

// function to insert node at end
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

// function to sort linked list by swapping values
void sortByValue() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // swap values
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("List sorted by swapping values.\n");
}

// function to sort linked list by changing addresses
void sortByAddress() {
    if (head == NULL || head->next == NULL) {
        printf("List is too short to sort.\n");
        return;
    }

    node *i, *j, *prev, *temp;
    int swapped;

    do {
        swapped = 0;
        prev = NULL;
        i = head;

        while (i->next != NULL) {
            j = i->next;

            if (i->data > j->data) {
                // swap links instead of data
                if (prev == NULL) {
                    head = j;
                } else {
                    prev->next = j;
                }
                i->next = j->next;
                j->next = i;

                swapped = 1;
                prev = j;
            } else {
                prev = i;
                i = i->next;
            }
        }
    } while (swapped);

    printf("List sorted by swapping addresses.\n");
}

// function to display menu
int menu() {
    int choice;
    printf("\nLINKED LIST SORT MENU\n");
    printf("1. Insert Node at End\n");
    printf("2. Display List\n");
    printf("3. Sort by Swapping Values\n");
    printf("4. Sort by Changing Addresses\n");
    printf("5. Exit\n");
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
                displayList();
                break;
            case 3:
                sortByValue();
                displayList();
                break;
            case 4:
                sortByAddress();
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

