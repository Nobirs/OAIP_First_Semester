#include "Console_BabyToy.h"


void baby_toy_start(list_t* list) {

	int choice = 7;

	while (choice) {
		choice = element_menu();

		switch (choice) {
		case 1: create_new_toy(list); break;
		case 2: sort_toy_list(list); break;
		case 3: find_toy(list); break;
		case 4: change_toy(list); break;
		case 5: del_toy_from_list(list); break;
		case 6: print_toy_list(list); break;
		}
	}
}


void create_new_toy(list_t* list) {
	baby_toy_t* elem = get_new_toy_from_console();
	list_elem_t* new_elem = create_list_elem(elem);
	add_first(list, new_elem);
}


void sort_toy_list(list_t* list) {
	printf("\n�������� ���� �������� ��� ����������: ");
	printf("\n1. �������� �������");
	printf("\n2. ����");
	printf("\n3. ����������");
	printf("\n4. ������������ �� ��������(���-���)");
	printf("\n-> ");

	int choice = 0;
	scanf_s("%d", &choice);

	switch (choice) {
	case 1: sort_toys_by(list, L"name"); break;
	case 2: sort_toys_by(list, L"price"); break;
	case 3: sort_toys_by(list, L"tool_number"); break;
	case 4: sort_toys_by(list, L"recommended_years"); break;
	}
}


void sort_toys_by(list_t* list,const wchar_t* param) {
	for (int i = 0; i < list->size; i++) {
		for (int j = i + 1; j < list->size; j++) {

			list_elem_t* elem1 = get_element(list, i);
			baby_toy_t* obj_1 = (baby_toy_t*)elem1->obj;
			list_elem_t* elem2 = get_element(list, j);
			baby_toy_t* obj_2 = (baby_toy_t*)elem2->obj;

			bool is_more = comp_toys_by(obj_1, obj_2, param);
			if (is_more) swap_elems(elem1, elem2);
		}
	}
}


void find_toy(list_t* list) {
	printf_s("\n�������� �������� ��� ������: ");
	printf("\n1. �������� �������");
	printf("\n2. ����");
	printf("\n3. ����������");
	printf("\n4. ������������ �� ��������(���-���)");
	printf("\n-> ");

	int choice = 0;
	size_t len = 0;
	scanf_s("%d", &choice);
	wchar_t* str_to_find;
	baby_toy_t* obj;

	switch (choice) {
	case 1:
		str_to_find = get_wstr(L"�������� ������� -> ", &len);
		obj = get_toy_by_wstr(list, L"name", str_to_find, len);
		if (obj != nullptr) print_toy(obj);
		break;
	case 2:
		str_to_find = get_wstr(L"���� -> ", &len);
		obj = get_toy_by_wstr(list, L"price", str_to_find, len);
		if (obj != nullptr) print_toy(obj);
		break;
	case 3:
		str_to_find = get_wstr(L"���������� -> ", &len);
		obj = get_toy_by_wstr(list, L"tool_number", str_to_find, len);
		if (obj != nullptr) print_toy(obj);
		break;
	case 4:
		str_to_find = get_wstr(L"������������ �� ��������(���-���) -> ", &len);
		obj = get_toy_by_wstr(list, L"recommended_years", str_to_find, len);
		if (obj != nullptr) print_toy(obj);
		break;
	}
}


baby_toy_t* get_toy_by_wstr(list_t* list, const wchar_t* param, wchar_t* str_to_find, size_t len) {
	bool is_found = false;
	baby_toy_t* obj = nullptr;

	for (int i = 0; i < list->size; i++) {

		list_elem_t* elem = get_element(list, i);
		obj = (baby_toy_t*)elem->obj;

		if (param == L"name" and wcsncmp(str_to_find, obj->name, len) == 0) is_found = true;
		else if (param == L"price" and (float)_wtof(str_to_find) == obj->price) is_found = true;
		else if (param == L"tool_number" and (int)_wtoi(str_to_find) == obj->tool_number) is_found = true;
		else if (param == L"recommended_years" and recom_years_equal(create_year_att_from_wstr(str_to_find), obj->recommended_years)) is_found = true;
	}
	if (is_found) return obj;
	else return nullptr;
}


void change_toy(list_t* list) {
	int i;
	wprintf(L"\n������� ������ ��������, ������� ����� �������(0-%d):", list->size - 1);
	wscanf_s(L"%d", &i);
	if (i < 0 || i > list->size - 1) {
		wprintf(L"\n�������� � ����� �������� ���...");
		return;
	}
	else {
		list_elem_t* elem = get_element(list, i);
		baby_toy_t* obj = (baby_toy_t*)elem->obj;

		wprintf(L"��������. �������� ���� �������, ���� �� ������ ������...\n");
		wprintf(L"\n[%d] Element:", i);
		wchar_t buff[100];
		swprintf(buff, 100, L"\n��������: %s ->", obj->name);
		get_new_toy_field(buff, obj, L"name");

		swprintf(buff, 100, L"\n����: %.2f ->", obj->price);
		get_new_toy_field(buff, obj, L"price");

		swprintf(buff, 100, L"\n����������: %d ->", obj->tool_number);
		get_new_toy_field(buff, obj, L"tool_number");

		swprintf(buff, 100, L"\n��������������� �������: (%d-%d) ->", obj->recommended_years->from, obj->recommended_years->to);
		get_new_toy_field(buff, obj, L"recommended_years");

	}
}

void print_field(const wchar_t* prompt) {
	wprintf(prompt);
}

void get_new_toy_field(const wchar_t* prompt, baby_toy_t* obj, const wchar_t* param) {
	wprintf(prompt);

	size_t len = 100;
	wchar_t* new_field = prep_str(len);

	_cgetws_s(new_field, len, &len);
	clear_buffer();

	if (param == L"name" and len != 0) obj->name = new_field;
	else if (param == L"price" and len != 0) obj->price = _wtof(new_field);
	else if (param == L"tool_number" and len != 0) obj->tool_number = _wtoi(new_field);
	else if (param == L"recommended_years" and len != 0) obj->recommended_years = create_year_att_from_wstr(new_field);


}


void del_toy_from_list(list_t* list) {
	int i;
	printf("\n������� ������ ��������, ������� ����� �������(0-%d): ", list->size - 1);
	scanf_s("%d", &i);
	if (i < 0 || i > list->size - 1) {
		printf("\n�������� � ����� �������� ���...");
		return;
	}
	else {
		list_elem_t* elem = get_element(list, i);
		elem = del_element(list, elem);
		del_baby_toy((baby_toy_t*)elem->obj);
	}
}

baby_toy_t* get_new_toy_from_console() {
	wchar_t* name = prep_str(101);
	size_t name_len;

	wprintf(L"\n�������� �������: ");
	_cgetws_s(name, 101, &name_len);

	float price = 0;
	wprintf(L"\n����: ");
	wscanf_s(L"%f", &price);

	int number = 0;
	wprintf(L"\n����������: ");
	wscanf_s(L"%d", &number);

	wchar_t* years_att = prep_str(101);
	size_t years_len;

	wprintf(L"\n������������� �� ��������(���-���): ");
	_cgetws_s(years_att, 101, &years_len);
	year_attention_t* recom_years = create_year_att_from_wstr(years_att);

	baby_toy_t* obj = create_baby_toy(name, price, number, recom_years->from, recom_years->to);
	return obj;
}


void print_toy(baby_toy_t* obj) {
	wprintf(L"\n\t\t\t\t�������� �������: %s", obj->name);
	wprintf(L"\n\t\t\t\t����: %f", obj->price);
	wprintf(L"\n\t\t\t\t����������: %d", obj->tool_number);
	wprintf(L"\n\t\t\t\t������������� �� �����: %d-%d", obj->recommended_years->from, obj->recommended_years->to);
	wprintf(L"\n");
}

void print_toy_list(list_t* list) {
	wprintf(L"\n------------------------Current List--------------------------\n");
	for (int i = 0; i < list->size; i++) {
		list_elem_t* elem = get_element(list, i);
		baby_toy_t* obj = (baby_toy_t*)elem->obj;
		wprintf(L"\n[%d] Element:", i);
		print_toy(obj);
	}
	wprintf(L"\n--------------------------------------------------------------\n");
}