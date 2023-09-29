#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


#define N 10


void task_10();
void task_25();
void task_40();
void task_55();


int main() {
	setlocale(LC_ALL, "rus");

	task_10();
	task_25();
	task_40();
	task_55();

	_getch();
	return 0;
}


void task_10() {
	const char task[] = "10.В одномерном массиве, состоящем из n вещественных элементов, вычислить: \
							\n\r–  произведение отрицательных элементов массива;\
							\n\r– сумму положительных элементов массива, расположенных до максимального элемента.";

	printf("\n\n%s\n\n", task);
	
	srand(time(NULL));
	float numbers[N]; // = { 1.33, 2., -3., 5., -18., 10., 42., 9., -1., 3. };
	printf("\nМассив случайных вещественных чисел длиной N=%d -> {", N);
	for (int i = 0; i < N; i++) {
		numbers[i] = float(-1000 + rand() % 2000) / 100.;
		printf(" %.2f,", numbers[i]);
	}
	printf(" }\n");

	int max_number_index = -1;
	float negative = 1, sum_of_positive = 0, max_element = -99999999;
	
	for (int i = 0; i < N; i++) {
		negative = (numbers[i] < 0.) ? negative * numbers[i] : negative;
		if (numbers[i] > max_element) {
			max_element = numbers[i];
			max_number_index = i;
		}
	};
	printf("\nПроизведение отрицательных элементов массива = %.2f", negative);

	for (int i = 0; i < max_number_index; i++) {
		sum_of_positive = (numbers[i] > 0) ? sum_of_positive + numbers[i] : sum_of_positive;
	}

	printf("\nСумма положительных элементов массива, расположенных до максимального элемента = %.2f\n", sum_of_positive);

	return;
}


void task_25() {
	const char task[219] = "25. Задан массив A из n элементов. Подсчитать, сколько раз в этом массиве встречается\
							\n\rмаксимальное по величине число.";
	printf("\n\n%s\n\n", task);

	double numbers[N] = { 0. };
	printf("Тестовый массив(использовать запятую): 1 2 2,34 2,34 1,45 1,46 0,58 2,34 2,34 1\n");
	printf("Введите %d чисел: ", N);
	for (int i = 0; i < N; i++) {
		scanf_s("%lf", &numbers[i]);
	}

	double max_number = -999999999;
	int max_number_index = 0;
	int max_number_counter = 0;

	for (int i = 0; i < N; i++) {
		if (numbers[i] > max_number) {
			max_number = numbers[i];
			max_number_index = i;
		}
	}

	for (int i = 0; i < N; i++) {
		if (numbers[i] == max_number) {
			max_number_counter++;
		}
	}

	printf("\nКоличество повторений максимального элемента в массиве - %d", max_number_counter);

	return;
}


void task_40() {
	const char task[286] = "40. Дан массив L целых чисел, содержащий 22 элемента. Все положительные элементы заменить на – 5.\
							\n\rВывести полученный массив и номера измененных элементов.";
	printf("\n\n%s\n\n", task);

	const int LENGTH = 22;

	int numbers[LENGTH] = { 0 };
	int changed_indexes[LENGTH] = { 0 };
	printf("Тестовый массив:  1 2 -3 -5 -6 -5 -4 3 4 6 5 4 23 5 2345 23 21 21 12 -13 -45 -5\n");
	printf("Введите %d целых чисел: ", LENGTH);
	for (int i = 0; i < LENGTH; i++) {
		scanf_s("%i", &numbers[i]);
		if (numbers[i] > 0) {
			numbers[i] = -5;
			changed_indexes[i] = i;
		}
	}
	printf("\nИзмененный  массив: ");
	for (int i = 0; i < LENGTH; i++) {
		printf("%i ", numbers[i]);
	}
	printf("\nИзмененные индексы: ");
	for (int i = 0; i < LENGTH; i++) {
		if (changed_indexes[i] != 0) {
			printf(" %d ", changed_indexes[i]);
		}
		else {
			printf("   ");
		}
	}

	return;
}


void task_55() {
	const char task[252] = "55. С клавиатуры задать массив из 10 элементов. Умножить все элементы на 2. \
							\n\rВывести только положительные элементы полученного массива.";
	printf("\n\n%s\n\n", task);


	float numbers[N] = { 0. };
	printf("Тестовый массив: 1,23 12,4 -85,1 44,25 18 -5 -5,44 12,5 13,6 -0,1\n");
	printf("Введите %d чисел: ", N);
	for (int i = 0; i < N; i++) {
		scanf_s("%f", &numbers[i]);
		numbers[i] = numbers[i] * 2;
	}
	printf("Положительные элементы массива: ");
	for (int i = 0; i < N; i++) {
		if (numbers[i] > 0) {
			printf("%.2f ", numbers[i]);
		}
	}

	return;
}