#pragma once
#include "list.h"
#include "BabyToy.h"
#include "Console_Overall.h"


void baby_toy_start(list_t*);

void create_new_toy(list_t*);
void sort_toys_by(list_t*, const wchar_t*);
void sort_toy_list(list_t*);
void change_toy(list_t*);
void find_toy(list_t*);

void print_toy(baby_toy_t*);
void print_toy_list(list_t*);

baby_toy_t* get_new_toy_from_console();

baby_toy_t* get_toy_by_wstr(list_t*, const wchar_t*, wchar_t*, size_t);

void get_new_toy_field(const wchar_t*, baby_toy_t*, const wchar_t*);

void del_toy_from_list(list_t*);

