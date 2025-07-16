#include<stdio.h>

int insert(int n,int a[],int pos)
{
	if(pos==4)
	{
		printf("error:cannot insert\n");
		return 4 ;
	}
	a[++pos]=n;
	return pos;
}
int delete_element(int a[],int pos)
{	
	if(pos==-1)
	{	
		printf("error:array empty\n");
		return -1;
	}
	printf("deleted %d\n",a[pos--]);
	return pos;
}
int menu()
{	
	int input;
	printf("1.insert \n 2.delete \n 3.search\n 4.display\n5.sort\n6.exit\n enter your choice:");
	scanf("%d",&input);
	return input;
}
void search(int n,int a[],int pos)
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
void display(int a[],int pos)
{
	int i;
	for(i=0;i<=pos;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void sort(int a[],int pos)
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
	display(a,pos);
}
void processArray()
{
	int a[10],pos=-1;
	int ch;
	for(ch=menu();ch!=6;ch=menu())
	{
		switch(ch)
		{
			case 1:
				printf("enter element:");
				scanf("%d",&ch);
				pos=insert(ch,a,pos);
				break;
			case 2:
				pos=delete_element(a,pos);
				break;
			case 3:
				printf("enter element:");
				scanf("%d",&ch);
				search(ch,a,pos);
				break;
			case 4:
				display(a,pos);
				break;
			case 5:
				sort(a,pos);
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
