/*  
    Binary Search Tree (BST) with Names
    Insertion and In-Order Traversal (Ascending Order)
    @JIYO P V   16 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50  // maximum length of a name

// BST node structure
typedef struct node {
    char name[MAX];
    struct node *left;
    struct node *right;
} node;

// create a new node
node* createNode(char value[]) {
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->name, value);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// insert into BST
node* insert(node* root, char value[]) {
    if (root == NULL)
        return createNode(value);

    int cmp = strcmp(value, root->name);

    if (cmp < 0)
        root->left = insert(root->left, value);
    else if (cmp > 0)
        root->right = insert(root->right, value);
    // duplicate names ignored

    return root;
}

// inorder traversal to display names in ascending order
void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s\n", root->name);
        inorder(root->right);
    }
}

// menu
int menu() {
    int choice;
    printf("\nBINARY SEARCH TREE MENU (Names)\n");
    printf("1. Insert Name\n");
    printf("2. Display Names in Ascending Order (Inorder)\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// process menu
void process() {
    node* root = NULL;
    int choice;
    char name[MAX];

    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Enter name to insert: ");
                scanf("%s", name); // no spaces
                root = insert(root, name);
                break;
            case 2:
                printf("Names in ascending order:\n");
                inorder(root);
                break;
            case 3:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}

// main
int main() {
    process();
    return 0;
}

