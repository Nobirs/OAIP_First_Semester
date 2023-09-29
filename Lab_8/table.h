#pragma once
#include <wchar.h>

typedef struct {
	wchar_t* type;
	wchar_t* table_material;
	wchar_t* legs_material;
	int legs_number;
	float size;
	float height;
} table_t;

table_t* add_table();
table_t* sort_tables(table_t* list);
table_t* find_table(table_t* list);
table_t* change_table(table_t* obj);
table_t* del_table(table_t* obj, table_t* list);
void print_tables(table_t* list, void* print_func(void*));