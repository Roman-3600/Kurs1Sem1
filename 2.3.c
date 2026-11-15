#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Считывает входные данные
 * @param x Указатель на сторону x кирпича
 * @param y Указатель на сторону y кирпича
 * @param z Указатель на сторону z кирпича
 * @param r Указатель на сторону r отверстия
 * @param s Указатель на сторону s отверстия
 */
void input_data(double *x, double *y, double *z, double *r, double *s);

/**
 * @brief Проверяет область допустимых значений (ОДЗ)
 * @param x Сторона x кирпича
 * @param y Сторона y кирпича
 * @param z Сторона z кирпича
 * @param r Сторона r отверстия
 * @param s Сторона s отверстия
 */
void check_odz(const double x, const double y, const double z, const double r, const double s);

/**
 * @brief Проверяет, пройдет ли кирпич сквозь отверстие
 * @param x Сторона x кирпича
 * @param y Сторона y кирпича
 * @param z Сторона z кирпича
 * @param r Сторона r отверстия
 * @param s Сторона s отверстия
 * @return 1, если кирпич пройдет, и 0, если не пройдет
 */
int check_fit(const double x, const double y, const double z, const double r, const double s);

/**
 * @brief Главная функция программы
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main(void) {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    double r = 0.0;
    double s = 0.0;
    input_data(&x, &y, &z, &r, &s);
    check_odz(x, y, z, r, s);
    int result = check_fit(x, y, z, r, s);
    printf("%d\n", result);
    return 0;
}

void input_data(double *x, double *y, double *z, double *r, double *s) {
    if (scanf("%lf %lf %lf %lf %lf", x, y, z, r, s) != 5) {
        printf("Error");
        exit(1);
    }
}

void check_odz(const double x, const double y, const double z, const double r, const double s) {
    if (x <= 0.0 || y <= 0.0 || z <= 0.0 || r <= 0.0 || s <= 0.0) {
        printf("Error");
        exit(1);
    }
}

int check_fit(const double x, const double y, const double z, const double r, const double s) {
    if ((x <= r && y <= s) || (x <= s && y <= r)) {
        return 1;
    }
    if ((x <= r && z <= s) || (x <= s && z <= r)) {
        return 1;
    }
    if ((y <= r && z <= s) || (y <= s && z <= r)) {
        return 1;
    }
    return 0;
}

