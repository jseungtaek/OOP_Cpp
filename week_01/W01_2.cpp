/*
0이 입력될 때까지 1~100 사이의 정수들을 입력하면, 각 숫자들이 몇 번씩
입력되었는지를 출력하는 프로그램을 작성하시오. 단, 한 번 이상 입력된 수만
출력하여라.
*/
#include <stdio.h>

int main(void)
{
    int arr[200] = {0};

    for (int i = 0;; i++)
    {
        int num;
        scanf("%d", &num);
        if (num == 0 || num > 100)
            break;
        arr[num] += 1;
    }
    for (int i = 1; i <= 100; i++)
    {
        if (arr[i] > 0)
            printf("%d:%d ", i, arr[i]);
    }
    return 0;
}