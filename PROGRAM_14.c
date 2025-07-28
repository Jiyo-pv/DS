// Program to reverse a string in place @JIYO P V
//24 July 2025
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];     // Declare a character array to hold the string
    int i, len;        // Variables for loop index and string length
    char temp;         // Temporary variable for swapping characters
    
    printf("Enter a string: ");
    scanf("%s", str);  // Read a single word  from user
    
    len = strlen(str); // Calculate the length of the string
    
    // Reverse the string in the same array (in-place)
    for (i = 0; i < len / 2; i++) {
        temp = str[i];                        // Store character from the start
        str[i] = str[len - 1 - i];            // Move character from end to start
        str[len - 1 - i] = temp;              // Place stored character at the end
    }
    
    // Print the reversed string
    printf("Reversed string: %s\n", str);
    
    return 0;
}

