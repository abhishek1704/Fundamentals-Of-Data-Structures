
#include <stdio.h>
#include <stdlib.h>

void input_sets(int n,int A[]);
void display_sets(int n,int A[]);
int union_of_sets(int n,int m,int A[],int B[],int Un[]);
int intersection(int n,int m,int A[],int B[],int intr[]);
int difference(int n,int m,int A[],int B[],int D1[]);
int symm_diff(int n,int m,int A[],int B[],int C[]);

int main(void) {
	int A[50],B[50],Un[100],intr[50],D1[50],D2[50],Sm[50],i,j,m,n;
	int count,p,ch,k,flag,sizu,sizi,sizd1,sizd2,sizsm;

	do
	{
		printf("\n-----:Main Menu:-----\n\n1.Input Sets\n2.Display Sets\n3.Union\n4.Intersection\n");
		printf("5.(A-B)\n6.(B-A)\n7.Symmetric Difference\n8.Exit\n\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);

		switch(ch){
		case 1:
		    printf("Enter the size of set A: ");
		    scanf("%d",&n);
		    printf("Enter the size of set B: ");
			scanf("%d",&m);
            input_sets(n,A);
			input_sets(m,B);
			count=1;
			break;

		case 2:
			if((count)==1){
			printf("\nA = { ");
			display_sets(n,A);
			printf("}\n");
			printf("B = { ");
			display_sets(m,B);
			printf("}\n");}
			else{printf("A ={ }\n\nB = { }\n");}
			break;

		case 3:
			if(count==1){
			printf("\nA = { ");
			display_sets(n,A);
			printf("}\n\n");
			printf("B = { ");
			display_sets(m,B);
			printf("}\n\n");
			sizu = union_of_sets(n,m,A,B,Un);
			printf("Union = { ");
		    for(i=0;i<sizu;i++)
	        printf("%d ",Un[i]);
		    printf("}\n\n");}

			else{printf("A = { }\n\nB = { }\n\nUnion = { }\n");}
			break;

		case 4:
			if(count==1){
			printf("\nA = { ");
			display_sets(n,A);
			printf("}\n\n");
			printf("B = { ");
			display_sets(m,B);
			printf("}\n\n");
			sizi = intersection(n,m,A,B,intr);
			printf("Intersection = { ");
		    for(i=0;i<sizi;i++)
		    printf("%d ",intr[i]);
		    printf("}\n\n");}
			else{printf("A = { }\n\nB = { }\n\nIntersection = { }\n");}
			break;

		case 5:
			if(count==1){
			printf("\nA = { ");
			display_sets(n,A);
			printf("}\n\n");
			printf("B = { ");
			display_sets(m,B);
			printf("}\n\n");
			sizd1 = difference(n,m,A,B,D1);
			printf("(A-B) = { ");
		    for(i=0;i<sizd1;i++)
		    printf("%d ",D1[i]);
		    printf("}\n\n");}
			else{printf("A = { }\n\nB = { }\n\n(A - B) = { }\n");}
			break;

		case 6:
			if(count==1){
			printf("\nA = { ");
			display_sets(n,A);
			printf("}\n\n");
			printf("B = { ");
			display_sets(m,B);
			printf("}\n\n");
			sizd2 = difference(m,n,B,A,D2);
			printf("(B-A) = { ");
		    for(i=0;i<sizd2;i++)
		    printf("%d ",D2[i]);
		    printf("}\n\n");}
			else{printf("A = { }\n\nB = { }\n\n(B - A) = { }\n");}
			break;

		case 7:
			if(count==1){
			printf("\nA = { ");
			display_sets(n,A);
			printf("}\n\n");
			printf("B = { ");
			display_sets(m,B);
			printf("}\n\n");
			sizsm = symm_diff(sizd1,sizd2,D1,D2,Sm);
			printf("Sym_diff = { ");
		    for(i=0;i<sizsm;i++)
		    printf("%d ",Sm[i]);
		    printf("}\n\n");}
			else{printf("A = { }\n\nB = { }\n\nSymm_diff = { }\n");}
			break;
		}
		if(ch==8)
			break;
		printf("Press 1 key to continue...(0 :Exit)\n");
        scanf("%d",&p);
		if(p==0)
		break;


	}while(p==1);
	return EXIT_SUCCESS;
}

void input_sets(int n,int A[])
{
    int i;
    printf("Enter the elements: ");
    for(i=0;i<n;i++)	
    {   
        scanf("%d",&A[i]);
        if(A[i]>100)
        {
            printf("Enter the element again: ");i--;
        }
        else if(i>0){        
        if(A[i]==A[i-1])
        {
            printf("Enter the element again: ");
         i--;}}
    }
}

void display_sets(int n,int A[])
{
    int i;
    for(i=0;i<n;i++)
    {	
        printf("%d ",A[i]);
    }

}

int union_of_sets(int n,int m,int A[],int B[],int Un[])
{
	int i,j,k,flag;	
   	k=0;
	for(i=0;i<n;i++)
	{
		Un[k]=A[i];
		k++;
	}
	for(j=0;j<m;j++)
	{
		flag=0;
		for(i=0;i<n;i++)
		{
			if(B[j]==Un[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			Un[k] = B[j];
			k++;
		}

	}
	return k;	
}

int intersection(int n,int m,int A[],int B[],int intr[])
{
	int i,j,k;	
    k=0;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(A[i]==B[j])
			{
				intr[k]=A[i];k++;
		    }
		}
	}
	return k;

}

int difference(int n,int m,int A[],int B[],int D1[])
{
	 int i,j,flag,k;
	 k=0;
	 for(i=0;i<n;i++)
	 {
		flag=0;
		for(j=0;j<m;j++)
		{
			if(A[i]==B[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			D1[k] = A[i];
			k++;
		}
	}
	return k;
}

int symm_diff(int n,int m,int A[],int B[],int C[])
{
    int size;
    
    size = union_of_sets(n,m,A,B,C);
    
    return size;
}

