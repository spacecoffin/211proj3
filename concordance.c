//
//  concordance.c
//
//  Reed Rosenberg
//
//  Builds a concordance from a piece of text.
//

#include <stdio.h>
#include <stdlib.h>	// for atoi()
#include <stddef.h>	// for sizeof()
#define STRMAX 29	// used for maximum size for a word string. 28 is length
			// of longest non-coined non-technical English word.
#define DEBUG 1

/* Function prototypes */
//int insert(char*, char*, int);

void print(char *Table[], int n)
{
	// Prints Table in its entirety, which should be in sorted order.
}

void empty(char *Table[], int n)
{
	/*
	 * emptys Table by freeing all the strings currently stored in it and
	 * setting the string pointers back to NULL.
	 */
}

int main(int argc, const char *argv[])
{
	if ((argc < 2) || (argc > 3)) {
		printf("Usage: concordance table_size");
		//exit pgm
	}
	
	//int table_size = atoi(argv[1]);	// Set table_size equal to value of
					// first command-line argument,
					// converting the string input to int.
	
	//char *Table[table_size];	// The word table should be implemented
					// as an array of pointers to strings.
	//char *word[
	
	int temp = getchar();
	
	#if DEBUG
	printf("%c", temp);
	#endif
	
	//insert();
	
	return 0;
}

int insert(char *word, char *Table[], int n)
{
        /*
	 * Inserts the string word into Table, which should be maintained in
	 * sorted order. Returns n+1 if the string is successfully inserted;
	 * otherwise returns n.
	 */
	
	/*
	 * The function insert() should first determine whether the given word 
	 * is already in Table. If it is, then the word should not be inserted 
	 * and the function should simply return the current value of n. On the 
	 * other hand, if word is not in the table, then it should be inserted 
	 * into its proper position so that after the insertion is performed, 
	 * Table maintains its sorted order. The function should then return 
	 * n+1, the new number of words in the table.
	 */
	int m=1;
	
	return m;
}