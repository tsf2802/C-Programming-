#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (){
	int count=0;
	int getto =16;
	int currFar =0;
	int celc =0;
	printf("Fahrenheit-Celsius\n");
	
	while(count<getto){
		printf("    %d",currFar);
		printf("	");
		celc=(currFar-32);
		celc=celc*5/9;
		printf("     %d",celc);
		printf("\n");
		currFar=currFar+20;
		count++;
	}
	
}	

