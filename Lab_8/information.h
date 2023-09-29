#pragma once
#include <wchar.h>

typedef struct {
	wchar_t* keeper;
	float size;
	wchar_t* name;
	wchar_t* author;
} information_t;


information_t* add_information(wchar_t*, float, wchar_t*, wchar_t*);
void del_information(information_t* obj);