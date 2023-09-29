#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void task_10();
void task_25();
void task_40();
void task_55();


int main() {
	setlocale(LC_ALL, "rus");

	while (1) {
		//task_10();
		//task_25();
		//task_40();
		task_55();
		printf("\n\n");
		_getch();
	}


	return 0;
}


void task_10() {
	const char task[] = "10.	В одномерном массиве, состоящем из n вещественных элементов, вычислить:\
		\n\r– минимальный по модулю элемент массива;\
		\n\r– сумму элементов массива, расположенных между первым и последним отрицательными элементами.";
	printf("\n\n%s\n\n", task);

	int N = 0;
	do {
		printf("\nВведите число элементов массива: ");
		scanf_s("%d", &N);
	} while (N == 0);
	// Declare massive and check if malloc successful
	float* massive = (float*)malloc(N * sizeof(float));
	if (!massive) {
		printf("Не удалось выделить достаточно памяти.\nПроверьте длину массива...");
		_getch();
		return;
	}
	else { // Initialize with random values
		for (int i = 0; i < N; i++) {
			*(massive + i) = rand() % 10 - 5 + (rand() % 100 / 100.);
		}
	}
	
	// Print massive
	for (int i = 0; i < N; i++) {
		printf("%.2f  ", *(massive + i));
	}
	printf("\n");

	// Find min |element| in massive
	float min_element = *massive;
	int min_element_index = 0;
	for (int i = 1; i < N; i++) {
		if (fabs(*(massive + i)) < fabs(min_element)) {
			min_element = *(massive + i);
			min_element_index = i;
		}
	}
	printf("\nМинимальный по модулю элемент массива (%.2f); его индекс [%d]\n", min_element, min_element_index);

	// Find sum of the elements between first and last negative elements
	float sum = 0;
	int after_first = 0, before_last = 0;
	int first_negative_index = 0, last_negative_index = 0;
	for (int i = 0; i < N; i++) {
		if (*(massive + i) < 0) {
			first_negative_index = i;
			break;
		}
	}
	for (int j = N - 1; j >= 0; j--) {
		if (*(massive + j) < 0) {
			last_negative_index = j;
			break;
		}
	}
	for (int i = first_negative_index + 1; i < last_negative_index; i++) {
		sum += *(massive + i);
	}

	/*for (int i = 0, j = N - 1; i <= j; i++, j--) {
		if (after_first && before_last && i == j) {
			sum += *(massive + i);
			break;
		}
		if (!after_first && *(massive + i) < 0) {
			after_first = 1;
			first_negative_index = i;
		}
		else if(after_first) {
			sum += *(massive + i);
		}

		if (!before_last && *(massive + j) < 0) {
			before_last = 1;
			last_negative_index = j;
		}
		else if (before_last) {
			sum += *(massive + j);
		}
	}
	if (last_negative_index - first_negative_index == 1) {
		sum = 0;
	}*/

	printf("\nСумма элементов между первым и последним отрицательными элементами -> %.2f", sum);

	free(massive);

	return;
}


void task_25() {
	const char task[] = "25.	В одномерном массиве, состоящем из n целых элементов, вычислить:\
		\n\r– количество положительных элементов массива;\
		\n\r– сумму элементов массива, расположенных после последнего элемента, равного нулю";
	printf("\n\n%s\n\n", task);

	int N = 0;
	do {
		printf("Введите длину массива: ");
		scanf_s("%d", &N);
	} while (N == 0);

	// Trying to declare massive using malloc
	int* massive = NULL;
	if (!(massive = (int*)malloc(N * sizeof(int)))) {
		printf("\nОшибка выделения памяти...");
		_getch();
		return;
	}

	// Initialize massive using random values
	for (int i = 0; i < N; i++) {
		*(massive + i) = rand() % 100 - 50;
	}

	// Print massive
	for (int i = 0; i < N; i++) {
		printf("%d ", *(massive + i));
	}
	printf("\n");

	int number_of_positive = 0;
	for (int i = 0; i < N; i++) {
		if (*(massive + i) > 0) {
			number_of_positive++;
		}
	}
	printf("\nКоличество положительных элементов массива: %d", number_of_positive);

	int sum = 0;
	int last_zero = 0; // false by default(meaning there no zero number in massive by default)
	for (int j = N - 1; j >= 0; j--) {
		if (*(massive + j) == 0) {
			last_zero = 1; // true (we found zero number in massive)
			break;

		}
		else {
			sum += *(massive + j);
		}
	}
	if (last_zero) {
		printf("\nСумма элементов массива, расположенных до нуля: %d", sum);
	}
	else {
		printf("\nНе найден элемент массива, равный нулю.");
	}

	free(massive);

	return;
}


void task_40() {
	const char task[] = "40. Дана целочисленная прямоугольная матрица. \
						\n\r\tОпределить количество столбцов, не содержащих ни одного нулевого элемента.";
	printf("\n\n%s\n\n", task);

	int row = 0, column = 0;
	do {
		row = rand() % 15;
		column = rand() % 15;
	} while (row == 0 || column == 0);

	int** matrix = NULL;
	if (!(matrix = (int**)malloc(row * sizeof(int*)))) {
		printf("\nОшибка выделения памяти...");
		_getch();
		return;
	}
	for (int i = 0; i < row; i++) {
		if (!(*(matrix + i) = (int*)malloc(column * sizeof(int)))) {
			printf("\nОшибка выделения памяти для строки [%d]", i);
			_getch();
			return;
		}
	}

	// Set random values
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			*(*(matrix + i) + j) = rand() % 10 - 5;
		}
	}

	// Print Matrix
	for (int i = 0; i < row; i++) {
		printf("\n");
		for (int j = 0; j < column; j++) {
			printf("%d ", matrix[i][j]);
		}
	}

	int columns_counter = 0;
	for (int j = 0; j < column; j++) {
		int column_have_zero = 0; // false by default
		for (int i = 0; i < row; i++) {
			if (*(*(matrix + i) + j) == 0) {
				column_have_zero = 1; // column have zero number
				break;
			}
		}
		if (!column_have_zero) {
			columns_counter++;
		}
	}

	printf("\nКоличество столбцов, не содержащих 0 -> %d", columns_counter);

	_getch();

	for (int i = row - 1; i >= 0; i--) {
		free(matrix[i]);
	}
	free(matrix);

	return;
}


void task_55() {
	const char task[] = "55. Дана целочисленная квадратная матрица. Определить сумму элементов в тех строках, \
						\n\r\tкоторые не содержат нулевых элементов.";
	printf("\n\n%s\n\n", task);

	int rang = 0;
	do {
		rang = rand() % 15;
	} while (rang == 0);

	int** matrix = NULL;
	if (!(matrix = (int**)malloc(rang * sizeof(int*)))) {
		printf("\nОшибка выделения памяти...");
		_getch();
		return;
	}
	for (int i = 0; i < rang; i++) {
		if (!(*(matrix + i) = (int*)malloc(rang * sizeof(int)))) {
			printf("\nОшибка выделения памяти для строки [%d]", i);
			_getch();
			return;
		}
	}

	// Set random values
	for (int i = 0; i < rang; i++) {
		for (int j = 0; j < rang; j++) {
			*(*(matrix + i) + j) = rand() % 10 - 5;
		}
	}

	// Print Matrix
	for (int i = 0; i < rang; i++) {
		printf("\n");
		for (int j = 0; j < rang; j++) {
			printf("%d ", matrix[i][j]);
		}
	}

	for (int i = 0; i < rang; i++) {
		int sum = 0;
		int has_zero_elem = 0; // false by default
		for (int j = 0; j < rang; j++) {
			sum += matrix[i][j];
			if (matrix[i][j] == 0) {
				has_zero_elem = 1; // true
				break;
			}
		}
		if (!has_zero_elem) {
			printf("\nСумма элементов в строке [%d] равна (%d)", i, sum);
		}
	}

	_getch();

	for (int i = 0; i < rang; i++) {
		free(matrix[i]);
	}
	free(matrix);

	return;
}