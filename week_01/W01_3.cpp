/*
- 0이 입력될 때까지 정수 데이터를 입력 받아 0을 제외한 입력 데이터들을
v[]배열에 저장하고 입력된 데이터의 개수를 리턴하는 함수 int GetIntArray(int
v[])를 작성한다.
- 길이가 n인 배열 int v[ ]에서 연속해서 저장된 임의의 개수의 정수들의 합의
최소값 min을 계산하여 '구간'을 리턴하는 함수 void SubSumMin(int v[ ], int n, int*
indexstart, int* indexend)를 작성한다.
- 이를 이용하여 0이 입력될 때까지 정수(100개 이하)들을 입력 받아, 연속해서
입력된 임의의 개수의 정수들의 합이 최소가 되는 경우를 출력하는 프로그램을
작성하시오.
- 단, 합이 최소인 구간이 둘 이상인 경우에는 가장 "나중에" 나오는 구간을
출력하여라.
*/
#include <stdio.h>
#include <climits>

int GetIntArray(int v[])
{
    int i;
    for (i = 0;; i++)
    {
        scanf("%d", &v[i]);
        if (v[i] == 0)
            break;
    }
    return i;
}

void SubSumMin(int v[], int n, int *indexstart, int *indexend)
{
    int min = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += v[k];
            if (min >= sum)
            {
                min = sum;
                *indexstart = v[i];
                *indexend = v[j];
            }
        }
    }
}

int main(void)
{
    int arr[100], arr_size, indexstart, indexend;

    arr_size = GetIntArray(arr);
    SubSumMin(arr, arr_size, &indexstart, &indexend);

    printf("%d %d", indexstart, indexend);
    return 0;
}