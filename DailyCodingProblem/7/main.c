#include <stdio.h>
#include <string.h>
#include <stdint.h>

uint64_t fn(char *array, uint32_t len, uint32_t index)
{
	uint64_t single_count = 0;
	uint64_t double_count = 0;

	//base case
	if(index+1 >= len)
		return 1;

	//recursive case
	single_count = fn(array, len, index+1);
	if((array[index] == '1') || ((array[index] == '2') && (array[index+1] >= '0' && array[index+1] <= '6')))
	{
		double_count = fn(array, len, index+2);
	}

	return single_count + double_count;
}	


int main()
{
	char array[100];
	uint32_t len = 0;
	
	printf("Enter the number string: ");
	scanf("%s", array);

	len = strlen(array);
	
	printf("possible combinations: %ld\n", fn(array, len, 0));

	return 0;
}
