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


table_t* create_table(wchar_t* type, wchar_t* table_material, wchar_t* legs_material, int legs_number, float size, float height);
void del_table(table_t* obj);