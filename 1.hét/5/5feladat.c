#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int lower, upper, random;

    printf("Please write a low and high number with a space between them: ");
    if (scanf("%d %d", &lower, &upper) != 2) {
        printf("Hiba: Két egész számot kell megadni!\n");
        return 1;
    }

    if (upper < lower) {
        printf("The second number has to be higher than the first one!\n");
        return 1;
    }
    
    srand(time(NULL));

    random = rand() % (upper - lower) + lower;
    printf("%d, %d\n", lower, upper);
    printf("%d\n", random);
}