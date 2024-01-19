#pragma once

typedef struct {
	void* obj;
	void* before;
	void* after;
} list_elem_t;

typedef struct {
	int size;
	list_elem_t* first;
	list_elem_t* last;
} list_t;


list_t* create_list();
list_t* clear_list(list_t*);
list_elem_t* create_list_elem(void* obj);
void swap_elems(list_elem_t*, list_elem_t*);
void add_first(list_t* list, list_elem_t* obj);
void add_last(list_t* list, list_elem_t* obj);
list_elem_t* get_element(list_t* list, int index);
list_elem_t* del_element(list_t* list, list_elem_t* obj);
list_elem_t* _pop_first(list_t* list);
list_elem_t* _pop_last(list_t* list);

list_elem_t* add_pos(list_t* list, list_elem_t* elem, int pos);