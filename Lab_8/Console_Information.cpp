#include "Console_Information.h"
#include "File_Information.h"



void choose_and_insert(list_t* list) {
	printf("\nInput position: ");
	int pos = 0;
	scanf_s("%d", &pos);

	information_t* elem = get_new_info_from_console();
	list_elem_t* new_elem = create_list_elem(elem);

	add_pos(list, new_elem, pos);
}

void information_start(list_t* list) {

	int choice = 7;

	while (choice) {
		choice = element_menu();

		switch (choice) {
		case 1: create_new_info(list); break;
		case 2: sort_info_list(list); break;
		case 3: find_info(list); break;
		case 4: change_info(list); break;
		case 5: del_info_from_list(list); break;
		case 6: print_info_list(list); break;
		case 7: choose_and_insert(list); break;
		}
	}
}




void create_new_info(list_t* list)
{
	information_t* elem = get_new_info_from_console();
	list_elem_t* new_elem = create_list_elem(elem);
	add_last(list, new_elem);
}


void sort_info_list(list_t* list)
{
	printf("\nВыберите поле элемента для сортировки: ");
	printf("\n1. Держатель информации");
	printf("\n2. Размер информации");
	printf("\n3. Название");
	printf("\n4. Автор");
	printf("\n-> ");

	int choice = 0;
	scanf_s("%d", &choice);

	switch (choice) {
	case 1: sort_info_by(list, L"keeper"); break;
	case 2: sort_info_by(list, L"size"); break;
	case 3: sort_info_by(list, L"name"); break;
	case 4: sort_info_by(list, L"author"); break;
	}
}


void sort_info_by(list_t* list, const wchar_t* param) {
	for (int i = 0; i < list->size; i++) {
		for (int j = i + 1; j < list->size; j++) {

			list_elem_t* elem1 = get_element(list, i);
			information_t* obj_1 = (information_t*)elem1->obj;
			list_elem_t* elem2 = get_element(list, j);
			information_t* obj_2 = (information_t*)elem2->obj;

			bool is_more = comp_info_by(obj_1, obj_2, param);
			if (is_more) swap_elems(elem1, elem2);
		}
	}
}


void find_info(list_t* list)
{
	printf_s("\nВыберите параметр для поиска: ");
	printf_s("\n1. Держатель информации");
	printf_s("\n2. Размер");
	printf_s("\n3. Название");
	printf_s("\n4. Автор");
	printf_s("\n-> ");

	int choice = 0;
	size_t len = 0;
	scanf_s("%d", &choice);
	wchar_t* str_to_find;
	information_t* obj;

	switch (choice) {
	case 1:
		str_to_find = get_wstr(L"Держатель информации -> ", &len);
		obj = get_info_by_wstr(list, L"keeper", str_to_find, len);
		if (obj != nullptr) print_info(obj);
		break;
	case 2: 
		str_to_find = get_wstr(L"Размер -> ", &len);
		obj = get_info_by_wstr(list, L"size", str_to_find, len);
		if (obj != nullptr) print_info(obj);
		break;
	case 3:
		str_to_find = get_wstr(L"Название -> ", &len);
		obj = get_info_by_wstr(list, L"name", str_to_find, len);
		if (obj != nullptr) print_info(obj);
		break;
	case 4:
		str_to_find = get_wstr(L"Автор -> ", &len);
		obj = get_info_by_wstr(list, L"author", str_to_find, len);
		if (obj != nullptr) print_info(obj);
		break;
	default: printf("\nНеверный параметр для поиска...");
	}
}


information_t* get_info_by_wstr(list_t* list, const wchar_t* param, wchar_t* str_to_find, size_t len) {
	bool is_found = false;
	information_t* obj = nullptr;

	for (int i = 0; i < list->size; i++) {

		list_elem_t* elem = get_element(list, i);
		obj = (information_t*)elem->obj;

		if (param == L"keeper" and wcsncmp(str_to_find, obj->name, len) == 0) is_found = true;
		else if (param == L"size" and (float)_wtof(str_to_find) == obj->size) is_found = true;
		else if (param == L"name" and wcsncmp(str_to_find, obj->name, len) == 0) is_found = true;
		else if (param == L"author" and wcsncmp(str_to_find, obj->author, len) == 0) is_found = true;
		if (is_found) break;
	}
	if (is_found) return obj;
	else return nullptr;
}


void change_info(list_t* list) {
	int i;
	wprintf(L"\nВведите индекс элемента, который нужно удалить(0-%d): ", list->size - 1);
	wscanf_s(L"%d", &i);
	if (i < 0 || i > list->size - 1) {
		printf("\nЭлемента с таким индексом нет...");
		return;
	}
	else {
		list_elem_t* elem = get_element(list, i);
		information_t* obj = (information_t*)elem->obj;

		wprintf(L"Внимание. Оставьте поля пустыми, если не хотите менять...\n");
		wprintf(L"\n[%d] Element:", i);
		wchar_t buff[100];
		swprintf(buff, 100, L"\nДержатель информации: %s ->", obj->keeper);
		get_new_info_field(buff, obj, L"keeper");

		swprintf(buff, 100, L"\nРазмер %.2f ->", obj->size);
		get_new_info_field(buff, obj, L"size");

		swprintf(buff, 100, L"\nНазвание %s ->", obj->name);
		get_new_info_field(buff, obj, L"name");

		swprintf(buff, 100, L"\nАвтор %s ->", obj->author);
		get_new_info_field(buff, obj, L"author");

		/*wchar_t* new_keeper = (wchar_t*)malloc(100 * sizeof(wchar_t));
		size_t len = 0;
		_cgetws_s(new_keeper, 100, &len);
		obj->keeper = len != 0 ? new_keeper : obj->keeper;
		clear_buffer();*/

	}
}


void get_new_info_field(const wchar_t* prompt, information_t* obj, const wchar_t* param) {
	wprintf(prompt);

	size_t len = 100;
	wchar_t* new_field = prep_str(len);

	_cgetws_s(new_field, len, &len);
	clear_buffer();

	if (param == L"keeper" and len != 0) obj->keeper = new_field;
	else if (param == L"size" and len != 0) obj->size = _wtof(new_field);
	else if (param == L"name" and len != 0) obj->name = new_field;
	else if (param == L"author" and len != 0) obj->author = new_field;
}


void del_info_from_list(list_t* list) {
	int i;
	int max_index = list->size - 1;
	printf("\nВведите индекс элемента, который нужно удалить(0-%d): ", max_index);
	scanf_s("%d", &i);
	if (i < 0 || i > max_index) {
		printf("\nЭлемента с таким индексом нет...");
		return;
	}
	else {
		list_elem_t* obj = get_element(list, i);
		obj = del_element(list, obj);
		del_information((information_t*)obj->obj);
	}
}


information_t* get_new_info_from_console()
{
	wchar_t* keeper = prep_str(101);
	size_t keeper_len;

	printf("\nДержатель информации: ");
	_cgetws_s(keeper, 101, &keeper_len);

	float size = 0;
	printf("\nРазмер информации: ");
	scanf_s("%f", &size);

	wchar_t* name = prep_str(101);
	size_t name_len;
	printf("\nНазвание: ");
	_cgetws_s(name, 101, &name_len);

	wchar_t* author = prep_str(101);
	size_t author_len;
	printf("\nАвтор: ");
	_cgetws_s(author, 101, &author_len);

	information_t* obj = create_information(keeper, size, name, author);
	return obj;
}


void print_info(information_t* obj) {
	wprintf(L"\n\t\t\t\tДержатель информации: %s", obj->keeper);
	wprintf(L"\n\t\t\t\tРазмер: %f", obj->size);
	wprintf(L"\n\t\t\t\tНазвание: %s", obj->name);
	wprintf(L"\n\t\t\t\tАвтор: %s", obj->author);
	wprintf(L"\n");
}

void print_info_list(list_t* list) {
	wprintf(L"\n------------------------Current List--------------------------\n");
	for (int i = 0; i < list->size; i++) {
		list_elem_t* list_obj = get_element(list, i);
		information_t* obj = (information_t*)list_obj->obj;
		wprintf(L"\n[%d] Element:", i);
		print_info(obj);
	}
	wprintf(L"\n--------------------------------------------------------------\n");
}