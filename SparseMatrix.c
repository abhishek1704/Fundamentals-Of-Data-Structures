
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int row;
	int col;
	int value;

}sparse;

int main(void) {

	int i,j,ch,a[10][10],b[10][10],row1,col1,row2,col2,c1,c2,c3;
	sparse s1[20],s2[20],result[20];

	do
	{
		printf("\n\n--Main Menu--\n\n1. Input matrix\n2. Display matrix\n3. Simple transpose\n4. Fast Transpose\n5. Addtion\n6. Exit");
		printf("\n\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("Enter the number of rows and columns in matrix:");
			scanf("%d%d",&row1,&col1);
			c1 = inputMatrix(a,row1,col1,s1);
			s1[0].row=row1;
			s1[0].col = col1;
			s1[0].value =c1-1;
			break;

		case 2:
			table();
			displayMatrix(s1,c1);
			break;

		case 3:
			simpleTranspose(s1,s2);
			printf("\nOriginal Matrix is:");
			table();
			displayMatrix(s1,c1);
			printf("\n\nTranspose matrix is:\n");
			table();
			displayMatrix(s2,c1);
			break;

		case 4:
			fastTranspose(s1,s2);
			printf("\nOriginal Matrix is:");
			table();
			displayMatrix(s1,c1);
			printf("\n\nTranspose matrix is:\n");
			table();
			displayMatrix(s2,c1);
			break;

		case 5:
		    printf("Enter the number of rows and columns in matrix 1:");
			scanf("%d%d",&row1,&col1);
			c1 = inputMatrix(a,row1,col1,s1);
			s1[0].row=row1;
			s1[0].col = col1;
			s1[0].value =c1-1;
			printf("Enter the number of rows and columns in matrix 2:");
			scanf("%d%d",&row2,&col2);
			c2 = inputMatrix(b,row2,col2,s2);
			s2[0].row=row2;
			s2[0].col = col2;
			s2[0].value =c2-1;
			c3 = addition(s1,s2,result);
			printf("\nMatrix 1 :\n\n");
			table();	
			displayMatrix(s1,c1);
			printf("\nMatrix 2 :\n\n");
			table();
			displayMatrix(s2,c2);
			printf("\nAddition :\n\n");
			table();
			displayMatrix(result,c3);
						
			break;

		case 6:
			break;

		default:
			printf("\nYou have entered a wrong choice !!");
			break;
		}

	}while(ch!=6);

	return EXIT_SUCCESS;
}

int inputMatrix(int a[10][10],int row,int col,sparse s[])
{
	int i,j,k,count=0;
	k=1;
	printf("\nEnter the elements of matrix:");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0)
			{
				s[k].row = i;
				s[k].col = j;
				s[k].value=a[i][j];
				k++;
			}
		}
	}

	return k;
}
void table()
{
	printf("\n__________________________\n");
	printf("\n|  Row  | Column | Value |\n");
	printf("__________________________\n");
}

void displayMatrix(sparse s[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("\n|   %d\t    %d\t    %d\t |",s[i].row,s[i].col,s[i].value);

	}
	printf("\n__________________________\n");
}

void simpleTranspose(sparse s1[],sparse s2[])
{
	int k,j,col;
	 s2[0].col=s1[0].row;
	 s2[0].row=s1[0].col;
	 s2[0].value=s1[0].value;

	k=1;
	for(col=0;col<s1[0].col;col++)
	{
		for(j=0;j<s1[0].value+1;j++)
		{
			if(s1[j].col==col)
			{
				s2[k].row = s1[j].col;
				s2[k].col = s1[j].row;
				s2[k].value = s1[j].value;
				k++;
			}
		}
	}
	 s2[0].col=s1[0].row;
	 s2[0].row=s1[0].col;
	 s2[0].value=s1[0].value;
}

void fastTranspose(sparse s1[],sparse s2[])
{
	int num_col,num_terms,i,j,row_terms[50],starting_pos[50];
	num_col = s1[0].col;
	num_terms = s1[0].value;
	s2[0].row = num_col;
	s2[0].col = s1[0].row;
	s2[0].value = num_terms;

	if(num_terms>0)
	{
		for(i=0;i<num_col;i++)
		{
			row_terms[i] = 0;
		}
		for(i=1;i<=num_terms;i++)
		{
			row_terms[s1[i].col]++;
		}
		starting_pos[0] = 1;
		for(i=1;i<num_col;i++)
		{
			starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
		}
		for(i=1;i<=num_terms;i++)
		{
			j = starting_pos[s1[i].col];
			s2[j].row = s1[i].col;
			s2[j].col = s1[i].row;
			s2[j].value = s1[i].value;
			starting_pos[s1[i].col]++;
		}
	}
}


int addition(sparse s1[],sparse s2[],sparse result[])
{

	int i=1,j=1,k=1;
	int t1,t2;
	t1 = s1[0].value;
	t2 = s2[0].value;
	
	result[0].row = s1[0].row;
	result[0].col = s1[0].col;
	
	while(i<=t1 && j<=t2)
	{
		if(s1[i].row<s2[j].row)
		{
			result[k].row = s1[i].row;
			result[k].col = s1[i].col;
			result[k].value = s1[i].value;
			i++;k++;
			goto last;
		}
			
		if(s1[i].row>s2[j].row)
		{
			result[k].row = s2[j].row;
			result[k].col = s2[j].col;
			result[k].value = s2[j].value;
			j++;k++;
			goto last;
		}
		
		if(s1[i].col<s2[j].col)
		{
			result[k].row = s1[i].row;
			result[k].col = s1[i].col;
			result[k].value = s1[i].value;
			i++;k++;
			goto last;
		}
		
		if(s1[i].col>s2[j].col)
		{
			result[k].row = s2[j].row;
			result[k].col = s2[j].col;
			result[k].value = s2[j].value;
			j++;k++;
			goto last;
		}	

			
		result[k].row = s1[i].row;
		result[k].col = s1[i].col;
		result[k].value = s1[i].value + s2[j].value;
		i++;j++;k++;
			
		last:printf("");
	}
	
	while(i<=t1)
	{
		result[k].row = s1[i].row;
		result[k].col = s1[i].col;
		result[k].value = s1[i].value;
		i++;k++;
	}
		
	while(j<=t2)
	{
		result[k].row = s2[j].row;
		result[k].col = s2[j].col;
		result[k].value = s2[j].value;
		j++;k++;
	}
	
	result[0].value = k-1;
	
	return k-1;
}

