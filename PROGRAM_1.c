// Program to demonstrate different storage classes in C
// @JIYO P V   24 July 2025

#include <stdio.h>

// Global variables (have external linkage by default)
int x = 5, c = 100;

// Function to display global variables
void show_Globals()
{
    // Accessing global variables c and x
    printf("global variables\nc=%d\nx=%d", c, x);
}

// Function to demonstrate static variable
void disp()
{
    static int i = 1;  // static variable retains its value between calls
    printf("%d", i++);
}

int main()
{
    // Register storage class for faster access (suggestion to compiler)
    register int i;

    // Local variables (automatic storage class by default)
    int a, b;
    a = 10;
    b = 5;

    // Displaying local variables
    printf("local variables\n a=%d b=%d \n", a, b);

    // Calling function to display global variables
    show_Globals();

    // Demonstrating static variable behavior
    printf("\nstatic variables\n");
    disp();  // Prints 1
    disp();  // Prints 2
    disp();  // Prints 3
	
    // Demonstrating register variable in loop
    for (i = 1; i < 5; i++)
    {
        printf("\nregister i=%d\n", i);
    }

    return 0;
}

