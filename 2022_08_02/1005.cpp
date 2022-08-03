#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int graph[1001][1001];
int result[1001];
int time[1001];
char s1[100] = {0};
char D[10000] = {0};

//전역변수는 stack에 저장되므로 저장 한도가 커서 좋다?
int main()
{
    int testcase = 0;
    int N = 0;
    int K = 0;
    int start = 0;
    int finish = 0;
    int W = 0;

    scanf("%d", &testcase);
    while (testcase--)
    {
        for (int i = 0; i < 1001; i++)
        {
            for (int j = 0; j < 1001; j++)
                graph[i][j] = 0;
        }

        for (int i = 0; i < 1001; i++)
            result[i] = 0;

        for (int i = 0; i < 1001; i++)
            time[i] = 0;

        for (int i = 0; i < 10000; i++)
        {
            D[i] = 0;
            //printf("D[%d] = %d\n",i, D[i]); #Debug#
        }
        for (int i = 0; i < 100; i++)
            s1[i] = 0;

        scanf("%d %d", &N, &K);
        getchar();

        fgets(D, sizeof(D), stdin); //각 건물의 짓는시간을 일련의 문자열로 입력받음
        //gets(D);
        char *ptr1 = strtok(D, " "); //문자열로 받은 시간값은 쪼갬

        for (int i = 1; i < N + 1; i++)
        {
            time[i] = atoi(ptr1);
            ptr1 = strtok(NULL, " ");
            // printf("time[%d] = %d\n",i, time[i]);//#Debug#
        }

        char *ptr2;
        for (int i = 0; i < K; i++)
        {
            fgets(s1, sizeof(s1), stdin);
            ptr2 = strtok(s1, " ");
            start = atoi(ptr2);
            ptr2 = strtok(NULL, " ");
            finish = atoi(ptr2);
            graph[start][finish] = 1;
            // printf("graph[%d][%d] = %d\n",start, finish, graph[start][finish]);//#Debug#
        }

        scanf("%d", &W);

        int check = 0;

        for (int i = 1; i < N + 1; i++) // single인 건물을 우선적으로 result값 기입
        {
            check = 0;
            for (int j = 1; j < N + 1; j++)
            {
                if (graph[j][i] == 1)
                    check++;
            }
            if (check == 0) // single인 경우
            {
                result[i] = time[i];
            }
            //printf("result[%d] = %d\n",i,result[i]);//#Debug
        }

        for (int i = 1; i < N+1; i++) 
        {
            for (int j = 1; j < N + 1; j++) //모든 건물을 확인하면서 연관이 작은 건물 순서대로 result값을 계산
            {
                int num = 0;
                if(result[j] != 0)
                    continue;

                for (int k = 1; k < N + 1; k++)
                {
                    if (graph[k][j] == 1 && result[k] != 0)
                    {
                        num = (num > result[k]) ? num : result[k];
                        result[j] = time[j] + num;
                    }
                    else if(graph[k][j] == 1 && result[k] == 0)
                    {
                        result[j] = 0;
                        break;
                    }
                }
            }
        }

        printf("%d\n", result[W]);
    }

    return 0;
}