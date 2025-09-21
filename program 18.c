/*  infix  to prefix conversion  @JIYO P V
  17 September 2025   Roll no:33    */
  
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//
char stack[100], postfix[100], prefix[100];
int top = -1;

//stack operations
void push(char c) { 
    stack[++top] = c; 
}
char pop() { 
    return stack[top--]; 
}
char peek() { 
    return stack[top]; 
}

//check precedence of operator
int precedence(char op) {
    if (op == '+' || op == '-')
         return 1;
    if (op == '*' || op == '/') 
        return 2;
    return 0;
}
//function to reverse a string
void reverse(char str[]) {
    int i;
    int len = strlen(str);
    //swap first elements with last elements till middle
    for (i = 0; i < len / 2; i++) {
        char t = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = t;
    }
}

// Infix to Postfix conversion
void infixToPostfix(char infix[]) {
    int i, j = 0;
    top = -1;

    for (i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (isdigit(ch)) {
            postfix[j++] = ch;		//if digit add to postfix
        } else if (ch == '(') {
            push(ch);		//push to stack
        } else if (ch == ')') {
            while (peek() != '(') // remove all operators till ( is found
                postfix[j++] = pop();
            pop(); // Remove '('
        } else {
            while (top != -1 && precedence(peek()) > precedence(ch))
                postfix[j++] = pop(); 
            push(ch);
        }
    }
    while (top != -1) 
        postfix[j++] = pop();
    postfix[j] = '\0';
}

// Infix to Prefix conversion
void infixToPrefix(char infix[]) {
    int i;
    char rev[100];
    strcpy(rev, infix);
    reverse(rev);
	
	//reverse brackets as the expression is now reversed
    for (i = 0; rev[i]; i++) {
        if (rev[i] == '(') 
			rev[i] = ')';
        else if (rev[i] == ')') 
			rev[i] = '(';
    }

    infixToPostfix(rev);   // converted into postfix
    reverse(postfix);      // reverse postfix
    strcpy(prefix, postfix); //store postfix to prefix
}

// Main function
int main() {
    char infix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix);
    printf("Prefix: %s\n", prefix);

    return 0;
}

