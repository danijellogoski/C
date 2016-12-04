/* Function that returns a pointer. */

#include <stdio.h>

int larger1(int x, int y);
int *larger2(int *x, int *y);

int main(int argc, char *argv[]){

    int a, b, bigger1, *bigger2;

    printf("Enter two integer values: ");
    scanf("%d %d", &a, &b);

    bigger1 = larger1(a, b);
    printf("\nThe larger value is %d.", bigger1);
    bigger2 = larger2(&a, &b);
    printf("\nThe larger value is %d.\n", *bigger2);
    return 0;
}

int larger1(int x, int y)
{
    if (y > x)
        return y;
    return x;
}

int *larger2(int *x, int *y)
{
    if (*y > *x)
        return y;

    return x;
}

