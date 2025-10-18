/*  
    Linked Queue Implementation using Linked List
    @JIYO P V   16 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <stdlib.h>

// structure for queue node
typedef struct node {
    int data;
    struct node *next;
} node;

node *front = NULL; // pointer to front of queue
node *rear = NULL;  // pointer to rear of queue

// enqueue operation
void enqueue(int value) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) { // empty queue
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to queue\n", value);
}

// dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("Queue underflow\n");
        return;
    }

    node *temp = front;
    printf("%d dequeued from queue\n", front->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

// display operation
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    node *temp = front;
    printf("Queue elements (front to rear): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// menu function
int menu() {
    int choice;
    printf("\nLINKED QUEUE MENU\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
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

