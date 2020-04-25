
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct gll {

	int flag;
	struct gll *next;
	union {
		char data[MAX];
		struct gll *dlink;
	} u;

};

typedef struct gll node;

node* getNode(node*);
node* createGLL(node *head, char[]);
void disp(node *head);

int main() {

	char str[MAX];
	int choice;
	node *head;
	head = NULL;

	do {
	
		printf("Enter the string: ");

		scanf("\n");
		gets(str);

		printf("\n\n_______INDEX_________\n1");

		head = createGLL(head, str); //create the generalised list

		disp(head);

		printf("\n___________________________");
		printf("\n\nDo you want continue?\n\nPress 1 if yes and 0 if no...\n");
		scanf("%d", &choice);
	} while (choice!=0);

	return 0;
}

node* getNode(node *nev) {
	nev = (node*) malloc(sizeof(node)); //synamic memory allocation

	nev->next = NULL;
	nev->u.dlink = NULL;

	return nev;
}

node* createGLL(node *head, char str[10]) {
	int i = 0, j;
	node *temp;

	for (i = 0; *str != '\0';) {

		if (*str == '(' && i == 0) //head node
				{
			head = getNode(head);
			temp = head;
		} else {
			temp->next = getNode(temp->next);
			temp = temp->next;
		}

		i++;
		str++;
		j = 0;

		while (*str != ',' && *str != '(' && *str != ')') { //create nodes on same level
			temp->u.data[j] = *str;
			i++;
			str++;
			j++;
		}

		temp->u.data[j] = '\0'; //end the string
		temp->flag = 0; //for atomic node

		if (*str == '(') {
			temp->next = getNode(temp->next);
			temp = temp->next;
			temp->flag = 1; //for sublist

			temp->u.dlink = createGLL(NULL, str); //recursively calling the same function

			while (*str != ')') {
				i++;
				str++;
			}
			str++;
			i++;
		}

		if (*str == ')')//end of a list or sublist
			return head;

	}
}

void disp(node *temp) {
	static int depth; //for recursive calling
	depth++;
	int i;

	if (temp == NULL) {
		if (depth == 1)
			printf("LIST IS EMPTY!");
		else {
			printf("SUBLIST IS EMPTY!");
		}
	}

	else
		while (temp != NULL) {

			if (temp->flag == 0) { //atomic node
				printf("\n");

				for (i = 1; i < depth; i++)

					printf("  ");
				printf("%s", temp->u.data); //list titles

			}

			else
				disp(temp->u.dlink); //move to down link and repeat
			temp = temp->next;

		}

	depth--;
}


