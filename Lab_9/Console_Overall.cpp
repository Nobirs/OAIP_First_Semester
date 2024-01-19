#include "Console_Overall.h"
#include "Console_Information.h"



int element_menu() {
	int choice = 0;
	printf("\n\t1.Create element"); // complete
	printf("\n\t2.Sort elements");  // complete
	printf("\n\t3.Find element by parameter"); // complete
	printf("\n\t4.Change element"); // complete
	printf("\n\t5.Delete element"); // complete
	printf("\n\t6.View all elements"); // complete
	printf("\n\t7.Insert at position");
	printf("\n\t8.Save list to Binary file");
	printf("\n\t9.Load list from Binary file");
	printf("\n\t10.Find object in file by name");
	printf("\n\t11.Save info to the end of file");
	printf("\n\t0.Exit");				// complete
	printf("\n\t->");
	scanf_s("%d", &choice);
	return choice;
}


wchar_t* prep_str(int length) {
	wchar_t* str = (wchar_t*)malloc(length * sizeof(wchar_t));

	if (!str) {
		printf("\n[Error]\tОшибка выделения памяти");
		return nullptr;
	}
	return str;
}

wchar_t* get_wstr(const wchar_t* prompts, size_t* len)
{
	wchar_t* str = prep_str(STR_BUFFER_SIZE);
	if (str) {
		wprintf(prompts);
		_cgetws_s(str, STR_BUFFER_SIZE, len);
		
		clear_buffer();

		return str;
	}
	return nullptr;
}


void clear_buffer() {
	while (_kbhit()) { //  While buffer is not empty
		getchar();
	}
	return;
}