/*  
    multiply 2 polynomials
    @JIYO P V   03 OCTOBER 2025   Roll no:33    
*/

#include<stdio.h> 

// Function to read coefficients of the polynomial
void read(int a[], int deg)
{
	int i;
	// Loop from 0 to deg to input coefficients for each power of x
	for(i = 0; i <= deg; i++)
	{
		printf("enter coefficient of x^%d:", i);  // Ask user to enter coefficient of x^i
		scanf("%d", &a[i]);  // Store the entered coefficient in array a[]
	}
}

// Function to display the polynomial
void display(int a[], int deg)
{
	int i;
	printf("\nPOLYNOMIAL:");  
	// Loop from highest degree to 0 to display polynomial in decreasing powers
	for(i = deg; i >= 0; i--)
	{
		if(a[i])		//skip zeroes
		{
			if(i == deg)  // For the first term (highest power), print without leading '+'
			{
				printf("%dx^%d", a[i], i);
			}
			else if(i == 0)  // For the constant term (x^0), just print '+coefficient'
			{
				printf("+%d", a[i]);
			}
			else  // For all intermediate terms, print with '+coefficient*x^power'
			{
				printf("+%dx^%d", a[i], i);
			}
		}
	}
}

// Function to multiply two polynomials
void multiply(int a[], int b[], int deg1, int deg2)
{
    int i, j;                 // Loop counters
    int size = deg1 + deg2;   // Degree of the resulting product polynomial
    int c[20] = {0};          // Array to store coefficients of the product, initialized to 0

    // Multiply each term of the first polynomial with each term of the second
    for(i = 0; i <= deg1; i++) {
        for(j = 0; j <= deg2; j++) {
            c[i + j] += a[i] * b[j];  // Coefficient of x^(i+j) in the product
        }
    }

    // Display the resulting polynomial
    printf("\nPRODUCT OF POLYNOMIALS");  
    display(c, size);  // Call the display function to print the product
}
// Main function
int main()
{
	int a[10], b[10], deg1, deg2;  // Arrays to store coefficients and variables for degree
	
	printf("enter degree of first polynomial:"); 
	scanf("%d", &deg1);  // Read degree from user
	read(a, deg1);      // Call read function to input coefficients of first polynomial
	display(a, deg1);   // Call display function to print first polynomial
	
	printf("\nenter degree of 2nd polynomial:");  
	scanf("%d", &deg2);  // Read degree from user
	read(b, deg2);      // Call read function to input coefficients of second polynomial
	display(b, deg2);   // Display second polynomial
	
	multiply(a, b, deg1, deg2);  // Call multiply function to calculate product
	
	return 0;  
}

