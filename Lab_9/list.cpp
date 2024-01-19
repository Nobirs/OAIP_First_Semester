#include "list.h"
//#include "information.h"

#ifndef _INC_STDLIB
//#define _INC_STDLIB
#include <stdlib.h>
#include <stdio.h>
#endif

list_t* create_list() {
	list_t* list = (list_t*)malloc(sizeof(list_t));
	list->size = 0;
	list->first = nullptr;
	list->last = nullptr;
	return list;
}

list_t* clear_list(list_t* list)
{
	for (int i = 0; i < list->size; i++) {
		list_elem_t* elem = _pop_first(list);
		free(elem);
	}
	list->size = 0;
	list->first = nullptr;
	list->last = nullptr;
	return list;
}

list_elem_t* create_list_elem(void* obj)
{
	list_elem_t* elem = (list_elem_t*)malloc(sizeof(list_elem_t));
	elem->obj = obj;
	elem->before = nullptr;
	elem->after = nullptr;
	return elem;
}


void add_first(list_t* list, list_elem_t* obj) {
	if (obj != nullptr) {

		if (list->first != nullptr) {
			list->first->before = obj;
			obj->after = list->first;
			obj->before = nullptr;
			list->first = obj;
			list->size++;
		}
		else {
			list->first = obj;
			list->last = obj;
			list->size++;
		}
	}
	else {
		printf("\n[Error]Ошибка добавление nullptr элемента в список");
	}
}

void add_last(list_t* list, list_elem_t* obj) {
	if (list->first != nullptr) {
		list->last->after = obj;
		obj->before = list->last;
		obj->after = nullptr;
		list->last = obj;
		list->size++;
	}
	else {
		list->first = obj;
		list->last = obj;
		list->size++;
	}
}


void swap_elems(list_elem_t* elem1, list_elem_t* elem2) {
	void* obj1 = elem1->obj;
	void* obj2 = elem2->obj;
	elem2->obj = obj1;
	elem1->obj = obj2;
}


list_elem_t* get_element(list_t* list, int index) {
	list_elem_t* obj = list->first;
	if (index == 0) {
		return obj;
	}
	else if (index > list->size - 1) {
		return nullptr;
	}
	for (int i = 1; i <= index; i++) {
		obj = (list_elem_t*)obj->after;
	}
	/*for (int i = 1; i < index; i++) {
		if (obj == list->first && i != index) {
			return nullptr;
		}
		obj = (list_elem_t*)obj->after;
	}*/
	return obj;
}

list_elem_t* del_element(list_t* list, list_elem_t* obj) {
	if (list->first == obj) {
		return _pop_first(list);
	}
	else if (list->last == obj) {
		return _pop_last(list);
	}
	else {
		list_elem_t* before = (list_elem_t*)obj->before;
		list_elem_t* after = (list_elem_t*)obj->after;
		before->after = (void*)after;
		after->before = (void*)before;
		obj->before = nullptr;
		obj->after = nullptr;
		list->size -= 1;
		return obj;
	}
}

list_elem_t* _pop_first(list_t* list)
{
	if (list->size == 0) {
		return nullptr;
	}
	else {
		list_elem_t* obj = list->first;
		if (obj->after == nullptr) {
			list->first = nullptr;
			list->size = 0;
		}
		else {
			list->first = (list_elem_t*)obj->after;
			list->first->before = nullptr;
			list->size -= 1;
		}
		return obj;
	}
}

list_elem_t* _pop_last(list_t* list)
{
	if (list->size == 0) {
		return nullptr;
	}
	else {
		list_elem_t* obj = list->last;
		if (obj->before == nullptr) {
			list->last = nullptr;
			list->size = 0;
		}
		else {
			list->last = (list_elem_t*)obj->before;
			list->last->after = nullptr;
			list->size -= 1;
		}
		return obj;
	}
}


list_elem_t* add_pos(list_t* list, list_elem_t* elem, int pos) {
	if (list->size == 0 || pos == 0) {
		add_first(list, elem);
	}
	else if (pos >= list->size){
		add_last(list, elem);
	}
	else {
		list_elem_t* elem_before = get_element(list, (pos-1));
		//information_t* inform_before = (information_t*)elem_before->obj;
		list_elem_t* elem_after = get_element(list,  (pos));
		//information_t* inform_after = (information_t*)elem_after->obj;

		elem_before->after = elem;
		elem->before = elem_before;
		elem_after->before = elem;
		elem->after = elem_after;
		list->size++;
	}
	return elem; 
}

