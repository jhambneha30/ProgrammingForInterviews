#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node* head;

void insertAtFront(int newData)
{
	struct node *new = (struct node*)malloc(sizeof(struct node*));
	new->data=newData;
	new->prev=NULL;
	new->next=NULL;

	if(!head)
	{
		head=new;
	}
	else
	{
		new->next=head;
		head=new;
		head->next->prev=new;
	}
}

void insertAtEnd(int newData)
{
	struct node *new = (struct node*)malloc(sizeof(struct node*));
	new->data=newData;
	new->prev=NULL;
	new->next=NULL;
	struct node *p=head;

	if(!head)
	{
		head=new;
	}
	else
	{
		while(p->next)
		{
			p=p->next;
			
		}
		p->next=new;
		new->prev=p;

	}
}

void insertAfterItem(int newData, int item)
{
	struct node *new = (struct node*)malloc(sizeof(struct node*));
	new->data=newData;
	new->prev=NULL;
	new->next=NULL;
	struct node *p=head;
	if(!head)
	{
		head=new;
	}
	else
	{
		while(p->data!=item)
		{
			p=p->next;
		}
		new->next=p->next;
		new->prev=p;
		new->next->prev=new;
		p->next=new;
	}

}

void traverseDoubleLL()
{
	struct node* p=head;
	printf("%s\n","LL is:=============");
	while(p)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}

int main()
{
	int choice,newData;
	int item;
	while(choice!=4)
	{
		printf("%s\n","MENU for insertion");
		printf("%s\n","1: Insert at front \n2: Insert at end \n3: Insert after an element \n4: Exit");
		scanf("%d",&choice);
		if(choice!=4)
		{
			printf("%s\n","Enter the data to be inserted.");
			scanf("%d",&newData);
		}
			
		switch(choice)
		{
			case 1: 
				insertAtFront(newData);
			break;
			case 2:
				insertAtEnd(newData);
			break;
			case 3:
				printf("%s\n","Enter the item after which data is to be inserted.");
				scanf("%d",&item);
				insertAfterItem(newData,item);
			case 4:
				printf("%s\n","BYE");
			break;
		}
		traverseDoubleLL();
	}
	
	return 0;
}