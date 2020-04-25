
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	char name[20];
	char rollNo[10];
	long int mobileNo;
	int marks[5];
	float per;
	char dob[15];
	
}student;

int main(void) {

	int i,ch,n,p,flag,x,r;
	char roll[10],name[20];
	
	student s[50];
	do
	{
		printf("\n----Main Menu----\n\n1.Add record\n2.Display\n3.Search\n4.Update\n5.Delete\n6.Max Percentage\n7.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
		case 1:
			printf("Enter the number records you want to add: ");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				add(&s[i],i+1);
			}
			break;

		case 2:
			preDisplay();
			for(i=0;i<n;i++)
				display(&s[i],i+1);
			break;

		case 3:
			printf("Enter the roll no. of the student to be searched:");
			scanf("%s",roll);
			printf("\n%s\n",roll);
			for(i=0;i<n;i++)
				search(&s[i],&flag,roll);
			if(flag==1)
				printf("Student found !!");
			else
				printf("Student not found !!");
			break;

		case 4:
			update(s,n);
			break;

		case 5:
			delet(s,&n);
			break;

		case 6:
			percentage(s,n,name);
			break;
			
		case 7:
			break;
			
		default :
			printf("\nYou have entered a wrong choice !\n");
			break;

		}
		if(ch==7)
			break;
		printf("\n\nDo you want to continue?\nPress 1 if yes and 0 if no: ");
		scanf("%d",&p);
	}while(p!=0);

	return EXIT_SUCCESS;
}

void add(student *stud ,int n)
{
	int i,no,s=0;
	no=n;
	char str1[10],str2[10];
	strcpy(str1,"STUD");
	printf("Enter the name of student: ");
	scanf("\n");
	gets(stud->name);
	sprintf(str2,"%03d",no);
	strcat(str1,str2);
	strcpy(stud->rollNo,str1);
	printf("Enter the mobile no.: ");
	scanf("%ld",&stud->mobileNo);
	printf("Enter the date of birth:");
	scanf("%s",stud->dob);
	printf("Enter the marks in 5 subjects");
	
	for(i=0;i<5;i++)
	{
		printf("Subject %d: ",i+1);
		scanf("%d",&stud->marks[i]);
		s = s + stud->marks[i];
	}
	
	s = s/5;
	stud->per = s;
	
}

void display(student *stud,int i)
{
	
	printf(" %d.\t  %s\t\t%s\t   %ld\t  %s\t%f\n",i,stud->name,stud->rollNo,stud->mobileNo,stud->dob,stud->per);

}

void preDisplay()
{

	printf("---------------------------------------------------------------------------\n");
	printf("|Sr No.|   Name   |   Roll No.   |   Mobile No. | Date of Birth | Percentage |\n");
	printf("---------------------------------------------------------------------------\n");
}

void search(student *stud,int *flag,char roll[])
{
	if((strcmp(stud->rollNo,roll))==0)
		*flag = 1;
	else
		*flag = 0;
}

void update(student s1[],int n)
{
	int i,flag=0;
	char roll[10];
	printf("Enter the roll no. of student to be updated:");
	scanf("%s",roll);
	for(i=0;i<n;i++)
	{
		if((strcmp(s1[i].rollNo,roll)==0))
		{
			flag = 0;
			printf("Enter the name of student: ");
			scanf("\n");
			gets(s1[i].name);
			printf("Enter the mobile no.: ");
			scanf("%ld",&s1[i].mobileNo);
		}
		else
			flag = 1;
	}
	if(flag == 1)
		printf("Student not found !!");

}
void delet(student s2[],int *n)
{
	student temp;
	int i,flag=1,index;
	char r[10];
	printf("Enter the roll no. of the student to be deleted: ");
	scanf("%s",&r);
	for(i=0;i<*n;i++)
	{
		if(strcmp(s2[i].rollNo,r)==0)
		{
			flag = 0;
			index = i;
		} 		
	}
	if(flag==0)
	{
		temp = s2[index];
		s2[index] = s2[*n-1];
		s2[*n-1] = temp;
		*n-=1;
		
	}
	else
		printf("Student not found !!");
}

int percentage(student s1[],int n,char name[])
{
	int i,j,s=0;
	float max;
	s1[0].per = max;
	for(i=1;i<n;i++)
	{
		if(s1[i].per>=max)
		{
			max = s1[i].per;
			strcpy(name,s1[i].name);
		}
	}
	printf("The highest percentage obtained by %s which is  %f %",name,max);
	return max;
}

