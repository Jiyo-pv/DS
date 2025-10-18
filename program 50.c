/*  
    Linked List of Names with Insert, Delete, Display, Sort, Reverse, Count
    @JIYO P V   16 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for a node
typedef struct node {
    char name[50];
    struct node *next;
} node;

node *head = NULL; // head pointer

// function to insert a name at the end
void insertName(char *name) {
    node *newNode = (node *)malloc(sizeof(node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("%s inserted into the list\n", name);
}

// function to delete a name
void deleteName(char *name) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = head, *prev = NULL;

    // if head node holds the name
    if (strcmp(head->name, name) == 0) {
        head = head->next;
        free(temp);
        printf("%s deleted from the list\n", name);
        return;
    }

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%s not found in the list\n", name);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("%s deleted from the list\n", name);
}

// function to display all names
void displayList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node *temp = head;
    printf("Names in the list: ");
    while (temp != NULL) {
        printf("%s -> ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

// function to sort names alphabetically
void sortList() {
    if (head == NULL || head->next == NULL)
        return;

    node *i, *j;
    char temp[50];

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->name, j->name) > 0) {
                strcpy(temp, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp);
            }
        }
    }
    printf("List sorted alphabetically\n");
}

// function to reverse the linked list
void reverseList() {
    node *prev = NULL, *current = head, *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
    printf("List reversed\n");
}

// function to count number of names
void countList() {
    int count = 0;
    node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Number of names in the list: %d\n", count);
}

// function to display menu
int menu() {
    int choice;
    printf("\nLINKED LIST OF NAMES MENU\n");
    printf("1. Insert Name\n");
    printf("2. Delete Name\n");
    printf("3. Display List\n");
    printf("4. Sort List\n");
    printf("5. Reverse List\n");
    printf("6. Count Names\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // consume newline
    return choice;
}

// function to process menu
void process() {
    int choice;
    char name[50];

    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Enter name to insert: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove newline
                insertName(name);
                break;
            case 2:
                printf("Enter name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                deleteName(name);
                break;
            case 3:
                displayList();
                break;
            case 4:
                sortList();
                break;
            case 5:
                reverseList();
                break;
            case 6:
                countList();
                break;
            case 7:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}

// main function
int main() {
    process();
    return 0;
}

