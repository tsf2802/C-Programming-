#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define MAX_BUFFER (30)

int main(int argc, char *argv[]){

//printf("%d\n", argc);
	
	
	if (argc != 3){
		printf("Not right amount of  arguments!");
	}else{
		
		FILE *input_file  = fopen(argv[2], "r" );
		FILE *output_file;
		char initialname[50] ;
		strcpy(initialname, argv[2]);
		char aftername[strlen(initialname-3)];
	//	printf("%d",strlen(initialname));
		int i=0;
		for(i ; initialname[i] != '.'; i++){
			aftername[i] = initialname[i];
		}
		aftername[i] = '\0';
	//	printf("%s\n",aftername); 
		
		
		
	//	int len = strlen(filename);
	//	filename[len-4] = '\0'; guess this doesnt work for substringggg, onto replace
		
		
	//	printf("argument %s", argv[1]);
		if(strcmp(argv[1], "-e")==0){
			//argv[2] = filename
		//	printf("encrypt");
		//	char addition[] =  "_enc.txt";
			char* newname = strcat(aftername, "_enc.txt");
		//	printf("%s name \n", newname);
			output_file =fopen(newname,"w");
			int next_char =0;
			if(input_file){
				while((next_char = getc(input_file)) != EOF){
					putc(next_char+100, output_file);
				}
				
			}
			fclose(input_file);
			fclose(output_file);
		}else{
			if(strcmp(argv[1], "-d")== 0){		
				char* newname = strcat(aftername,"_dec.txt");
				output_file = fopen(newname,"w");
				int next_char =0;
				if (input_file){
					while((next_char = getc (input_file)) != EOF){		
						putc(next_char-100, output_file);
					}
				}
				fclose(input_file);
				fclose(output_file);
			}
		}	
		
	}
}
