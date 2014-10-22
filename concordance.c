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
#include <string.h>	// for strtok(), strcmp, etc.
#define STRMAX 29	// used for maximum size for a word string. 28 is length
			// of longest non-coined non-technical English word.
#define DEBUG 1

/* Function prototypes */
int insert(char*, char*, int);
int bin_srch(char*, char**, int);
//void print(char *, int);
//void empty(char *, int);

int main(int argc, const char *argv[])
{
	const char delimiters[] = " .,;:!\"?\n";

	if ((argc < 2) || (argc > 3)) {
		printf("Usage: concordance table_size\n");
		return 1;
	}
	
	int table_size = atoi(argv[1]);	// Set table_size equal to value of 
					// first command-line arg, converting 
					// the string to int.

	printf("%i\n", table_size);
	
	char word_tbl[table_size][STRMAX];
	char *table[table_size];	// The word table should be implemented
					// as an array of pointers to strings.

	char *line = NULL;
	size_t length = 0;
	ssize_t read;
	char *word;

	int i = 0, n = 0;

	

	while ((read = getline(&line, &length, stdin)) != -1) {

		i++;
		printf("%i. %s", i, line);

		word = strtok(line, delimiters);

		while ((word != NULL) && (n <= table_size)) {
			printf("%s\n", word);
			n = insert(&word, &table, n);
			word = strtok(NULL, delimiters);
		}
	}
	free(line);
	
	return 0;
}

void print(char *table[], int n)
{
	// Prints Table in its entirety, which should be in sorted order.
}

void empty(char *table[], int n)
{
	/*
	 * emptys table by freeing all the strings currently stored in it and
	 * setting the string pointers back to NULL.
	 */
}

int insert(char *word, char *table, int n)
{
        /*
	 * Inserts the string word into table, which should be maintained in
	 * sorted order. Returns n+1 if the string is successfully inserted;
	 * otherwise returns n.
	 */
	
	/*
	 * The function insert() should first determine whether the given word 
	 * is already in table. If it is, then the word should not be inserted 
	 * and the function should simply return the current value of n. On the 
	 * other hand, if word is not in the table, then it should be inserted 
	 * into its proper position so that after the insertion is performed, 
	 * table maintains its sorted order. The function should then return 
	 * n+1, the new number of words in the table.
	 */

	char temp[STRMAX];

	if (!(bin_srch(*word, *table, n))) {
		if (n == 0) {
			for (i = 0; isalpha(*word[i]); i++) {
				temp[i] = tolower(*word[i]);
			}
			*table[0] = strndup(*temp, STRMAX);

			strdup;
			n++;
			printf("Stored %s at beginning", *word)
		} else if ((n % 2) == 1) {

	}
	} 


	
	
	//printf("insert: %s\n", *word);
	
	return n;
}

int bin_srch(char *word, char **table, int n)
{
	// Binary search to determine if word is in table.
	// returns an int expressing if the target value was found in the table
	// where: 0 = no, 1 = yes. This will be used in insert() to determine
	// if the target word should be inserted into the table.

	int result;

	if (n == 0) {		// if table is empty
		return 0;	// then it doesn't contain the target
	} else if (n == 1) {	// if the table consists of one element
		result = strncasecmp(*word, **table[0]); // case-insensitive comp.
		result = (result != 0);
		return result;
	} else {
		int lo = 0, hi = n-1, mid;
		while (lo <= hi) {
			mid = lo + (hi-lo)/2;
			result = strncasecmp(*word, **table[mid]);
			if (result == 0) {
				return 1;	// target found in table
			} else if (result < 0) {
				lo = mid + 1;
				continue;
			} else if (result > 0) {
				hi = mid - 1;
				continue;
			} else {
				return 0;	// target not in table
			}
		}
	}
}