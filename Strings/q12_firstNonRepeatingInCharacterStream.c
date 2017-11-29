/*Find first non-repeating character from a stream of characters.

Method 1: If we use the previous approach to find the first non repeating character using
hash table containing the count and index of characters, then to check for the first non
repeating char in the hash table will result into O(n^2) time in worst case.
============================================================================================
Method 2:Use a data structure containing a hash table with count of characters and a pointer/link 
pointing to that character followed by the next character in case this character gets repeated.

Whenever a character gets repeated, we increment its count and remove that character from the DLL.

AMMORTIZED TIME: O(n)
This means that if at every input, we are asked to tell the non repeating character, then we can
asnwer it in O(1) time, thus resulting into O(n) ammortized time!
SC=O(n)

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
#define COUNT 256

char str[MAX];
int curr=0;

struct node
{
	char data;
	struct node *next,*prev;
};

struct hash_cell
{
	int count;
	struct node *head;
};

struct hash_cell *hashTable;
struct node *dll_head, *dll_tail;

struct node * newNode(char data)
{
	struct node *new=(struct node *)malloc(sizeof(struct node *));
	new->data=data;
	new->next=new->prev=NULL;
	return new;
}

void insertAtEnd(struct node *new)
{
	if(!dll_head)
	{
		dll_head=new;
		dll_tail=new;
		return;
	}

	
	dll_tail->next=new;
	new->prev=dll_tail;
	dll_tail=new;
}

void removeFromDLL(struct node *toBeRemoved)
{
	if(!dll_head)
		return;
	struct node *temp=toBeRemoved;
	//If single node in DLL:
	if(!toBeRemoved->prev && !toBeRemoved->next)
	{
		free(temp);
		return;
	}
	//If first node needs to be removed
	if(dll_head==toBeRemoved)
	{

		dll_head=toBeRemoved->next;
		printf("toBeRemoved is dll head,new:%c\n",dll_head->data);
		toBeRemoved->next->prev=NULL;
		free(temp);
		return;
	}
	//If last node in DLL is to be removed, update tail
	if(!toBeRemoved->next)
	{
		toBeRemoved->prev->next=NULL;
		dll_tail=toBeRemoved->prev;
		free(temp);
		return;
	}
	toBeRemoved->prev->next=toBeRemoved->next;
	toBeRemoved->next->prev=toBeRemoved->prev;
	free(temp);
}

void traverseDLL()
{
	struct node *ptr=dll_head;
	while(ptr)
	{
		printf("%c -> ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

char firstNonRepeatingChar(char str[])
{
	if(hashTable[str[curr]].count==0)
	{
		printf("Adding: %c\n",str[curr]);
		//Increment the count and add a new node pointe by this hash table cell.
		//Also add this node to the end of DLL.
		hashTable[str[curr]].head=newNode(str[curr]);
		insertAtEnd(hashTable[str[curr]].head);

	}
	else if(hashTable[str[curr]].count>0)
	{
		printf("Getting removed--%c\n",hashTable[str[curr]].head->data);		
		removeFromDLL(hashTable[str[curr]].head);

	}
	hashTable[str[curr]].count++;

	return dll_head->data;

}

int main()
{
	hashTable=(struct hash_cell *)calloc(COUNT,sizeof(struct hash_cell *));
	char ch;
	printf("Keep entering the character one by one! Enter * to quit \n");
	scanf(" %c",&ch);
	// ch=getchar();
	while(ch!='?')
	{
		str[curr]=ch;
		printf("you entered: %c at index: %d\n",str[curr],curr);
		char res=firstNonRepeatingChar(str);
		printf("First non repeating character is: %c\n",res);
		curr++;
		traverseDLL();
		printf("Enter next\n");
		scanf(" %c",&ch);
		// ch=getchar();
	}

}