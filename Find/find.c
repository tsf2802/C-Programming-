/*
 * Implementation of functions that find values in strings.
 *****
 * YOU MAY NOT USE ANY FUNCTIONS FROM <string.h>
 *****
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "find.h"

#define NOT_FOUND (-1)	// integer indicator for not found.

/*
 * Return the index of the first occurrence of <ch> in <string>,
 * or (-1) if the <ch> is not in <string>.
 */
int find_ch_index(char string[], char ch) {
	bool string_end =false;
	int index =0;
	if (strlen(string) == 0){
		return NOT_FOUND;
	}
	while(!string_end){
		if (string[index]== ch){
			return index;
		}else{
			index++;
			if(string[index] == '\0'){
				string_end =true;
			}
		}
	}
	return NOT_FOUND ;	// placeholder
}

/*
 * Return a pointer to the first occurrence of <ch> in <string>,
 * or NULL if the <ch> is not in <string>.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_ch_ptr(char *string, char ch) {
	int check = find_ch_index(string,ch);
	if(check == NOT_FOUND){
		return NULL;
	}
	while(*string != '\0'){
		if(*string == ch){
			return &*string;
		}
		*string++;
	}
	return 	NULL;
}

/*
 * Return the index of the first occurrence of any character in <stop>
 * in the given <string>, or (-1) if the <string> contains no character
 * in <stop>.
 */
int find_any_index(char string[], char stop[]) {
	bool stop_end = false;
	bool string_end = false;
	int stop_index=0;
	int string_index= 0;
	if(strlen(string) == 0){
		return -1;
	}
	while(!string_end){
		while(!stop_end){
			if(string[string_index] ==  stop[stop_index]){
				return string_index;
			}else{	
				stop_index++;
				if(stop[stop_index] == '\0'){
					stop_end = true;
				}
			}
		}
		stop_index= 0;
		stop_end = false;
		string_index++;
		if(string[string_index] == '\0'){
			string_index= true;
			return -1;
		}
	}
	return -1;	// placeholder
}

/*
 * Return a pointer to the first occurrence of any character in <stop>
 * in the given <string> or NULL if the <string> contains no characters
 * in <stop>.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_any_ptr(char *string, char* stop){
	
	if(strlen(string) == 0){
		return NULL ;	// placeholder
	}
	while(*string != '\0'){
		char* indexer =  stop;
		while(*indexer != '\0' ){
			if(*string == *indexer){
				return &*string;
			}
			*indexer++;

		}
		*string++;
	}
	
}

/*
 * Return a pointer to the first character of the first occurrence of
 * <substr> in the given <string> or NULL if <substr> is not a substring
 * of <string>.
 * Note: An empty <substr> ("") matches *any* <string> at the <string>'s
 * start.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *find_substr(char *string, char* substr) {
	if(strlen(substr) == 0){
		return string;
	}
	bool same= true;	
	while(*string != '\0'){
		if(*string == *substr){
			char* newpointerstr = string;
			char* newpointersub = substr;
			while(same == true){
				*newpointersub++;
				*newpointerstr++;
				if(*newpointersub == '\0'){
					return &*string;
				}
				if(*newpointersub != *newpointerstr){
					same = false;
				}
			}
			same= true;
		}	
		*string++;
	}
		
	return NULL ;	// placeholder
}
