#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE sizeof(char)


void flip(char *val, unsigned int index, unsigned int *curr_open)
{
	char mask = 1 << index;                 
        int bit = ((*val) & mask) >> index;     
        if(bit)                                 
        {                                       
        	mask = ~mask;                   
                (*val) = (*val) & mask;         
                (*curr_open)--;                    
        }                                       
        else                                    
        {                                       
        	(*val) = (*val) | mask;         
                (*curr_open)++;                    
        }                                     

}


void fn(char *arr, unsigned int n, unsigned int *currOpenCount)
{
	if(n < SIZE)
		flip(&arr[0], n, currOpenCount);
	else
		flip(&arr[n/SIZE], n%SIZE, currOpenCount);
}

int main(void)
{
	unsigned long long int N;
	unsigned int K;
	char *tweetStatus = NULL;
	unsigned int curr_open = 0;
	char *input = NULL;
	unsigned long int memSize = 0;
	unsigned int tweetNum = 0;
	size_t a;

	if(getline(&input, &a, stdin) == -1)
		return -1;

	sscanf(input,"%lld %d",&N, &K);
	memSize = (N/SIZE) + 1;

	tweetStatus = (char*)malloc(memSize);
	if(input != NULL)
	{
		free(input);
		input = NULL;
	}
	
	while(K > 0)
	{
		if(getline(&input, &a, stdin) == -1)
		{
			break;
		}

		if(strcmp(input, "CLOSEALL\n") == 0)
		{
			curr_open = 0;
			memset(tweetStatus,0x0, memSize);
		}
		else
		{
			sscanf(input, "CLICK %d", &tweetNum);
			fn(tweetStatus, tweetNum, &curr_open);
		}
		
		printf("%d\n",curr_open);

		if(input != NULL)
		{
			free(input);
			input = NULL;
		}
		K--;
	}


	free(tweetStatus);
	return 0;
}

