/*
학생의 학번, 나이, 이름을 저장하기 위한 구조체를 정의하고, 이를 이용하여 n명의
학생들의 정보를 저장한다. void sorting(Student arr[], int n)함수를 이용해 이름순으로
출력하시오.
단, 입력으로 먼저 n(n < 10)이 들어오고 다음으로 학생의 학번, 나이, 이름 순서대로
들어온다.
*/
#include <stdio.h>
#include <string.h>

typedef struct
{
    int num;
    int age;
    char name[100];
} Student;

void inputdata(Student *s)
{
    scanf("%d %d %s", &s->num, &s->age, s->name);
}


void sorting(Student arr[], int n)
{
    Student tmp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0)
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main(void)
{
    Student person[10];
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d%s", &person[i].num, &person[i].age, person[i].name);
    /*for (int i = 0; i < n; i++)
        inputdata(person + i); */
    sorting(person, n);
    for (int i = 0; i < n; i++)
        printf("%d, %d, %s\n", person[i].num, person[i].age, person[i].name);
    return 0;
}
