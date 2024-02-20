#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, result, userResult;
    time_t start, end;
    double elapsed_time;

    srand(time(NULL));

    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;

    printf("Heres your exercise: %d + %d\n", num1, num2);
    start = time(NULL);
    scanf("%d", &userResult);
    result = num1 + num2;
    if (userResult == result)
    {
        printf("Correct!\n");
    }
    else
    {
        printf("Wrong! The right answer is %d!\n", result);
    }
    end = time(NULL);
    elapsed_time = difftime(end, start);
    printf("Runtime: %.2f sec\n", elapsed_time);

    return 0;
}