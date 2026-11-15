#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Считывает входные данные
 * @param x_start Указатель на начало интервала
 * @param x_end Указатель на конец интервала
 * @param dx Указатель на шаг табулирования
 */
void input_data(double *x_start, double *x_end, double *dx);

/**
 * @brief Проверяет область допустимых значений (ОДЗ)
 * @param x_start Начало интервала
 * @param x_end Конец интервала
 * @param dx Шаг табулирования
 */
void check_odz(const double x_start, const double x_end, const double dx);

/**
 * @brief Вычисляет значение функции y(x)
 * @param x Значение аргумента x
 * @return Значение функции y
 */
double calculate_y(const double x);

/**
 * @brief Табулирует функцию на заданном интервале и выводит результаты
 * @param x_start Начало интервала
 * @param x_end Конец интервала
 * @param dx Шаг табулирования
 */
void tabulate_function(const double x_start, const double x_end, const double dx);

/**
 * @brief Главная функция программы
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main(void) {
    double x_start = 0.0;
    double x_end = 0.0;
    double dx = 0.0;
    input_data(&x_start, &x_end, &dx);
    check_odz(x_start, x_end, dx);
    tabulate_function(x_start, x_end, dx);
    return 0;
}

void input_data(double *x_start, double *x_end, double *dx) {
    if (scanf("%lf %lf %lf", x_start, x_end, dx) != 3) {
        printf("Error");
        exit(1);
    }
}

void check_odz(const double x_start, const double x_end, const double dx) {
    if (dx <= 0.0 || x_start > x_end) {
        printf("Error");
        exit(1);
    }
}

double calculate_y(const double x) {
    return 0.29 * pow(x, 3) + x - 1.2502;
}

void tabulate_function(const double x_start, const double x_end, const double dx) {
    for (double x = x_start; x <= x_end + 1e-6; x += dx) {
        double y = calculate_y(x);
        printf("%.3lf %.3lf\n", x, y);
    }
}

