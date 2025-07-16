#include<stdio.h>
int a[5],pos=-1;
void insert(int n)
{
	if(pos==4)
	{
		printf("error:cannot insert\n");
		return ;
	}
	a[++pos]=n;
}
void delete_element()
{	
	if(pos==-1)
	{	
		printf("error:array empty\n");
		return;
	}
	printf("deleted %d\n",a[pos--]);
}
int menu()
{	
	int input;
	printf("1.insert \n 2.delete \n 3.search\n 4.display\n5.sort\n6.exit\n enter your choice:");
	scanf("%d",&input);
	return input;
}
void search(int n)
{
	int i,flag=-1;
	for(i=0;i<=pos;i++)
	{
		if(a[i]==n)
		{
			flag=i;
		}
	}
	if(flag)
	{
		printf("found at index %d\n",i++);
	}
	else
	{
		printf("search failed\n");
	}

}
void display()
{
	int i;
	for(i=0;i<=pos;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void sort()
{
	int i,j,temp;
	for(i=0;i<=pos;i++)
	{
		for(j=0;j<=pos;j++)
		{
			if(a[i]<a[j])
			{
				
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
		
			}
		}
	}
	display();
}
void processArray()
{
	int ch;
	for(ch=menu();ch!=6;ch=menu())
	{
		switch(ch)
		{
			case 1:
				printf("enter element:");
				scanf("%d",&ch);
				insert(ch);
				break;
			case 2:
				delete_element();
				break;
			case 3:
				printf("enter element:");
				scanf("%d",&ch);
				search(ch);
				break;
			case 4:
				display();
				break;
			case 5:
				sort();
				break;
				
			default:
				printf("wrong choice\n");
		}
	}
	
}
int main()
{
	processArray();	
	return 0;
}
