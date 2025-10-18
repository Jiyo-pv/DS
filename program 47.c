/*  
    Create a singly linked list of n nodes and display it in reverse order
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

// function to create linked list of n nodes
void createList(int n) {
    int i, value;
    node *newNode, *temp;

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode = (node *)malloc(sizeof(node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

// function to display list in normal order
void displayList() {
    node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// function to display list in reverse order (using recursion)
void displayReverse(node *ptr) {
    if (ptr == NULL)
        return;

    displayReverse(ptr->next);
    printf("%d -> ", ptr->data);
}

// main function
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createList(n);

    printf("\nList in normal order:\n");
    displayList();

    printf("\nList in reverse order:\n");
    displayReverse(head);
    printf("NULL\n");

    return 0;
}

