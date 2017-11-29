/*Chaining implementation
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	int data;
	struct node *next;
};

struct hash
{
	int count;
	struct node *head;
};

struct hash *hashTable;
int size=10;

void addToHashTable(int k)
{
	int index=k % size;
	printf("index: %d\n",index);
	struct node *new = (struct node*)malloc(sizeof(struct node*));
	new->data=k;
	new->next=NULL;
	if(!hashTable[index].head)
	{

        hashTable[index].head=new;         
        hashTable[index].count=1;
		printf("First node added!-> %d\n",hashTable[index].head->data);         
		return;
	}

	//If head node exists, then add the new node at the front and return.
	new->next=hashTable[index].head;
	hashTable[index].head=new;	
	hashTable[index].count++;
	return;
	
}

void deleteKey(int k)
{
	int index= k % size;
	int flag=0;
	struct node *ptr, *temp, *prev;
	ptr=hashTable[index].head;
	if(!ptr)
	{
		printf("No key at this index!");
		return;
	}
	
	prev=ptr;
	while(ptr)
	{
		if(ptr->data==k)
		{
			flag=1;
			temp=ptr;
			if(ptr==hashTable[index].head)
			{
				hashTable[index].head=ptr->next;
			}
			else
			{
				prev->next=ptr->next;
			}
			hashTable[index].count--;
			free(temp);
			break;
		}
		prev=ptr;
		ptr=ptr->next;
	}

	if(!flag)
	{
		printf("Key not found!");
	}
	
	return;
}

void searchKey(int k)
{
	int index= k%size;
	int flag=0;
	struct node *ptr;
	if(hashTable[index].count==0)
	{
		printf("No key at the index: %d\n",index);
		return;
	}
	ptr=hashTable[index].head;
	while(ptr)
	{
		if(ptr->data==k)
		{
			printf("Key exists at index: %d\n",index);
			flag=1;
		}
			
		ptr=ptr->next;
	}

	if(!flag)
		printf("Key does not exist!");

}

void printHash()
{
	int i;
	struct node *ptr;
	for(i=0;i<size;i++)
	{
		printf("Index: %d",i);
		if(hashTable[i].count==0)
			continue;
		ptr=hashTable[i].head;
		while(ptr)
		{
			printf("--> %d",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
	return;
}

int main()
{
	int key,choice;
	// printf("Enter the size of hash table/max element");
 //    scanf("%d\n",&size);
	hashTable = (struct hash *)calloc(size,sizeof(struct hash));
	printf("\n1. Insertion\t2. Deletion\n");
    printf("3. Searching\t4. Display\n5. Exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
	while(choice!=5)
	{
		
        switch (choice) 
        {
        	case 1: 
        		printf("Enter the key for insertion\n");
        		scanf("%d",&key);
        		printf("key: %d\n",key);
        		addToHashTable(key);
        		break;
        	case 2:
        		printf("Enter the key for deletion\n");
        		scanf("%d",&key);
        		deleteKey(key);
        		break;
        	case 3:
        		printf("Enter the key to be searched\n");
        		scanf("%d",&key);
        		searchKey(key);
        		break;
        	case 4: 
        		printHash();
        		break;
        	case 5:
        		printf("BYE");
        		exit(0);
        		break;
        	default:
            	printf("Wrong option!!\n");
           		break; 	
        }
        printf("Enter your choice:");
    	scanf("%d", &choice);
	}
	return 0;
}
