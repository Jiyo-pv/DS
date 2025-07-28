// array operations using local variables  @JIYO P V
//24 July 2025
#include<stdio.h>

// Function to insert an element into the array
int insert(int n, int a[], int pos)
{
    if(pos == 4) // Limit the array to 5 elements (index 0 to 4)
    {
        printf("error:cannot insert\n");
        return 4;
    }
    a[++pos] = n; // Insert element at next position
    return pos;   // Return updated position
}

// Function to delete the last element from the array
int delete_element(int a[], int pos)
{	
    if(pos == -1) // Check if array is empty
    {	
        printf("error:array empty\n");
        return -1;
    }
    printf("deleted %d\n", a[pos--]); // Print and delete last element
    return pos; // Return new position
}

// Function to display menu and return user's choice
int menu()
{	
    int input;
    printf("1.insert \n2.delete \n3.search\n4.display\n5.sort\n6.exit\nenter your choice:");
    scanf("%d", &input);
    return input;
}

// Function to search for an element in the array
void search(int n, int a[], int pos)
{
    int i, flag = -1; // Initialize flag to -1 (not found)
    for(i = 0; i <= pos; i++) // Traverse the array
    {
        if(a[i] == n)
        {
            flag = i; // Store index if match is found
        }
    }
    if(flag != -1)
    {
        printf("found at index %d\n", flag); // Corrected to print correct index
    }
    else
    {
        printf("search failed\n"); // Element not found
    }
}

// Function to display all elements in the array
void display(int a[], int pos)
{
    int i;
    for(i = 0; i <= pos; i++) // Loop through array and print elements
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

// Function to sort the array in ascending order using bubble sort
void sort(int a[], int pos)
{
    int i, j, temp;
    for(i = 0; i <= pos; i++)
    {
        for(j = 0; j <= pos; j++)
        {
            if(a[i] < a[j]) // Swap if out of order
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    display(a, pos); // Show sorted array
}

// Function to manage user interaction and perform array operations
void processArray()
{
    int a[10], pos = -1; // Declare array and initialize position
    int ch;
    for(ch = menu(); ch != 6; ch = menu()) // Loop until user selects exit
    {
        switch(ch)
        {
            case 1:
                printf("enter element:");
                scanf("%d", &ch); // Using 'ch' to store element input
                pos = insert(ch, a, pos); // Insert element
                break;
            case 2:
                pos = delete_element(a, pos); // Delete last element
                break;
            case 3:
                printf("enter element:");
                scanf("%d", &ch); // Using 'ch' for element to search
                search(ch, a, pos); // Search for element
                break;
            case 4:
                display(a, pos); // Display all elements
                break;
            case 5:
                sort(a, pos); // Sort elements
                break;
            default:
                printf("wrong choice\n"); // Handle invalid menu input
        }
    }
}

// Main function to start the program
int main()
{
    processArray(); // Begin array operation processing
    return 0;
}

