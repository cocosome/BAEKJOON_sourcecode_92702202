#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char array[700];
int card[100] = {0};

int main()
{
    for(int i = 0; i<700; i++)
        array[i] = 0;

    int N;
    int M;
    int sum = 0;
    int result = 0;
    scanf("%d %d",&N, &M);
    getchar();
    
    fgets(array, sizeof(array), stdin); 
    char *ptr1 = strtok(array, " ");

    for (int i = 0; i < N; i++)
    {
        card[i] = atoi(ptr1);
        ptr1 = strtok(NULL, " ");
        //printf("card[%d] = %d\n",i, card[i]); //#Debug
    }

    for(int i = 0; i<N; i++)
    {
        if(card[i] <= M)
        {
            sum = card[i];
            //printf("현재 sum = %d( %d )\n", sum, card[i]); //#Debug
        }
        else
            continue;

        for(int j = i+1; j<N; j++)
        {
            if(card[j] + card[i] <= M)
            {
                sum = card[i] + card[j];
                //printf("현재 sum = %d (%d + %d)\n",sum, card[i], card[j]); //#Debug
            }
            else
                continue;

            for(int k = j+1; k<N; k++)
            {
                if(card[k] + card[j] + card[i] <= M)
                    sum = card[i] + card[j] + card[k];

                else
                    continue;
                //printf("현재 sum = %d (%d + %d + %d)\n",sum, card[i], card[j], card[k]); //#Debug
                result = (sum > result) ? sum : result;
               // printf("최종 result = %d\n\n",result); //#Debug
                
            }
        }
    }

    printf("%d\n", result);
    return 0;
}