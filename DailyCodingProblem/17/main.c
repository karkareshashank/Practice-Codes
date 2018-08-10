#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int my_index = 0;

void get_string(char *array, int *index, int len, char* string, bool move_index)
{
	int local_index = *index;
	int i = 0;
	int count = 0;

	while(local_index < len)
	{
		if(array[local_index] == '\\' && array[local_index+1] == 'n')
		{
			count++;
			if(count == 2)
				break;
		}
		string[i] = array[local_index];
		i++;
		local_index++;
	}

	string[i] = '\0';

	if(move_index)
		*index = local_index;		
}

int depth_of_string(char* array, int len)
{
	int depth = 0;
	int i = 0;
	
	for(i = 0;i < len; i++)
		if(array[i] == '\\' && array[i+1] == 't')
			depth++;

	return depth;
}

bool is_filename(char* array, int len)
{
	int i  = 0;

	for(i = 0; i < len; i++)
		if(array[i] == '.')
			return true;

	return false;
}

int fn(char* array, int depth, int len)
{
	int max_file_len = 0;
	int file_len = 0;
	int curr_depth = 0;
	int i = 0;
	char string[100];


	get_string(array, &my_index, len, string, false);

	//base case
	if(is_filename(string, strlen(string)))
		return strlen(string);

	curr_depth = depth_of_string(string, strlen(string));
	if(curr_depth == depth)
		return 0;

	//recursive case
	while(curr_depth == depth+1)
	{
		file_len = fn(array, curr_depth, len);
		if(file_len != 0)
			file_len = file_len + strlen(string) + 1 - ((curr_depth+1)*2);

		if(file_len > max_file_len)
			max_file_len = file_len;

		for(i = 0;i < 100; i++)
			string[i] = '\0';
		
		get_string(array, &my_index, len, string, true);
		curr_depth = depth_of_string(string, strlen(string));
	}

	return max_file_len;
}


int main()
{
	char array[500];
	int max_file_len = 0;
	int root_dir_len = 0;
	int len = 0;

	scanf("%s", array);
	printf("string = %s\n", array);
	len = strlen(array);

	while(array[my_index] != '\\')
	{
		my_index++;
	}

	root_dir_len = my_index;

	max_file_len = fn(array, 0, len);

	printf("Max file len = %d\n", max_file_len + root_dir_len);

	return 0;
}
