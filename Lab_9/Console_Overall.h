#pragma once
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



int element_menu();

wchar_t* prep_str(int length);
wchar_t* get_wstr(const wchar_t*, size_t*);
void clear_buffer();