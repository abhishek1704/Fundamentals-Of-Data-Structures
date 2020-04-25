
#include <stdio.h>
#include <stdlib.h>

struct student
{
	char name[20];
	int rollNo;
	int marks[5];
	float per;

};

int main(void) {

	int i,ch,key,n,p,m;
	char roll[10],name[20];
	struct student s[20];
	do
	{
		printf("\n----Main Menu----\n\n1.Create record\n2.Display record\n3.Bubble Sort\n4.Selection Sort\n5.Binary Search\n6.Binary Search with rec\n7.Exit");
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
			summary();
			bubbleSort(s,n);
			printf("\nSorted record in ascending order of roll numbers:");
			preDisplay();
			for(i=0;i<n;i++)
				display(&s[i],i+1);
			printf("_______________________________________________\n\n");

			break;

		case 4:
		    summary();
			selectionSort(s,n);		    
			printf("\n\nSorted record in descending order of names:\n\n");
			preDisplay();
			for(i=0;i<n;i++)
				display(&s[i],i+1);
			break;

		case 5:
			printf("Enter the roll no. of the student to be searched:");
			scanf("%d",&key);
			m = binarySearch(s,n,key);
			if(m==0)
				printf("Record not found !!");
			else
			{
				printf("Record found at sr. no. %d\n",m+1);
				preDisplay();
				display(&s[m],m+1);
			}
			break;
			
		case 6:
			printf("Enter the roll no. of the student to be searched:");
			scanf("%d",&key);
			binarySearchRec(s,0,n,key);
			break;

		}
		printf("\n\nDo you want to continue?\nPress 1 if yes and 0 if no: ");
		scanf("%d",&p);
	}while(ch!=7 && p!=0);

	return EXIT_SUCCESS;
}


void add(struct student *stud)
{
	int i,s=0;
	printf("Enter the name of student: ");
	scanf("\n");
	gets(stud->name);
	printf("Enter the roll number:");
	scanf("%d",&stud->rollNo);
	printf("Enter the marks in 5 subjects");
	for(i=0;i<5;i++)
	{
		printf("\nSubject %d: ",i+1);
		scanf("%d",&stud->marks[i]);
		s = s + stud->marks[i];
	}
	s = s/5;
	stud->per = s;
}

void display(struct student *stud ,int i)
{

	printf(" %d\t  %s\t\t%d\t   %f\n",i,stud->name,stud->rollNo,stud->per);
}

void preDisplay()
{

	printf("\n______________________________________________\n");
	printf("\n|Sr No.|   Name   |   Roll No.  | Percentage |\n");
	printf("______________________________________________\n\n");

}

void swap(struct student *s1,struct student *s2)
{
	struct student temp;
	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void bubbleSort(struct student s[],int n)
{
	int i,j,flag,pass=0,comp=0,exch=0,a[20],k,b[20];
	a[0]=b[0]=0;
	for(i=0;i<n-1;i++)
	{
		flag = 0;
		pass++;
		for(j=0;j<n-i-1;j++)
		{
			comp++;
			a[i+1] = comp;
			if(s[j].rollNo>s[j+1].rollNo)
			{
				exch++;
			    b[i+1] = exch;
				swap(&s[j],&s[j+1]);
				flag = 1;
			}
		}
		displaySummary(pass,comp-a[i],exch-b[i],s,n,1);
		if(flag==0)
			break;
	}
	
	printf("\n___________________________________________________\n\n");
	printf("\nNumber of passes: %d\n",pass);
	printf("\nNumber of comparisons: %d\n",comp);
	printf("\nNumber of exchanges: %d\n ",exch);
	
	j=((n)*(n-1))/2;
	if(comp==j)
		printf("\nThis is the best case !!\nTime complexity: O(n)\n\n");
	else if((comp)==(n-1))
		printf("\nThis is the worst case !!\nTime complexity: O(n^2)\n\n");
	else
		printf("\nThis is the average case !!");
}

void selectionSort(struct student s[],int n)
{
	int pass=0,comp=0,exch=0;
	int i,j,min,a[20],b[20];
	a[0]=b[0]=0;
	for(i=0;i<n;i++)
	{
		pass++;
		min = i;
		for(j=i+1;j<n;j++)
		{
			comp++;
			a[i+1] = comp;
			if((strcmp(s[j].name,s[min].name))>0)
			{
				min = j;
			}
		}
		if(min!=i)
		{
			exch++;
			b[i+1] = exch;
			swap(&s[min],&s[i]);
		}
		displaySummary(pass,comp-a[i],exch-b[i],s,n,0);
	}
	
	printf("\n___________________________________________________\n\n");
	printf("\nNumber of passes: %d\n",pass);
	printf("\nNumber of comparisons: %d\n",comp);
	printf("\nNumber of exchanges: %d\n ",exch);
	
	
	j=((n)*(n-1))/2;
	if(comp==j)
		printf("\nThis is the best case !!\nTime complexity: O(n)\n\n");
	else if((comp)==(n-1))
		printf("\nThis is the worst case !!\nTime complexity: O(n^2)\n\n");
	else
		printf("\nThis is the average case !!");	
}

int binarySearch(struct student s[],int n,int key)
{
	int low,high,med,i;
	low = 0;
	high = n;

	while(low<=high)
	{
		med = low + high;
		med = med/2;
		if(s[med].rollNo == key)
			return med;
		else if(key<s[med].rollNo)
			high = med -1;
		else
			low = med + 1;
	}
	return 0;
}

int binarySearchRec(struct student s[],int first,int last,int key)
{
	int mid;
	
	mid = (first+last)/2;
	
	if(s[mid].rollNo<key)
	{
		binarySearchRec(s,mid+1,last,key);
	}
	else if(s[mid].rollNo==key)
	{
		printf("Record found!!");
	}
	else if(s[mid].rollNo>key)
	{
		binarySearchRec(s,first,mid-1,key);
	}
	else
		printf("Record not found!!");
		
}
void summary()
{
	printf("\nSummary:");
	printf("\n____________________________________________________\n");
	printf("\n|  Pass  | Comp. |  Swaps |          Array          |\n");
	printf("____________________________________________________\n");
}

void displaySummary(int pass,int comp,int exch,struct student s[],int n,int id)
{
	int i;
	printf("\n    %d\t     %d\t      %d\t   ",pass,comp,exch);
	if(id==1)
	{	
		for(i=0;i<n;i++)
		{
			printf("   %d",s[i].rollNo);
		}
		printf("\n");
	}
	else
	{
		for(i=0;i<n;i++)
		{
			printf(" %s",s[i].name);
		}
		printf("\n");
	}
}
