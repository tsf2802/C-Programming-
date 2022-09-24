/*
 * Implementation of functions that filter values in strings.
 *****
 * YOU MAY NOT USE ANY FUNCTIONS FROM <string.h> OTHER THAN
 * strcpy() and strlen()
 *****
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "filter.h"

#define NUL ('\0')

/*
 * YOU MAY FIND THIS FUNCTION USEFUL.
 * Return true if and only if character <c> is in string <s>.
 */
static bool includes(char c, char *s) {
	while( *s && c != *s ) {
		s++ ;
	}
	return c == *s ;
}

/*
 * YOU MAY ALSO FIND THIS FUNCTION USEFUL.
 * Return true if and only if string <pre> is a prefix of string <s>.
 */
static bool prefix(char *s, char *pre) {
	while( *pre && *s == *pre ) {
		s++ ;
		pre++ ;
	}
	return *pre == NUL ;
}

/*
 * Copy <string> to <result> while removing all occurrences of <ch>.
 */
void filter_ch_index(char string[], char result[], char ch) {
	int respoint =0;
	int strpoint =0;
	while(strpoint < strlen(string)){
		if(string[strpoint] != ch){
			result[respoint] = string[strpoint];
			respoint++;
		}
		strpoint++;

	}
	result[respoint] = '\0';
}

/*
 * Return a pointer to a string that is a copy of <string> with
 * all occurrences of <ch> removed. The returned string must occupy
 * the least possible dynamically allocated space.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *filter_ch_ptr(char *string, char ch) {
	char* p_copy =  malloc(sizeof(*string)+1);
	char* p  = p_copy;
	while(*string != '\0'){
		if(*string != ch){
			char c= *string++;
			*p =c;
			p++;
		}else{
			*string++;
		}
	}
	*p= NUL;
	char* p_final = malloc(strlen( p_copy)+1);
	strcpy(p_final, p_copy);
	free(p_copy);
	return p_final;
}

/*
 * Copy <string> to <result> while removing all occurrences of
 * any characters in <remove>.
 */
void filter_any_index(char string[], char result[], char remove[]) {
	int respoint =0;
	int strpoint =0;
	int rem =0;
	bool contains = false;
	while(strpoint< strlen(string)){
		while(rem < strlen(remove)){
			if(string[strpoint] == remove[rem]){
				contains = true;
			}
			rem++;
		}
		if(contains == false){
			result[respoint] = string[strpoint];
			respoint++;
		}
		contains = false;
		strpoint++;
		rem=0;
	}
	result[respoint]= '\0';
}

/*
 * Return a pointer to a copy of <string> after removing all
 * occurrrences of any characters in <remove>.
 * The returned string must occupy the least possible dynamically
 * allocated space.
 *****
 * YOU MAY *NOT* USE INTEGERS OR ARRAY INDEXING.
 *****
 */
char *filter_any_ptr(char *string, char* remove) {
	char* first_copy= malloc(sizeof(*string)+1);
	char* first = first_copy;
	while(*string != '\0'){//this loops the actual string
		char *remove_point = remove;
		bool found = false;
		while(*remove_point != '\0'  && found == false){// this loops through the remove array 
			if(*string == *remove_point){
				found = true;
			}else{
				*remove_point++;
			}
		}
		if( found == false){
			*first=  *string;
			first++;
		}
		*string++;
	}
	*first =NUL;
	char* p_final = malloc(strlen(first_copy)+1);
	strcpy(p_final, first_copy);
	free(first_copy);
	return p_final;
}

/*
 * Return a pointer to a copy of <string> after removing all
 * occurrrences of the substring <substr>.
 * The returned string must occupy the least possible dynamically
 * allocated space.
 *****
 * YOU MAY *NOT* USE ARRAY INDEXING.
 *****
 */
char *filter_substr(char *string, char* substr) {
	char* first_copy = malloc(sizeof(*string)+1);
	char* first = first_copy;
	while(*string != '\0'){
		char *substrcpy = substr;
		char *strcpy = string;
		bool is_sub= true;
		while(*substrcpy !=  '\0' && is_sub == true){
			if(*strcpy != *substrcpy ){
				is_sub = false;
			}
			*strcpy++;
			*substrcpy++;
		}
		if(is_sub == false){
			*first = *string;
			first++;
			*string++;
		}else{
			int index =0;
			while(index < strlen(substr) && *string!= '\0'){
				*string++;
				index++;
			}
		}
	}
	*first = NUL;
	char* p_final = malloc(strlen(first_copy)+1);
	strcpy(p_final, first_copy);
	free(first_copy);
	return p_final;
}
