// array elements in reverse using recursion @JIYO P V
//24 July 2025
#include<stdio.h>

// Recursive function to display array elements in reverse
void display(int a[], int n)
{
	if(n == 0) // Base case: when index reaches 0
	{
		printf("%d\t", a[n]); // Print the first element
		return;
	}

	printf("%d\t", a[n]);     // Print current element
	display(a, n - 1);        // Recursive call with previous index
}

int main()
{
	int a[20], n, i;

	printf("enter n:");	
	scanf("%d", &n); // Read number of elements

	// Input array elements
	printf("enter array:");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("array in reverse:");
	display(a, n - 1); // Start recursion from the last element

	return 0;
}

