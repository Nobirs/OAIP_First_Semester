#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <conio.h>

#include "Console_Overall.h"

#include "information.h"
#include "Console_Information.h"

#include "BabyToy.h"
#include "Console_BabyToy.h"

#include "table.h"
#include "Console_Table.h"

#include "list.h"


int main(int argc, char** argv) {
	setlocale(LC_ALL, "rus");

	int choice = 0;
	list_t* info_list = create_list();
	list_t* baby_tools_list = create_list();
	list_t* tables_list = create_list();
	while (1) {
		printf("\nВыберите объект для действий: ");
		printf("\n1.Information");
		/*printf("\n2.Baby tool");
		printf("\n3.Table");*/
		printf("\n0.Exit the program");
		printf("\n->");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1: information_start(info_list); break;
		//case 2: baby_toy_start(baby_tools_list); break;
		//case 3: table_start(tables_list); break;
		case 0: printf("\n\v\t\t\t\tExit the program...\n\n\n\n"); return 0;
		}
	}

	return 0;
}
