//FileName:		dsA2.h
//Project:		dsA2
//Author:		Alex Guerrero	
//Date:			January 30, 2014
//Description:	This program takes a user inputted argument containing a directory.  
//				The program processes the string to make it a viable directory path to search for all
//				mp3 files in that directory.  The program then prompts the user to search for song titles that were just
//				loaded and stored in the linked list and hashtable.  The program searches for the song title and informs the
//				user of how many searches and number of comparisons done by each the linked list and hashtable.



//Include files
#include<Windows.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>



//disables a warning to allow the use of depreciated functions
#pragma warning(disable: 4996)



//Constants
#define kOne 1
#define kTrue 1
#define kFalse 0
#define BUCKETCOUNT 127
#define kMemSize 200


//structure
typedef struct songInfo 
{
	char artist[kMemSize];
	char songTitle[kMemSize];
	struct songInfo *next;

} songInfo;


void copyContents( char buffer[], char finalString[] );
void addFileExtension( char *p, char buffer[], char finalString[]);
void replaceAllDashesAndDots( char string[] );
unsigned long hashKeyGenerator(char* string);
void addNameHash(char artist[], char song[], int index, songInfo *hashTable[]);
songInfo *addNameSortedLL(char artist[], char song[], int index, songInfo *head);
int searchNameHash(char song[], int index, songInfo *hashTable[], int *foundFlag);
void removeNewLine( char userInput[] );
int searchNameSortedLL( char song[], int index, songInfo *head, int *foundFlag);
void delete_infoHash(songInfo *hashTable[] );
void delete_info (songInfo *head);