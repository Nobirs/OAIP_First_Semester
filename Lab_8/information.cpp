#include "information.h"
#ifndef _INC_STDLIB
#include <stdlib.h>
#endif

information_t* add_information(wchar_t* keeper, float size, wchar_t* name, wchar_t* author) {
	information_t* obj;
	obj->keeper = keeper;
	obj->size = size;
	obj->name = name;
	obj->author = author;
	return obj;
}

void del_information(information_t* obj) {
	free(obj->keeper);
	free(obj->name);
	free(obj->author);
	free(obj);
}