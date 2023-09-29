#pragma once
#include <wchar.h>

typedef struct {
	int from;
	int to;
} year_attention_t;

typedef struct {
	wchar_t* name;
	float price;
	int tool_number;
	year_attention_t recommended_years;
} baby_tool_t;


baby_tool_t* add_baby_tool();
baby_tool_t* sort_baby_tools(baby_tool_t* list);
baby_tool_t* find_baby_tool(baby_tool_t* list);
baby_tool_t* change_baby_tool(baby_tool_t* obj);
baby_tool_t* del_baby_tool(baby_tool_t* obj, baby_tool_t* list);
void print_tables(baby_tool_t* list, void* print_func(void*));