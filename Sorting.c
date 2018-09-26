#include <stdio.h>
#include <string.h>
#include <malloc.h>

void merge(int* array, int start, int mid, int end)
{
    int i = start, j =  mid + 1, k = 0;
    int *temp = NULL;
    
    if(start >= end)
        return;

    temp = malloc(sizeof(int)* (end-start + 1));
 
    while(i <= mid && j <= end)
    {
        if(array[i] <= array[j])
        {
            temp[k] = array[i];
            k++;i++;
        }
        else
        {
            temp[k] = array[j];
            k++;j++;
        }
    }
    
    while(i <= mid)
    {
        temp[k] = array[i];
        k++;i++;
    }
    
    while(j <= end)
    {
        temp[k] = array[j];
        k++;j++;
    }
    
    for(i = 0; i < k; i++)
        array[start+i] = temp[i];
    
    if(temp)
        free(temp);
}

void mergesort(int* array, int start, int end)
{
    int mid = (start+end)/2;
    
    if(start >= end)
        return;
        
    mergesort(array, start, mid);
    mergesort(array, mid+1, end);
    merge(array, start, mid, end);
}

void swap(int *array, int pos1, int pos2)
{
    int temp = 0;
    
    temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

int partition(int* array, int start, int end)
{
    int ret = 0;
    int pivot = start;
    int left = start+1;
    int right = end;
    
    while(left < right)
    {
        if((array[left] > array[pivot]) && (array[right] <= array[pivot]))
        {
            swap(array, left, right);
            left++; right--;
        }
        else if(array[left] <= array[pivot])
            left++;
        else
            right--;
    }
    
    if(array[left] < array[pivot])
        ret = left;
    else
        ret = left-1;
        
    swap(array, ret, pivot);
    
    return ret;
}

void quicksort(int* array, int start, int end)
{
    int pivot;
    
    if(start >= end)
        return;
        
    pivot = partition(array, start, end);
    quicksort(array, start, pivot-1);
    quicksort(array, pivot+1, end);
}

int main()
{
    int array[] = {3,4,5,6,78,89,3,21,3,2,5,7,12,23};
    int i = 0;

    quicksort(array, 0, 13);

    for(i = 0; i < 14; i++)
    {
        printf("%d  ", array[i]);
    }

    return 0;
}
