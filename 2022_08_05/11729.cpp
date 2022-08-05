#include <stdio.h>
#include <math.h>
void Hanoi(int input, int start, int finish);


int main()
{
    int input;
    scanf("%d",&input);
    printf("%d\n",(int)pow(2, input) - 1);
    Hanoi(input, 1, 3);
    return 0;
}

void Hanoi(int input, int start, int finish)
{
    if(input == 0)
        return;
    input = input - 1;
    

    if(start == 1 && finish == 2)
    {   
        Hanoi(input, 1, 3);
        printf("1 2\n");
        Hanoi(input, 3, 2);
    }

    else if(start == 1 && finish == 3)
    {   
        Hanoi(input, 1, 2);
        printf("1 3\n");
        Hanoi(input, 2, 3);
    }

    else if(start == 2 && finish == 1)
    {   
        Hanoi(input, 2, 3);
        printf("2 1\n");
        Hanoi(input, 3, 1);
    }

    else if(start == 2 && finish == 3)
    {   
        Hanoi(input, 2, 1);
        printf("2 3\n");
        Hanoi(input, 1, 3);
    }

    else if(start == 3 && finish == 1)
    {   
        Hanoi(input, 3, 2);
        printf("3 1\n");
        Hanoi(input, 2, 1);
    }

    else if(start == 3 && finish == 2)
    {   
        Hanoi(input, 3, 1);
        printf("3 2\n");
        Hanoi(input, 1, 2);
    }

    return;
}