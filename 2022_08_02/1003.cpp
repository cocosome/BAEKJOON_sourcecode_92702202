#include <stdio.h>
#define MAX 40
int main()
{
    int array[41][2];

    array[0][0] = 1;
    array[0][1] = 0;
    array[1][0] = 0;
    array[1][1] = 1;
    
    for(int i = 2; i <= MAX; i++)
    {
        array[i][0] = array[i-1][0] + array[i-2][0];
        array[i][1] = array[i-1][1] + array[i-2][1]; 
    }



    int testcase = 0;
    int input = 0;
    scanf("%d",&testcase);

    while (testcase--)
    {
        scanf("%d",&input);
        printf("%d %d",array[input][0], array[input][1]);
    }
    return 0;
}