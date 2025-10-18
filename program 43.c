/*  
    Implement varchar using realloc to handle any length
    @JIYO P V   15 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str;          // pointer to store dynamic string
    int size = 10;      // initial allocation size
    int len = 0;        // current length of string
    char ch;

    // allocate initial memory
    str = (char *)malloc(size * sizeof(char));
    if (str == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter a string (press Enter to finish): ");

    while (1)
    {
        ch = getchar(); // read one character

        if (ch == '\n') // stop on Enter
            break;

        str[len] = ch;
        len++;

        // check if we need more memory
        if (len >= size)
        {
            size *= 2; // double the size
            str = (char *)realloc(str, size * sizeof(char));
            if (str == NULL)
            {
                printf("Memory reallocation failed!\n");
                return 1;
            }
        }
    }

    str[len] = '\0'; // null terminate the string

    printf("You entered: %s\n", str);

    // free memory
    free(str);

    return 0;
}

