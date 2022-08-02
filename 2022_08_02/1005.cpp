#include <stdio.h>
#include <stdlib.h>
int row_check(int* addr, int N);
void row_cal(int* addr, int* result, int* time, int N, int j);


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
        scanf("%d %d", &N, &K);
        int **graph = (int **)malloc(sizeof(int) * (N + 1));//건물 짓는 순서

        for (int i = 0; i < N + 1; i++)
        {
            graph[i] = (int *)malloc(sizeof(int) * (N + 1));
            for(int j = 0; j< N+1; j++)
                graph[i][j] = 0;
        }

        int *result = (int *)malloc(sizeof(int) * (N + 1)); //실질적으로 건물을 짓기 위해 필요한 값(순서를 생각해야하는 값)

        for(int i = 0; i< N+1; i++)
            result[i] = 0;

        int *time = (int *)malloc(sizeof(int) * (N + 1)); //건물 하나를 짓는데 걸리는 상수값


        for(int i = 1; i < N+1; i++)
        {
            scanf("%d",time[i]);
            scanf("%*c");
        }

        for(int i = 0; i < K; i++)
        {
            scanf("%d %d",&start, &finish);
            graph[start][finish] = 1;
        }

        scanf("%d",&W);

        int check = 0;
        
        for(int i = 1; i < N+1; i++)//single인 건물을 우선적으로 result값 기입
        {   
            check = 0;
            check = row_check(graph[i], N);
            if(check == 0)//single인 경우
                result[i] = time[i];
        }

        for(int i = 1; i < N; i++)//연관이 1인 건물부터 N-1인 건물 순서로 반복
        {
            for(int j = 1; j < N+1; j++)//모든 건물을 확인하면서 연관이 작은 건물 순서대로 result값을 계산
            {
                check = 0;
                check = row_check(graph[j], N);
                if(check == i)
                {
                    row_cal(graph[j], result, time, N, j);
                }

            }
        }


        printf("%d",result[W]);



        for (int i = 0; i < N + 1; i++)
            free(graph[i]);

        free(result);
        free(time);
    }

    return 0;
}

int row_check(int* addr, int N)
{
    int check = 0;
    for(int i =1; i < N+1; i++)
    {
        if(addr[i] == 1)
            check++;
    }
    return check;
}

void row_cal(int* addr, int* result, int* time, int N, int j)
{
    int num = 0;
    for(int i = 1; i < N+1; i++)
    {
        if(addr[i] == 1)
        {
            num = (num > result[i]) ? num : result[i];
        }
    }

    result[j] = time[j] + num;

}