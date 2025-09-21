/*  infix  to postfix conversion  @JIYO P V
  17 september 2025   Roll no:33    */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
//declare global array variables  for a stack and  postfix 
char stack[100], postfix[100];
int top = -1;	//top of stock

//stack functions
void push(char c) { 
		stack[++top] = c;
	 }
char pop() {
	 	return stack[top--]; 
	 }
char peek(){
	 	return stack[top]; 
	 }

//check precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
		 return 1;
    if (op == '*' || op == '/') 
		return 2;
    return 0;
}

// Infix to Postfix conversion
void infixToPostfix(char infix[]) {
    int i, j = 0;
    top = -1;

    for (i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (isdigit(ch)) {   //if number add to postfix
            postfix[j++] = ch;
        } else if (ch == '(') { //if '(' add to postfix
            push(ch);
        } else if (ch == ')') {
            while (peek() != '(') 
				postfix[j++] = pop();	
            pop(); // Remove '('
        } else {
        	//to add operator remove operators with higher or equal precednce and then add
            while (top != -1 && precedence(peek()) >= precedence(ch))   
                postfix[j++] = pop();
            push(ch);
        }
    }
    while (top != -1) postfix[j++] = pop(); //add remaining operators in stack
    postfix[j] = '\0'; 	//add an null character at the end of postfix array
}



// Main function
int main() {
    char infix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);
    printf("Postfix: %s\n", postfix);
    

    return 0;
}

