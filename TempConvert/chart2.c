#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main (){
	int count=0;
	int getto =16;
	int currFar =0;
	float celc =0;
	float celcsub =0;
	printf("Fahrenheit-Celsius\n");
	
	while(count<getto){
		printf("%6d",currFar);
		printf("	");
		celcsub=(currFar-32);
		celc=celcsub*5/9;
		printf("%9.1f",celc);
		printf("\n");
		currFar=currFar+20;
		count++;
	}	
	
}	

