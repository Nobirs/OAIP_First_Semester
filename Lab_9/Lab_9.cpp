#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <time.h>
#include <string.h>

#include "Console_Information.h"


void task_1();
void task_2();
void task_3();


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "RUS");

	/*FILE* from1;
	FILE* from2;
	FILE* to;
	int ret1 = fopen_s(&from1, "C:\\Users\\User\\source\\repos\\Lab_1\\Lab_9\\test_file_1.txt", "rt");
	int ret2 = fopen_s(&from2, "C:\\Users\\User\\source\\repos\\Lab_1\\Lab_9\\test_file_2.txt", "rt");
	int ret3 = fopen_s(&to, "C:\\Users\\User\\source\\repos\\Lab_1\\Lab_9\\result_file.txt", "wt");*/

	/*if (ret1 == 0 && ret2 == 0 && ret3 == 0) {

		char str1[1000];
		char str2[1000];
		fgets(str1, 1000, from1);
		fgets(str2, 1000, from2);
		int num = 0;
		for (int i = 0; i < strlen(str1); i++) {
			if (str1[i] != ' ') {
				num = num * 10 + atoi(&str1[i]);
			}
			else {
				arr1[ind1] = num;
				ind1++;
			}
		}
		num = 0;
		for (int i = 0; i < strlen(str2); i++) {
			if (str2[i] != ' ') {
				num = num * 10 + atoi(&str2[i]);
			}
			else {
				arr2[ind2] = num;
				ind2++;
			}
		}*/
		/*fclose(from1);
		fclose(from2);
		fclose(to);*/

	int arr1[1000] = { 1, 2, 2, 4, 6, 8, 9, 19, 22 };
	int ind1 = 8;
	int arr2[1000] = { 1, 3, 4, 7, 9 };
	int ind2 = 4;
	int arr3[1000];
	int ind = 0;
	int max_len = ind1 > ind2 ? ind1 + 1 : ind2 + 1;
	for (int i = 0, j = 0; i + j < ind1 + ind2; ) {
		if (arr1[i] > arr2[j]) {
			arr3[ind] = arr2[j];
			ind++;
			j++;
		}
		else {
			arr3[ind] = arr1[i];
			ind++;
			i++;
		}
	}
	for (int i = 0; i <= ind; i++) {
		printf("%d ", arr3[i]);
	}


}
















	/*int choice = 0;

	while (1) {
		printf("\n1.Задание 1");
		printf("\n2.Задание 2");
		printf("\n3.Задание 3");
		printf("\n0.Выход");
		printf("\n >>> ");
		scanf_s("%d", &choice);
		getchar();

		switch (choice) {
			case 1: task_1(); break;
			case 2: task_2(); break;
			case 3: task_3(); break;
			case 0: return 0; 
			default: printf("\nОшибка. Неверный ввод данных"); break;
		}
	}
*/

//	return 0;
//}


void task_1()
{
	/*
	* 10.	Создать текстовый файл F1 не менее, 
	* чем из 10 строк и записать в него информацию.
	* Скопировать в файл F2 только строки из F1, 
	* которые не содержат цифр.
	*/
	FILE* file_from;
	int str_number = 0;
	char new_line[] = "\n";
	char null_sym[] = "\0";
	if (fopen_s(&file_from, "file_from.txt", "w+") == 0)
	{
		char buffer[255];
		int stop_write = 0;
		int empty_strings = 0;
		printf("\nВведите информацию, для записи в файл: \n");
		while (!stop_write) {

			gets_s(buffer);

			if (buffer[0] == '\0') {

				empty_strings = 1;

				char buffer2[255];
				gets_s(buffer2);

				if (buffer2[0] == '\0') 
				{
					stop_write = 1;
					break;
				}
				else 
				{
					fputs(buffer, file_from);
					fputs(new_line, file_from);
					fputs(buffer2, file_from);
					fputs(new_line, file_from);
					str_number += 2;
				}
			} else {
				fputs(buffer, file_from);
				fputs(new_line, file_from);
				str_number++;
			}
		}
		fputs(null_sym, file_from);
		fclose(file_from);
	}

	if (str_number < 10) {
		printf("\nСтрок в файле: %d", str_number);
	}

	FILE* file_to;
	
	if (fopen_s(&file_from, "file_from.txt", "r") == 0 && fopen_s(&file_to, "file_to.txt", "w") == 0) {
		while (!feof(file_from)) {
			char buffer[255] = { 0 };
			fgets(buffer, 255, file_from);
			char* ptr = buffer;
			int contains_num = 0;
			for (int i = 0; i < 255 && (*ptr != '\n' && *ptr != '\0'); i++) {
				char num[1] = { *ptr };
				if (atoi(num) != 0) contains_num = 1;
				ptr++;
			}
			if (!contains_num) {
				fputs(buffer, file_to);
			}
		}
		fclose(file_to);
	}

}


void task_2() {
	/*
	* 25.	Компоненты файла F1 – действительные числа. 
	* Получить файл F2, образованный из F1 включением разности 
	* между первым и последним числами файла F1.
	*/
	srand(time(NULL));
	const int TOTAL_NUMBERS = 500;
	float first_number, last_number;
	FILE* f1;
	if (fopen_s(&f1, "f1.txt", "w") == 0) {
		for (int i = 0; i < TOTAL_NUMBERS; i++) {
			float random_number = rand() % 1000 + rand() / 100000.0;
			printf("%d: %f\n", i, random_number);
			fprintf(f1, "%f\n", random_number);
		}
		fclose(f1);
	}

	FILE* f2;
	if (fopen_s(&f1, "f1.txt", "r") == 0 && fopen_s(&f2, "f2.txt", "w") == 0)
	{
		char buffer[255];
		fgets(buffer, 255, f1);
		printf("\nСчитано из файла: ");
		puts(buffer);
		
		first_number = atof(buffer);

		int not_enough = 1;
		int offset = -3;
		while (not_enough) {
			fseek(f1, offset, SEEK_END);
			char sym = fgetc(f1);
			offset--;
			if (sym == '\n') not_enough = 0;
		}
		
		char buffer2[255];
		fseek(f1, offset+2, SEEK_END);
		fgets(buffer2, -offset, f1);
		printf("\nСчитано из файла: ");
		puts(buffer2);

		last_number = atof(buffer2);

		float diff = first_number - last_number;

		printf("\nРазность между первым и последним: %f", diff);
		fprintf(f2, "%f\n", diff);
		fclose(f2);
		fclose(f1);
	}



}


void task_3() {
	list_t* list = create_list();
	information_start(list);

	return;
}