#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    int size[3][50];
    char num[10];

    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<50;j++)
            size[i][j] = 0;
    }

    scanf("%d",&N);
    getchar();

    char *ptr;
    for(int i = 0; i < N; i++)
    {
        fgets(num, sizeof(num),stdin);
        ptr = strtok(num, " ");
        size[0][i] = atoi(ptr);
        ptr = strtok(NULL, " ");
        size[1][i] = atoi(ptr);

        //scanf("%d %d",size[0][i], size[1][i]);
        //getchar();
        //printf("size[0][%d] = %d\n",i,size[0][i]);
        //printf("size[1][%d] = %d\n",i,size[1][i]);
    }

    for(int i = 0; i<N; i++)
    {
        size[2][i] = 1;
        //printf("size[2][%d] = %d\n",i,size[2][i]);
    }

    for(int i = 0; i<N; i++)
    {
        for(int j = i+1; j<N; j++)
        {
            if((size[0][i] > size[0][j]) && (size[1][i] > size[1][j]))
            {
                size[2][j]++;
            }

            else if((size[0][i] < size[0][j]) && (size[1][i] < size[1][j]))
            {
                size[2][i]++;
            }
        }
        printf("%d ",size[2][i]);
    }


    return 0;
}