/****
 * Functions for the DMV customer scheduling and service application.
 * Implementation file.
 ****/
#include <stdio.h>
#include <stdlib.h>
#include "dmv_schedule.h"
#include <stdbool.h>
/*
 * Actual definition of the line array of service lines.
 */
struct service_line line[NLINES] ;

/*
 * Initialize the service lines so that (a) line[0] has priority 'A'
 * through line[2] having priority 'C' and (b) there are no customers
 * in any line.
 * NOTES: As usual, an empty list is signified by a NULL pointer.
 */
void init_service_lines() {
	line[0].priority = 'A';
	line[1].priority = 'B';
	line[2].priority = 'C';
}

/*
 * Return the next ticket number.
 * 	The first customer gets ticket number 1.
 *	The number increases by 1 on each call.
 * Local (static) int ticket holds the current ticket value.
 */
static int ticket = 1 ;
int next_ticket() {
	
	return ticket++;	// Placeholder for your code.
}

/*
 * A new customer arrives with the given <priority> and
 * <ticket_number>. The customer is placed at the end of
 * the appropriate service line.
 */
void new_customer(char priority, int ticket_num) {
	struct customer* entryBoi = malloc(sizeof(*entryBoi));
	entryBoi->ticket_number=ticket_num;
	bool next = false;
	if(priority== 'A'){
	struct customer* workp = line[0].head_of_line;
		if(line[0].head_of_line ==  NULL){//noone in line
			line[0].head_of_line = entryBoi;
		}else{
			//a pointer of customer
			while(next == false ){
				if( workp->next_customer != NULL){
					workp = workp->next_customer;
				}else{
					workp-> next_customer = entryBoi;
					next=true;
				}
				
			}
			

		}
	}
	if(priority == 'B'){
	struct customer* workp = line[1].head_of_line;
		if(line[1].head_of_line ==  NULL){//noone in line
			line[1].head_of_line = entryBoi;
		}else{
			//a pointer of customer
			while(next == false ){
				if( workp->next_customer != NULL){
					workp = workp->next_customer;
				}else{
					workp-> next_customer = entryBoi;
					next=true;
				}
				
			}
			

		}
	}
	if(priority == 'C'){
	struct customer* workp = line[2].head_of_line;
		if(line[2].head_of_line ==  NULL){//noone in line
			line[2].head_of_line = entryBoi;
		}else{
			//a pointer of customer
			while(next == false ){
				if( workp->next_customer != NULL){
					workp = workp->next_customer;
				}else{
					workp-> next_customer = entryBoi;
					next=true;
				}
				
			}
			

		}
	}
}

/*
 * Return the ticket number of the first customer in the
 * line for <priority> after removing the customer from the
 * associated service_line.
 *
 * Return NO_CUSTOMER if there are no customers in the indicated line.
 */
int serve_customer(char priority) {
	
	int retnumber =0;

	if(priority == 'A'){
	//	customer_count('A');
		if(line[0].head_of_line == NULL){
			return NO_CUSTOMER;
		}
		struct customer* workp = line[0].head_of_line;
		retnumber = workp->ticket_number;
		line[0].head_of_line = workp->next_customer;	
		return retnumber;
	}
	if(priority =='B'){
		customer_count('B');
		if(line[1].head_of_line == NULL){
			return NO_CUSTOMER;
		}
		struct customer* workp = line[1].head_of_line;
		retnumber = workp->ticket_number;
		line[1].head_of_line = workp->next_customer;	
		return retnumber;
	
	}
	if(priority =='C'){
		if(line[2].head_of_line == NULL){
			return NO_CUSTOMER;
		}
		struct customer* workp = line[2].head_of_line;
		retnumber = workp->ticket_number;
		line[2].head_of_line = workp->next_customer;	
		return retnumber;

	}
	return retnumber;
}

/*
 * Return the ticket number of the first customer in the highest
 * priority line that has customers after removing the customer
 * from the line. 'A' is highest priority and 'C' is lowest.
 *
 * Return NO_CUSTOMER if there are no customers in any of the lines.
 *
 * Example: if there are 0 customers in the 'A' line, 3 customers in the 'B'
 *          line and 2 customers in the 'C' line, then the first customer in
 *          the 'B' line would be removed and his/her ticket number returned.
 */
int serve_highest_priority_customer() {

	if(customer_count('A') >0 ){
		return serve_customer('A');
	}else{
		if(customer_count('B')> 0){
			return serve_customer('B');
		}else{ 
			if(customer_count('C')>0){
				return serve_customer('C');
			}else{
				return NO_CUSTOMER;
			}
		}
	}
	return 0 ; // Placeholder for your code
}

/*
 * Return the number of customers in the service line for <priority>
 */
int customer_count(char priority) {
	int ret_number =0;
	
	if(priority == 'A'){
		struct customer* workp = line[0].head_of_line;
		//	printf("TICKETNUMS FOR A\n");
		while(workp != NULL){
		//	printf("TICKET NUMBERRRR %d\n", workp->ticket_number);
			ret_number++;
			workp = workp->next_customer;
		}
	
		return ret_number;
	}
	if(priority == 'B') {

		struct customer* workp = line[1].head_of_line;

		//	printf("ticketNUMS FOR B\n");
		while(workp != NULL){
		//	printf("TICKET NUMBERRRR %d\n", workp->ticket_number);
			ret_number++;
			workp= workp->next_customer;
		}
		return ret_number;
	}
	if(priority == 'C'){

		struct customer* workp = line[2].head_of_line;
		
	//	printf("ticketNUMS FOR C\n");
		while(workp != NULL){
	//		printf("TICKET NUMBERRRR %d\n", workp->ticket_number);
			ret_number++;
			workp = workp->next_customer;
		}
		return ret_number;
		
	}
	return ret_number;
}

/*
 * Return the number of customers in all service lines.
 */
int customer_count_all() {
	int totes= 0;
	totes += customer_count('A');
	totes += customer_count('B');
	totes += customer_count('C');
	return totes ; // Placeholder for your code.
}
