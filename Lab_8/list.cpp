#include "list.h"

list_t* create_list() {
	list_t list;
	list.size = 0;
	list.first = nullptr;
	list.last = nullptr;
	return &list;
}


void add_first(list_t* list, list_elem_t* obj) {
	list->first->before = obj;
	obj->after = list->first;
	obj->before = nullptr;
	list->first = obj;
	list->size += 1;
}

void add_last(list_t* list, list_elem_t* obj) {
	list->last->after = obj;
	obj->before = list->last;
	obj->after = nullptr;
	list->last = obj;
	list->size += 1;
}

list_elem_t* get_element(list_t* list, int index) {
	list_elem_t* obj = list->first;
	for (int i = 1; i <= index; i++) {
		if (obj == list->last) {
			return nullptr;
		}
		obj = (list_elem_t*)obj->after;
	}
	return obj;
}

list_elem_t* del_element(list_t* list, list_elem_t* obj) {
	list_elem_t* before = (list_elem_t*)obj->before;
	list_elem_t* after = (list_elem_t*)obj->after;
	before->after = after;
	after->before = before;
	list->size -= 1;
	return obj;
}