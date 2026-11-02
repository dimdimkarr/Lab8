#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

double f(double x);

int main(void)
{
    setlocale(LC_ALL, "");

    int i;
    int count;
    char symbol;
    char second_symbol;

    int m, n;
    long long sum = 0;
    int iterations = 0;

    int max_power;
    unsigned long long power = 1;

    double x;
    double step;
    double y;
    int points;

    // Задание 0

    printf("Введите количество символов: ");
    scanf("%d", &count);

    if (count <= 0)
    {
        printf("Количество символов должно быть положительным.\n");
    }
    else
    {
        printf("Введите символ: ");
        scanf(" %c", &symbol);

        for (i = 1; i <= count; i++)
        {
            putchar(symbol);
        }
        printf("\n");

        putchar('+');

        for (i = 1; i <= count; i++)
        {
            putchar(symbol);
        }

        putchar('+');
        printf("\n");

        printf("Введите второй символ: ");
        scanf(" %c", &second_symbol);

        for (i = 1; i <= count; i++)
        {
            if (i <= count / 2)
            {
                putchar(symbol);
            }
            else
            {
                putchar(second_symbol);
            }
        }
        printf("\n");

        for (i = 1; i <= count; i++)
        {
            putchar(symbol);
            putchar('!');
        }

        printf("\n\n");
    }

    // Задание 1

    printf("Введите числа m и n: ");
    scanf("%d %d", &m, &n);

    sum = 0;
    iterations = 0;

    if (m <= n)
    {
        for (i = m; i <= n; i++)
        {
            sum += i;
            iterations++;
        }
    }
    else
    {
        for (i = m; i >= n; i--)
        {
            sum += i;
            iterations++;
        }
    }

    printf("Выполнено итераций: %d\n", iterations);
    printf("Результат: %lld\n\n", sum);

    // Задание 1А

    printf("Введите максимальную степень n (от 0 до 63): ");
    scanf("%d", &max_power);

    if (max_power < 0 || max_power > 63)
    {
        printf("Ошибка! Степень должна быть от 0 до 63.\n");
    }
    else
    {
        power = 1;

        for (i = 0; i <= max_power; i++)
        {
            printf("2^%-2d = %20llu\n", i, power);

            if (i < max_power)
            {
                power *= 2;
            }
        }

        printf("Результат: %.1fK\n\n", power / 1024.0);
    }

    // Задание 2

    printf("Функция: y = x^3 - 4x^2 + 2\n");
    printf("Интервал: [1; 3]\n");

    printf("Введите шаг табуляции: ");
    scanf("%lf", &step);

    if (step <= 0)
    {
        printf("Ошибка! Шаг должен быть больше нуля.\n");
    }
    else
    {
        points = (int)((3.0 - 1.0) / step + 1e-9) + 1;

        printf("\n");
        printf("+------------+------------+\n");
        printf("|     x      |    f(x)    |\n");
        printf("+------------+------------+\n");

        for (i = 0; i < points; i++)
        {
            x = 1.0 + i * step;
            y = f(x);

            printf("| %10.3f | %10.4f |\n", x, y);
        }

        printf("+------------+------------+\n");
    }

    return 0;
}

double f(double x)
{
    double y;

    y = x * x * x - 4 * x * x + 2;

    return y;
}