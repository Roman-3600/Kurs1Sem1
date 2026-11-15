#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Перечисление для выбора формулы вычисления
 */
enum FormulaChoice {
    /** @brief Вычисление периметра */
    CHOICE_PERIMETER = 1,
    /** @brief Вычисление площади */
    CHOICE_AREA = 2
};

/**
 * @brief Считывает входные данные
 * @param a Указатель на первый катет
 * @param b Указатель на второй катет
 * @param choice Указатель на выбор формулы
 */
void input_data(double *a, double *b, int *choice);

/**
 * @brief Проверяет область допустимых значений (ОДЗ)
 * @param a Длина первого катета
 * @param b Длина второго катета
 */
void check_odz(const double a, const double b);

/**
 * @brief Проверяет корректность выбранного пункта меню
 * @param choice Введенный пункт меню
 */
void check_choice(const int choice);

/**
 * @brief Вычисляет периметр прямоугольного треугольника
 * @param a Длина первого катета
 * @param b Длина второго катета
 * @return Периметр прямоугольного треугольника
 */
double calculate_perimeter(const double a, const double b);

/**
 * @brief Вычисляет площадь прямоугольного треугольника
 * @param a Длина первого катета
 * @param b Длина второго катета
 * @return Площадь прямоугольного треугольника
 */
double calculate_area(const double a, const double b);

/**
 * @brief Главная функция программы
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main(void) {
    double a = 0.0;
    double b = 0.0;
    int choice_input = 0;
    input_data(&a, &b, &choice_input);
    check_odz(a, b);
    check_choice(choice_input);
    enum FormulaChoice choice = (enum FormulaChoice)choice_input;
    if (choice == CHOICE_PERIMETER) {
        double perimeter = calculate_perimeter(a, b);
        printf("%.3lf\n", perimeter);
    } else if (choice == CHOICE_AREA) {
        double area = calculate_area(a, b);
        printf("%.3lf\n", area);
    }
    return 0;
}

void input_data(double *a, double *b, int *choice) {
    if (scanf("%lf %lf %d", a, b, choice) != 3) {
        printf("Error");
        exit(1);
    }
}

void check_odz(const double a, const double b) {
    if (a <= 0.0 || b <= 0.0) {
        printf("Error");
        exit(1);
    }
}

void check_choice(const int choice) {
    if (choice != CHOICE_PERIMETER && choice != CHOICE_AREA) {
        printf("Error");
        exit(1);
    }
}

double calculate_perimeter(const double a, const double b) {
    return a + b + sqrt(pow(a, 2) + pow(b, 2));
}

double calculate_area(const double a, const double b) {
    return (a * b) / 2.0;
}

