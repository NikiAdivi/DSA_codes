#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
	}Node;
Node *head=NULL;

/*Node* createnode()
{
	Node* n1=(Node*)malloc(sizeof(Node));
	n1->data=12;
	n1->next=NULL;
	return n1;
}*/

void insert_end(Node** head,int data)
{
	Node** temp=head;
	Node* n1=(Node*)malloc(sizeof(Node));
	n1->data=data;
	n1->next=NULL;
	if(*head==NULL)
	{
		*head=n1;
	}
	while(*temp->next!=NULL)
	{
		*temp=*temp->next;
	}
	
	*temp->next=n1;
}

Node* insert_beg(Node** head,int data)
{
	Node* n1=(Node*)malloc(sizeof(Node));
	n1->data=data;
	n1->next=NULL;
	n1->next=head->next;
	head=n1;
	return head;
}
void display(Node* temp)
{
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
}
	
		
int main()
{
	head=(Node*)malloc(sizeof(Node));
	head->data=23;
	head->next=NULL;
	int i=0;
	Node* temp=head;
	Node* n1;
	while(i<5)
	{
		insert_end(head,i);
		i++;
	}
	display(head);
	insert_end(head,5);
	display(head);
	insert_beg(&head,6);
	display(head);
	return 0;
}
	
	
