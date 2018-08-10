#include <stdio.h>
#include <stdint.h>

uint64_t fn(uint64_t *array, uint32_t index, uint32_t len)
{
	uint64_t value_with = 0, value_without = 0;

	//base case
	if(index >= len) return 0;
	if(index == len-1) return array[index];

	//recursive case
	value_without = fn(array, index+1, len);
	value_with = fn(array, index+2,len);

	if(value_with + array[index] > value_without)
		return (value_with + array[index]);
	else
		return value_without;
}

int main()
{
	uint64_t array[100];
	uint32_t len = 0;
	uint32_t i = 0;

	scanf("%d", &len);

	for(i = 0; i < len; i++)
	{
		scanf("%ld", &array[i]);
	}

	printf("Max value = %ld\n", fn(array, 0, len));

	return 0;
}
