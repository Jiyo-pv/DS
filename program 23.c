/*
read and add  2 sparse matrices
@JIYO P V   01 OCTOBER 2025  ROLL NO:33
*/


#include<stdio.h>
void read_matrix(int mat[][5],int r,int c)
{
	//function to read matrix
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
}
int sparse(int a[][5],int s[][3],int m,int n)
{
	//count used to store  no of non zero values	
	int count=0,i,j;	
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
	return count;
}
void add(int a[][3],int b[][3],int m,int n)
{
	int c[m+n][3];	
	int i=1,j=1,k=1;
	while(i<=m && j<=n)
	{
		if(a[i][0]==b[j][0] && a[i][1]==b[j][1])
		{	
			//we have values at same positions 
			c[k][0]=a[i][0];	
			c[k][1]=a[i][1];
			c[k][2]=a[i][2]+b[j][2];
			i++;
			j++;
			k++;
		}
		else if(a[i][0]==b[j][0])
		{			
			if(a[i][1]<b[j][1])
			{  
			     //next element is from a
				c[k][0]=a[i][0];
				c[k][1]=a[i][1];
				c[k][2]=a[i][2];
				i++;
				k++;
			}
			else
			{	//next element is from b
				c[k][0]=b[j][0];
				c[k][1]=b[j][1];
				c[k][2]=b[j][2];
				j++;
				k++;
			}
		}
		else if(a[i][0]<b[i][0])
		{		
			//next element is from a
			c[k][0]=a[i][0];
			c[k][1]=a[i][1];
			c[k][2]=a[i][2];
			i++;
			k++;
		}
		else
		{
			//next element is from b
			c[k][0]=b[j][0];
			c[k][1]=b[j][1];
			c[k][2]=b[j][2];
			j++;
			k++;					
		}
	}
	while(i<=m)	//if we  reached end of b before a
	{
			c[k][0]=a[i][0];
			c[k][1]=a[i][1];
			c[k][2]=a[i][2];
			i++;
			k++;
	}
	while(j<=n)		//if we  reached end of a before b
	{
		c[k][0]=b[j][0];
		c[k][1]=b[j][1];
		c[k][2]=b[j][2];
		j++;
		k++;	
	}
	//set first row of triplet 
	c[0][0]=a[0][0];
	c[0][1]=a[0][1];
	c[0][2]=k-1;	//store no of non zero values
	printf("SPARSE ADDITION\n");
	//display the resultant triplet form
	for(i=0;i<k;i++)
	{	
		for(j=0;j<3;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}	
}
int main()
{
	//one matrix to read input and one to represent the sparse in triplet form
	int a[5][5],b[5][5],s1[10][3],s2[10][3];	
	int m,n,count1,count2;    //no of rows,cols and non zero values
	int i,j;	//iteration variables
	//matrix should have same order to perform addition 
	printf("enter no of rows and columns:");
	scanf("%d%d",&m,&n);
	printf("enter 1st matrix\n");
	//input a matrix that is sparse
	read_matrix(a,m,n);
	//convert matrix to sparse and return no of  non zeroes to a variable
	count1=sparse(a,s1,m,n);
	//input second matrix	
	printf("enter 2nd matrix\n");
	read_matrix(b,m,n);
	count2=sparse(b,s2,m,n);
	//add two sparse matrix triplet forms
	add(s1,s2,count1,count2);	
	return 0;
}
