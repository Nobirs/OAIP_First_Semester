#include "information.h"


information_t* create_information(wchar_t* keeper, float size, wchar_t* name, wchar_t* author) {
	information_t* obj = (information_t*)malloc(sizeof(information_t));
	obj->keeper = keeper;
	obj->size = size;
	obj->name = name;
	obj->author = author;
	return obj;
}

bool comp_info_by(information_t* obj1, information_t* obj2, const wchar_t* param)
{
	bool is_more = false;

	if (param == L"keeper") is_more = wcscmp(obj1->name, obj2->name) > 0;
	else if (param == L"size") is_more = (obj1->size > obj2->size);
	else if (param == L"name") is_more = wcscmp(obj1->name, obj2->name) > 0;
	else if (param == L"author") is_more = wcscmp(obj1->author, obj2->author) > 0;

	return is_more;
}


void del_information(information_t* obj) {
	free(obj->keeper);
	free(obj->name);
	free(obj->author);
	free(obj);
}