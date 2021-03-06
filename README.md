# dsA2
compare the efficiency of searching a linked list and a hash table.

DS Assignment #2

For this assignment, you will compare the efficiency of searching a linked list and a hash table.

You should use your code for Assignment #1 for this (but you are not required to do so; you can come up with a variation of what you submitted for Assignment #1 if you wish).

Requirements

You should load at least 1000 MP3 files. It is OK if you share MP3 files with classmates for this (since you're not submitting them).

Modify your loop that loads the artist / title pairs into the linked list so that it ALSO puts that data into a hash table.

Make that hash table 127 buckets in size.  Make each linked list found in the hash table buckets a sorted linked list. Make the song title the key for the hash function. Use the djb2 hash function (not the revised one; you can change the parameter a char * instead of unsigned char *) to generate the key value.  Call djb2 from within your hash function, converting the key value to the hash value using the division method.

Create a linked list search function so that it displays one of the following messages once the search is done:

"title was found in the list in number comparisons", where title is the song title being searched for, list is either "linked list" or "hash table bucket" and number equals the number of times that stricmp was called 
"title was NOT found in the list in number comparisons"
Set up a loop in main that then prompts the user for a song title and does a search (using your linked list search function) for the song title in both the linked list and the hash table bucket. Quit the loop when the user enters "." as the only thing on the input line.

Once finished the loop, display the total number of searches, the total number of comparisons done by the linked list, and the total number of comparisons done by the hash table.

Clean up all allocated memory before exiting.

Other Requirements

Design your linked list code so that you do not have to duplicate code between the hash table and linked list code. 

Your program must compile without warnings. If you have to use a #pragma as stated in the C course notes in order to get rid of the Microsoft-specific warnings, you should do so.

Your executable must be named dsA2.exe (renamed to dsA2.x for handing in).

The source file that contains your main() function must be called dsA2.c or dsA2.cpp. Put all hash table-related code in hash.c or hash.cpp.  Put all linked list-related code in linkedlist.c or linkedlist.cpp (and linkedlist.h if you are using a class).  If you want to create other source files, name them appropriately.

Remember to put appropriate header comments at the top of ALL source files.

Create a JPG file called compare.jpg that contains a screenshot of your program running with a full screen of sample output (so that we can see the difference in comparison count between the two methods for several tries). Make sure that it includes the final summary output.

Your code must meet the code standards specified in class, this semester and in the C course last semester. If you did not take the C course, it is your responsiblility to read the C course notes and C assignment requirements so that you know what is expected. 

Submit your source code, executable, and compare.jpg to the appropriate dropbox. Yes, there is one additional file beyond what is normally required.

Hints

You should unit test your functions.  You should not leave your unit testing code in your submitted source.

You can use the examples provided on the DS website and C website as long as you attribute credit in a comment. You must attribute credit for the djb2 hash function.

You can use either C or C++. Do not use C++ language features that you are not comfortable with.
