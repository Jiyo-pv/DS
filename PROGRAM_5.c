// sort array in ascending order  @JIYO P V
//24 July 2025
#include<stdio.h>

// Global declarations
int a[100], n, i, j;

// Function to display the array
void display()
{
	printf("\narray:");
	for(i = 0; i < n; i++)
	{
		printf("\t%d", a[i]); // Print each element with a tab
	}
}

// Function to read array elements
void read()
{
	printf("enter n:"); // Read number of elements
	scanf("%d", &n);

	printf("enter array:"); // Read array elements
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
}

// Function to sort the array in ascending order
void sort()
{
	int temp;
	for(i = 0; i < n; i++) // Outer loop
	{
		for(j = 0; j < n; j++) // Inner loop compares every pair
		{
			if(a[i] < a[j]) // Swap if a[i] is smaller than a[j]
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("\nafter sort ");
	display(); // Display the sorted array
}

// Main function
int main()
{
	read();     // Input array
	display();  // Display before sorting
	sort();     // Perform sorting
	return 0;
}

