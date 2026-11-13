#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

double calculate_power(double x, int n);
unsigned long long calculate_factorial(int n);
double calculate_series(double x);

int main(void)
{
    setlocale(LC_ALL, "Russian");

    double x;
    double result;

    printf("Введите значение x: ");
    scanf("%lf", &x);

    result = calculate_series(x);

    printf("Результат: %.10f\n", result);

    return 0;
}

double calculate_power(double x, int n)
{
    double result = 1;
    int i;

    for (i = 1; i <= n; i++)
    {
        result *= x;
    }

    return result;
}

unsigned long long calculate_factorial(int n)
{
    unsigned long long factorial = 1;
    int j;

    for (j = 1; j <= n; j++)
    {
        factorial *= j;
    }

    return factorial;
}

double calculate_series(double x)
{
    double sum = 0;
    double term;
    int i;
    int degree;

    for (i = 0; i <= 6; i++)
    {
        degree = 2 * i + 1;

        term = calculate_power(x, degree) /
            calculate_factorial(degree);

        if (i % 2 == 0)
        {
            sum += term;
        }
        else
        {
            sum -= term;
        }
    }

    return sum;
}