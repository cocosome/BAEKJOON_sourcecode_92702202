#include <stdio.h>

int main()
{
    int hour = 0;
    int min = 0;
    int cook_time = 0;
    scanf("%d %d", &hour, &min);
    scanf("%d", &cook_time);
    min = min + cook_time;

    while (true)
    {
        if (min >= 60)
        {
            hour = hour + 1;
            min = min - 60;
        }
    
        else
        {
            break;
        }
    }

    while (true)
    {
        if (hour >= 24)
        {
            hour = hour - 24;
        }
        else{
            break;
        }
    }

    printf("%d %d", hour, min);

    return 0;
}