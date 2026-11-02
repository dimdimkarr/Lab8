#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "");

    double x;
    double sum = 0;
    double factorial;
    double term;

    int i, j;
    int degree;

    printf("Введите значение x: ");
    scanf("%lf", &x);

    for (i = 0; i <= 6; i++)
    {
        degree = 2 * i + 1;

        factorial = 1;

        for (j = 1; j <= degree; j++)
        {
            factorial *= j;
        }

        term = pow(x, degree) / factorial;

        if (i % 2 == 0)
        {
            sum += term;
        }
        else
        {
            sum -= term;
        }
    }

    printf("Результат: %.10f\n", sum);

    return 0;
}