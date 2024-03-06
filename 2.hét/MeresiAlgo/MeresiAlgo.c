#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int unique(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] == array[j])
            {
                return 0;
            }
        }
    }
    return 1; 
}

int main()
{
    srand(time(NULL));
    clock_t begin = clock();
    int size = 10;
    int array[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = i + 1; 
    }

    for (int i = 0; i < size; i++)
    {
        if (rand() % 2 == 0)
        {                          
            int j = rand() % size; 
            array[i] = array[j];
        }
            printf("%d ", array[i]);
    }

    if (unique(array, size))
    {
        printf("All of them are unique.\n");
    }
    else
    {
        printf("There is a duplicate.\n");
    }
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - begin) / CLOCKS_PER_SEC;
    printf("\nIt took %f seconds to execute\n", elapsed_time);

    return 0;
}