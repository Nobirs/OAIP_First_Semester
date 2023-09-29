#include <stdio.h>
#include <conio.h>
#include <locale.h>


void task_10();
void task_25();
void task_40();


int main() {
	setlocale(LC_ALL, "rus");
	printf("Введите номер задачи ");
	char task_number = _getch();
	if (task_number == '1') {
		task_10();
	}
	else if (task_number == '2') {
		task_25();
	}
	else if (task_number == '3') {
		task_40();
	}
	else {
		printf("Нет задачи с таким номером");
	}
	_getch();
	return 0;
}

void task_10() {
	const char task[] = "10. Население города ежегодно увеличивается на 1/n жителей, где n – натуральное число. Написать программу, определяющую, через сколько лет население города утроится.";
	printf("\n\n%s\n\n", task);

	int n = 0;
	printf("Введите количество жителей: ");
	scanf_s("%i", &n);

	int years = 0;
	double current_population = n;
	while (current_population < 3 * n) {
		current_population += 1 / current_population;
		//printf("\n%.0lf\n", current_population);
		years++;
	}
	printf("\nНынешнее население - %.0lf", current_population);
	printf("\nНаселение увеличится в 3 раза через %i лет", years);

	return;
}


//void bank_percent_n10() {
//	
//	const char task[327] = "9.	Сумма R рублей положена в банк под 4 % годовых (процент капитализированный). \
//							\n\rСоставить программу, определяющую, через какой промежуток времени  сумма достигнет M рублей (M > R).";
//	printf("\n\n%s\n\n", task);
//
//	float R, M;
//	float percent = 0.04;
//
//	printf("\nВведите начальную сумму:");
//	scanf_s("%f", &R);
//
//	printf("\nВведите ожидаемую сумму:");
//	scanf_s("%f", &M);
//
//	if (M < R) {
//		printf("Ожидаемая сумма меньше начальной. Повторите попытку позже...");
//		return;
//	}
//
//	unsigned int years = 0;
//	float current_money = R;
//
//	while (current_money < M) {
//		current_money = current_money + percent * current_money;
//		years++;
//	}
//
//	printf("\nВаш вклад в банке достигнет значения %.2f через %d лет.", M, years);
//
//	return;
//}


void task_25() {
	
	const char task[193] = "25. Даны числа от 1 до 1000 и число m. \
							\n\rВывести результат целочисленного деления нечетных сотен на число m.";
	printf("\n\n%s\n\n", task);

	float m;
	printf("\nВведите число m:");
	scanf_s("%f", &m);

	for (int i = 0; i < 1001; i += 100) {
		if (i >= 100 and (i / 100) % 2 != 0) {
			printf("\nРезультат целочисленного деления %d на %.2f равен: %i", i, m, int(i / m));
		}
	}

	return;
}


void task_40() {
	
	const char task[272] = "40. Дана последовательность целых чисел, за которой следует 0. \
							\n\rНайти разность минимального и максимального элементов в этой последовательности.";
	printf("\n\n%s\n\n", task);

	double min = 999999999999, max = -(min);
	printf("\nMin value: %.2lf\nMax value: %.2lf", min, max);

	double current_value;

	do {
		printf("\nВведите число последовательности(0 - для завершения):");
		scanf_s("%lf", &current_value);

		if (current_value == 0.) break;

		min = (current_value < min) ? current_value : min;
		max = (current_value > max) ? current_value : max;

	} while (current_value != 0.);

	printf("\nMin(%.2lf) - Max(%.2lf) = %.2lf", min, max, min - max);


	return;
}