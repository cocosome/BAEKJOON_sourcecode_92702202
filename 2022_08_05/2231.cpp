#include <stdio.h>

int cal(int num);

int main()
{
    int input;
    int result;
    scanf("%d",&input);

    for(int i = 1; i <= input; i++)
    {
        result = cal(i);
        //printf("%d의 분해합 = %d\n",i, result); //Debug
        if(input == result)
        {
            printf("%d",i);
            return 0;
        }
    }
    printf("0");
    return 0;
}

int cal(int num)
{
    int sum = 0;
    int remain = num;

    while(remain > 9)
    {
        sum = sum + remain % 10;
        remain = remain/10;
    }

    sum = sum + remain + num;
    return sum;
}