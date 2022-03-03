/* 
자연수원소들로 구성된 두 집합을 입력받고, 두 집합의 합집합을 출력한다.
● 각 집합의 원소들은 0이 입력될때까지 숫자가 작은 순서대로 각각 입력받는다.
● 각 집합의 최대 크기는 100이다.
● 각 집합은 값이 작은 순서로 배열에 저장된다.
● getIntArray(int arr[])함수에서 0이 입력될때까지 배열 arr에 차례대로 저장하고,
입력의 개수를 리턴한다.
● setUnion(int *a, int sizea, int *b, int sizeb, int *c)함수에서 크기가 sizea인 배열 a와
크기가 sizeb인 배열 b의 합집합을 구해서 c에 저장하고, c의 크기를 리턴한다.
● getIntArray()와 setUnion()함수를 완성하기
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

int getIntArray(int arr[])
{
    int i;
    for (i = 0;; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] == 0)
            break;
    }
    return i;
}

int setUnion(int *a, int size_a, int *b, int size_b, int *c)
{
    int k = 0;
    for (int i = 0; i < size_a; i++)
    {
        c[k++] = a[i];
    }
    for (int i = 0; i < size_b; i++)
    {
        for (int j = 0; j < size_a; j++)
        {
            if (c[j] == b[i])
                break;
            if (j == size_a - 1)
                c[k++] = b[i];
        }
    }
    sort(c, c + k);
    return k;
}

int main(void)
{
    int a[100], b[100], c[200], size_a, size_b, size_c;
    size_a = getIntArray(a);
    size_b = getIntArray(b);
    size_c = setUnion(a, size_a, b, size_b, c);

    for (int i = 0; i < size_c; i++)
    {
        printf("%d ", c[i]);
    }
    return 0;
}