// matrix addition and subtraction @JIYO P V
//24 July 2025
#include<stdio.h>

// Function to read a matrix from user
void read(int a[][10], int m, int n)
{
	int i, j;
	printf("Enter matrix elements:\n");
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);  // Read each element
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
			printf("%d\t", a[i][j]);  // Print each element with tab spacing
		}
		printf("\n");  // Newline after each row
	}
}

// Function to calculate and display the sum of two matrices
void sum(int a[][10], int b[][10], int m, int n)
{
	int i, j;
	printf("Sum of matrices:\n");
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d\t", a[i][j] + b[i][j]);  // Element-wise addition
		}
		printf("\n");
	}
}

// Function to calculate and display the difference of two matrices
void diff(int a[][10], int b[][10], int m, int n)
{
	int i, j;
	printf("Difference of matrices:\n");
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d\t", a[i][j] - b[i][j]);  // Element-wise subtraction
		}
		printf("\n");
	}
}

int main()
{
	int a[10][10], b[10][10], m, n;

	// Input number of rows and columns
	printf("Enter number of rows and columns: ");
	scanf("%d %d", &m, &n);

	// Read and display first matrix
	printf("First matrix:\n");
	read(a, m, n);
	show(a, m, n);

	// Read and display second matrix
	printf("Second matrix:\n");
	read(b, m, n);
	show(b, m, n);

	// Perform and display sum and difference
	sum(a, b, m, n);
	diff(a, b, m, n);

	return 0;
}

