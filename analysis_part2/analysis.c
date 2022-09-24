// Document Analysis project functions for Part 2

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "analysis.h"
#include "unit_tests.h"

// Helper function for read_file to validate inputs.
static FILE *validate_read_file_parameters( struct linked_list *p_list, char *file_name )
{
	if ( p_list == NULL || file_name == NULL || *file_name == '\0' )	// if NULL list or if a bad or empty file name string return 0
		return 0 ;
	
	return fopen( file_name, "r" ) ;
}



// First checks that p_list is not NULL. Returns 0 if p_list is a NULL pointer.
// Then checks that word pointer is not NULL and word is not any empty string.
// Returns 0 if either of the above tests on the passed word fails.
//
// Creates the list if starting a fresh list.
// Searches existing list for a match on the word. Increments word count
// if found. If not found adds the word in alphabetic order.
// Returns 1 if the word was added successfully.
// Returns 0 on failure.
// NOTE -- this function makes no assumption on upper or lower case. That is handled by read_file.
// For simplicity all words passed from the unit tests are all lower case only.
int process_word ( struct linked_list *p_list, char *word )
{	
	int find_result = find_word(p_list,word);
	if( p_list == NULL || word ==NULL || *word =='\0' ){
		return 0;
	}
	if(find_result ==1){ 
		p_list->p_current ->one_word.word_count++;
		return 1;
	}
	if(p_list ->p_current ==p_list ->p_tail){
		add_node_after_current(p_list,word);
		return 1;
	}
	if(p_list ->p_current == p_list-> p_head){
		add_node_after_current(p_list,word);
		return 1;
	}
	add_node_after_current(p_list,word);
	return 1;
}

// First checks that the passed string with the file name is not a NULL pointer and is not an empty string.
// Also checks that the passed pointer to the linked_list struct is not a NULL pointer.
// Returns 0 if any of the above tests fail.
// returns 0 if the file cannot be read or if the file does not contain any words as defined for this project.
// returns the number of words if the file was found, opened successfully, and it contained at least one valid word.
// NOTE -- this function MUST convert all words read to lower case only! e.g "First" becomes "first"
int read_file( struct linked_list *p_list, char *file_name )
{
	if(p_list == NULL ||file_name  == NULL || *file_name == '\0'){
		return 0;
	}
	FILE *input_file = validate_read_file_parameters( p_list, file_name ) ;
	if ( input_file == NULL ){
		return 0 ;
	}
	// Now read and process the entire file.
	char one_char ;
	char buffer[ MAX_WORD + 1 ] ;
	int index = 0 ;
//	int in_a_word = 0 ;
	int word_count = 0 ;	
	for ( one_char = fgetc( input_file ) ; one_char != EOF ; one_char = fgetc( input_file )){
		if( (one_char =='\n' && index!=0 )||one_char ==' '){

			buffer[index] = '\0'; 
			if(process_word(p_list, buffer) ==1){
				word_count++;
			}
			index =0;
		}else{
			// in_a_word = (int)  one_char;
			
		// 65 90 97 122 ascii
			if(one_char != '\n' && isalpha(one_char) ){
				buffer[index] = tolower(one_char) ;
				index++;
			}
		}
	}
	// Process all of the characters in the file one at a time.
	buffer[index] = '\0';
	process_word(p_list,buffer);
	fclose( input_file ) ;
	return word_count ;
}

// Returns 0 in the word_count field if the p_list pointer is NULL.
// Returns 0 in the word_count field if no first word meaning p_head == NULL (empty list).
// Otherwise, returns a struct with the first unique word and its number of occurrences in the text file.
struct word_entry get_first_word( struct linked_list *p_list ){
	struct word_entry entry ;
	if( p_list ==NULL || p_list->p_head == NULL){
		entry.word_count = 0 ;		// cover empty list case.
		return entry;
	}
	entry = p_list->p_head->one_word;
	p_list->p_current = p_list->p_head;
	return entry ;
}

// Returns 0 in the word_count field if p_list is NULL.
// Returns 0 in the word_count field if no next word (previously reached end of list or it is an empty list).
// Otherwise, returns a struct with the next unique word and its number of occurrences in the text file.
struct word_entry get_next_word( struct linked_list *p_list )
{
		
	struct word_entry entry;
	if( p_list == NULL || p_list->p_current ==NULL|| p_list->p_current->p_next ==NULL){
		entry.word_count=0;
		return entry;
	
	}
	entry = p_list->p_current->p_next->one_word;
	p_list->p_current = p_list->p_current->p_next;
	return entry;	
}

// Returns 0 in the word_count field if no previous word (was already at beginning of the list or it is an empty list).
// Otherwise, returns a struct with the previous unique word and its number of occurrences in the text file.
struct word_entry get_prev_word( struct linked_list *p_list ){
	struct word_entry entry ;
	//completely empty list, a empty list, beginning of list so no previous
	if(p_list ==NULL|| p_list->p_head == NULL|| p_list->p_head == p_list->p_current){
		entry.word_count =0;;
		return entry;
	}
	entry  = p_list ->p_current->p_previous->one_word;
	p_list->p_current = p_list->p_current->p_previous;
	return entry ;
}

// Returns 0 in the word_count field if the p_list pointer is NULL.
// Returns 0 in the word_count field if no last word meaning p_tail == NULL (empty list).
// Otherwise, returns a struct with the last unique word and its number of occurrences in the text file.
struct word_entry get_last_word( struct linked_list *p_list )
{
	struct word_entry entry ;
	if(p_list ==NULL || p_list->p_tail == NULL){	
		entry.word_count = 0 ;		// cover empty list case.
		return entry ;
	}
	entry = p_list->p_tail->one_word;
	p_list->p_current = p_list->p_tail;
	return entry;
}

// First check the p_list is not NULL. Return 0 if it is NULL.
// Return 0 if the list is empty (e.g. p_head is NULL).
// Writes the sorted unique word list to a csv file.
// Receives the linked list pointer and the name of the file to be created.
// Returns 1 on a successful write of the file.
// Returns 0 on any failure.
// Test for a NULL or empty string in the file_name. Return 0 for failure if NULL or empty.
// Be sure to test for failure to open the file, failure to write to the file, and failure to close.
// You must have a header row exactly like this (without the quotes): "word,count"
// You must have one row for each unique word and its count (e.g. without quotes "student,5").
// It must be in sorted order and must be the complete list.
int write_unique_word_list_to_csv_file(  struct linked_list *p_list, char *file_name )
{
	int status = 0 ;
	
	if ( p_list == NULL || p_list->p_head == NULL || file_name == NULL || *file_name == '\0' )
		return status ;
	
	FILE *out_file = fopen( file_name, "w" ) ;
	fputs("word,count", out_file);
	fputs("\n", out_file);
//	fprintf(file_name, "%s,%d", get_first_word(p_list),);
	if ( out_file != NULL)	{
		struct node * ptr = p_list->p_head;
		while(ptr  != NULL){
			fputs(ptr->one_word.unique_word, out_file);//word
			fputs(",", out_file);// comma
			fprintf(out_file, "%d", ptr->one_word.word_count);
			fputs ("\n", out_file);
			ptr = ptr ->p_next;
		}
		fclose( out_file ) ;
		return 1;
	}

	return 0;
}
