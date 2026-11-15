// Программа А
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Считывает значение n
 * @param n Указатель на переменную для хранения n
 */
void input_data(int *n);

/**
 * @brief Проверяет область допустимых значений (ОДЗ)
 * @param n Верхняя граница суммы
 */
void check_odz(const int n);

/**
 * @brief Вычисляет сумму n членов ряда
 * @param n Верхняя граница суммы
 * @return Сумма ряда
 */
double calculate_sum(const int n);

/**
 * @brief Главная функция программы
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main(void) {
    int n = 0;
    input_data(&n);
    check_odz(n);
    double sum = calculate_sum(n);
    printf("%.6lf\n", sum);
    return 0;
}

void input_data(int *n) {
    if (scanf("%d", n) != 1) {
        printf("Error");
        exit(1);
    }
}

void check_odz(const int n) {
    if (n < 0) {
        printf("Error");
        exit(1);
    }
}

double calculate_sum(const int n) {
    double sum = 0.0;
    double current_term = 1.0;
    for (int k = 0; k <= n; k++) {
        sum += current_term;
        current_term *= -1.0 / ((k + 1.0) * (k + 2.0));
    }
    return sum;
}


// Программа Б
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Считывает значение точности e
 * @param e Указатель на переменную для хранения e
 */
void input_data(double *e);

/**
 * @brief Проверяет область допустимых значений (ОДЗ)
 * @param e Точность вычислений
 */
void check_odz(const double e);

/**
 * @brief Вычисляет сумму членов ряда, по модулю больших либо равных e
 * @param e Точность вычислений
 * @return Сумма ряда
 */
double calculate_sum(const double e);

/**
 * @brief Главная функция программы
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main(void) {
    double e = 0.0;
    input_data(&e);
    check_odz(e);
    double sum = calculate_sum(e);
    printf("%.6lf\n", sum);
    return 0;
}

void input_data(double *e) {
    if (scanf("%lf", e) != 1) {
        printf("Error");
        exit(1);
    }
}

void check_odz(const double e) {
    if (e <= 0.0) {
        printf("Error");
        exit(1);
    }
}

double calculate_sum(const double e) {
    double sum = 0.0;
    double current_term = 1.0;
    int k = 0;
    while (fabs(current_term) >= e) {
        sum += current_term;
        current_term *= -1.0 / ((k + 1.0) * (k + 2.0));
        k++;
    }
    return sum;
}

