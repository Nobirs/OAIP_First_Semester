#define _USE_MATH_DEFINES

#include <stdio.h>
#include <cmath>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <wchar.h>
#include <string.h>
#include <Windows.h>


void check_if_even() {

	const char task[127] = "10. Определить, имеется ли среди целых чисел a, b и c хотя бы одно чётное.";
	printf("\n\n%s\n\n", task);

	int a, b, c;
	printf("Введите 3 целых числа a b c:");
	scanf_s("%i%i%i", &a, &b, &c);

	if (a % 2 == 0 and a != 0) printf("a - четное\n");
	else if (b % 2 == 0 and b != 0) printf("b - четное\n");
	else if (c % 2 == 0 and c != 0) printf("c - четное\n");
	else printf("Среди них нет четных чисел\n");
	printf("\n");
}


void evaluate_expression() {

	const char task[130] = "25. Для вещественных чисел m, n и знака операции s вычислить выражение n s m.";
	printf("\n\n%s\n\n", task);

	double m, n;
	printf("Введите два вещественных числа m n:");
	scanf_s("%lf%lf", &m, &n);

	char statement;
	printf("\nВведите знак операции:");
	while ((getchar()) != '\n');
	scanf_s("%c", &statement, 1);

	switch (statement) {
	case '+':
		printf("%.3f + %.3f = %.3f", m, n, m + n);
		break;
	case '-':
		printf("%.3f - %.3f = %.3f", m, n, m - n);
		break;
	case '*':
		printf("%.3f * %.3f = %.3f", m, n, m * n);
		break;
	case '/':
		printf("%.3f / %.3f = %.3f", m, n, m / n);
		break;
	case '^':
		printf("pow(%.3f, %.3f) = %.3f", m, n, pow(m, n));
		break;
	default:
		printf("Неверное значение операнда");
	}

}


void set_to_zero_if_less() {

	const char task[286] = "40. Даны два действительных числа. Заменить первое число нулем, \
							\n\rесли оно меньше второго или равно ему,  оставить числа без изменения в противном случае. ";
	printf("\n\n%s\n\n", task);

	float a, b;
	printf("Введите два действительных числа a b:");
	scanf_s("%f%f", &a, &b);

	if (a <= b) {
		a = 0;
		printf("a <= b\nЗаменяем число a на 0.\na = %.3f\nb = %.3f", a, b);
	}
	else {
		printf("a > b. Оставляем числа без изменений.\na = %.3f\nb = %.3f", a, b);
	}
}


void evaluate_area_of_first_quater() {

	const char task[338] = "55. Заданы координаты вершин прямоугольника со сторонами, параллельными осям координат. \
							\n\rОпределить площадь части прямоугольника, расположенной в первой координатной четверти.  ";
	printf("\n\n%s\n\n", task);

	// Input coordinates
	float x[4] = { 0 }, y[4] = { 0 };
	for (int i = 0; i < 4; i++) {
		char suff[3] = { 0 };
		strcpy_s(suff, ((i != 2) ? "ой" : "ей"));
		printf("Введите координаты %d-%s вершины прямоугольника x y:", i+1, suff);
		scanf_s("%f%f", &x[i], &y[i]);
	}

	if (x[0] != x[1] and x[0] != x[2] and x[0] != x[3]) {
		printf("Координаты не принадлежат прямоугольнику");
		return;
	}
	else if (y[0] != y[1] and y[0] != y[2] and y[0] != y[3]) {
		printf("Координаты не принадлежат прямоугольнику");
		return;
	}

	// Get square for all dots
	float s[4] = { 0 };
	float max_s = 0, min_s = 99999999;
	int in_first_quater = 0;
	for (int i = 0; i < 4; i++) {
		if (x[i] <= 0 or y[i] <= 0) s[i] = 0;
		else {
			s[i] = x[i] * y[i];
			in_first_quater += 1;
			max_s = (s[i] > max_s) ? s[i] : max_s;
			min_s = (s[i] < min_s) ? s[i] : min_s;
		}
	}

	float result = max_s;

	if (in_first_quater == 0) {
		printf("Area = 0");
	}
	else if (in_first_quater == 1) {
		printf("Area = %.2f", result);
	}
	else if (in_first_quater == 2) {
		result = result - min_s;
		printf("Area = %.2f", result);
	}
	else if (in_first_quater == 4) {
		for (int i = 0; i < 4; i++) {
			if (s[i] == max_s) continue;
			else if (s[i] == min_s) result = result + min_s;
			else result -= s[i];
		}
	}
	printf("\nРезультат: %.2f", result);
}


void country_capital() {

	const char task[250] = "10. Составить программу, которая бы выдавала по названию страны название столицы этой страны (использовать не менее шести названий). ";
	printf("\n\n%s\n\n", task);

	int country_number = 0;
	printf("\nВарианты возможных стран:\n1.Afghanistan\n2.Albania\n3.Algeria\n4.Andorra\n5.Angola\n6.Argentina\n");
	printf("Введите Номер страны:");
	scanf_s("%d", &country_number);

	switch (country_number) {
	case 1: printf("\nСтолица страны - Kabul"); break;
	case 2: printf("\nСтолица страны - Tirana"); break;
	case 3: printf("\nСтолица страны - Algiers"); break;
	case 4: printf("\nСтолица страны - Andorra"); break;
	case 5: printf("\nСтолица страны - Luanda"); break;
	case 6: printf("\nСтолица страны - Buenos Aires"); break;
	default: printf("\nТакой страны нет в моём списке...");
	}
}


int main() {

	setlocale(LC_ALL, "rus");

	country_capital();
	evaluate_area_of_first_quater();
	set_to_zero_if_less();
	evaluate_expression();
	check_if_even();

	return 0;
}