# Lab8
## Условие задачи
Задание 0. Написать программу для вывода заданного количества символов с использованием цикла for. Предусмотреть различные способы вывода символов.

Задание 1. Написать программу, которая вычисляет сумму целых чисел от m до n включительно. Вывести количество выполненных итераций и результат.

Задание 1А. Написать программу для вывода степеней двойки от нулевой до заданной пользователем степени. Результаты вывести в столбик. Перевести конечный результат в K с точностью до одного знака после запятой.

Задание 2. Вариант 6. Выполнить табулирование функции на заданном интервале:

y = x³ - 4x² + 2

Интервал: [1; 3].

Шаг табуляции вводится пользователем.

## Реализация программы
```c
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
```
## Пример работы программы    


Пример 1. Задание 0  
Введите количество символов: 5  
Введите символ: *  
*****  
+*****+  
Введите второй символ: #  
**###  
*!*!*!*!  

Пример 2. Задание 1  
Введите числа m и n: 3 5  
Выполнено итераций: 3  
Результат: 12  

Пример 3. Задание 1А  
Введите максимальную степень n (от 0 до 63): 11  
2^0  =                    1  
2^1  =                    2  
2^2  =                    4  
2^3  =                    8  
2^4  =                   16  
2^5  =                   32  
2^6  =                   64  
2^7  =                  128  
2^8  =                  256  
2^9  =                  512  
2^10 =                 1024  
2^11 =                 2048  
Результат: 2.0K  

Пример 4. Задание 2  
Функция: y = x^3 - 4x^2 + 2  
Интервал: [1; 3]  
Введите шаг табуляции: 0.5  
+------------+------------+  
|     x      |    f(x)    |    
+------------+------------+  
|      1.000 |    -1.0000 |    
|      1.500 |    -3.6250 |   
|      2.000 |    -6.0000 |    
|      2.500 |    -7.3750 |    
|      3.000 |    -7.0000 |    
+------------+------------+  

## Домашнее задание. Вариант 7.

Вычислить значение выражения:

S = x - x³/3! + x⁵/5! - x⁷/7! + x⁹/9! - x¹¹/11! + x¹³/13!

Значение x вводится пользователем с клавиатуры.

## Реализация программы
```c
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
```
## Пример работы программы

Пример 1:  
Введите значение x: 1  
Результат: 0.8414709848  

Пример 2:  
Введите значение x: 0  
Результат: 0.0000000000  

Пример 3:  
Введите значение x: 2  
Результат: 0.9092974268  

## Информация о разработчике
Жукова Дарья, бИД-261
