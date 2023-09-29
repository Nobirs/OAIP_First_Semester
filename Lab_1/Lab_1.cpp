#define _USE_MATH_DEFINES

#include <stdio.h>
#include <cmath>
#include <conio.h>
#include <locale.h>
#include <math.h>




void arithmetic_progression_n10() {

    const char task[202] = "10.	Найти сумму членов арифметической прогрессии a, a + d, ..., a + (n – 1)d по \
                            \n\rвведенным значениям a, d, n.";
    printf("\n\n%s\n\n", task);
    
    float a, d, sum;
    unsigned int n;

    printf("Введите a:");
    scanf_s("%f", &a);
    printf("Введите d:");
    scanf_s("%f", &d);
    printf("Введите n:");
    scanf_s("%d", &n);
    printf("%.2f %.2f %d\n", a, d, n);
    sum = ((2 * a + d * (n - 1)) * n) / 2;
    printf("Результат: %.2f\n", sum);
}


void arithmetical_mean_n25() {

    const char task[201] = "25.	Даны два числа. Найти среднее арифметическое кубов этих чисел и среднее геометрическое модулей этих чисел.";
    printf("\n\n%s\n\n", task);

    float a, b, average_of_cubes, geometric_mean_of_abs;

    printf("Введите a b:");
    scanf_s("%f%f", &a, &b);
    average_of_cubes = (pow(a, 3) + pow(b, 3)) / 2;
    geometric_mean_of_abs = sqrt(abs(a) * abs(b));
    printf("Среднее арифметическое кубов: %.2f\n", average_of_cubes);
    printf("Среднее геометрическое модулей: %.2f\n", geometric_mean_of_abs);
}

void circle_area_n40() {

    const char task[153] = "40. Известна длина окружности. Найти площадь круга, ограниченного этой окружностью. ";
    printf("\n\n%s\n\n", task);

    float l, area;

    printf("Введите длину окружности:");
    scanf_s("%f", &l);
    area = pow(l, 2) / (4 * M_PI);
    printf("Площадь круга с длиной окружности %.2f равна - %.2f\n", l, area);
}

void ring_area_n55() {

    const char task[] = "55. Найти площадь кольца, внутренний радиус которого равен r1, а внешний радиус равен r2 (r1 < r2). ";
    printf("\n\n%s\n\n", task);

    float r1, r2, area;

    printf("Введите радиусы окружностей r1 r2 (r1 < r2):");
    scanf_s("%f%f", &r1, &r2);
    area = M_PI * (pow(r2, 2) - pow(r1, 2));
    printf("Площадь кольца: %.2f\n", area);
}



int main() {
    setlocale(LC_ALL, "rus");

    arithmetic_progression_n10();
    arithmetical_mean_n25();
    circle_area_n40();
    ring_area_n55();


    return 0;
}
