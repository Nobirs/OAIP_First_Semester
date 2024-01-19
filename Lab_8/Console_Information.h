#pragma once
#include "list.h"
#include "information.h"
#include "Console_Overall.h"


void information_start(list_t* list);

void create_new_info(list_t* list);
void sort_info_list(list_t* list);
void change_info(list_t* list);
void find_info(list_t* list);


void print_info(information_t*);
void print_info_list(list_t*);

information_t* get_new_info_from_console();

void get_new_info_field(const wchar_t*, information_t*, const wchar_t*);

void del_info_from_list(list_t* list);

void sort_info_by(list_t* list, const wchar_t* param);
information_t* get_info_by_wstr(list_t* list, const wchar_t* param, wchar_t* str_to_find, size_t len);