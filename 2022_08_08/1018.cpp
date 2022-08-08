#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char chess_board[50][50];
    //char string_input[100];

    int M;
    int N;
    scanf("%d %d",&M,&N);
    getchar();

    int start_M = M - 8;
    int start_N = N - 8;

    char start_color;
    int start_loc;
    int min = M*N;

    int tmp;
    int cal;

    for(int i = 0; i<M; i++)
    {
        fgets(chess_board[i],sizeof(chess_board[i]),stdin);
    }

    for(int i = 0; i <= start_M; i++)
    {
        for(int j = 0; j <= start_N; j++)
        {
            start_color = 'B';
            start_loc = i + j;
            tmp = 0;
            cal = 0;
            for(int k = i; k < i + 8; k++)
            {
                for(int p = j; p < j + 8; p++)
                {
                    tmp = ((k + p) - start_loc)%2;
                    if((tmp == 1)&&(start_color == chess_board[k][p]))
                        cal++;
                    else if((tmp == 0) && (start_color != chess_board[k][p]))
                        cal++;
                }
            }
            min = (min > cal) ? cal : min;

            start_color = 'W';
            start_loc = i + j;
            tmp = 0;
            cal = 0;
            for(int k = i; k < i + 8; k++)
            {
                for(int p = j; p < j + 8; p++)
                {
                    tmp = ((k + p) - start_loc)%2;
                    if((tmp == 1)&&(start_color == chess_board[k][p]))
                        cal++;
                    else if((tmp == 0) && (start_color != chess_board[k][p]))
                        cal++;
                }
            }
            min = (min > cal) ? cal : min;
        }
    }
    printf("%d",min);
    return 0;
}