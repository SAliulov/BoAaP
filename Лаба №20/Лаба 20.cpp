// Лаба 20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#define MAX_N 8
#define MAX_M 10
int arr[MAX_N][MAX_M] = {
    { 0,  1,  222,  3},
    {10, 11, 12, 13},
    {20, 21, 22, 23}
};

//Глобальные переменные
int n = 3;
int m = 4;

void print() {
    printf("!!!! print() !!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d ", arr[i][j]);
        }
        printf("\n");
    }
}

void fillIx10() {
    printf("!!!! fillIx10() !!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = i * 10 + j;
        }
    }
}

void fillZero() {
    printf("!!!! fillZero() !!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = 0;
        }
    }
}

void randFill() {
    printf("!!!! randFill() !!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand();
        }
    }
}


void alloddx10() {
    printf("!!!! alloddx10() !!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] % 2 != 0) {
                arr[i][j] *= 10;
            }
        }
    }
}

void allmultof10divide10() {
    printf("!!!! alloddx10() !!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] % 10 == 0) {
                arr[i][j] /= 10;
            }
        }
    }
}

void entermassive() {
    printf("!!!! entermassive !!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &arr[i][j]);
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void SaveArr() {
    FILE* fileout = fopen("C:\\Users\\MIX PC\\Desktop\\SaveArr.txt", "wt");
    if (fileout == NULL) {
        printf("Не удалось записать массив в файл");
        return;
    }
    
    fprintf(fileout, "Размерность массива = %d x %d\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(fileout, "%d ", arr[i][j]);
        }
        fprintf(fileout, "\n");
    }
    printf("Массив успешно записан в файл SaveArr.txt\n\n\n");

    fclose(fileout);
}

void LoadArr() {
    FILE* filein = fopen("C:\\Users\\MIX PC\\Desktop\\LoadArr.txt", "rt");
    if (filein == NULL) {
        printf("Не удалось загрузить массив из файла");
        return;
    }
    printf("Размерность массива %d x %d\n\n\n", n, m);
    fscanf(filein, "%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(filein, "%d ", &arr[i][j]);
        }
        printf("\n");
    }
    printf("Массив успешно загружен из файла LoadArr.txt\n\n");
    fclose(filein);
}

void deleteRow(int delRow) {
    printf("!!!! deleteRow(%d) !!!!\n", delRow);
    //delRow-1, чтобы при вводе 1 удалялась строка под человеческим номером 1 (а не вторая)
    for (int i = delRow-1; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = arr[i + 1][j];
        }
    }
    n--;
}


void СopySpecArrayColumn(int column) {
    printf("!!!! СopySpecifiedArrayColumn(%d) !!!!\n", column);

    if (m < MAX_M) {
        for (int i = 0; i < n; i++) {
            //column-1, чтобы при вводе 1 удалялась строка под человеческим номером 1 (а не вторая)
            arr[i][m] = arr[i][column-1];
        }
        m++;
    }
}

//Удаление тех столбцов, в которых есть хотя бы 2 одинаковых элемента
void removeDuplicateColumns() {
    int duplicateFound = 0;
    int newN = n;
    // i - столбцы, j - строки, duplicateFound - флаг
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < newN - 1; j++) {
            for (int k = j + 1; k < newN; k++) {
                if (arr[j][i] == arr[k][i]) {
                    duplicateFound = 1;
                    break;
                }
            }
            if (duplicateFound) {
                for (int l = i; l < m - 1; l++) {
                    for (int p = 0; p < newN; p++) {
                        arr[p][l] = arr[p][l + 1];
                    }
                }
                m--;
                i--;
                duplicateFound = 0;
                break;
            }
        }
    }
    n = newN;
}



void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("main() start\n");

    int n;

    do {
        printf("\n");
        print();
        printf("\n");
        printf("Введите номер нужной вам операции:\n");
        printf("1: Заполнить значениями i * 10 + j\n");
        printf("2: Заполнить  нулями\n");
        printf("3: Заполнить случайными значениями\n");
        printf("4: Все нечетные увеличить в 10 раз\n");
        printf("5: Все кратные 10 уменьшить в 10 раз\n");
        printf("6: Ввод массива с клавиатуры\n");
        printf("7: Сохранение состояния массива в файл\n");
        printf("8: Загрузка массива из файла\n");
        printf("9: Удалить заданную строку из массива\n");
        printf("10: Продублировать заданный столбец\n");
        printf("11: Вариант B1: Удалить те столбцы, в которых встречается хотя бы два одинаковых элемента.");
        printf("\n\n-1: Выход их программы\n");
        scanf_s("%d", &n);
        switch (n) {
        case 1:
            fillIx10();
            break;
        case 2:
            fillZero();
            break;
        case 3:
            randFill();
            break;
        case 4:
            alloddx10();
            break;
        case 5:
            allmultof10divide10();
            break;
        case 6:
            entermassive();
            break;
        case 7:
            SaveArr();
            break;
        case 8:
            LoadArr();
            break;
        case 9:
            printf("Напишите строку, которую хотите удалить\n");
            int string;
            scanf_s("%d", &string);
            deleteRow(string);
            break;
        case 10:
            printf("Напишите столбец, который хотите скопировать\n");
            int column;
            scanf_s("%d", &column);
            СopySpecArrayColumn(column);
            break;
        case 11:
            removeDuplicateColumns();
            break;
        }

    } while (n != -1);
    printf("\nmain() finish");
}
