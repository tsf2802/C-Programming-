// In class exercise for reading and writing binary files
// (C) Larry Kiser April 26, 2021

// Submission -- create directory binary_io at the top
// of your repo and submit this one file by the end of class on May 5th.

// Build instructions:
// gcc -g -Wall -o main main.c
// to run: ./main

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #defines and function prototypes normally go in header files
#define MAX_BUFFER (19)


// struct definitions normally go in header files!
// located here for demo purposes
struct binary_demo{
	char name[MAX_BUFFER + 1] ;
	int  value ;
} ;

//  functions go here
//
// This reads the passed file containing one bianary_Demo struct
// returns 0 on success and 1 on failure.
int read_binary_file( char *file_name){
	struct binary_demo record;
	record.name[0] = '\0';
	record.value= 0;
	int status =1;

	FILE *input_file = fopen (file_name, "rb" );
	if (input_file){
		printf("\n File opened for read  binary %s\n", file_name);
		fread(&record, sizeof(record),1,input_file);
		printf("\nrecord count %d, name %s, value %d\n",record_count,  record.name,  record.value);
		fclose(input_file);
		status =0;
	}
	return status;
}
int main( int argc, char *argv[] ){
	//assuming that a filename is provided as an argument
	FILE *output_file = fopen (argv[1], "wb");
	struct binary_demo name_record;
	char *p_name = malloc(MAX_BUFFER +1);
	memset( &name_record, '?', sizeof(name_record));
//	char *name2 = "input test 2";
	//one instance of struct, initualize two fields in it
//	strcpy(name_record.name, "swen-250");
	strcpy(p_name, "malloc demo");
	name_record.value = 0x30;
//	strcpy(name_record.name, p_name);
	memcpy(name_record.name, p_name, MAX_BUFFER +1);
	free(p_name);

	if(output_file){
		int count =fwrite( &name_record , sizeof(struct binary_demo), 1, output_file);
		if(count != 1){
			printf("\nFailure writing output filke\n");
		}
		fclose(output_file);
		read_binary_file(argv[1]);
	}else{
		printf("\nCould not open %s for write\n", argv[1]);
	}
	
	return 0 ;
}
