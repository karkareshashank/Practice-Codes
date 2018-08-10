#include <stdio.h>
#include <string.h>

int main()
{
	char array[100];
	char output[100];
	int K = 0, len = 0, i = 0;
	int max = 0, start = 0,end  = 0;
	int currK = 0, temp_start = 0 , temp_end = 0;
	int count[26] = { 0 };

	printf("Enter string: ");
	scanf("%s", array);

	printf("Enter K: ");
	scanf("%d", &K);	

	len = strlen(array);

	while(temp_end < len)	
	{
		do{
			if(count[array[temp_end] - 'a'] == 0)
			{
				if(currK+1 > K)
					break;
				currK++;
			}
			count[array[temp_end] - 'a']++;
			temp_end++;
		}while(temp_end < len);

		if(temp_end - temp_start > max)
		{
			max = temp_end - temp_start;
			start = temp_start;
			end = temp_end;
		}

		while(temp_start < temp_end)
		{
			count[array[temp_start] - 'a']--;
			if(count[array[temp_start] - 'a'] == 0)
			{ 
				currK--;
				temp_start++;
				break;
			}

			temp_start++;
		}
	}	


	for(i = 0 ;i < max; i++)
	{
		output[i] = array[start + i];
	}
	output[i] = '\0';

	printf("output = %s\n",output);

	return 0;
}
