/*
    Priority Queue using Array
    @JIYO P V   08 OCTOBER 2025   Roll no:33
*/

#include <stdio.h>
#define SIZE 50

int queue[SIZE];       // Store elements
int priority[SIZE];    // Store corresponding priorities
int n = 0;             // Current number of elements in queue

// Function to insert an element with priority
void enqueue(int element, int prio) {
    if (n == SIZE) {
        printf("Queue Overflow! Cannot insert element.\n");
        return;
    }

    queue[n] = element;
    priority[n] = prio;
    n++;
    printf("%d with priority %d inserted into queue.\n", element, prio);
}

// Function to remove element with highest priority
void dequeue() {
    if (n == 0) {
        printf("Queue Underflow! No elements to delete.\n");
        return;
    }

    int i, maxIndex = 0;

    // Find element with highest priority
    for (i = 1; i < n; i++) {
        if (priority[i] > priority[maxIndex]) {
            maxIndex = i;
        }
    }

    printf("%d with priority %d removed from queue.\n", queue[maxIndex], priority[maxIndex]);

    // Shift remaining elements left
    for (i = maxIndex; i < n - 1; i++) {
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }

    n--;
}

// Function to display all elements
void display() {
    int i;
    if (n == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements (Element:Priority):\n");
    for (i = 0; i < n; i++) {
        printf("%d:%d ", queue[i], priority[i]);
    }
    printf("\n");
}

// Menu function
int menu() {
    int choice;
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Process menu
void processQueue() {
    int choice, element, prio;
    for (choice = menu(); choice != 4; choice = menu()) {
        switch(choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter priority: ");
                scanf("%d", &prio);
                enqueue(element, prio);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Main function
int main() {
    processQueue();
    return 0;
}

