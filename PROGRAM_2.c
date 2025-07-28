// array operations using global variables @JIYO P V
//24 July 2025
#include<stdio.h>
// Global array and position tracker
int a[5], pos = -1;

// Function to insert an element into the array
void insert(int n)
{
    if(pos == 4) // Maximum index reached (array size = 5)
    {
        printf("error:cannot insert\n");
        return;
    }
    a[++pos] = n; // Increment position and insert element
}
// Function to delete the last element from the array
void delete_element()
{	
    if(pos == -1) // Check if array is empty
    {	
        printf("error:array empty\n");
        return;
    }
    printf("deleted %d\n", a[pos--]); // Print and remove last element
}

// Function to display menu and take user input
int menu()
{	
    int input;
    printf("1.insert \n2.delete \n3.search\n4.display\n5.sort\n6.exit\nenter your choice:");
    scanf("%d", &input); // Read user menu choice
    return input;
}

// Function to search for an element in the array
void search(int n)
{
    int i, flag = -1; // Initialize flag to -1 (not found)
    for(i = 0; i <= pos; i++) // Traverse the array
    {
        if(a[i] == n)
        {
            flag = i; // Store index if match found
        }
    }
    if(flag != -1)
    {
        printf("found at index %d\n", flag); // Print index where found
    }
    else
    {
        printf("search failed\n"); // Element not found
    }
}

// Function to display all array elements
void display()
{
    int i;
    for(i = 0; i <= pos; i++) // Loop and print elements
    {
        printf("%d\t", a[i]);
    }
    printf("\n"); // Newline after display
}

// Function to sort the array using bubble sort
void sort()
{
    int i, j, temp;
    for(i = 0; i <= pos; i++) // Outer loop
    {
        for(j = 0; j <= pos; j++) // Inner loop
        {
            if(a[i] < a[j]) // If out of order, swap
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    display(); // Display sorted array
}

// Function to process user menu choices and perform operations
void processArray()
{
    int ch;
    for(ch = menu(); ch != 6; ch = menu()) // Loop until user exits
    {
        switch(ch)
        {
            case 1:
                printf("enter element:");
                scanf("%d", &ch); // Reuse 'ch' to take element input
                insert(ch); // Insert element into array
                break;
            case 2:
                delete_element(); // Delete last element
                break;
            case 3:
                printf("enter element:");
                scanf("%d", &ch); // Reuse 'ch' to take search input
                search(ch); // Search for element
                break;
            case 4:
                display(); // Display array contents
                break;
            case 5:
                sort(); // Sort the array
                break;
            default:
                printf("wrong choice\n"); // Invalid menu choice
        }
    }
}

// Main function
int main()
{
    processArray(); // Start menu-driven operations
    return 0;
}

