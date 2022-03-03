/*
수식 문자열을 매개변수로 입력 받아 연산에 대한 결과를 double형으로 반환하는
함수를 작성하시오. 연산은 add, mul, div, sub 가 있다. 0 ~ 100000 사이의 숫자가
입력으로 주어진다.
ex)
11 add 11 = 22.0
10 div 2 = 5.0
2 div 4 = 0.5
2 sub 5 = -3.0
● (힌트) strtok, strcmp, atoi 함수를 사용하면 쉽게 풀 수 있습니다.
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

double calcul(char str[])
{
    int i = 0;
    char *tmp;
    double num[2];
    char *op;
    double res = 0;

    tmp = strtok(str, " ");
    while (tmp != NULL)
    {
        if (tmp[0] >= '0' && tmp[0] <= '9')
            num[i++] = atoi(tmp);
        else
            op = tmp;
        tmp = strtok(NULL, " ");
    }
    if (strcmp(op, "add") == 0)
        res = num[0] + num[1];
    else if (strcmp(op, "mul") == 0)
        res = num[0] * num[1];
    else if (strcmp(op, "div") == 0)
        res = num[0] / num[1];
    else if (strcmp(op, "sub") == 0)
        res = num[0] - num[1];
    return res;
}

int main(void)
{
    char str[20];

    cin.getline(str, 20); //공백입력
    printf("%.1f", calcul(str));
    return 0;
}