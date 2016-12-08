//FileName:		linkedlist.c
//Project:		dsA2
//Author:		Alex Guerrero	
//Date:			March 4, 2014
//Description:	This file contains the function definitions for the linkedlists and hashtable linked list.



//include file
#include"dsA2.h"



//FunctionName: addNameHash(char *string, int index, WordNode *hashTable[])
//Description:  this function adds words to the linked list and connects it to the hasTable.
//				The funcion creates a newBlock, allocates memory and copies the word to the structure.
//				This list is also sorted alphabetically.
//Parameters: char artist[], char song[], int index, songInfo *hashTable[]
//Return Values: Void
void addNameHash(char artist[], char song[], int index, songInfo *hashTable[])
{
	//variables initialized
	songInfo *newBlock = NULL;
	songInfo *ptr = NULL;

	//allocate memory for new block,  if new is empty infor the user
	newBlock = (songInfo*)malloc(sizeof( songInfo ));
	if (newBlock == NULL) 
	{
		printf ("Error! No memory!\n");
	}

	//scan the wor into the structure and set ptr->next NULL
	sscanf( artist, "%s", newBlock->artist );
	sscanf( song, "%s", newBlock->songTitle );
	newBlock->next = NULL;

	//if the hashTable is NULL, the list is empty, set the address of 
	//the newly created block to the first element in the hashtable as 
	//the head of the linked list
	if(hashTable[index] == NULL) 
	{
		hashTable[index] = newBlock;
	}
	
	//special case, inserting in the first location to keep the list in
	//alphabetic order.
	//compare the top of the list with the new entry, if the first word in the list is
	//greater in value than the new entry, set the next pointer of the newBlock to be the
	// location that used to be at the front of the list
	else if(stricmp(hashTable[index]->songTitle, newBlock->songTitle) >= 0) 
	{
		newBlock->next = hashTable[index];
		// set new block to point to the new start of the list
		hashTable[index] = newBlock;
	}
	else
	{
		//The lis is not empty, so assign the address of the top of the list
		//to ptr and find the end of the list.
		ptr = hashTable[index];
		while (ptr->next != NULL) 
		{
			ptr = ptr->next;
		}
		//if ptr->next is NULL, we are at the end of the list.
		//assign the new block to the end of the list
		if(ptr->next == NULL)
		{
			ptr->next = newBlock;
		}
	}
}



//FunctionName: *addNameSortedLL(char artist[], char song[], int index, songInfo *head
//Description:  this function adds words to the linked list.
//				The funcion creates a newBlock, allocates memory and copies the word to the structure.
//				This list is also sorted alphabetically.
//Parameters: char artist[], char song[], int index, songInfo *head
//Return Values: Void
songInfo *addNameSortedLL(char artist[], char song[], int index, songInfo *head)
{
	//variables initialized
	songInfo *newBlock = NULL;
	songInfo *ptr = NULL;

	//allocate memory for new block,  if new is empty inform the user
	newBlock = (songInfo*)malloc(sizeof( songInfo ));
	if (newBlock == NULL) 
	{
		printf ("Error! No memory!\n");
	}

	//scan the wor into the structure and set ptr->next NULL
	sscanf( artist, "%s", newBlock->artist );
	sscanf( song, "%s", newBlock->songTitle );
	newBlock->next = NULL;

	//if the hashTable is NULL, the list is empty, set the address of 
	//the newly created block to the first element in the hashtable as 
	//the head of the linked list
	if(head == NULL) 
	{
		head = newBlock;
	}
	
	//special case, inserting in the first location to keep the list in
	//alphabetic order.
	//compare the top of the list with the new entry, if the first word in the list is
	//greater in value than the new entry, set the next pointer of the newBlock to be the
	// location that used to be at the front of the list
	else if(stricmp(head->songTitle, newBlock->songTitle) >= 0) 
	{
		newBlock->next = head;
		// set new block to point to the new start of the list
		head = newBlock;
	}
	else
	{
		//The lis is not empty, so assign the address of the top of the list
		//to ptr and find the end of the list.
		ptr = head;
		while (ptr->next != NULL) 
		{
			ptr = ptr->next;
		}
		//if ptr->next is NULL, we are at the end of the list.
		//assign the new block to the end of the list
		if(ptr->next == NULL)
		{
			ptr->next = newBlock;
		}
	}
	return head;
}



////FunctionName: searchNameHash(char song[], int index, songInfo *hashTable[], int *foundFlag)
////Description:  This function searches the linked list, with the index provided by hashKeyGenerator.
////				The function then searches that linked list to see if it finds a match.  Each comparision 
////				is displayed on the screen until the function finds a match. if a/no match is found, the user 
////				is informed through a printf and the function exits.
////Parameters:		char song[], int index, songInfo *hashTable[], int *foundFlag
////Return Values: int numComparisons
int searchNameHash( char song[], int index, songInfo *hashTable[], int *foundFlag )
{
	//Variables initialized
	songInfo *ptr = NULL;
	int exit = 0;
	int numComparisons = 0;

	//assign the address of the top of the hashTable linked list to ptr to traverse 
	//the structure
	ptr = hashTable[index];

	while(kOne)
	{
		//if ptr is NULL, nothing to search for so inform user and exit.
		if(ptr == NULL)
		{
			break;
		}
		//while the list is not empty, compare the search word with the current word in the list.
		//if a match is found inform the user, the value of exit is changed to 1 to exit the loop.
		while (ptr->next != NULL) 
		{
			numComparisons++;
			if(stricmp(song, ptr->songTitle) == 0)
			{
				exit = 1;
				*foundFlag = 1;
				break;
			}
			ptr = ptr->next;
		}

		//if exit equal 1, a match was found exit the function
		if(exit == 1)
		{
			break;
		}
		//compare the last word in the list, if a match is found, inform the user and break out of the
		//function
		if(ptr->next == NULL)
		{
			numComparisons++;
			if(stricmp(song, ptr->songTitle) == 0)
			{
				*foundFlag = 1;
				break;
			}
			else
			{
				ptr = ptr->next;
			}
		}
		//if the function has searched the contents and found no match,
		//inform the user and exit the function.
	}
	return numComparisons;
}



//FunctionName: searchNameSortedLL(char *string, int index, WordNode *hashTable[])
//Description:  This function searches the linked list for words.
//				The function then searches that linked list to see if it finds a match.  Each comparision 
//				is counted. if a/no match is found, the user 
//				is informed through a printf and the function exits.
//Parameters: char *string, int index, WordNode *hashTable[]
//Return Values: int numComparisons
int searchNameSortedLL( char song[], int index, songInfo *head, int *foundFlag)
{
	//Variables initialized
	songInfo *ptr = NULL;
	int exit = 0;
	int numComparisons = 0;
	//assign the address of the top of the hashTable linked list to ptr to traverse 
	//the structure
	ptr = head;

	while(kOne)
	{
		//if ptr is NULL, nothing to search for so inform user and exit.
		if(ptr == NULL)
		{
			break;
		}
		//while the list is not empty, compare the search word with the current word in the list.
		//if a match is found inform the user, the value of exit is changed to 1 to exit the loop.
		while (ptr->next != NULL) 
		{
			numComparisons++;
			if(stricmp(song, ptr->songTitle) == 0)
			{
				exit = 1;
				*foundFlag = 1;
				break;
			}
			ptr = ptr->next;
		}

	
		//if exit equal 1, a match was found exit the function
		if(exit == 1)
		{
			break;
		}
		//compare the last word in the list, if a match is found, inform the user and break out of the
		//function
		if(ptr->next == NULL)
		{
			numComparisons++;
			if(stricmp(song, ptr->songTitle) == 0)
			{
				*foundFlag = 1;
				break;
			}
			ptr = ptr->next;
		}
	}

	return numComparisons;
}



//FunctionName: delete_info(songInfo *head)
//Description:  This function frees the memory of the linkedlist.
//Parameters:  songInfo *head
//Return Values: void
void delete_info(songInfo *head)
{
	songInfo *curr = NULL, *ptr = NULL;

	//set start of list to ptr
	ptr = head;
	if(ptr == NULL )
	{
		printf("nothing here to delete\n");
	}
	// follow the chain until the pointer is null
	while (ptr != NULL)
	 {
		// first, save the current cell
		curr = ptr;
		// next, move to the next cell
		ptr = ptr->next;

		// can’t free curr before getting the next pointer
		free (curr);
	}	/* end while */
}



//FunctionName: delete_info(songInfo *head)
//Description:  This function frees the memory of the hashtable.
//Parameters:  songInfo *hashTable[]
//Return Values: void
void delete_infoHash( songInfo *hashTable[] )
{
	int index = 0;
	songInfo *ptr = NULL;
	songInfo *current = NULL;

	//set start of list to ptr
	ptr = hashTable[index];
	if(ptr == NULL )
	{
		printf("nothing here to delete\n");
	}
	else
	{
		//go through every index
		for( index = 0; index < BUCKETCOUNT; index++ )
		{
			// follow the chain until the pointer is null
			while( ptr != NULL )
			{
				// first, save the current cell
				current = ptr;
				// next, move to the next cell
				ptr = ptr->next;
				//free memory
				free( current );
			}
		}
	}
}