#pragma once
#include <wchar.h>
#include <stdlib.h>

#include "list.h"

typedef struct {
	wchar_t* keeper;
	float size;
	wchar_t* name;
	wchar_t* author;
} information_t;


void del_information(information_t* obj);
information_t* create_information(wchar_t*, float, wchar_t*, wchar_t*);

bool comp_info_by(information_t*, information_t*, const wchar_t*);