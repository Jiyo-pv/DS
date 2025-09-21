/*  infix  to postfix conversion and then evaluation  @JIYO P V
  17 september 2025   Roll no:33    */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
//declare global array variables  for a stack and  postfix 
char stack[100], postfix[100];
int top = -1;	//top of stock
int valstack[100],vtop=-1;
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
void pushval(int a)
{
	valstack[++vtop]=a;
}
int popval()
{
	return valstack[vtop--];
}
//check precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
		 return 1;
    if (op == '*' || op == '/') 
		return 2;
    return 0;
}
//apply operation based on a sign
int apply(int a, int b, char sign) {
    switch (sign) {
        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
            return a / b;
    }
}

void evaluate()
{
	//evaluate postfix expression
	int i=0,a,b;
	char token;
	while(postfix[i])
	{
        token=postfix[i];
		if (isdigit(token))
		{
			pushval(token-'0');
		}
		else
		{
			b=popval();
			a=popval();
			pushval(apply(a,b,token));
		}
		i++;
	}
	printf("RESULT:%d",valstack[0]);
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
    printf("Postfix: %s\n", postfix);
    //now evaluate the postfix expression
    evaluate();
}



// Main function
int main() {
    char infix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);
    
    

    return 0;
}

