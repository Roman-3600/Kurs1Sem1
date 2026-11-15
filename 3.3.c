#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Вычисляет точное значение функции y(x) = e^x
 * @param x Значение аргумента
 * @return Точное значение функции
 */
double calculate_y(const double x);

/**
 * @brief Вычисляет приближенное значение суммы ряда для e^x
 * @param x Значение аргумента
 * @param eps Заданная точность
 * @return Приближенная сумма функционального ряда
 */
double calculate_s(const double x, const double eps);

/**
 * @brief Табулирует функцию и ряд на заданном интервале
 * @param a Начало интервала
 * @param b Конец интервала
 * @param h Шаг табулирования
 * @param eps Точность вычисления ряда
 */
void tabulate(const double a, const double b, const double h, const double eps);

/**
 * @brief Главная функция программы
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main(void) {
    const double a = 1.0;
    const double b = 2.0;
    const double h = 0.1;
    const double eps = 1e-4;
    tabulate(a, b, h, eps);
    return 0;
}

double calculate_y(const double x) {
    return exp(x);
}

double calculate_s(const double x, const double eps) {
    double sum = 0.0;
    double term = 1.0;
    int n = 1;
    while (fabs(term) >= eps) {
        sum += term;
        term *= x / n;
        n++;
    }
    return sum;
}

void tabulate(const double a, const double b, const double h, const double eps) {
    for (double x = a; x <= b + 1e-6; x += h) {
        double y = calculate_y(x);
        double s = calculate_s(x, eps);
        printf("%.2lf %.5lf %.5lf\n", x, y, s);
    }
}

