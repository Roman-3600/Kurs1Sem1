#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Считывает входные данные
 * @param x Указатель на переменную для хранения значения x
 */
void input_data(double *x);

/**
 * @brief Вычисляет значение функции y(x)
 * @param x Значение аргумента x
 * @param a Значение параметра a
 * @return Значение функции y
 */
double calculate_y(const double x, const double a);

/**
 * @brief Главная функция программы
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main(void) {
    double x = 0.0;
    const double a = 2.0;
    input_data(&x);
    double y = calculate_y(x, a);
    printf("%.3lf\n", y);
    return 0;
}

void input_data(double *x) {
    if (scanf("%lf", x) != 1) {
        printf("Error");
        exit(1);
    }
}

double calculate_y(const double x, const double a) {
    if (x < 1.0) {
        return 1.0;
    } else if (x >= 1.0 && x <= 2.0) {
        return a * pow(x, 2 * log(x));
    } else {
        return exp(a * x) * cos(x);
    }
}

