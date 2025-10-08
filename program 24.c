/*
read and multiply  2 sparse matrices
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
void multiply(int a[][3], int b[][3])
{
    int t[20][3], result[50][3];
    int i, j, k, p;
    int terms = b[0][2], cols = b[0][1];
    int rowsA = a[0][0], colsA = a[0][1], termsA = a[0][2];
    int rowsB = b[0][0], colsB = b[0][1];
    int count = 0;

    if (colsA != rowsB)
    {
        printf("Matrix multiplication not possible!\n");
        return;
    }

    // Step 1: Transpose of B
    k = 1;
    for (i = 0; i < cols; i++)
    {
        for (j = 1; j <= terms; j++)
        {
            if (b[j][1] == i)
            {
                t[k][0] = b[j][1]; // row <- col
                t[k][1] = b[j][0]; // col <- row
                t[k][2] = b[j][2];
                k++;
            }
        }
    }
    t[0][0] = cols;
    t[0][1] = rowsB;
    t[0][2] = terms;


    // Step 2: Multiply A and B using triplets
    for (i = 0; i < rowsA; i++)   // for each row of A
    {
        for (j = 0; j < colsB; j++)  // for each column of B
        {
            int sum = 0;
            // dot product of row i of A and column j of B
            for (k = 1; k <= termsA; k++)
            {
                if (a[k][0] == i) // row matches
                {
                    for (p = 1; p <= terms; p++)
                    {
                        if (t[p][0] == j && a[k][1] == t[p][1])
                        {
                            sum += a[k][2] * t[p][2];
                        }
                    }
                }
            }
            if (sum != 0)
            {
                count++;
                result[count][0] = i;
                result[count][1] = j;
                result[count][2] = sum;
            }
        }
    }
    result[0][0] = rowsA;
    result[0][1] = colsB;
    result[0][2] = count;
    // Step 3: Print Result
    printf("\nResultant Matrix (Triplet form):\n");
    for (i = 0; i <= count; i++)
    {
        printf("%d\t%d\t%d\n", result[i][0], result[i][1], result[i][2]);
    }
}
int main()
{
	//one matrix to read input and one to represent the sparse in triplet form
	int a[5][5],b[5][5],s1[10][3],s2[10][3];	
	int m,n,p,q,count1,count2;    //no of rows,cols and non zero values
	int i,j;	//iteration variables
	//matrix should have same order to perform multiplication
	printf("enter no of rows and columns:");
	scanf("%d%d",&m,&n);
	printf("enter 1st matrix\n");
	//input a matrix that is sparse
	read_matrix(a,m,n);
	//convert matrix to sparse and return no of  non zeroes to a variable
	count1=sparse(a,s1,m,n);
	//input second matrix	
	printf("enter no of  rows and cols of 2nd matrix :");
	scanf("%d%d",&p,&q);
	printf("enter 2nd matrix\n");
	read_matrix(b,p,q);
	count2=sparse(b,s2,p,q);
	//multiply two sparse matrix triplet forms
	multiply(s1,s2);	
	return 0;
}
