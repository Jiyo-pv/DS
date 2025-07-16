#include<stdio.h>
int x=5,c=100;   //global variable c

void show_Globals()
{
	printf("global variables\nc=%d\nx=%d",c,x);	//using global variable c
}
void disp()
{
	static int i=1;		//static variables
	printf("%d",i++);
}
int main()
{		register int i;		//register variables
		int a,b;	//local variables a and b
		a=10;
		b=5;
		printf("local variables\n a=%d b=%d \n",a,b);
		show_Globals();
		printf("\nstatic variables\n");
		disp();
		disp();
		disp();
		for(i=1;i<5;i++)
		{
			printf("\nregister i=%d\n",i);
		}
		return 0;
	
}
