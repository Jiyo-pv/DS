/*  
    Circular Linked Queue Implementation
    @JIYO P V   16 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <stdlib.h>

// structure for node
typedef struct node {
    int data;
    struct node *next;
} node;

node *front = NULL; // front pointer
node *rear = NULL;  // rear pointer

// enqueue operation
void enqueue(int value) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;

    if (rear == NULL) { // empty queue
        newNode->next = newNode; // circular
        front = rear = newNode;
    } else {
        newNode->next = front;
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d enqueued to circular queue\n", value);
}

// dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("Queue underflow\n");
        return;
    }

    node *temp = front;
    int value = temp->data;

    if (front == rear) { // only one node
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front; // maintain circularity
    }

    free(temp);
    printf("%d dequeued from circular queue\n", value);
}

// display queue elements
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    node *temp = front;
    printf("Circular Queue elements (front to rear): ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("(back to front)\n");
}

// menu function
int menu() {
    int choice;
    printf("\nCIRCULAR QUEUE MENU\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
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
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
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

