/*
 * Implementation of the read_data module.
 *
 * See read_data.h for a description of the read_data function's
 * specification.
 *
 * Note that the parameter declarations in this module must be
 * compatible with those in the read_data.h header file.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "read_data.h"
#include <stdbool.h>


// Reads the three fields from lines such as W$1349$1.414$ into
// local variables using getchar().
// Converts the two numeric fields to numbers using atoi for the
// integer fields and atof for the double.
// Using a correctly defined set of parameters (use pointers) pass
// those values back to the program that called this function.
//

int location =0;

char intstorage[25];
char doublestorage[25];
void read_data ( char *first_char, int  *middle_int, double *end_double) {
	/* your declarations and statements REPLACE this comment */
	int ch;
	int location=0;
	int index=0;
	for(ch =getchar(); ch != '\n' && ch != EOF; ch =getchar()){
		if(ch == '$'){
			location++;
			index=0;
		}else{
			if(location == 0){
				//make first_char = ch;
				*first_char = ch;
			}else{
				if(location == 1){
					intstorage[index] = ch;
					index++;
					//stick this num to the middle int array
				}else{
					if(location ==2){
						doublestorage[index]=ch;
						index++;
						//stick this num to the end_double
					}
				}
			}
		}

	}
	//modify middleint with intstorage atoi, make equal to pointer
	*middle_int = atoi(intstorage);
	//modify end_doube with doublesrorage atof, make equal to pointer
	*end_double= atof(doublestorage);
	return ;
}
