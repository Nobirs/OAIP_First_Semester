#define _CRT_SECURE_NO_WARNINGS

#define INFORMATION_FILE "information.bin"
#ifndef STR_BUFFER_SIZE
#define STR_BUFFER_SIZE 256
#define WSTR_SIZE sizeof(wchar_t) * STR_BUFFER_SIZE
#define INFO_SIZE WSTR_SIZE * 3 + sizeof(float)
#endif


#include "File_Information.h"


void clear_wstr(wchar_t* str) {
	for (int i = 0; i < STR_BUFFER_SIZE; i++) {
		str[i] = 0;
	}
}


int save_info_to_binary_file(information_t* info, FILE* file) {
	wchar_t keeper[STR_BUFFER_SIZE] = { 0 };
	wcscpy(keeper, info->keeper);

	float size = info->size;

	wchar_t name[STR_BUFFER_SIZE] = { 0 };
	wcscpy(name, info->name);

	wchar_t author[STR_BUFFER_SIZE] = { 0 };
	wcscpy(author, info->author);

	fwrite(keeper, WSTR_SIZE, 1, file);
	fwrite(&size, sizeof(size), 1, file);
	fwrite(name, WSTR_SIZE, 1, file);
	fwrite(author, WSTR_SIZE, 1, file);

	return 0;
}

int save_info_to_the_end_of_file(list_t* list) 
{
	information_t* info = get_new_info_from_console();
	FILE* file;
	int structs_number = 0;
	int ret = fopen_s(&file, INFORMATION_FILE, "rb");
	if (ret == 0) {

		//fseek(file, 0, SEEK_SET);
		fread(&structs_number, sizeof(structs_number), 1, file);
		structs_number++;
		fclose(file);
	}

	ret = fopen_s(&file, INFORMATION_FILE, "r+b");
	if(ret == 0){
		fseek(file, 0, SEEK_SET);
		printf("\n%d\n", ftell(file));
		int res = fwrite(&structs_number, sizeof(structs_number), 1, file);

		fseek(file, 0, SEEK_END);
		printf("\n%d\n", ftell(file));
		save_info_to_binary_file(info, file);

		fclose(file);
	}
	return 0;
}


information_t* read_info_from_binary_file(FILE* file) {

	float size = 0;
	wchar_t* keeper = (wchar_t*)malloc(WSTR_SIZE);
	wchar_t* name = (wchar_t*)malloc(WSTR_SIZE);
	wchar_t* author = (wchar_t*)malloc(WSTR_SIZE);

	fread(keeper, WSTR_SIZE, 1, file);
	fread(&size, sizeof(size), 1, file);
	fread(name, WSTR_SIZE, 1, file);
	fread(author, WSTR_SIZE, 1, file);
	
	information_t* new_info = create_information(keeper, size, name, author);

	return new_info;
}


void save_list_to_binary_file(list_t* list)
{
	FILE* bin_information;
	int ret = fopen_s(&bin_information, INFORMATION_FILE, "wb");
	if (ret == 0) {
		int structs_number = list->size;
		fwrite(&structs_number, sizeof(structs_number), 1, bin_information);
		for (int i = 0; i < list->size; i++) {
			list_elem_t* elem = get_element(list, i);
			information_t* info = (information_t*)elem->obj;
			save_info_to_binary_file(info, bin_information);
		}
		fclose(bin_information);
	}
}

void load_list_from_binary_file(list_t* list)
{
	clear_list(list);


	FILE* bin_information;
	int ret = fopen_s(&bin_information, INFORMATION_FILE, "rb");
	if (ret == 0) {

		int structs_number = 0;
		fread(&structs_number, sizeof(structs_number), 1, bin_information);

		while (!feof(bin_information) && structs_number > 0)
		{
			information_t* info = read_info_from_binary_file(bin_information);
			list_elem_t* elem = create_list_elem(info);
			add_last(list, elem);
			structs_number--;
		}
		fclose(bin_information);
	}
}

void find_in_file_by_author()
{
	size_t len;
	list_elem_t* elem;
	information_t* info;
	list_t* finded = create_list();

	const wchar_t* sub_str = get_wstr(L"\nВведите имя для поиска структуры в файле: ", &len);

	FILE* file;
	int ret = fopen_s(&file, INFORMATION_FILE, "rb");
	if (ret == 0) {
		int structs_number = 0;
		fread(&structs_number, sizeof(structs_number), 1, file);

		while (!feof(file) && structs_number > 0) {
			info = read_info_from_binary_file(file);
			if (wcsstr(info->author, sub_str) != NULL) {
				elem = create_list_elem(info);
				add_last(finded, elem);
			}
			structs_number--;
		}

		fclose(file);
	}

	if (finded->size > 0) {
		print_info_list(finded);
	}
	else {
		wprintf(L"\nПоиск по файлу с заданными параметрами не выявил совпадений...\n");
	}

}
