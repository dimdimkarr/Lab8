#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

long long sum_range(int m, int n, int *count);
void print_powers(int n);
void print_powers_limit(int m);
double f(double x);

int main(void)
{
    setlocale(LC_ALL, "Russian");

    int i;
    int count;
    char symbol;
    char second_symbol;

    int m, n;
    int max_power;
    long long sum;

    double x;
    double step;

    // Задание 0

    printf("Введите количество символов: ");
    scanf("%d", &count);

    if (count <= 0)
    {
        printf("Количество должно быть положительным.\n");
    }
    else
    {
        printf("Введите символ: ");
        scanf(" %c", &symbol);

        for (i = 0; i < count; i++)
        {
            putchar(symbol);
        }
        printf("\n");

        putchar('+');

        for (i = 0; i < count; i++)
        {
            putchar(symbol);
        }

        putchar('+');
        printf("\n");

        printf("Введите второй символ: ");
        scanf(" %c", &second_symbol);

        for (i = 0; i < count; i++)
        {
            if (i < count / 2)
            {
                putchar(symbol);
            }
            else
            {
                putchar(second_symbol);
            }
        }
        printf("\n");

        for (i = 0; i < count; i++)
        {
            putchar(symbol);
            putchar('!');
        }

        printf("\n\n");
    }

    // Задание 1

    printf("Введите числа m и n: ");
    scanf("%d %d", &m, &n);

    count = 0;

    sum = sum_range(m, n, &count);

    printf("Количество итераций: %d\n", count);
    printf("Сумма чисел: %lld\n\n", sum);

    // Задание 1А

    printf("Введите максимальную степень n (от 0 до 63): ");
    scanf("%d", &max_power);

    if (max_power < 0 || max_power > 63)
    {
        printf("Ошибка! Степень должна быть от 0 до 63.\n");
    }
    else
    {
        print_powers(max_power);
    }

    printf("\nВведите целое число m: ");
    scanf("%d", &m);

    if (m < 1)
    {
        printf("Ошибка! Число m должно быть положительным.\n");
    }
    else
    {
        print_powers_limit(m);
    }

    // Задание 2

    printf("\nФункция: y = x^3 - 4x^2 + 2\n");
    printf("Интервал: [1; 3]\n");

    printf("Введите шаг табуляции: ");
    scanf("%lf", &step);

    if (step <= 0)
    {
        printf("Ошибка! Шаг должен быть больше нуля.\n");
    }
    else
    {
        printf("\n");
        printf("+------+------------+------------+\n");
        printf("|  №   |     x      |    f(x)    |\n");
        printf("+------+------------+------------+\n");

        count = 0;

        for (i = 0; ; i++)
        {
            x = 1.0 + i * step;

            if (x > 3.0 + 1e-9)
            {
                break;
            }

            count++;

            printf("| %4d | %10.3f | %10.4f |\n",
                count, x, f(x));
        }

        printf("+------+------------+------------+\n");
    }

    return 0;
}

// Задание 1

long long sum_range(int m, int n, int *count)
{
    long long sum = 0;
    long long i;

    if (m <= n)
    {
        for (i = m; i <= n; i++)
        {
            sum += i;
            (*count)++;

            printf("Итерация %d: число = %lld, сумма = %lld\n",
                *count, i, sum);
        }
    }
    else
    {
        for (i = m; i >= n; i--)
        {
            sum += i;
            (*count)++;

            printf("Итерация %d: число = %lld, сумма = %lld\n",
                *count, i, sum);
        }
    }

    return sum;
}

// Задание 1А

void print_powers(int n)
{
    unsigned long long power = 1;
    int i;

    for (i = 0; i <= n; i++)
    {
        printf("2^%-2d = %20llu\n", i, power);

        if (i < n)
        {
            power *= 2;
        }
    }

    printf("Результат: %.1fK\n", power / 1024.0);
}

void print_powers_limit(int m)
{
    unsigned long long power = 1;
    unsigned long long last_power = 1;
    int i = 0;

    while (power <= (unsigned long long)m)
    {
        printf("2^%-2d = %20llu\n", i, power);

        last_power = power;
        power *= 2;
        i++;
}

    printf("Результат: %.1fK\n", last_power / 1024.0);
}

// Задание 2

double f(double x)
{
    double result;

    result = x * x * x - 4 * x * x + 2;

    return result;
}        