
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int mat1[10][10],mat2[10][10],mat3[10][10],mul[10][10],trans[10][10];
	int i,j,row1,row2,col1,col2,ch;

	do{
		printf("\n--- Main Menu ---\n\n1.Addition\n2.Multiplication\n3.Transpose\n4.Saddle Point\n5.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
		case 1:
			printf("Enter no. of rows in mat1: ");
			scanf("%d",&row1);
			printf("Enter no. of columns in mat1: ");
			scanf("%d",&col1);
			input(mat1,row1,col1);
			printf("Enter no. of rows in mat2: ");
			scanf("%d",&row2);
			printf("Enter no. of columns in mat2: ");
			scanf("%d",&col2);
			input(mat2,row2,col2);
			printf("Matrix 1 :\n");
			display(mat1,row1,col1);printf("\n");
			printf("Matrix 2 :\n");
			display(mat2,row2,col2);printf("\n");
			if(row1==row2 && col1==col2){
			printf("Addition :\n");
			addition(mat1,mat2,mat3,row1,col1);}
			else{printf("Addition is not possible...!!\n");}
			break;
		case 2:
			printf("Enter no. of rows in mat1: ");
			scanf("%d",&row1);
			printf("Enter no. of columns in mat1: ");
			scanf("%d",&col1);
			input(mat1,row1,col1);
			printf("Enter no. of rows in mat2: ");
			scanf("%d",&row2);
			printf("Enter no. of columns in mat2: ");
			scanf("%d",&col2);
			input(mat2,row2,col2);
			printf("Matrix 1 :\n");
			display(mat1,row1,col1);printf("\n");
			printf("Matrix 2 :\n");
			display(mat2,row2,col2);printf("\n");
			if(col1==row2){
			printf("Multiplication :\n");
			multiplication(mat1,mat2,mul,row1,col1,col2);
			display(mul,row1,col2);}
			else{printf("Multiplication is not possible...!!\n");}
			break;
		case 3:
			printf("Enter no. of rows in matrix: ");
			scanf("%d",&row1);
			printf("Enter no. of columns in matrix: ");
			scanf("%d",&col1);
			input(mat1,row1,col1);
			printf("Matrix :\n");
			display(mat1,row1,col1);printf("\n");
			printf("Transpose of matrix:\n");
			transpose(mat1,row1,col1,trans);
			display(trans,col1,row1);
			break;
		case 4:
			printf("Enter no. of rows in matrix: ");
			scanf("%d",&row1);
			printf("Enter no. of columns in matrix: ");
			scanf("%d",&col1);
			input(mat1,row1,col1);
			printf("Matrix :\n");
			display(mat1,row1,col1);printf("\n");
		    saddle_point(mat1,row1,col1);				
			break;
		}

	 }while(ch!=5);
	return EXIT_SUCCESS;
}

void input(int mat[10][10],int row,int col)
{
	int i,j;
	printf("Enter elements:");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}

}
void display(int mat[][10],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d  ",mat[i][j]);
		}
		printf("\n");
	}

}
void addition(int mat1[10][10],int mat2[10][10],int mat3[10][10],int row1,int col1)
{
	int i,j;

	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			mat3[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			printf("%d  ",mat3[i][j]);
		}
		printf("\n");
	}
}
void multiplication(int mat1[10][10],int mat2[10][10],int mul[10][10],int row1,int col1,int col2)
{
	int i,j,k;
	for(i=0;i<row1;i++)
	{
		for(k=0;k<col2;k++)
		{	mul[i][k] = 0;
			for(j=0;j<col1;j++)
			{
				mul[i][k] = mul[i][k] +(mat1[i][j]*mat2[j][k]);
			}
		}
	}
}
void transpose(int mat[10][10],int row,int col,int trans[10][10])
{   int i,j;
	for(i=0;i<col;i++)
	{
		for(j=0;j<row;j++)
		{
			trans[i][j] = mat[j][i];
		}
	}
}
void saddle_point(int mat[10][10],int row,int col)
{
	int i,j,k,min,max,column,flag=0;
	for(i=0;i<row;i++)
	{
		min=mat[i][0];
		for(j=0;j<col;j++)
		{
			if(min>=mat[i][j]){
				min=mat[i][j];
				column = j;}
		}
		max=mat[0][column];
		for(k=0;k<row;k++)
		{
			if(max<=mat[k][column])
			{
				max = mat[k][column];
			}
		}	
		if(max==min){
			flag=1;
			printf("Saddle point is : %d  at (%d , %d)",max,i,column);}			
	}
	if(flag==0)
			printf("Saddle point doesn't exist !!");

}Abhishek Vishwas 
