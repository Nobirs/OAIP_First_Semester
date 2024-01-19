#pragma once
#include <wchar.h>
#include <stdlib.h>

#include "list.h"

typedef struct {
	int from;
	int to;
} year_attention_t;

typedef struct {
	wchar_t* name;
	float price;
	int tool_number;
	year_attention_t* recommended_years;
} baby_toy_t;

year_attention_t* create_year_att_from_wstr(wchar_t* str);
year_attention_t* create_year_att(int from, int to);
baby_toy_t* create_baby_toy(wchar_t* name, float price, int tool_number, int year_from, int year_to);
void del_baby_toy(baby_toy_t* obj);

bool comp_toys_by(baby_toy_t*, baby_toy_t*,const wchar_t*);
baby_toy_t* get_toy_by(list_t*, const wchar_t*);
bool comp_year_attention(year_attention_t*, year_attention_t*);
bool recom_years_equal(year_attention_t*, year_attention_t*);
