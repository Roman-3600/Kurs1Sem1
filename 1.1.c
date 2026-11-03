#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

/**
 * @brief Вычисляет значение переменной a по заданной формуле
 * @param x значение параметра x
 * @param y значение параметра y
 * @return Рассчитанное значение
 */
double A(const double x, const double y);

/**
 * @brief Вычисляет значение переменной b по заданной формуле
 * @param z значение параметра z
 * @return Рассчитанное значение
 */
double B(const double z);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    const double x = 1.426;
    const double y = -1.22;
    const double z = 3.5;

    printf("Исходные данные:\n");
    printf("x = %.3f\n", x);
    printf("y = %.2f\n", y);
    printf("z = %.1f\n\n", z);

    printf("Результат вычислений:\n");
    printf("a = %.3f\n", A(x, y));
    printf("b = %.3f\n", B(z));

    return 0;
}

double A(const double x, const double y)
{
    return (2.0 * cos(x - M_PI / 6.0)) / (0.5 + pow(sin(y), 2.0));
}

double B(const double z)
{
    return 1.0 + pow(z, 2.0) / (3.0 + pow(z, 2.0) / 5.0);
}
