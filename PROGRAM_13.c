// print string in reverse @JIYO P V
//24 July 2025
#include <stdio.h>
#include <string.h>
int main() 
{
    char str[100];  // array to store input string
    int len, i;     // variables for length and loop counter
    
    printf("Enter a string: ");
    scanf("%s", str);  // read a single word (no spaces) from user
    
    len = strlen(str); // get length of the string
    
    printf("Reversed string: ");
    // print characters in reverse order from the end to the beginning
    for (i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
    
    return 0;
}

