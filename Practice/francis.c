#include <stdio.h>

// Returns the number of elements in array that are >= threshold.
int countFilter(int array[], int size, int threshold)
{   
    if(size == 0)
    {
        return 0;
    }
    else
    {
        int checker; 
        if (array[0] >= threshold)
            checker = 1;
        else    checker = 0;
        return countFilter(array + 1, size - 1, threshold) + checker;
    }
}

int main()
{
    int array[] = {1, 2, 3};
    int size = 3;
    int threshold = 2;

    int result = countFilter(array, size, threshold);
    printf("Count of elements >= %d: %d\n", threshold, result);

    return 0;
}


