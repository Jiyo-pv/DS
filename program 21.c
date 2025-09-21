/*
a letter means push and an asterisk means pop program
@JIYO P V  17 SEPTEMBER 2025 ROLL NO:33
*/

#include<stdio.h>
char stack[100];		//stack to store pushed values
int top=-1;

//stack  functions
void push(char a)
{
	stack[++top]=a;
}
void pop()
{
	printf("%c",stack[top--]);
}
//function to perform push pop sequence
void processSequence(char *a)
{
	int i=0;
	printf("processed sequence:");
	while(a[i])
	{
		if(a[i]=='*')	//pop on asterisk
			pop();
		else		//push on letter
			push(a[i]);
		i++;
	}
}
int main()
{
	char a[50];
	printf("enter the sequence:"); //read sequence
	scanf("%s",a);
	processSequence(a);		//initiate push-pop sequence
	return 0;
	
}
