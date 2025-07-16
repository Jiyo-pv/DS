#include<stdio.h>
int main()
{
	int i,j,a[10],n;
	int track[10]={0};
	printf("no of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(track[j]!=-1)
			{
				track[i]++;
				track[j]=-1;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		if(track[i]!=-1)
		{
			printf("%d has %d occurances\n",a[i],track[i]);
		}
	}	
	return 0;
}
