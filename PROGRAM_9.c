// Matrix multiplication  @JIYO P V
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
			scanf("%d", &a[i][j]);  // Read each element from user input
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
		printf("\n");  // Move to next line after each row
	}
}

// Function to perform matrix multiplication
void multiply(int a[][10], int b[][10], int m, int n, int p, int q)
{
	int i, j, k, res;
	if(n == p)  // Check if multiplication is valid (columns of A == rows of B)
	{	
		printf("Product of matrices:\n");
		for(i = 0; i < m; i++)
		{
			for(j = 0; j < q; j++)
			{
				res = 0;  // Initialize result for position (i,j)
				for(k = 0; k < n; k++)
				{
					res += a[i][k] * b[k][j];  // Sum of products for row i and column j
				}
				printf("%d\t", res);  // Print result for position (i,j)
			}
			printf("\n");  // Newline after each row of result
		}
	}
	else
	{
		printf("error: invalid operation");  // Print error if dimensions are not compatible
	}
}

int main()
{
	int a[10][10], b[10][10], m, n, p, q;

	// Read and display first matrix
	printf("First matrix:\n");
	
	// Input dimensions for first matrix
	printf("Enter number of rows and columns: ");
	scanf("%d %d", &m, &n);
	read(a, m, n);   // Read matrix A
	show(a, m, n);   // Display matrix A

	// Read and display second matrix
	printf("Second matrix:\n");
	
	// Input dimensions for second matrix
	printf("Enter number of rows and columns: ");
	scanf("%d %d", &p, &q);
	read(b, p, q);   // Read matrix B
	show(b, p, q);   // Display matrix B

	// Perform and display product of matrices
	multiply(a, b, m, n, p, q);

	return 0;
}

