// in-class exercise 1
// Version 1 - Larry Kiser RIT June 2021
// Version 2 - Mitesh Parikh RIT Aug 2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Objective -- explore data types & bitwise operation.
//Submit to in-class 1 activity folder by due date in myCourses.


// Functions to print Binary
void bin_prnt_byte(int x_byte)
{
        int n;
        // Print Byte (8 bits)
        for(n=0; n<8; n++)
        {
                if((x_byte & 0x80) !=0)
                {
                        printf("1");
                }
                else
                {
                        printf("0");
                }
                if (n==3)
                {
                        //insert a space between nibbles
                        printf(" ");
                }
                x_byte = x_byte << 1;
        }

}

void bin_prnt_int(int x_word)
{
	int hi_byte;
	int lo_byte;

	// for top Byte.. shift right and logical AND 
	hi_byte = (x_word >> 8) & 0x00FF;
	// for low Byte .. just AND with 0x00FF
	lo_byte = x_word & 0x00FF;

	// Print hi-byte
	bin_prnt_byte(hi_byte);
	printf(" ");
	
	// Print lo-byte
	bin_prnt_byte(lo_byte);
}


int main( int arg_count, char *arg_list[] ){
        int result = 0 ;                // default to success
        unsigned char q1 =73;
        printf("Binary -> ");
        bin_prnt_byte(q1);
        printf("\nHexadecimal ->0x%x\n",q1);

	signed char q2 = -5;
	printf("\n\nBinary -> ");
	bin_prnt_byte(q2);
	printf("\nHexadecimal -> 0x%x\n",q2);

	unsigned char q3 = 0b11010110;
	printf("\n\nDecimal: %i ", q3 );
	printf("\nHexadecimal ->0x%x\n",q3);


	unsigned char a=26;
	unsigned char b= 55;
	char c=0;
	c=a & b;
	printf("\n hexadecimal -> 0x%x\n",c);	
        c= a |b;
	printf("\n hexadecimal -> 0x%x\n",c);
	c=a^b;
	printf("\n hexadecimal -> 0x%x\n",c);
	c = ~a;
	printf("\n hexadecimal -> 0x%x\n",c);
	c = a<<2;
	printf("\n hexadecimal -> 0x%x\n",c);
	c = a>>2;
	printf("\n hexadecimal -> 0x%x\n",c);
	 
	//check if the top bit is set in q3
	char check = q3>>7;
	if (check){
		printf("\ntopbit is set\n");
	}else{
		printf("\ntop bit is not set\n");
	}
       	return result ;
}

