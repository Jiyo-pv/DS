//reverse string using stack  @JIYO P V
//24 July 2025

#include<stdio.h>

// Declare a character stack of size 10
char stack[10];
// Initialize top of stack to -1 indicating empty stack
int top = -1;

// Function to push a character onto the stack
void push(char ch)
{
	stack[++top] = ch; // Increment top and assign character to stack
}

// Function to pop a character from the stack
char pop()
{
	if(top != -1) // Check if stack is not empty
	{
		return stack[top--]; // Return top character and decrement top
	}
}

int main()
{
	int i;
	char string[20]; // Declare a character array to store input string

	// Prompt user to enter a string
	printf("enter a string:");
	scanf("%s", &string); // Read input string

	// Push each character of the string onto the stack
	for(i = 0; string[i] != '\0'; i++)
	{
		push(string[i]);
	}

	// Print the reversed string by popping characters from the stack
	printf("string  in reverse:");
	while(top != -1)
	{
		printf("%c", pop()); // Pop and print characters
	}

	return 0; // Indicate successful completion
}

