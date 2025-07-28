// Stack operations using array @JIYO P V
//24 July 2025

#include <stdio.h>
// Function to push an element onto the stack
int push(int n, int a[], int pos)
{
    if (pos + 1 == 5) // Check for stack overflow (max size is 5)
    {
        printf("error: stack overflow\n");
        return 4; // Return max valid position
    }
    a[++pos] = n; // Increment position and insert element
    return pos;   // Return new top position
}

// Function to pop the top element from the stack
int pop(int a[], int pos)
{
    if (pos == -1) // Check for stack underflow (empty stack)
    {
        printf("error: stack underflow\n");
        return -1;
    }
    printf("%d removed\n", a[pos--]); // Print and remove top element
    return pos; // Return new top position
}

// Function to peek at the top element of the stack
void peek(int a[], int pos)
{
    if (pos != -1) // If stack is not empty
    {
        printf("%d at top", a[pos]); // Show top element
    }
    else
    {
        printf("stack is empty"); // Stack is empty
    }
    printf("\n");
}

// Display the menu and return the user's choice
int menu()
{
    int input;
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. peek\n");
    printf("4. exit\n");
    printf("your choice: ");
    scanf("%d", &input); // Read user input
    return input;
}

// Function to process user commands and perform stack operations
int processStack(int a[], int pos)
{
    int ch;
    for (ch = menu(); ch != 4; ch = menu()) // Loop until user chooses to exit
    {
        switch (ch)
        {
            case 1:
                printf("enter element: ");
                scanf("%d", &ch);         // Reuse ch to read element to push
                pos = push(ch, a, pos);   // Call push function
                break;
            case 2:
                pos = pop(a, pos);        // Call pop function
                break;
            case 3:
                peek(a, pos);             // Call peek function
                break;
            default:
                printf("wrong choice\n"); // Invalid menu option
        }
    }
    return pos;
}

// Main function to initialize and start stack operations
void main()
{
    int a[5], pos = -1; // Initialize stack array and top position
    pos = processStack(a, pos); // Start processing stack operations
}

