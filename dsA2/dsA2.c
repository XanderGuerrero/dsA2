//FileName:		dsA2.c
//Project:		dsA2
//Author:		Alex Guerrero	
//Date:			January 30, 2014
//Description:	This program takes a user inputted argument containing a directory.  
//				The program processes the string to make it a viable directory path to search for all
//				mp3 files in that directory.  The program then prompts the user to search for song titles that were just
//				loaded and stored in the linked list and hashtable.  The program searches for the song title and informs the
//				user of how many searches and number of comparisons done by each the linked list and hashtable.



//include file
#include"dsA2.h"



int main(int argc, char* argv[])
{
	//variables for use in the program initialized
	char finalString[kMemSize] = {0};
	char buffer[kMemSize] = {0};
	char string[kMemSize] = {0};
	char *p = NULL;
	char artist[kMemSize] = {0};
	char song[kMemSize] = {0};
	char userInput[kMemSize] = {0};
	int count = 1;
	int numLLComparisons = 0;
	int numHashComparisons = 0;
	int numSearches = 0;
	int c = 0;
	int skip = 0;
	songInfo *hashTable[BUCKETCOUNT] = {0};
	songInfo *head = NULL;
	WIN32_FIND_DATA fileData = {0};
	HANDLE h = NULL;
	int TotalNumHashComparisons = 0;
	int TotalNumLLComparisons = 0;
	int foundFlag = 0;
	char size = 0;
	unsigned long index = 0;
	int exit = 0;

	//if agrument count is only 1 or no argument is detected
	//display error message and set exit to 1
	if( argc == kTrue || argc == kFalse )
	{
		exit = 1;
		printf("Error: Usage dsAssignment1<directory...>\n");
	}
	else
	{
		//While loop to control program flow
		while( argv[ count ] != '\0' )
		{	
			//copy argument string into buffer
			strcpy( buffer, argv[ count ] );
			//if the buffer is empty, display message to the user
			//break out of the loop and try next directory
			if( buffer == NULL )
			{
				printf("String not copied\n");
				break;
			}

			//copy buffer contents to final string using the copyContents
			//ex.will copy C:\temp and create C:\\temp in finalString
			copyContents( buffer, finalString );

			//String is passed to addFileExtension to add the .mp3
			//extension
			addFileExtension( p, buffer, finalString );

			//will contain a proper directory name parameter
			//ex.C:\\temp\\*.mp3
			h = FindFirstFile( finalString, &fileData );
			if( h == INVALID_HANDLE_VALUE )
			{
				printf("nope no file found\n");
			}
			else
			{
			//Once the string has been prepared for file searching, it is passed to fileSearchAttachToList()
			//variables initialzed
			//function used to find file information passing handle to h
				//While .mp3 file data was found
				while( h != INVALID_HANDLE_VALUE )
				{
					//This section of code allocates space in memory for string and copies the filename found
					//by findFirstFile into string.  The length of string is calculated and the file name is processed
					//to determine if any dashes or dot's appear in the file name.  Id they do, they are replaced with 
					//spaces.  
					//The size of string is determined and assigned to size, which is used to allocate space in memory for 3 three strings
					//to hold the artist name, song title and mp3 file extension
					strcpy( string, fileData.cFileName );
					replaceAllDashesAndDots( string );

					//This section of code, sscans the string and places the artist name, song title into
					//the 2 strings artist and song found in main.
					//flush the contents of stdin and calculate the index, add the words to the linked list and
					//hashtable
					sscanf( string, "%s %s", artist, song );
					fflush(stdin);
					index = hashKeyGenerator( song );
					head = addNameSortedLL(artist, song, index, head);
					addNameHash(artist, song, index, hashTable);

					//if couldnt find anymore files, set h to invalid handle value and exit loop
					if ( !FindNextFile( h, &fileData ))
					{
						FindClose(h);
						h = INVALID_HANDLE_VALUE;
						break;
					}
				} 
			}
			//Increment the argument count and proceed to find next directories mp3 files
			++count;
			//If there are no more arguments on the command line, list the linked list
			//information, free allocated memory and break out of final loop
			//to exit the program
			if(argv[count] == NULL)
			{
				break;
			}
		}
	}
	
	//enter while loop and prompt user for song title to search while there is something to search for
	while(kOne && exit == 0 )
	{
		printf("Enter a song to search the database and press enter.\n");
		printf("To quit searching for song titles, press the '.' key\n\n");
		fgets(userInput, 20, stdin);
		//if input is empty, inform user
		//if input is a '.' stop prompting for more word searches and exit
		if(userInput[kFalse] == '.')
		{
			break;
		}
		printf("\n");
		if(userInput == NULL)
		{
			printf("Input not recieved\n");
		}
		//null the string
		string[kFalse] = '\0';
		//remove newline from fgets and place string into string variable for function
		removeNewLine( userInput );
		sscanf(userInput, "%s", string );
		//calculate index
		index = hashKeyGenerator( string );

		//search sorted linked list and return number of comparisons
		numLLComparisons = searchNameSortedLL( string, index, head, &foundFlag );
		if( foundFlag == kTrue )
		{
			printf("%s was found in the %s in %d comparisons\n", string, "LinkedList", numLLComparisons );
		}
		else 
		{
			printf("%s was NOT found in the %s in %d comparisons\n", string, "LinkedList", numLLComparisons );
		}
		//reset foundflag to 0
		foundFlag = kFalse;
		//search sorted linked list and return number of comparisons
		numHashComparisons = searchNameHash( string, index, hashTable, &foundFlag );
		if( foundFlag == kTrue )
		{
			printf("%s was found in the %s in %d comparisons\n", string, "HashTable Bucket", numHashComparisons );
		}
		else 
		{
			printf("%s was NOT found in the %s in %d comparisons\n", string, "HashTable Bucket", numHashComparisons );
		}
		printf("\n");
		//reset foundflag to 0
		foundFlag = kFalse;
		//incremement number of searches
		++numSearches;
		//total num of comparisons
		TotalNumLLComparisons = TotalNumLLComparisons + numLLComparisons;
		TotalNumHashComparisons = TotalNumHashComparisons + numHashComparisons;
	}

	//if there were arguments on the command line exit is 0, so display number of searches and number of comparisons for both.
	if( exit == 0 )
	{
		printf("searches performed: %d\n", numSearches);
		printf("LinkedList had a total of %d comparisons\n", TotalNumLLComparisons);
		printf("HashTable had a total of %d comparisons\n\n", TotalNumHashComparisons);
		//free memory
		delete_info( head );
		delete_infoHash( hashTable );
	}

	return 0;
}