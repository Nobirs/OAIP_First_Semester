#include "table.h"
#ifndef _INC_STDLIB
//#define _INC_STDLIB
#include <stdlib.h>
#endif

table_t* create_table(wchar_t* type, wchar_t* table_material, wchar_t* legs_material, int legs_number, float size, float height) {
	table_t* obj = (table_t*)malloc(sizeof(table_t));
	obj->type = type;
	obj->table_material = table_material;
	obj->legs_material = legs_material;
	obj->legs_number = legs_number;
	obj->size = size;
	obj->height = height;
	return obj;
}

void del_table(table_t* obj) {
	free(obj->type);
	free(obj->table_material);
	free(obj->legs_material);
	free(obj);
}
