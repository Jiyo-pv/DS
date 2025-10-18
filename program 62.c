/*  
    Binary Search Tree (BST) Insertion and Pre-Order Traversal (Non-Recursive)
    @JIYO P V   16 OCTOBER 2025   Roll no:33    
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // maximum stack size

// structure for BST node
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// create a new BST node
node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// insert into BST
node* insert(node* root, int value) {
    if (root == NULL)
        return createNode(value);

    node *current = root, *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->data)
            current = current->left;
        else if (value > current->data)
            current = current->right;
        else
            return root; // duplicate, do nothing
    }

    if (value < parent->data)
        parent->left = createNode(value);
    else
        parent->right = createNode(value);

    return root;
}

// stack for non-recursive traversal
typedef struct {
    node* data[MAX];
    int top;
} Stack;

void initStack(Stack* s) { s->top = -1; }
int isEmpty(Stack* s) { return s->top == -1; }
void push(Stack* s, node* n) { s->data[++s->top] = n; }
node* pop(Stack* s) { return s->data[s->top--]; }

// pre-order traversal without recursion
void preorderNonRecursive(node* root) {
    if (root == NULL) return;

    Stack s;
    initStack(&s);
    push(&s, root);

    while (!isEmpty(&s)) {
        node* current = pop(&s);
        printf("%d ", current->data);

        // push right first, then left so left is processed first
        if (current->right != NULL) push(&s, current->right);
        if (current->left != NULL) push(&s, current->left);
    }
}

// menu
int menu() {
    int choice;
    printf("\nBINARY SEARCH TREE MENU\n");
    printf("1. Insert\n");
    printf("2. Pre-Order Traversal (Non-Recursive)\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// process menu
void process() {
    node* root = NULL;
    int choice, value;

    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Pre-Order Traversal: ");
                preorderNonRecursive(root);
                printf("\n");
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

