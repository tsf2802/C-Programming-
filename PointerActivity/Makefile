test_pointers: main.o read_data.o
	gcc -o test_pointers main.o read_data.o 

main.o: main.c read_data.h
	gcc -c -Wall -g main.c 

read_data.o: read_data.c read_data.h
	gcc -c -Wall -g read_data.c read_data.h
clean: 
	rm *.o
	rm test_pointers
