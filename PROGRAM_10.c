// Transpose of a matrix  @JIYO P V
//24 July 2025
#include<stdio.h>

// Function to read a matrix from the user
void read(int a[][10], int m, int n)
{
	int i, j;
	printf("Enter matrix elements:\n");
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);  // Read each matrix element from user input
		}
	}
}

// Function to display a matrix
void show(int a[][10], int m, int n)
{	
	int i, j;
	printf("Matrix:\n");
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d\t", a[i][j]);  // Print each element followed by a tab
		}
		printf("\n");  // Move to the next line after each row
	}
}

// Function to display the transpose of a matrix
void transpose(int a[][10], int m, int n)
{	
	int i, j;
	printf("Transpose of matrix:\n");
	for(i = 0; i < n; i++)  // Loop through columns
	{
		for(j = 0; j < m; j++)  // Loop through rows
		{
			printf("%d\t", a[j][i]);  // Print the transposed element
		}
		printf("\n");  // Move to the next line after each transposed row
	}
}

int main()
{
	int a[10][10], m, n;

	// Prompt user to enter matrix dimensions and elements
	printf("Enter matrix:\n");
	printf("Enter number of rows and columns: ");
	scanf("%d %d", &m, &n);

	read(a, m, n);      // Read matrix from user
	show(a, m, n);      // Display the original matrix
	transpose(a, m, n); // Display the transpose of the matrix

	return 0;
}

