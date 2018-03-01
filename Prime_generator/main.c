#include <stdio.h>
#include <math.h>

#define ARR_SIZE 500000

int arr[ARR_SIZE] = {0};

int is_prime(unsigned long long int val)
{
	unsigned long long int sqroot = sqrt(val);
	unsigned long long int i = 0;

	if(val == 1)
		return 0;

	for(i = 2; i <= sqroot; i++)
	{
		if(val%i == 0)
			return -1;
	}

	return 1;
}

void generate_prime(unsigned long long int m, unsigned long long int n)
{
	unsigned long long int i;

	if(!(m & 0x1))
		m++;

	for(i = m; i <= n; i+=2)
	{
		if( i < ARR_SIZE)
		{
			if(arr[i] != 0)
			{
				if(arr[i] == 1)
					printf("%lld\n",i);
				continue;
			}
		}
				
		if(is_prime(i) == 1)
		{
			if(i < ARR_SIZE)
				arr[i] = 1;

			printf("%lld\n",i);
		}
		else
		{
			if(i < ARR_SIZE)
				arr[i] = 0;
		}
	}
}


int main(void)
{
	unsigned int T = 0;
	unsigned long long int n,m;

	scanf("%d", &T);

	while(T != 0)
	{
		scanf("%lld %lld", &m, &n);

		generate_prime(m,n);
		printf("\n");

		T--;
	}

	return 0;
}
