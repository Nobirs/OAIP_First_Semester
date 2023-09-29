#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;


void task_10();
void task_25();
void task_40();
void task_55();


int cmp_func(const void* a, const void* b) {
	return (*(int*)b - *(int*)a);
}

void print_2x2(int matrix[], int RANK) {
	printf("\n");
	for (int i = 0; i < RANK; i++) {
		for (int j = 0; j < RANK; j++) {
			printf("%i ", matrix[i*RANK + j]);
		}
		printf("\n");
	}
}

//int partition(int *matrix_line, int l, int r) {
//	int pivot = ((int*)matrix_line)[int(rand() % r - l)];
//	int m = l;
//	for (int i = l; i <= r - 1; i++) {
//		if (matrix_line[i] < pivot) {
//			int temp = matrix_line[i];
//			matrix_line[i] = matrix_line[m];
//			matrix_line[m] = temp;
//			m++;
//		}
//	}
//	return m;
//}
//
//void sort(int *matrix_line, int l, int r) {
//	if (r - l == 1) {
//		return;
//	}
//	int m = partition((int*)matrix_line, l, r);
//	sort(matrix_line, l, m);
//	sort(matrix_line, m, r);
//}


int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] >= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] >= pivot) {
			i++;
		}

		while (arr[j] < pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(arr, start, end);

	// Sorting the left part
	quickSort(arr, start, p - 1);

	// Sorting the right part
	quickSort(arr, p + 1, end);
}


int main() {
	setlocale(LC_ALL, "rus");

	/*task_10();
	task_25();
	task_40()*/;
	task_55();

	return 0;
}


void task_10() {
	const char task[] = "10. Для заданной матрицы размером 8 × 8 найти такие k, \
		\n\rчто k–я строка матрицы совпадает с k – м столбцом. Найти сумму элементов в \
		\n\rтех строках, которые содержат хотя бы один отрицательный элемент.";
	printf("\n\n%s\n\n", task);

	const int RANK = 8;
	int matrix[RANK][RANK] = { 0 };

	int equal_strings[RANK] = { 0 };
	int contains_negative[RANK] = { 0 };

	for (int i = 0; i < RANK; i++) {
		printf("Введите %i-ю строку матрицы(%i чисел): ", i, RANK);
		scanf_s("%i%i%i%i%i%i%i%i", &matrix[i][0], &matrix[i][1], &matrix[i][2], &matrix[i][3], &matrix[i][4], &matrix[i][5], &matrix[i][6], &matrix[i][7]);
	}

	for (int i = 0; i < RANK; i++) {
		int is_equal = 0;
		for (int j = 0; j < RANK; j++) {
			if (matrix[i][j] == matrix[j][i]) {
				is_equal = 1; // true
			}
			else {
				is_equal = 0; // false;
				break;
			}
		}
		if (is_equal == 1) {
			equal_strings[i] = 1;
		}
	}

	for (int i = 0; i < RANK; i++) {
		for (int j = 0; j < RANK; j++) {
			if (matrix[i][j] < 0) {
				contains_negative[i] = 1;
			}
		}
	}
	
	for (int i = 0; i < RANK; i++) {
		int sum = 0;
		if (contains_negative[i] == 1) {
			for (int j = 0; j < RANK; j++) {
				sum = sum + matrix[i][j];
			}
			printf("\nСумма в %d-ой строке - %i", i, sum);
		}
	}
	for (int i = 0; i < RANK; i++) {
		if (equal_strings[i] == 1) {
			printf("\nСтрока и столбец с индексом %i равны", i);
		}
	}

	return;
}


void task_25() {
	const char task[] = "25. Проверить, все ли строки матрицы упорядочены по убыванию. \
						\n\rЕсли нет, найти первую неупорядоченную строку и упорядочить.";
	printf("\n\n%s\n\n", task);

	const int RANK = 9;
	int matrix[RANK][RANK] = {
		{9, 8, 7, 6, 5, 4, 3, 2, 1},
		{9, 8, 7, 6, 5, 4, 3, 2, 1},
		{9, 8, 7, 6, 5, 4, 3, 2, 1},
		{9, 8, 7, 6, 5, 4, 3, 2, 1},
		{9, 8, 7, 6, 5, 4, 3, 2, 1},
		{9, 8, 7, 6, 5, 4, 3, 2, 1},
		{9, 8, 7, 6, 5, 4, 3, 2, 1},
		{9, 7, 8, 6, 5, 4, 3, 2, 1},
		{1, 2, 3, 5, 4, 6, 7, 8, 9},
	};

	print_2x2(&matrix[0][0], RANK);

	bool is_decreasing = true;
	int decreasing_line_number = -1;
	for (int i = 0; i < RANK; i++) {
		for (int j = 0; j < RANK; j++) {
			if (j == 0) {
				continue;
			}
			else if (matrix[i][j] > matrix[i][j - 1]) {
				is_decreasing = false;
				decreasing_line_number = i;
				break;
			}
		}
		if (not is_decreasing) {
			printf("Индекс первой неупорядоченной строки: %i\n\n", decreasing_line_number);
			break;
		}
	}

	// sort needed line;
	quickSort(matrix[decreasing_line_number], 0, RANK - 1);

	// Print new matrix with reordered line according to task
	print_2x2(&matrix[0][0], RANK);

	return;
}


void task_40() {
	const char task[] = "40.	Даны оценки, полученные на 6 экзаменах во время сессии студентами одной группы (студентов в группе 10),\
						\n\rпо 10 – бальной системе. Определить, сколько студентов сдали сессию на балл не ниже 6.";
	printf("\n\n%s\n\n", task);


	int matrix[10][6] = {
		{4, 5, 7, 9, 8, 6},
		{7, 7, 7, 9, 4, 6},
		{4, 4, 4, 4, 4, 4},
		{1, 2, 3, 4, 5, 6},
		{4, 5, 4, 4, 4, 4},
		{4, 5, 7, 9, 8, 6},
		{7, 8, 9, 9, 9, 9},
		{4, 5, 7, 9, 8, 6},
		{2, 3, 4, 5, 5, 5},
		{4, 5, 4, 4, 5, 5},
	};

	float average_marks[10] = { 0 };
	int good_students = 0;

	for (int i = 0; i < 10; i++) {
		int sum_of_marks = 0;
		for (int j = 0; j < 6; j++) {
			sum_of_marks += matrix[i][j];
		}
		average_marks[i] = sum_of_marks / 6.;
		if (average_marks[i] >= 6) {
			printf("\nСтудент номер %i, средний балл: %.1f", i, average_marks[i]);
		}
	}

	return;
}


void task_55() {
	const char task[] = "55. Задана матрица F 9 × 3. Определить, равны ли все элементы первого столбца соответствующим \
						\n\rэлементам главной диагонали. Если нет, то поменять их местами. Вывести полученную матрицу на экран.";
	printf("\n\n%s\n\n", task);

	const int LOWEST_RANK = 4;
	int matrix[4][LOWEST_RANK] = {
		{1, 2, 3, 7},
		{1, 2, 3, 5},
		{1, 2, 3, 9},
		{1, 2, 3, 5}
	};

	for (int i = 0; i < LOWEST_RANK; i++) {
		if (matrix[i][0] != matrix[i][i]) {
			printf("Элементы [%i] и [%i] не равны, перестановка\n", matrix[i][0], matrix[i][i]);
			int a = matrix[i][0];
			matrix[i][0] = matrix[i][i];
			matrix[i][i] = a;
		}
	}

	// Print matrix
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < LOWEST_RANK; j++) {
			printf("%i ", matrix[i][j]);
		}
		printf("\n");
	}

	return;
}