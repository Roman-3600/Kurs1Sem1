#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Ускорение свободного падения (м/с^2)
 */
const double GRAVITY = 9.81;

/**
 * @brief Считывает с клавиатуры значение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();

/**
 * @brief Вычисляет силу тяжести, действующую на объект
 * @param m масса объекта в килограммах
 * @return Рассчитанное значение силы тяжести
 */
double gravityForce(const double m);

/**
 * @brief Вычисляет вес объекта, покоящегося на горизонтальной опоре
 * @param m масса объекта в килограммах
 * @return Рассчитанное значение веса
 */
double weight(const double m);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    const double m = getDouble();
    if (m < 0)
    {
        printf("Ошибка: масса не может быть отрицательной.\n");
        return 1;
    }
    printf("Сила тяжести: %.3f\n", gravityForce(m));
    printf("Вес мешка: %.3f\n", weight(m));
    return 0;
}

double getDouble()
{
    double val = 0.0;
    if (scanf("%lf", &val) != 1)
    {
        printf("Ошибка: некорректный ввод данных.\n");
        exit(1);
    }
    return val;
}

double gravityForce(const double m)
{
    return m * GRAVITY;
}

double weight(const double m)
{
    return m * GRAVITY;
}
