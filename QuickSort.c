
#include <stdio.h>
#include <stdlib.h>

struct user
{
	char name[30];
	long int mobileNo;
	int billAmount;
};

int main(void) {

	int i,ch,key,n,p,m;
	char roll[10],name[20];
	struct user s[20];
	do
	{
		printf("\n----Main Menu----\n\n1.Create record\n2.Display record\n3.Sort record\n4.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("Enter the number records you want to add: ");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				add(&s[i]);
			}
			break;

		case 2:
			preDisplay();
			for(i=0;i<n;i++)
				display(&s[i],i+1);
			break;

		case 3:
			printf("The array is : ");
			for(i=0;i<n;i++)
				printf("%s ",s[i].name);
			printf("\n");
			p=quickSort(s,0,n-1,n);
			printf("\nRecord after sorting: \n\n");
			preDisplay();
			for(i=0;i<n;i++)
				display(&s[i],i+1);					
			break;
		
		case 4:
			break;
			
		default:
			printf("You have entered a wrong choice !!");
			break;
		}
		
	}while(ch!=4);

	return EXIT_SUCCESS;
}

void add(struct user *user)
{
	int i,s=0;
	printf("\nEnter the name of user: ");
	scanf("\n");
	gets(user->name);
	printf("\nEnter the mobile number:");
	scanf("%ld",&user->mobileNo);
	printf("\nEnter the bill amount:");
	scanf("%d",&user->billAmount);
}

void display(struct user *user ,int i)
{

	printf(" %d\t  %s  \t%ld\t   %d\n",i,user->name,user->mobileNo,user->billAmount);

}

void preDisplay()
{

	printf("\n______________________________________________\n");
	printf("\n|Sr No.|   Name   |  Mobile No.  | Bill Amnt |\n");
	printf("______________________________________________\n\n");
}

void swap(struct user *s1,struct user *s2)
{
	struct user temp;
	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void quickSort(struct user s[],int low,int high,int N)
{
	static int p=1;
	int index;	
	if(low<high)
	{
		index = partition(s,low,high);
		printf("\n_______________________\n");
		printf("\nPass %d \n",p++);
		showsort(s,index,N);
		quickSort(s,low,index-1,N);
		quickSort(s,index+1,high,N);
	}
	
	return p;
}	

int partition(struct user s[],int start,int end)
{
	int i,j,pivot;
	
	pivot = start;
	i = start;
	j = end+1;
	
	do
	{
		do
		{
			i++;
		}while((strcmp(s[i].name,s[pivot].name))<0 && i<=end);
		
		do
		{
			j--;
		}while((strcmp(s[j].name,s[pivot].name))>0);
		
		if(i<j)
		{
			swap(&s[i],&s[j]);
		}
		
	}while(i<j);
	
	swap(&s[pivot],&s[j]);
	return j;
}

void showsort(struct user s[],int index,int N)
{
	int i;
	printf("\nPivot       : %3s\n",s[index].name);
	printf("Left part   : ");
	for(i=0;i<index;i++)
	{
		printf("%3s ",s[i].name);
	}
	if(i==0)
		printf("NIL\n");
	printf("\n");
	printf("Right  part : ");
	for(i=index+1;i<N;i++)
	{
		printf("%3s ",s[i].name);
	}
	if(i==index+1)
		printf("NIL\n");
	printf("\n");
}

