# Lab8
## Условие задачи
Задание 0. Написать программу для вывода заданного количества символов с использованием цикла for. Предусмотреть различные способы вывода символов.

Задание 1. Написать программу, которая вычисляет сумму целых чисел от m до n включительно. Вывести количество выполненных итераций и результат.

Задание 1А. Написать программу для вывода степеней двойки от нулевой до заданной пользователем степени. Результаты вывести в столбик. Перевести конечный результат в K с точностью до одного знака после запятой. Предусмотреть дополнительную версию с ограничением по заданному значению m.

Задание 2. Вариант 6. Выполнить табулирование функции на заданном интервале:  
y = x³ - 4x² + 2  
Интервал: [1; 3]  

Шаг табуляции вводится пользователем.

## Реализация программы
```c
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
Ввод:  
Введите числа m и n: 3 5  

Вывод:  
Итерация 1: число = 3, сумма = 3  
Итерация 2: число = 4, сумма = 7  
Итерация 3: число = 5, сумма = 12  
Количество итераций: 3  
Сумма чисел: 12  

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
Ввод:  
Введите шаг табуляции: 0.5  

Вывод:  
Функция: y = x^3 - 4x^2 + 2  
Интервал: [1; 3]  
+------+------------+------------+  
|  №   |     x      |    f(x)    |  
+------+------------+------------+  
|    1 |      1.000 |    -1.0000 |  
|    2 |      1.500 |    -3.6250 |  
|    3 |      2.000 |    -6.0000 |  
|    4 |      2.500 |    -7.3750 |  
|    5 |      3.000 |    -7.0000 |  
+------+------------+------------+  
## Домашнее задание. Вариант 7.

Вычислить значение выражения:

S = x - x³/3! + x⁵/5! - x⁷/7! + x⁹/9! - x¹¹/11! + x¹³/13!

Значение x вводится пользователем с клавиатуры.

## Реализация программы
```c
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
