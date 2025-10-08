/*  
    read a polynomial and display
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

// Main function
int main()
{
	int a[10], deg;  // Array to store coefficients and variable for degree
	printf("enter degree of polynomial:");  // Ask user for degree of polynomial
	scanf("%d", &deg);  // Read degree from user
	read(a, deg);      // Call read function to input coefficients
	display(a, deg);   // Call display function to print polynomial
	return 0;  // End of program
}

