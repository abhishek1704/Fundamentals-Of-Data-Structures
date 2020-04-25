
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int data;
	struct node *next;

}node;

node* getNode(node *temp);
node* insert(node *head,int pos);
node* delete(node *head,int key);
node* revert(node *head);

int main(void) {

	int n,i,j,ch,pos,key;
	node *head,*tail,*s;
	head = NULL;
	tail = NULL;
	printf("Enter the number of nodes to be created: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		s = (node*)malloc(sizeof(node));
		s->next = NULL;
		if(i==0)
			head=tail= s;
		printf("\nEnter a data:");
		scanf("%d",&s->data);
		if(i!=0)
			tail->next = s;
			tail = s;
	}

	do
	{
		printf("\n\n--Main Menu--\n1. insert\n2. Delete\n3. Display\n");
		printf("4. Display Reverse\n5. Revert the SLL\n6. Exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&ch);

		switch(ch)
		{
		case 1:
			printf("Total number of nodes: %d\n",n);
			printf("Enter the position to insert:");
			scanf("%d",&pos);
		    head = insert(head,pos);
			break;

		case 2:
			printf("Enter the data to be deleted:");
			scanf("%d",&key);
			head = delete(head,key);
			if(head!=NULL)
			{
				printf("\nList after deletion:\n");
				displaySLL(head);
			}
			else
				printf("List is empty !!");
			break;

		case 3:
			if(head!=NULL)
			{
				displaySLL(head);
			}
			else
				printf("List is empty !!");

			break;

		case 4:
			displayReverse(head);
			break;

		case 5:
			printf("\nList before reverting:\n");
			displaySLL(head);
			printf("\n\nList after reverting:\n");
			head = revert(head);
			displaySLL(head);
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
	return temp;
}

void displaySLL(node *head)
{
	node *ptr;
	ptr = head;

	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
}

node* insert(node *head,int pos)
{
	int i;
	node *nev,*prev;

	nev = getNode(nev);
	printf("Enter the data:");
	scanf("%d",&nev->data);
	if(pos==1)
	{
		nev->next = head;
		head = nev;
		return head;
	}
	prev = head;
	i=1;
	while(prev->next!=NULL && i<pos-1)
	{
		prev = prev->next;
		i++;
	}
	nev->next = prev->next;
	prev->next = nev;

	return head;
}

void displayReverse(node *head)
{
	if(head!=NULL)
	{
		displayReverse(head->next);
		printf("%d ",head->data);
	}

}

node* delete(node *head,int key)
{
	node *temp,*prev;
	
	if(head==NULL)
	{	printf("List is empty !!");
		return head;
	}
	temp = head;
	if(key==(head->data))
	{
		head = head->next;
		free(temp);
		return head;
	}
	while(temp!=NULL && (temp->data)!=key)
	{
		prev = temp;
		temp = temp->next;
	}
	if(temp==NULL)
	{
		printf("Data not found !!");
		return head;
	}
	prev->next=temp->next;
	free(temp);

	return head;
}

node* revert(node *head)
{
	node *current,*result,*temp;
	temp = NULL;
	result = NULL;
	current = head;
	
	while(current!=NULL)
	{
		temp = current->next;
		current->next = result;
		result = current;
		current = temp;
	}
	head = result;
	return head;
}
