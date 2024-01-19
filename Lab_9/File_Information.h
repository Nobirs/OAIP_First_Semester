#pragma once

#include <stdlib.h>

#include "list.h"
#include "information.h"
#include "Console_Overall.h"
#include "Console_Information.h"


void save_list_to_binary_file(list_t* list);
int save_info_to_binary_file(information_t*, FILE*);
int save_info_to_the_end_of_file(list_t*);
information_t* read_info_from_binary_file(FILE*);
void load_list_from_binary_file(list_t* list);
void find_in_file_by_author();