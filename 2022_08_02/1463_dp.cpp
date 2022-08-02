#include <stdio.h>
#include <stdlib.h>
#define MAX 10000001

int main()
{
    // int array[100000] = {0};
    int *dynamic;
    dynamic = (int *)malloc(sizeof(int) * MAX);
    // array[1] = 0;
    // array[2] = 1;
    // array[3] = 1;
    dynamic[0] = 0;
    dynamic[1] = 0;
    dynamic[2] = 1;
    dynamic[3] = 1;

    int input;
    for (int i = 4; i < MAX; i++)
    {
        int three;
        int two;
        int one;

        int result;

        if (i % 3 == 0)
            three = dynamic[i / 3] + 1;

        else
            three = MAX;

        if (i % 2 == 0)
            two = dynamic[i / 2] + 1;

        else
            two = MAX;

        one = dynamic[i - 1] + 1;

        result = (three > two) ? two : three;
        result = (result > one) ? one : result;
        dynamic[i] = result;
        //printf("dynamic[%d] = %d\n",i,result); debug
    }

    scanf("%d",&input);
    printf("%d",dynamic[input]);

    free(dynamic);
    return 0;
}