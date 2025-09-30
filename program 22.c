/*
read and display a sparse matrix
@JIYO P V   30 SEPTEMBER 2025  ROLL NO:33
*/


#include<stdio.h>
int main()
{
	//one matrix to read input and one to represent the sparse in triplet form
	int a[10][10],s[10][3];	
	int m,n,count;    //no of rows,cols and non zero values
	int i,j;	//iteration variables
	printf("enter no of rows and columns:");
	scanf("%d%d",&m,&n);
	printf("enter matrix\n");
	//input a matrix that is sparse
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	//count used to store  no of non zero values	
	count=0;	
	//loop through the matrix to find non zero values
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j])
			{
				//if non zero value then append to the triplet form 
				count++;
				s[count][0]=i;
				s[count][1]=j;
				s[count][2]=a[i][j];				
			}
		}
	}
	//first row of triplet form stores no of rows,columns and non zero values 
	s[0][0]=m;   
	s[0][1]=n;
	s[0][2]=count;
	
	//display the triplet representation
	printf("SPARSE REPRESENTATION\n");
	 for(i=0;i<=count;i++)
	{
		
		for(j=0;j<3;j++)
		{
			printf("%d\t",s[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
