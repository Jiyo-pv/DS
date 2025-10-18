/*  
    Structure for Books with author_name and book_name
    Read and display n books using pointers
    @JIYO P V   12 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for book details
struct Book
{
    char author_name[50];
    char book_name[50];
};

// function declarations
void readBooks(struct Book *b, int n);
void displayBooks(struct Book *b, int n);

int main()
{
    int n, i;
    struct Book *books;   // pointer for array of books

    printf("Enter number of books: ");
    scanf("%d", &n);
    getchar(); // to clear newline after scanf

    // allocate memory for n books
    books = (struct Book *)malloc(n * sizeof(struct Book));

    if (books == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // read and display books using functions
    readBooks(books, n);
    displayBooks(books, n);

    // free memory
    free(books);

    return 0;
}

// function to read book details
void readBooks(struct Book *b, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of book %d\n", i + 1);

        printf("Book Name: ");
        fgets((b + i)->book_name, 50, stdin);
        (b + i)->book_name[strcspn((b + i)->book_name, "\n")] = '\0';

        printf("Author Name: ");
        fgets((b + i)->author_name, 50, stdin);
        (b + i)->author_name[strcspn((b + i)->author_name, "\n")] = '\0';
    }
}

// function to display book details
void displayBooks(struct Book *b, int n)
{
    int i;
    printf("\n--- Book Details ---\n");
    for (i = 0; i < n; i++)
    {
        printf("\nBook %d:\n", i + 1);
        printf("Book Name  : %s\n", (b + i)->book_name);
        printf("Author Name: %s\n", (b + i)->author_name);
    }
}

