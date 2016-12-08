//FileName:		hash.c
//Project:		dsA2
//Author:		Alex Guerrero	
//Date:			March 4, 2014
//Description:	This file contains the function definition for the hashKeyGenerator function and the djb function



//include file
#include"dsA2.h"



//FunctionName: unsigned long djb2( char *string ) 
//Author:		Dan Bernstein
//Description:  this function generates a key that is returned
//Parameters: char* string
//Return Values: unsigned long hash
unsigned long djb2( char *string )  
{ 
	unsigned long hash = 5381; 
	int c = 0; 

	//while element is not NULL
	while(( c = *string++ ) != '\0' ) 
	{
		//add up the value of each individual element
		hash = (( hash << 5 ) + hash ) + c; 
	}
	//return value calculated
	return hash; 
} 


//FunctionName: unsigned long hashKeyGenerator(char* string)
//Description:  this function generates a key value by using a value return fom djb2. The function then
//				calculates the index using the division method and returns and index
//				the index
//Parameters: char* string
//Return Values: int index
unsigned long hashKeyGenerator(char* string)
{ 
	//Variables
	int count = 0; 
	unsigned long hashValue = 0;
	int index = 0;
	int length = 0;

	//determine the length of string and assign to length
	length = strlen(string);
	hashValue = djb2( string );
	//add up the ascii value of each letter of the word and divide 
	//it by the bucketCount(11) to determine the has value and assign it to index
	//for(count = 0; count <= length; count++) 
	//{
	//	hashValue = hashValue + string[count];
	//}
	index = hashValue % BUCKETCOUNT;

	//return index
	return index; 
}