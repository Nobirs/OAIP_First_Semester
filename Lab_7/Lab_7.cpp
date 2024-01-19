#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <wchar.h>
#include <ctype.h>
#include <windows.h>

int clear_console(void)
{
	HANDLE hStdOut;

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// Fetch existing console mode so we correctly add a flag and not turn off others
	DWORD mode = 0;
	if (!GetConsoleMode(hStdOut, &mode))
	{
		return ::GetLastError();
	}

	// Hold original mode to restore on exit to be cooperative with other command-line apps.
	const DWORD originalMode = mode;
	mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

	// Try to set the mode.
	if (!SetConsoleMode(hStdOut, mode))
	{
		return ::GetLastError();
	}

	// Write the sequence for clearing the display.
	DWORD written = 0;
	PCWSTR sequence = L"\x1b[2J";
	if (!WriteConsoleW(hStdOut, sequence, (DWORD)wcslen(sequence), &written, NULL))
	{
		// If we fail, try to restore the mode on the way out.
		SetConsoleMode(hStdOut, originalMode);
		return ::GetLastError();
	}

	// To also clear the scroll back, emit L"\x1b[3J" as well.
	// 2J only clears the visible window and 3J only clears the scroll back.

	// Restore the mode on the way out to be nice to other command-line applications.
	SetConsoleMode(hStdOut, originalMode);

	return 0;
}


void set_random_table(float**, int, int);
void set_random_table(int**, int, int);
void print_table(float**, int, int);
void print_table(int**, int, int);
int more_positive_in_row(float*, int);
void free_table(float**, int);
void free_table(int**, int);

void task_10();
void task_25();
void task_10_str();
void task_25_str();


int main(int argc, char* argv) {

	setlocale(LC_ALL, "rus");

	

	srand(time(NULL));

	int your_choice = 0;

	while (1) {
		printf("\n\n");
		printf("1.Выполнить задание 1\n");
		printf("2.Выполнить задание 2\n");
		printf("3.Выполнить задание 3\n");
		printf("4.Выполнить задание 4\n");
		printf("5.Выйти из программы.\n");
		printf("Введите номер варианта >> ");
		scanf_s("%d", &your_choice);
		printf("\n\n");

		switch (your_choice) {
		case 1: task_10(); break;
		case 2: task_25(); break;
		case 3: task_10_str(); break;
		case 4: task_25_str(); break;
		case 5: printf("\n\t\t\t\tВыйти из программы\n"); return 0;
		default: printf("\n\t\t\t\tОшибка. Неверное значение...\n"); break;
		}
		_getch();
		clear_console();
	}

	_getch();
	return 0;
}


void task_10() {
	const char task[] = "10. Определить, есть ли в данном массиве 4 × 4 строка, \
						\n\rсодержащая больше положительных элементов, чем отрицательных.";
	printf("\n\n%s\n\n", task);

	float** table = NULL;
	int rang = 4;
	if (!(table = (float**)malloc(4 * sizeof(float*)))) {
		printf("[Error]\t Ошибка выделения памяти.");
		return;
	}
	for (int i = 0; i < rang; i++) {
		if (!(*(table + i) = (float*)malloc(4 * sizeof(float)))) {
			printf("[Error]\t Ошибка выделения памяти.");
			return;
		}
	}

	set_random_table(table, rang, rang);
	print_table(table, rang, rang);

	for (int i = 0; i < rang; i++) {
		if (more_positive_in_row(table[i], rang)) {
			printf("\nВ строке с индексом [%d] больше положительных элементов", i);
		}
	}

	free_table(table, rang);

	return;
}


void task_25() {
	const char task[] = "25. Даны две матрицы размера M × N. Найти их сумму.";
	printf("\n\n%s\n\n", task);

	int M = 0, N = 0;
	do {
		M = rand() % 10;
		N = rand() % 10;
	} while (M == 0 || N == 0);

	int** first_table = NULL;
	if (!(first_table = (int**)malloc(M * sizeof(int*)))) {
		printf("\n[Error]\t Ошибка выделения памяти...");
		return;
	}
	for (int i = 0; i < M; i++) {
		if (!(first_table[i] = (int*)malloc(N * sizeof(int)))) {
			printf("\n[Error]\t Ошибка выделения памяти для строки таблицы...");
			return;
		}
	}
	set_random_table(first_table, M, N);

	int** second_table = NULL;
	if (!(second_table = (int**)malloc(M * sizeof(int*)))) {
		printf("\n[Error]\t Ошибка выделения памяти...");
		return;
	}
	for (int i = 0; i < M; i++) {
		if (!(second_table[i] = (int*)malloc(N * sizeof(int)))) {
			printf("\n[Error]\t Ошибка выделения памяти для строки таблицы...");
			return;
		}
	}
	set_random_table(second_table, M, N);

	int** result_table = NULL;
	if (!(result_table = (int**)malloc(M * sizeof(int*)))) {
		printf("\n[Error]\t Ошибка выделения памяти...");
		return;
	}
	for (int i = 0; i < M; i++) {
		if (!(result_table[i] = (int*)malloc(N * sizeof(int)))) {
			printf("\n[Error]\t Ошибка выделения памяти для строки таблицы...");
			return;
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			result_table[i][j] = first_table[i][j] + second_table[i][j];
		}
	}

	print_table(first_table, M, N);
	print_table(second_table, M, N);
	print_table(result_table, M, N);

	free_table(first_table, M);
	free_table(second_table, M);
	free_table(result_table, M);

	return;
}


void task_10_str() {
	const char task[] = "10. Дана строка. Все русские буквы привести к верхнему регистру, \
						\n\rлатинские — заменить на «;». Вывести результат на экран.";
	printf("\n\n%s\n\n", task);

	const wchar_t rus_lower_chr[] = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	const wchar_t latin_chr[] = L"";
	wchar_t str[101], *rus_symbol;
	size_t len;
	_cgetws_s(str, 101, &len);
	//wprintf(L"%s\n", str);
	wprintf(L"String length: %d\n", (int)len);

	// Тестовая строка for test this programmРусские буквы...

	while (1) {
		rus_symbol = wcspbrk(str, rus_lower_chr);
		if (rus_symbol == NULL) {
			break;
		}
		else {
			*rus_symbol = towupper(*rus_symbol);
		}
	}

	for (int i = 0; i < (int)len; i++) {
		if (isalpha(str[i])) {
			str[i] = L';';
		}
	}
	wprintf(L"%s\n", str);

	_getch();
	return;
}


void task_25_str() {
	const char task[] = "25.Ввести строку. Заменить во всех словах каждое вхождение буквы «м» на «мяу».";
	printf("\n\n%s\n\n", task);

	wchar_t *str;
	if (!(str = (wchar_t*)malloc(101 * sizeof(wchar_t)))) {
		printf("Ошибка выделения памяти.");
		return;
	}
	size_t len;
	size_t first_part_len = 0;
	wprintf(L"Введите строку: "); // Test string: test maybe мясо мода место мяу...
	_cgetws_s(str, 101, &len);

	while (1) {
		wchar_t* sub_sequence_ptr= wcsstr(str + first_part_len, L"м");
		if (sub_sequence_ptr == NULL) {
			break;
		}
		else {
			wchar_t* new_str;
			size_t new_len = len + 3;
			if (!(new_str = (wchar_t*)malloc(new_len * sizeof(wchar_t)))) {
				printf("Ошибка выделения памяти.");
				return;
			}
			first_part_len = sub_sequence_ptr - str;
			wcsncpy_s(new_str, new_len, str, first_part_len);
			wcscat_s(new_str, new_len, L"мяу");
			wcscat_s(new_str, new_len, ++sub_sequence_ptr);
			first_part_len = sub_sequence_ptr - str;
			free(str);
			str = new_str;
			len = new_len;
		}
	}

	wprintf(L"\n%s\n", str);


	return;
}


void set_random_table(float** table, int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			table[i][j] = rand() % 100 - 50;
		}
	}
}
void set_random_table(int** table, int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			table[i][j] = rand() % 100 - 50;
		}
	}
}


void print_table(float** table, int row, int column) {
	for (int i = 0; i < row; i++) {
		printf("\n");
		for (int j = 0; j < column; j++) {
			printf("%.2f ", table[i][j]);
		}
	}
	printf("\n");
}
void print_table(int** table, int row, int column) {
	for (int i = 0; i < row; i++) {
		printf("\n");
		for (int j = 0; j < column; j++) {
			printf("%d ", table[i][j]);
		}
	}
	printf("\n");
}


int more_positive_in_row(float* arr, int len) {
	int number_of_positive = 0, number_of_negative = 0;
	for (int i = 0; i < len; i++) {
		if (arr[i] > 0) number_of_positive++;
		else if (arr[i] < 0) number_of_negative++;
	}
	return number_of_positive > number_of_negative ? 1 : 0;
}


void free_table(float** table, int row) {
	for (int i = 0; i < row; i++) {
		free(table[i]);
	}
	free(table);
}
void free_table(int** table, int row) {
	for (int i = 0; i < row; i++) {
		free(table[i]);
	}
	free(table);
}