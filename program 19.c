/*  infix evaluation   @JIYO P V
    17 September 2025   Roll no:33  */

#include <stdio.h>
#include <ctype.h>
int precedence(char op) {
    switch (op) {
        case '/':
        case '*':
            return 1;
        case '+':
        case '-':
            return 0;
    }        
}
//perform operation based on given operator
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

int infix_evaluate(char a[100]) {
	//use one stack for operator and other for values
    int i = 0, vstack[100], vtop = -1, otop = -1;
    char opstack[100], token, sign;		 
    int v1, v2;
    while (a[i]) {
        token = a[i];
        if (isdigit(token)) {
            vstack[++vtop] = token - '0';	//'9'-'0' gives 9
        } else {
            while (otop > -1 && precedence(opstack[otop]) >= precedence(token)) {
                //pop 2 operands and pop operator and apply 
				v2 = vstack[vtop--];
                v1 = vstack[vtop--];
                sign = opstack[otop--];
                vstack[++vtop] = apply(v1, v2, sign);
                //result pushed to value stack
            }
            opstack[++otop] = token;
        }
        i++;
    }

    while (otop > -1) {
    	//pop 2 operands and pop operator and apply 
		//result pushed to value stack	
        v2 = vstack[vtop--];
        v1 = vstack[vtop--];
        sign = opstack[otop--];
        vstack[++vtop] = apply(v1, v2, sign);
    }
    return vstack[0];
}

int main() {
    char a[100];
    int result;

    printf("enter infix expression: ");
    scanf("%s", a);

    result = infix_evaluate(a);
    printf("RESULT: %d", result);

    return 0;
}

