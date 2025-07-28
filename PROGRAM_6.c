// display array elements with recursion @JIYO P V
//24 July 2025
#include<stdio.h>

// Recursive function to display array elements
void display(int a[], int n)
{
	if(n == 0) // Base case: first element
	{
		printf("%d\t", a[n]);
		return;
	}

	display(a, n - 1); // Recursive call to reach the first element
	printf("%d\t", a[n]); // Print after returning (in order)
}

int main()
{
	int a[20], n, i;

	printf("enter n:"); // Read number of elements
	scanf("%d", &n);
	printf("enter array:");
	// Input array elements
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	// Start recursion from the last index
	printf("array:");
	display(a, n - 1);

	return 0;
}

