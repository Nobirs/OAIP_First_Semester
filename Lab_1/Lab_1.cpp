#include <stdlib.h>
#include <stdio.h>


int main(){
    int A[5];
    int B[5];
    int C[5];
    FILE* file_a;
    FILE* file_b;
    FILE* file_c;
    FILE* file_d;

    fopen_s(&file_a, "nameA.txt", "w");
    fopen_s(&file_b, "nameB.txt", "w");
    fopen_s(&file_c, "nameC.txt", "w");

    printf("\nВведите данные для первого файла:\n");
    for(int i = 0; i < 5; i++){
        scanf_s("%d", &A[i]);
        fprintf(file_a, "%d\n", A[i]);
    }
    fclose(file_a);

     printf("\nВведите данные для второго файла:\n");
    for(int i = 0; i < 5; i++){
        scanf_s("%d", &B[i]);
        fprintf(file_b, "%d\n", B[i]);
    }
    fclose(file_b);

     printf("\nВведите данные для третьего файла:\n");
    for(int i = 0; i < 5; i++){
        scanf_s("%d", &C[i]);
        fprintf(file_c, "%d\n", C[i]);
    }
    fclose(file_c);

    fopen_s(&file_a, "nameA.txt", "r");
    fopen_s(&file_b, "nameB.txt", "r");
    fopen_s(&file_c, "nameC.txt", "r");
    fopen_s(&file_d, "nameC.txt", "w");

    int ind = 0;
    for(int i = 0; i < 15; i++){
        int a, b, c;
        fscanf_s(file_a, "%d", &a);
        fscanf_s(file_b, "%d", &b);
        fscanf_s(file_c, "%d", &c);
        fprintf(file_d, "%d %d %d", a, b, c);
    }

    fclose(file_a);
    fclose(file_b);
    fclose(file_c);
    fclose(file_d);










}