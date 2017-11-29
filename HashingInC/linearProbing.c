/*Linear Probing implementation
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10
struct hash
{
	int data;
	char status;
	// status can be N (null) or D or O (deleted)
};

static int size=SIZE;
struct hash hashTable[SIZE];

void insertKey(int key)
{
	int index= key%size; //index = hash(key)
	int i;
	for(i=1;i<size;i++)
	{
		if(hashTable[index].status=='N' || hashTable[index].status=='D')
		{
			hashTable[index].data=key;
			hashTable[index].status='O';
			printf("Inserted!\n");
			return;
		}
		if(hashTable[index].data==key)
		{

			printf("Duplicates not allowed!\n");
			return;
		}
		
		index=((key%size)+i)%size;
		
	}
	printf("Hash table limit exceeded!");
}

void searchKey(int key)
{
	int index=key%size;
	int i;

	for(i=1;i<size;i++)
	{
		if(hashTable[index].status=='N')
		{
			printf("Key is not present!\n");
			return;
		}
		if(hashTable[index].status=='O' && hashTable[index].data==key)
		{
			printf("Key found at index: %d\n",index);
			return;
		}
		index=((key%size)+i)%size;

	}
	printf("Key not found in the hash table :(\n");
	
}

void deleteKey(int key)
{
	int index=key % size;
	int i;
	for(i=1;i<size;i++)
	{
		if(hashTable[index].status=='N')
		{
			printf("Key is not present!\n");
			return;
		}
		if(hashTable[index].status=='O' && hashTable[index].data==key)
		{
			printf("Key found at index: %d\n",index);
			hashTable[index].status='D';
			printf("Key deleted!\n");
			return;
		}
		index=((key%size)+i)%size;

	}
	printf("Key not found in the hash table :(\n");
	

}

void display()
{
	int count,flag=0;
	for(count=0;count<size;count++)
	{
		printf("count: %d\n",count);
		if(hashTable[count].status=='O')
		{
			flag=1;
			printf("Occupied: %d\n",hashTable[count].data);
		}
		else if(hashTable[count].status=='D')
		{
			flag=1;
			printf("Deleted node!\n");
		}
	}
	if(flag==0)
		printf("Hahs table is empty!");
}

int main()
{
	int count,choice,key;
	for(count=0;count<size;count++)
	{
		hashTable[count].status='N';
	}
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
        		insertKey(key);
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
        		display();
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