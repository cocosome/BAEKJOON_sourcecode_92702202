#include <stdio.h>
int Recursive(int input, int cnt);


int main(){

    int count = 0;
    int input = 0;
    scanf("%d",&input);
    count = Recursive(input, count);
    printf("%d",count);


    return 0;
}

int Recursive(int input, int cnt){

    int three = input;
    int two = input;
    int one = input;

    int three_cnt=cnt;
    int two_cnt=cnt;
    int one_cnt=cnt;

    int result_cnt = 0;

    if(input == 0)
    {
        return cnt;
    }

    if(three % 3 == 0)
    {
        three = three/3;
        three_cnt++;
        three_cnt = Recursive(three, three_cnt);
    }

    else{
        three_cnt = 10000000;
    }

    if(two % 2 == 0)
    {
        two = two/2;
        two_cnt++;
        two_cnt = Recursive(two, two_cnt);
    }

    else{
        two_cnt = 10000000;
    }

    one = one - 1;
    one_cnt++;
    one_cnt = Recursive(one, one_cnt);

    result_cnt = (two_cnt < one_cnt) ? two_cnt : one_cnt;
    result_cnt = (result_cnt < three_cnt) ? result_cnt : three_cnt;
    
    return result_cnt;
}