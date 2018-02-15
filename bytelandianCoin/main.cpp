#include <stdlib.h>
#include <stdio.h>

#define ARR_SIZE 500000

unsigned long int arr[ARR_SIZE] = {0};
 
unsigned long int fn(unsigned long int n)
{
    unsigned long int sum = 0;
    unsigned long int retval = 0;
    
	if(n < 12)
		return n;
	if(n == 12)
		return 13;
	if(n < ARR_SIZE)
		if(arr[n] != 0)
			return arr[n];
    
    sum = (n/2) + (n/3) + (n/4);
    if(sum > n)
    {
        sum = fn(n/2) + fn(n/3) + fn(n/4);
        retval = sum;
    }
    else
        retval = n;

	if(n < ARR_SIZE)
	   arr[n] = retval;

   return retval;
}
 
int main(void) 
{
    char* a= NULL;
    char* endptr = NULL;
    size_t len = 0;
    unsigned long int n;
    
    while(getline(&a, &len, stdin) != -1)
    {
        n = strtol(a, &endptr, 10);
        printf("%ld\n", fn(n));
    }
}
