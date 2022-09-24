// Document Analysis project linked list functions
// L. Kiser Feb. 20, 2018

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "linked_list_functions.h"
#include "unit_tests.h"


// Implement this function first to create an initialized linked list node.
// It must allocate space for the passed string in the one_word structure.
// It must copy the passed string into that structure and sets its word count to 1.
// Assume that the passed word points is not NULL and is not an empty string.
// The calling function is responsible for passing a valid string.
// This function returns a pointer to the allocated node.
struct node *create_node( char *word )
{
	int count = strlen(word);
	struct node *nodepoint = malloc(sizeof(struct node));
	nodepoint->one_word.unique_word = malloc (count+1);
	strcpy(nodepoint->one_word.unique_word,word);

	nodepoint->one_word.word_count =1;
	nodepoint->p_previous =NULL;
	nodepoint->p_next= NULL;

	return nodepoint;	
}

// Inserts a node at the beginning of the linked list.
// Updates the passed set of pointers as needed based upon the addition that was done.
//
// It checks that p_list is not NULL. Checks that word is not NULL and is not an empty string. 
// Returns 0 for failure if either word test fails.
// Also on failure no change is made to the pointers in p_list.
//
// On success it returns a 1 and updates at least the passed p_head and p_current members of p_list.
// p_head and p_current will always point to the newly added node.
// When adding the first node to an empty list p_tail will also point to this same new node since it is the only node.
//
// Hint: use the create_node function to actually create the node.
// Hint: be sure to maintain both the p_previous and p_next pointers in each node.
int add_node_at_head( struct linked_list *p_list, char *word )
{
	if(p_list ==NULL || word ==NULL || *word =='\0'){
		return 0;
	}else{
		struct node *adding = create_node(word);
		if(p_list ->  p_head == NULL){
			p_list->p_current = adding;
			p_list->p_head = adding;
			p_list->p_tail = adding;
			return 1;
		}
	

		struct node *o = p_list->p_head;
		adding -> p_next =o;
		o->p_previous = adding;
		p_list -> p_current = adding;
		p_list -> p_head = adding;
		return 1;
	}
	
		
}

// For the passed linked_list pointer free all of the nodes in the list.
// Be careful to free the space for the string before freeing the node itself.
// Also be careful to save a copy of the pointer to the next item in the list before
// freeing the node.
// Lastly, return the number of nodes freed (which could be zero if p_list indicates an empty list).
int clear_linked_list( struct linked_list *p_list )
{
	/*
	int numberFreed =0;
	if(p_list->p_head == NULL){
		return 0; //has nothing so returns 0
	}
	struct node* list_pointer = p_list ->p_head; // a pointer to the head of the linked list
	struct node* temp_copy =NULL; //a temporary pointer for storage later
	
	while(list_pointer->p_next != NULL){
			numberFreed++;
			temp_copy=list_pointer->p_next;//copies the next node to keep
			free(list_pointer->one_word.unique_word);//freeing the space for string
			free(list_pointer);//free actual node
			list_pointer= temp_copy;
		
	}
	if(list_pointer->p_next == NULL && p_list->p_head != NULL){
		
			//exception when there is only 1
			
		numberFreed =1;
	}

	p_list->p_current =NULL;
	p_list->p_tail =NULL;
	p_list->p_current= NULL;
	return numberFreed ;	// REMOVE THIS and replace with working code
	*/
	
	//REDO
	
	if (p_list->p_head ==NULL ){
		return 0; //the head( first thing) is null so without a doubt, this returns 0
	}
	struct node* list_pointer = p_list->p_head;
	struct node* temp = NULL;
	bool complete= false;
	int clear_num=0;

	while(!complete){
		clear_num++;
		
		if(list_pointer->p_next != NULL){
			
			temp = list_pointer->p_next;
			free(list_pointer-> one_word.unique_word);
			free(list_pointer);
			list_pointer = temp;
		}else{
			list_pointer =NULL;
			complete = true;
		}
	}
	p_list->p_head = NULL;
	p_list->p_tail = NULL;;
	p_list->p_current =NULL;
	return clear_num;
}


// Inserts a node after the current pointer in the linked list.
// Updates the passed set of pointers as needed based upon the addition that was done.
//
// It checks that p_list is not NULL. Checks that word is not NULL and is not an empty string. 
// Returns 0 for failure if either word test fails.
// Also on failure no change is made to the pointers in p_list.
//
// On success it returns a 1 and updates at least the p_current member of p_list. p_current points to the newly added node.
// p_head is updated only if p_current is NULL (an empty list).
// p_tail is updated only if the new node is at the end of the list.
// When adding the first node to an empty list p_tail will also point to this same new node since it is the only node.
//
// Hint: use the create_node function to actually create the node.
// Hint: be sure to maintain both the p_previous and p_next pointers in each node.
// Hint: if this function is called with a p_current that is NULL (meaning the list is empty)
//       use the add_node_at_head function to create the new node.
int add_node_after_current( struct linked_list *p_list, char *word )
{	
	if(p_list ==NULL || word ==NULL || *word == '\0' ){
		return 0;// returns 0 for failure and no change
	}
	if(p_list->p_current == NULL){
		add_node_at_head(p_list, word);
		return 1;
	}else{
		struct node *setter = p_list->p_current->p_next ;
		struct node *cur_point = p_list->p_current;
		struct node *adder = create_node(word);
	
		if(cur_point->p_next == NULL){
			// if the next node is NULL
			cur_point = p_list->p_current;
			adder->p_previous = cur_point;
			p_list->p_tail = adder;
			p_list -> p_current->p_next = adder;
			p_list->p_current = adder;
			return 1;
		}
		cur_point = p_list->p_current; 
		adder->p_previous = cur_point;
		adder->p_next = setter;
		adder->p_next->p_previous = adder;
		p_list->p_current->p_next = adder;
		p_list->p_current = adder;
		return 1;
	}
	return 0;
	
}

// Searches the linked list for the passed word.
// NOTE -- this function REQUIRES that the linked list has been maintained in English language alphabetical order.
// Definition of match: every letter must match exactly including by case.
// e.g. "A" does NOT match "a". "a " does NOT match "a"
//
// If found it sets the current pointer to the matching node.
// If not found it returns a failure and sets the current pointer to the node just before the
// insertion point (by alphabetic order). Note the special case for a new word that goes at the
// beginning of the list. See the examples below.
//
// Hint: use strcmp to determine sorting order.
//
// If it is found the current pointer is set to the node containing the matching word.
// If it is found this function returns a 1 to indicate success.
//
// If it is not found the current pointer is set to the node just before the insertion point.
// If it is not found the function returns a 0 to indicate failure.
// e.g. the list contains the words "apple", "buy", "cat".
//      Searching for "baby" would set current to the node containing "apple".
//      Searching for "acid" would set current to NULL to indicate that "acid" belongs at the head.
//      searching for "zebra" would set current to the node containing "cat".
//
// Tests on p_list and word: p_list, p_list->head, and word must all not be NULL.
// In addition, word must not be an empty string.
// We must have a valid list with at least one node and we must a valid word to match.
// If any of these conditions are violated this function returns a -1 to indicate invalid input.
int find_word( struct linked_list *p_list, char *word ){
	if(word== NULL||*word =='\0'||p_list == NULL|| p_list->p_head == NULL){
		//returns failure on the cases tbat word and plist are null (which are the only -1 conditions)
		return -1;
	}else{
		struct node *parsing_pointer  = p_list->p_head;
		while(parsing_pointer != NULL){
			//comparing  the word
			if(strcmp( parsing_pointer->one_word.unique_word , word) ==0){
				//string is equal moment
				p_list->p_current = parsing_pointer;
				return 1;
			}
			//iterator
			parsing_pointer = parsing_pointer->p_next;
		}
		//after the loop, this is the result of words not found  in the  list
		//find the current node to set (another loop and then p_list->p_current =  whatever pointer
		parsing_pointer = p_list->p_head; //pointer reset
		bool headstuff =false;
		while( parsing_pointer != NULL ){	
			int curr = strcmp(parsing_pointer->one_word.unique_word, word);
				if ( curr > 0 ){
					if ( headstuff== false ){
						p_list-> p_current = NULL;
						return 0;	
					}else{
						p_list->p_current = parsing_pointer->p_previous;
						return 0;
					}
				}
				if (curr < 0 && parsing_pointer->p_next == NULL){
					p_list->p_current = p_list->p_tail;
					return 0;
				}
			headstuff= true;
			parsing_pointer = parsing_pointer->p_next;
		}
		return 0 ;

	} 
	return -1;
}

