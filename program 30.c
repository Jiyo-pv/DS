/*  
    Demonstrate circular queue using array
    @JIYO P V   08 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#define SIZE 5

int a[SIZE];
int front = -1, rear = -1;

// Function to insert element at the rear
void enqueue(int n)
{
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front)
    {
        printf("Queue Overflow! Cannot insert %d\n", n);
        return;
    }

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;

    a[rear] = n;
    printf("%d inserted into queue.\n", n);
}

// Function to remove element from the front
void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow! No elements to delete.\n");
        return;
    }

    printf("%d deleted from queue.\n", a[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

// ? Simplified display function
void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");

    int i = front;
    do
    {
        printf("%d ", a[i]);
        i = (i + 1) % SIZE;
    } while (i != (rear + 1) % SIZE);

    printf("\n");
}

// Function to display menu and take user input
int menu()
{
    int input;
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
    scanf("%d", &input);
    return input;
}

// Function to process user menu choices
void processArray()
{
    int ch, element;
    for (ch = menu(); ch != 4; ch = menu())
    {
        switch (ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                enqueue(element);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            default:
                printf("Wrong choice!\n");
        }
    }
}

// Main function
int main()
{
    processArray();
    return 0;
}

