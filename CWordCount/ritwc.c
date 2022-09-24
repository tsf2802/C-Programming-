#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define FALSE (0)
#define TRUE  (1)

int main() {
	int tot_chars = 0 ;	/* total characters */
	int tot_lines = 0 ;	/* total lines */
	int tot_words = 0 ;	 
	int pointer =0;
	int prevint= -1;
	while ((pointer = getchar()) !=EOF){
		tot_chars++;
		if(pointer == 10){
			tot_lines++;
		}
		if (prevint == -1){
			prevint= pointer;
		}else{
			if(pointer ==10 || pointer ==32){
				if (prevint!= 32 &&prevint!=10){
					tot_words++;
				}
			}
			prevint=pointer;
		}

	}
	printf(" %d",tot_lines);
	printf("  %d",tot_words);
	printf(" %d",tot_chars); 
	printf("\n");
	return 0 ;
}
