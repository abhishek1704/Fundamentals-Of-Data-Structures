
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	struct student
	{
		char name[20];
		int rollNo;
		int marks[5];
		float per;

	}s;

	struct node *prev,*next;

}node;

node* create(node *head,int n);
node* displayForward(node *head);
node* inputNode(node *nev);
node* displayBackward(node *head);
node* insert(node *head,int pos);
node* delete(node *head,char name[20]);

int main(void) {
	int n,i,j,ch,pos;
	char key[20];
	node *head,*tail;
	head = NULL;
	tail = NULL;

	do
		{
			printf("\n\n--Main Menu--\n1. Create\n2. insert\n3. Delete\n4. Display forward\n");
			printf("5. Display backward\n6. Exit\n");
			printf("\nEnter your choice:");
			scanf("%d",&ch);

			switch(ch)
			{
			case 1:
				printf("Enter the number of nodes to be created: ");
				scanf("%d",&n);
				head = create(head,n);
				break;

			case 2:
				printf("Total number of nodes: %d\n",n);
				printf("Enter the position to insert:");
				scanf("%d",&pos);
			    head = insert(head,pos);
				break;

			case 3:
				printf("Enter the name of the record to be deleted:");
				scanf("%s",key);
				head = delete(head,key);
				if(head!=NULL)
				{
					printf("\nList after deletion:\n");
					preDisplay();
					displayForward(head);
				}
				else
					printf("List is empty !!");
				break;

			case 4:
				preDisplay();
				head = displayForward(head);
				break;

			case 5:
				preDisplay();
				head = displayBackward(head);
				break;

			case 6:
				break;
			}

		}while(ch!=6);



	return EXIT_SUCCESS;
}

node* getNode(node *temp)
{
	temp = (node*)malloc(sizeof(node));
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

node* create(node *head,int n)
{
	int i,sum=0;
	node *nev,*last;
	nev = getNode(nev);
	if(head == NULL)
	{
		head = nev;
		nev = inputNode(nev);
		last = nev;
	}

	for(i=1;i<n;i++)
	{
		nev = getNode(nev);
		nev = inputNode(nev);
		last->next = nev;
		nev->prev = last;
		last = nev;
	}

	return head;
}

node* inputNode(node *nev)
{
	int i,sum=0;
	printf("Enter the name of student: ");
	scanf("\n");
	gets(nev->s.name);
	printf("Enter the roll number:");
	scanf("%d",&nev->s.rollNo);
	printf("Enter the marks in 5 subjects");
	for(i=0;i<5;i++)
	{
		printf("\nSubject %d: ",i+1);
		scanf("%d",&nev->s.marks[i]);
		sum = sum + nev->s.marks[i];
	}
	sum = sum/5;
	nev->s.per = sum;

	return nev;
}

void preDisplay()
{

	printf("\n______________________________________________\n");
	printf("\n|Sr No.|   Name   |   Roll No.  | Percentage |\n");
	printf("______________________________________________\n\n");

}

node* insert(node *head,int pos)
{
	int i;
	node *nev,*temp,*temp1;
	nev = getNode(nev);
	nev = inputNode(nev);
	if(pos == 1)
	{
		nev->next = head;
		if(head!=NULL)
			head->prev = nev;
		head = nev;
		return head;
	}
	i=1;
	temp = head;
	while(temp->next!=NULL && i<pos-1)
	{
		temp = temp->next;
		i++;
	}
	temp1 = temp->next;
	temp->next = nev;
	nev->next = temp1;
	nev->prev = temp;
	if(temp1!=NULL)
		temp1->prev = nev;

	return head;
}

node* displayForward(node *head)
{
	node* temp;
	int i=0;

	if(head == NULL)
	{
		printf("List is empty !!");
		return head;
	}
	temp = head;
	while(temp!=NULL)
	{
		printf(" %d\t  %s\t\t%d\t   %f\n",i+1,temp->s.name,temp->s.rollNo,temp->s.per);
		temp = temp->next;
		i++;
	}

	return head;
}

node* displayBackward(node *head)
{
	node* temp;
	int i=0;

	if(head == NULL)
	{
		printf("List is empty !!");
		return head;
	}
	temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	while(temp!=NULL)
	{
		printf(" %d\t  %s\t\t%d\t   %f\n",i+1,temp->s.name,temp->s.rollNo,temp->s.per);
		temp = temp->prev;
	}

	return head;
}

node* delete(node *head,char name[])
{
	node *temp,*P,*N;

	if(head == NULL)
	{
		printf("Database is empty !!");
	}
	temp = head;
	if(!strcmp(name,head->s.name))
	{
		head = head->next;
		if(head!=NULL)
		{
			head->prev = NULL;
		}
		free(temp);
		return head;
	}

	while(temp!=NULL && strcmp(name,temp->s.name))
	{
		temp = temp->next;
	}

	if(temp==NULL)
	{
		printf("Record not found !!");
	}

	P = temp->prev;
	N = temp->next;
	P->next = N;
	if(temp->next!=NULL)
	{
		N->prev = P;
	}

	free(temp);
	return head;
}
