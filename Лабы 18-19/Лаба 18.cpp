// Лаба 18.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

//!!!!!!!!!!!!!!!!!!!Сбросьте на рабочий стол, поменяйте имя пользователя(MIX PC) (ctrl + H) на свое



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#define MAXINDEX 10

//Глобальные переменные из лабы 19
int ARR[1000];
int n1;
//int *pARR;
int Temperature[1000];
int n3;
int n4;
int Finance[1000];
int *finance;
//Задача 1 и Задача 2 (комменты - задача 2(динамический массив))
void Load() {
    // Открытие входного файла
    FILE* Filein1 = fopen("C:\\Users\\MIX PC\\Desktop\\in1(19).txt", "rt");
    if (Filein1 == NULL) {
        printf("Входной файл не найден\n");
        return;
    }

    // Загрузка массива из входного файла
    fscanf(Filein1, "%d", &n1);
    //Выделение памяти под динамический массив

    /*pARR = (int*)malloc(sizeof(int) * n1);*/

    printf("Количество оценок ученика = %d\n", n1);
    for (int i = 0; i < n1; i++) {
        fscanf(Filein1, "%d", &ARR[i] /*&pARR[i]*/);
    }
    
    // Закрытие входного файла
    fclose(Filein1);
    printf("Оценки: ");
    for (int i = 0; i < n1; i++) {
       printf("%d ", ARR[i]);
    }
}

void SaveResult() {
    // Вычисление среднего арифметического
    float sa = 0;
    float s = 0;
    for (int i = 0; i < n1; i++) {
        s += ARR[i];
        /*s += pARR[i];*/
    }
    sa = s / n1;

    // Выяснение, сколько элементов больше ср арифметического
    int m = 0;
    for (int i = 0; i < n1; i++) {
        if (/*pARR[i]*/ ARR[i] > sa) {
            m++;
        }
    }
    FILE* Fileout6 = fopen("C:\\Users\\MIX PC\\Desktop\\out1(19).txt", "wt");
    if (Fileout6 == NULL) {
        printf("Выходной файл не найден\n");
        return;
    }

    // Сохранение элементов больших ср арифметического
    fprintf(Fileout6, "Среднее арифметическое = %d\nОценки выше ср арифм: ", m);
    for (int i = 0; i < n1; i++) {
        if (/*pARR[i]*/ ARR[i] > sa) {
            fprintf(Fileout6, "%d ", ARR[i] /*pARR[i]*/);
        }
    }
    // Закрытие файла
    fclose(Fileout6);
}

int Max() {
    int max = finance[0];
    for (int i = 1; i < n4; i++) {
        if (finance[i] > max) {
            max = finance[i];
        }
    }
    return max;
}

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Задача 1 из консоли
    printf("ВласенкО Олег (хорошая работа)\nЗадача 1\n");
    printf("Введите 3 числа в консоль, для их перемножения: ");

    // Числа, читаемые из входного файла
    int a, b, c;
    scanf_s("%d%d%d", &a, &b, &c);
    // Произведение, выводимое в выходной файл
    int S;
    printf("ввели: %d, %d, %d\n", a, b, c);
    // Обработка
    S = a * b * c;
    printf("S = %d\n", S);




    //Задача 2 из файла

    printf("\nВласенкО Олег\nЗадача 2\n");
    // Числа, читаемые из входного файла
    int a1, b1, c1;
    // Произведение, выводимое в выходной файл
    int p;

    // Входной файл
    FILE* fin = fopen("C:\\Users\\MIX PC\\Desktop\\in2.txt.txt", "rt");
    if (fin == NULL) {
        printf("Входной файл не найден");
        return;
    }
    fscanf(fin, "%d%d%d", &a1, &b1, &c1);
    fclose(fin);
    // логирование ввода
    printf("ввели: %d, %d, %d\n", a1, b1, c1);

    // Обработка
    p = a1 * b1 * c1;

    // логирование вывода
    printf("p =  %d", p);

    // Запись в выходной файл

    // Выходной файл
    FILE* fout;
    fout = fopen("C:\\Users\\MIX PC\\Desktop\\out2.txt.txt", "wt");
    if (fout == NULL) {
        printf("Выходной файл не создался");
        return;
    }
    fprintf(fout, "%d", p);
    fclose(fout);
    printf("\nЧек файл out2\n\n");


    //Задача 3
    printf("\nВласенкО Олег\nЗадача 3\n");
    int q, w, e, r, t;
    int Sum;
    printf("ВВедите 5 целых числа: \n");
    scanf_s("%d%d%d%d%d", &q, &w, &e, &r, &t);
    Sum = q + w + e + r + t;
    printf("Введенные числа: %d, %d, %d, %d, %d\nСумма = %d\n", q, w, e, r, t, Sum);



    //Задача 4
    printf("\nВласенкО Олег\nЗадача 4\n");

    int q1, q2, q3, q4, q5;
    int Summa;
    FILE* filein = fopen("C:\\Users\\MIX PC\\Desktop\\in4.txt", "rt");
    if (filein == NULL) {
        printf("Выходной файл не создался");
        return;
    }
    fscanf(filein, "%d%d%d%d%d", &q1, &q2, &q3, &q4, &q5);
    fclose(filein);
    Summa = q1 + q2 + q3 + q4 + q5;

    printf("ввели: %d, %d, %d, %d, %d\n", q1, q2, q3, q4, q5);

    FILE* fileout = fopen("C:\\Users\\MIX PC\\Desktop\\out4.txt", "wt");
    if (fileout == NULL) {
        printf("Не найден файл out4");
        return;
    }
    fprintf(fileout, "%d + %d + %d + %d + %d = %d\n", q1, q2, q3, q4, q5, Summa);
    fclose(fileout);
    printf("\nЧек файл out4\n\n");


    //Задача 5 Обработка одномерного массива
    printf("\nВласенкО Олег\nЗадача 5\n");
    int array[MAXINDEX];
    int firstr;
    int i;

    FILE* Filein = fopen("C:\\Users\\MIX PC\\Desktop\\in5.txt", "rt");
    if (Filein == NULL) {
        printf("Не найден");
        return;
    }

    fscanf(Filein, "%d", &firstr);

    for (i = 0; i < firstr; i++) {
        fscanf(Filein, "%d", &array[i]);
    }

    fclose(Filein);
    
    printf("Ввели массив array[%d] = [ ", firstr);
    for (i = 0; i < firstr; i++) {
        printf("%d ", array[i]);
    }
    printf("]");
    int Average = 0;
    for (i = 0; i < firstr; i++) {
        Average += array[i];
    }
    float Summarr = float(Average)/firstr;
    printf("\nAVERAGE ARITHMETIC = %f", Summarr);

    for (i = 0; i < firstr; i++) {
        if (array[i] > Summarr) {
            array[i] *= 10;
        }
    }
    printf("\nВывели массив array[%d] = [ ", firstr);
    for (i = 0; i < firstr; i++) {
        printf("%d ", array[i]);
    }
    printf("]");
    printf("\nЧек файл out5\n\n");

    //Запись
    FILE* Fileout = fopen("C:\\Users\\MIX PC\\Desktop\\out5.txt", "wt");
    if (Fileout == NULL) {
        printf("Didnot exist");
        return;
    }

    for (i = 0; i < firstr; i++) {
        fprintf(Fileout, "%d ", array[i]);
    }
    
    fclose(Fileout);



    //Задача 6
    printf("\nВласенкО Олег\nЗадача 6\n");
    FILE *Filein6 = fopen("C:\\Users\\MIX PC\\Desktop\\in6.txt", "rt");
    int n;
    int Arr6[MAXINDEX];
    int i6;
    if (Filein6 == NULL) {
        printf("Не найден");
        return;
    }

    fscanf(Filein6, "%d", &n);

    for (i6 = 0; i6 < n; i6++) {
        fscanf(Filein6, "%d", &Arr6[i6]);
    }

    fclose(Filein6);

    printf("Ввели массив Arr6[%d] = [ ", n);
    for (i6 = 0; i6 < n; i6++) {
        printf("%d ", Arr6[i6]);
    }
    printf("]");

    int Average6 = 0;
    for (i6 = 0; i6 < n; i6++) {
        Average6 += Arr6[i6];
    }
    float SummArr6 = float(Average6) / n;
    printf("\nAVERAGE ARITHMETIC = %f", SummArr6);

    for (i6 = 0; i6 < n; i6++) {
        if (Arr6[i6] % 2 == 0 and Arr6[i6] < SummArr6) {
            Arr6[i6] /= 2;
        }
    }
    printf("\nВывели массив Arr6[%d] = [ ", n);
    for (i6 = 0; i6 < n; i6++) {
        printf("%d ", Arr6[i6]);
    }
    printf("]");

    FILE* Fileout6 = fopen("C:\\Users\\MIX PC\\Desktop\\out6.txt", "wt");
    if (Filein6 == NULL) {
        printf("Не создан");
        return;
    }

    for (i6 = 0; i6 < n; i6++) {
        fprintf(Fileout6, "%d ", Arr6[i6]);
    }
    printf("\nЧек файл out6\n\n");
    fclose(Fileout6);
    printf("\n\n\n\n");

    //Мои так называемые задачи 7-8 - см. файл лаба16.cpp (case15 - 334 строка и 352 строка)

    //Лаба 19 Динамические массивы.
    
    printf("\nЛабораторная №19. ВласенкО Олег\nЗадача 1-2\n");
    
    Load();
    SaveResult();

    /*free(pARR);*/
    printf("\nЧек файл out1(19)\n\n");
    
    printf("\nВласенкО Олег\nЗадача 3\n");


    FILE* Tempin = fopen("C:\\Users\\MIX PC\\Desktop\\in3(19).txt", "rt");
    if (Tempin == NULL) {
        printf("Не удается открыть файл");
        return;
    }
    fscanf(Tempin, "%d", &n3);
    printf("Количество измерений = %d\n", n3);

    for (int i = 0; i < n3; i++) {
        fscanf(Tempin, "%d ", &Temperature[i]);

    }
    fclose(Tempin);
    printf("Ввели массив Temperature[%d] = [ ", n3);
    for (int i = 0; i < n3; i++) {
        printf("%d ", Temperature[i]);
    }
    printf("]");
    int Sumtemp = 0;
    for (int i = 0; i < n3; i++) {
        Sumtemp += Temperature[i];
    }

    double AverageTemp = double(Sumtemp) / n3;
    
    FILE *Tempout = fopen("C:\\Users\\MIX PC\\Desktop\\out3(19).txt", "wt");
    if (Tempout == NULL) {
        printf("Не удалось создать файл");
        return;
    }
    //Почему на выводе среднего арифмeтического выводятся мусорные значения, но алгоритм правильно выводит в файл элементы меньшие среднего арифм?
    printf("\nСреднее аримфетическое = %d\n", AverageTemp);
    for (int i = 0; i < n3; i++) {
        if (Temperature[i] > 0 and Temperature[i] < AverageTemp) {
            fprintf(Tempout, "%d ", Temperature[i]);
        }
    }
    printf("\nЧек файл out3(19)\n\n");








    //Задача 4
    
    printf("\nВласенкО Олег\nЗадача 4\n");
    // Открытие входного файла
    FILE* Filein4 = fopen("C:\\Users\\MIX PC\\Desktop\\in4(19).txt", "rt");
    if (Filein4 == NULL) {
        printf("Входной файл не найден\n");
        return;
    }

    // Загрузка массива из входного файла
    fscanf(Filein4, "%d\n", &n4);
    //Выделение памяти под динамический массив

    finance = (int*)malloc(sizeof(int) * n4);

    printf("Количество доходов = %d\n", n4);
    for (int i = 0; i < n4; i++) {
        fscanf(Filein4, "%d", &finance[i]);
    }

    // Закрытие входного файла
    fclose(Filein4);
    printf("Доходы: ");
    for (int i = 0; i < n4; i++) {
        printf("%d ", finance[i]);
    }

    
    // ненавижу флоат, поэтому инт
    int m1 = 0;
    int Maximum = Max();
    int Ifmax0 = Maximum * 2;
    int Ifmax = Ifmax0 / 3;
    for (int i = 0; i < n4; i++) {
        if (finance[i] >= Ifmax) {
            m1++;
        }
    }

    FILE* Fileout4 = fopen("C:\\Users\\MIX PC\\Desktop\\out4(19).txt", "wt");
    if (Fileout4 == NULL) {
        printf("Выходной файл не найден\n");
        return;
    }


    fprintf(Fileout4, "Количество доходов, составляющих как минимум 2/3 от максимального дохода = %d\n", m1);
    

   
    
    // Закрытие файла
    printf("\n2/3 от максимального элемента = %d\n", Ifmax);
    for (int i = 0; i < n4; i++) {
        if (finance[i] >= Ifmax) {
            fprintf(Fileout4, "%d ", finance[i]);
        }
    }
    free(finance);
    fclose(Fileout4);


    
    printf("\nЧек файл out4(19)\n\n");

}

