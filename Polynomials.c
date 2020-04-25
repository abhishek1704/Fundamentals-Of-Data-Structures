#include <stdio.h>
#include <stdlib.h>

typedef struct CLL
{
	int pow;
	double coeff;
	struct CLL *next;
}CLL;

void assign(CLL **p,int pow,double coeff)
{
	(*p)->coeff=coeff;
	(*p)->pow=pow;
}

void insert(CLL **head,int pow,double coeff)
{
	CLL *q=*head,*p=(CLL*)malloc(sizeof(CLL)),*r;
	assign(&p,pow,coeff); 
	if(*head==0)
	{
		*head=p;
		p->next=(*head);
		return;
	}
	
	if(pow>(*head)->pow)
	{
		p->next= (*head);
		r= *head;
		while(r->next != *head)
		{
			r=r->next;
		}	
		r->next=p;
		*head=p;
		return;
	}
	while(q->next != *head && pow<=(q->next)->pow)
	{
		q=q->next;;
	}
	if(pow==(q->pow))
	{
		q->coeff+=coeff;
		free(p);
	}
	else
	{
		p->next=q->next;
		q->next=p;
	}
}

CLL* add(CLL *h1,CLL *h2)
{
	CLL *h=(CLL*)malloc(sizeof(CLL)),*p=h1,*q=h2;
	h=0;
	do
	{
		insert(&h,p->pow,p->coeff);
		p=p->next;
	}while(h1!=p);
	do
	{
		insert(&h,q->pow,q->coeff);
		q=q->next;
	}while(h2!=q);
	return h;
}

CLL* mult(CLL *h1,CLL *h2)
{
	CLL *h=(CLL*)malloc(sizeof(CLL)),*p=h1,*q=h2;
	do
	{
		q=h2;
		do
		{
			insert(&h,(p->pow)+(q->pow),(p->coeff)*(q->coeff));
			q=q->next;
		}while(q!=h2);
		p=p->next;
	}while(h1!=p);
	
	return h;
}

void disp(CLL *head)
{
	CLL *p=head;
	do
	{
		if(p!=head)
		printf(" + ");
		printf("{%.1f(x)^%d}",p->coeff,p->pow);
		p=p->next; 
	}while(p!=head);
	printf("\r\n");
}

int main()
{
	int pow,ch;
	double coeff;
	CLL *head1=0,*head2=0;
	do
	{
		printf("\n\n__Main Menu__\n");
		printf("1. Make Polynomials\n");
		printf("2. Add\n");
		printf("3. Multiply\n");
		printf("\nEnter your choice :");
		scanf("%d",&ch);
		int ch1;
		switch(ch)
		{
			case 1:
			{
				printf("Enter first polynomial :\n");
				do
				{
					printf("\nCoeff :");
					scanf("%lf",&coeff);
					printf("Power   :");
					scanf("%d",&pow);
					insert(&head1,pow,coeff);
					printf("Do you want to insert more (1/0):");
					scanf("%d",&ch1);		
				}while(ch1);
				disp(head1);
				printf("Enter second polynoial :\n");
				do
				{
					printf("\nCoeff :");
					scanf("%lf",&coeff);
					printf("Power  :");
					scanf("%d",&pow);
					insert(&head2,pow,coeff);
					printf("Do you want to insert more (1/0):");
					scanf("%d",&ch1);	
				}while(ch1);
				printf("\nYour polynomial is :\n");
				disp(head2);
			}break;
			case 2:
			{
				CLL* h=add(head1,head2);
				printf("\nAddition :");
				disp(h);
			}break;
			case 3:
			{
				CLL* h = mult(head1,head2);
				printf("\nMultiplication :");
				disp(h);	
			}break;
			
			case 0:break;
		}
	}while(ch);
	
	return 0;
}
