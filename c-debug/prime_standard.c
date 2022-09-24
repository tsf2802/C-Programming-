/* prime-number finding program
Originally by Norman Matloff, UC Davis
http://wwwcsif.cs.ucdavis.edu/~davis/40/gdb_Tutorial.htm
Modified by Mark Ardis, RIT, 11/1/2006

Will report a list of all primes which are less than
or equal to the user-supplied upper bound.
WARNING: There are bugs in this program! */

#include <stdio.h>

int primes[50];  /* Prime[i] will be 1 if i is prime, 0 otherwise.
		 The size of the array determines the bounds */  

int upper_bound; //limit to where to keep searching for primes

  /* checek_primes gets the array prime, and an int named given
  it sees if divider  divides given, for all values of divider which are
  themselves prime (no need to try divider if it is nonprime), and
  less than or equal to sqrt(given) (if given has a divisor larger
  than this square root, it must also have a smaller one,
  so no need to check for larger ones) */

void check_prime(int given, int primes[]){
  int divider;
  divider = 2;
  while (divider*divider<=given) {
    if (primes[divider] == 1){
      if (given % divider == 0)  {
        primes[given] = 0;
        return;
      } /* if (given % divider == 0) */
    } /* if (prime[divider] == 1) */
    divider++;
  } /* while (1) */

  /* if we get here, then there were no divisors of K, so it is prime */
  primes[given] = 1;
}

/*main first recieves the upper bound from the user,
 *then proceeds to loop to find all the prime
 *numbers until that input 
 */
int main(){
  int index;// index is later used in the for loop 
  printf("Enter upper bound:\n");
  scanf("%d", &upper_bound);
  primes[1] = 1;
  primes[2] = 1;
  for (index = 3; index <= upper_bound; index += 2) {
// check_prime is called in order to evaluate if the 
// current array index contains a prime number or not
    check_prime(index, primes);
    if (primes[index]) {
      printf("%d is a prime\n", index);
    } 
  } /* for (i = 3; i <= upper_bound; i += 2) */
  return 0;
} /* main() */
