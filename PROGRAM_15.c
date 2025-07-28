// sort n strings in ascending order @JIYO P V
//24 July 2025
#include<stdio.h>
#include<string.h>

int main()
{
	
	// Array to store up to 20 strings of max length 19 (1 for null char)
    char strings[20][20], temp[20]; 
    int n, i, j;

    // Ask user to enter number of strings
    printf("enter n: ");
    scanf("%d", &n);

    // Input the strings
    printf("enter strings\n");
    for(i = 0; i < n; i++)
    {
    	 // Read string (no & needed since strings[i] is already a pointer)
        scanf("%s", strings[i]); 
	}

    // Sort strings in ascending order using bubble sort logic
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            // Compare strings: if strings[i] < strings[j], swap them
            if(strcmp(strings[i], strings[j]) < 0)
            {
                strcpy(temp, strings[i]);
                strcpy(strings[i], strings[j]);
                strcpy(strings[j], temp);		
            }		
        }		
    }

    // Print the sorted strings
    printf("after sort\n");
    for(i = 0; i < n; i++)
    {
        printf("\n%s", strings[i]); // No & needed
    }
    return 0;	
}

