#include <stdio.h>
void Recursive(int input, int count);

int main(){
    int input;
    scanf("%d",&input);
    printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
    Recursive(input, 0);

    return 0;
}

void Recursive(int input, int count)
{
    int bar = count * 4;

    for(int i = 0; i < bar; i++)
        printf("_");

    printf("\"����Լ��� ������?\"\n");

    input--;

    if(input >= 0)
    {
        for(int i = 0; i < bar; i++)
            printf("_");
        printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
       
       for(int i = 0; i < bar; i++)
            printf("_");
        printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
        
        for(int i = 0; i < bar; i++)
            printf("_");
        printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
        
        count++;
        Recursive(input, count);
    }
    else
    {
        for(int i = 0; i < bar; i++)
            printf("_");
        printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
    }
    
    for(int i = 0; i < bar; i++)
        printf("_");

    printf("��� �亯�Ͽ���.\n");
}