/*
read dates using struct and compare
@JIYO P V Roll no:33
19/09/2025
*/
#include<stdio.h>
#include<malloc.h>
typedef struct date
{
	int dd;
	int mm;
	int yyyy;
}	date;
date *read_date()
{
	date *d;
	d=(date *) malloc(sizeof(date));
	printf("enter day(dd):");
	scanf("%d",&d->dd);
	printf("enter month(mm):");
	scanf("%d",&d->mm);
	printf("enter year(yyyy):");
	scanf("%d",&d->yyyy);
	return d;
}
void display(date *d)
{
	printf("date:%02d/%02d/%04d\n",d->dd,d->mm,d->yyyy);
}
void compare(date *d1,date *d2)
{
	if(d1->dd!=d2->dd||d1->mm!=d2->mm||d1->yyyy!=d2->yyyy)
	{
		printf("dates are not equal");
		return;
	}
	printf("you have entered equal dates ");
}
int main()
{
	date *d1;
	date *d2;
	d1=read_date();
	display(d1);
	d2=read_date();
	display(d2);
	compare(d1,d2);
	free(d1);
	free(d2);
}
