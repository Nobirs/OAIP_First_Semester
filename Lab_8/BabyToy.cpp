#include "BabyToy.h"

year_attention_t* create_year_att_from_wstr(wchar_t* str) {
	// Needed format -> year-year  (2-15)
	int from = 0, to = 0;
	year_attention_t* obj = nullptr;
	wchar_t* hyphen_p = wcschr(str, '-');

	if (hyphen_p != nullptr) {
		const wchar_t* from_year = str;
		const wchar_t* to_year = hyphen_p + 1;

		from = _wtoi(from_year);
		to = _wtoi(to_year);

		if (from <= to) obj = create_year_att(from, to);

		return obj;
	}
	return nullptr;
}


year_attention_t* create_year_att(int from, int to)
{
	year_attention_t* obj = (year_attention_t*)malloc(sizeof(year_attention_t));
	if (obj) {
		obj->from = from;
		obj->to = to;
	}
	return obj;
}

baby_toy_t* create_baby_toy(wchar_t* name, float price, int tool_number, int year_from, int year_to) {
	baby_toy_t* obj = (baby_toy_t*)malloc(sizeof(baby_toy_t));
	obj->name = name;
	obj->price = price;
	obj->tool_number = tool_number;

	year_attention_t* year_obj = (year_attention_t*)malloc(sizeof(year_attention_t));
	year_obj->from = year_from;
	year_obj->to = year_to;
	obj->recommended_years = year_obj;

	return obj;
}


bool comp_toys_by(baby_toy_t* obj_1, baby_toy_t* obj_2,const wchar_t* param)
{
	bool is_more = false;

	if (param == L"name") is_more = wcscmp(obj_1->name, obj_2->name) > 0;
	else if (param == L"price") is_more = obj_1->price > obj_2->price;
	else if (param == L"tool_number") is_more = obj_1->tool_number > obj_2->tool_number;
	else if (param == L"recommended_years") is_more = comp_year_attention(obj_1->recommended_years, obj_2->recommended_years);

	return is_more;
}

baby_toy_t* get_toy_by(list_t* list, const wchar_t* param)
{
	for (int i = 0; i < list->size; i++) {

		list_elem_t* elem = get_element(list, i);
		baby_toy_t* obj = (baby_toy_t*)elem->obj;

	}
	return nullptr;
}


bool recom_years_equal(year_attention_t* obj1, year_attention_t* obj2) {
	if (obj1->from == obj2->from and obj1->to == obj2->to) {
		return true;
	}
	return false;
}


bool comp_year_attention(year_attention_t* obj1, year_attention_t* obj2) {

	if (obj1->from > obj2->from) return true;
	else if (obj1->from == obj2->from) return (obj1->to > obj2->to);

	return false;
}


void del_baby_toy(baby_toy_t* obj) {
	free(obj->name);
	free(obj);
}