// Лаба23.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
#define MAX_LEN 100
char s[MAX_LEN];

int getNextDelim(FILE* fp, char token[]);
int getNextWord(FILE* fp, char token[], int maxLen);

char filename[] = "C:\\Users\\MIX PC\\Desktop\\Filename.txt";
char filenameIn[] = "C:\\Users\\MIX PC\\Desktop\\Alice.txt";
char filenameHTML[] = "C:\\Users\\MIX PC\\Desktop\\AliceHTML.html";

int isalpha_my(unsigned char ch);

// Возвращает 1 - если  из файла прочитан разделитель.
// В этом случае в token возвращается строка, содержащая 
// этот разделитель.
// Если в файле был не разделитель - возвращает 0.
// В этом случае состояние token неопределено.
int getNextDelim(FILE* fp, char token[])
{
    int ch = getc(fp);
    if (ch == EOF) {
        return 0;
    }
    if (isalpha_my((unsigned char)ch)) {
        ungetc(ch, fp);
        return 0;
    }
    token[0] = (unsigned char)ch;
    token[1] = '\0';
        return 1;
}

// Возвращает 1 - если  из файла прочитано слово.
// В этом случае в token возвращается строка, содержащая 
// это слово. Гарантируется что слово не болеее maxLen символов.
// Если в файле не было буквы - возвращает 0.
// В этом случае token содержит пустую строку.
int getNextWord(FILE* fp, char token[], int maxLen)
{
    int i = 0;
    int ch;
    while (((ch = getc(fp)) != EOF) && (i < maxLen - 1)) {
        if (!isalpha_my((unsigned char)(ch))) {
            break;
        }
        token[i++] = ch;
    }
    ungetc(ch, fp);
    token[i] = '\0';
        if (i == 0)
            return 0;
    return 1;
}

// Возвращает 0 - если ch - не буква.
// Возвращает 1 - если ch - буква.
// Корректно работает для латинских букв (с кодами < 128)
// И для русских букв из кодировки ANSI
int isalpha_my(unsigned char ch) {
    if (isalpha(ch))
        return 1;

    // ANSI кодировка!!!
    if (ch >= 192 && ch <= 223)
        return 1;
    if (ch >= 224 && ch <= 255)
        return 1;

    /*
    if (ch >= 'А' && ch <= 'Я') return 1;
    if (ch >= 'а' && ch <= 'п') return 1;
    if (ch >= 'р' && ch <= 'я')return 1;
    if (ch == 'ё' ) return 1;
    if (ch == 'Ё') return 1;*/

    return 0;
}

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("Власенко Олег\n");
    printf("ЛР23 Задача 1\n");

    //Задача 1
    // Входной файл
    FILE* fin = fopen("C:\\Users\\MIX PC\\Desktop\\Text1.txt", "rt");
    if (fin == NULL) {
        printf("Входной файл не найден");
        return;
    }

    // Выходной файл
    FILE* fout;
    fout = fopen("C:\\Users\\MIX PC\\Desktop\\out1.txt", "wt");
    if (fout == NULL) {
        printf("Выходной файл не создался");
        return;
    }

    // в цикле для всех строк
    while (!feof(fin)) {
        // загрузить строку
        if (fgets(s, MAX_LEN - 1, fin) != NULL) {
            // обработать загруженную строку
            for (int i = 0; s[i] != '\0'; i++) {

                if (s[i] == '\t') // Если прочитан пробел
                    s[i] = '%'; // Заменяем его на '%’

            }
            // сохранить строку в выходной файл
            fprintf(fout, "%s", s);
            printf(">>%s<<\n", s);
        }
    }
    // закрыли файлы
    fclose(fin);
    fclose(fout);

    printf("ЛР23 Задача 1 FINISH\n");

    //Задача 2
    // Входной файл
    FILE* fin2 = fopen("C:\\Users\\MIX PC\\Desktop\\text2.txt", "rt");
    if (fin2 == NULL) {
        printf("Входной файл не найден");
        return;
    }

    // Выходной файл
    FILE* fout2;
    fout2 = fopen("C:\\Users\\MIX PC\\Desktop\\out2.txt", "wt");
    if (fout2 == NULL) {
        printf("Выходной файл не создался");
        return;
    }

    // в цикле для всех строк
    while (!feof(fin2)) {
        // загрузить строку
        if (fgets(s, MAX_LEN - 1, fin2) != NULL) {
            // обработать загруженную строку
            for (int i = 0; s[i] != '\0'; i++) {
                s[i] = toupper(s[i]);
            }
            // сохранить строку в выходной файл
            fprintf(fout2, "%s", s);
            printf(">>%s<<\n", s);
        }
    }
    // закрыли файлы
    fclose(fin2);
    fclose(fout2);

    printf("ЛР23 Задача 2 FINISH\n\n\n");

    //Задача 3
    // Входной файл
    FILE* fin3 = fopen("C:\\Users\\MIX PC\\Desktop\\text3.txt", "rt");
    if (fin3 == NULL) {
        printf("Входной файл не найден");
        return;
    }

    // Выходной файл
    FILE* fout3;
    fout3 = fopen("C:\\Users\\MIX PC\\Desktop\\out3.txt", "wt");
    if (fout3 == NULL) {
        printf("Выходной файл не создался");
        return;
    }

    while (fgets(s, MAX_LEN, fin3) != NULL) {
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '\n') {
                s[i] = '\0';
                break;
            }
        }
        fprintf(fout3, "%s#\n", s);
    }

    // закрыли файлы
    fclose(fin3);
    fclose(fout3);

    printf("ЛР23 Задача 3 FINISH\n");

    //Задача 4
    printf("BEGIN!!!\n");
    // открываем файл с текстом
    FILE* fin4 = fopen(filename, "rt");
    if (fin4 == NULL) {
        // если файл не смогли открыть - сообщаем об этом
        printf("File %s doesn't opened!\n", filename);
        return;
    }
    char token[MAX_LEN];
    int res;

    // пока не конец файла
    while (!feof(fin)) {
        // пока есть разделитель - берем его
        while (getNextDelim(fin, token)) {
            // выводим разделитель в консоль
            printf("<DELIM>%s</DELIM>\n", token);
        }
        // если есть слово - берем его
        if (getNextWord(fin, token, MAX_LEN)) {
            // выводим слово в консоль
            printf("<WORD>%s</WORD>\n", token);
        }
    }

    // Закрываем файл с текстом
    fclose(fin);
    printf("END!!!\n");

    //Задача 5
    FILE* fin5 = fopen(filenameIn, "rt");
    if (fin5 == NULL) {
        // если файл не смогли открыть - сообщаем об этом
        printf("File %s doesn't opened!\n", filenameIn);
        return;
    }

    // открыть HTML файл (выходной файл)  
    FILE* fout5 = fopen(filenameHTML, "wt");
    if (fout5 == NULL) {
        // закрываем ранее успешно открытый входной файл 
        fclose(fin5);
        // если файл не смогли открыть - сообщаем об этом
        printf("File %s doesn't opened!\n", filenameHTML);
        return;
    }


    // Выводим в выходной файл заголовок HTML документа
    fprintf(fout5, "<!DOCTYPE html>");
    fprintf(fout5, "<html>");
    fprintf(fout5, "<head>");
    fprintf(fout5, "<meta http - equiv = \"Content-Type\" content =  \"text/html;charset=utf-8\" />");
    fprintf(fout5, "<title>HTML Document</title>");
    fprintf(fout5, "</head>");
    fprintf(fout5, "<body>");
    int ch;
    while ((ch = getc(fin5)) != EOF) {
        // в HTML файл добавляем только что прочитанный 
        // символ "КАК ЕСТЬ"
        fprintf(fout5, "%c", ch);

        // если в тексте был символ новой строки – 
        // в HTML добавляем тег <BR> - новая строка
        if (ch == '\n')
            fprintf(fout5, "<br>");
    }
    // выводит в HTML завершающие теги документа HTML
    fprintf(fout5, "</body>");
    fprintf(fout5, "</html>");

    // Закрываем файл с текстом
    fclose(fin5);

    // Закрываем HTML файл 
    fclose(fout5);
    printf("END!!!\n");

    FILE* fin6 = fopen("C:\\Users\\MIX PC\\Desktop\\text6.txt", "rt");
    FILE* fout6 = fopen("C:\\Users\\MIX PC\\Desktop\\out6.txt", "wt");

    if (fin6 == NULL || fout6 == NULL) {
        printf("Ошибка открытия файла\n");
        return;
    }

    while (fgets(s, MAX_LEN, fin6) != NULL) {
        int count = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == ';') {
                count++;
            }
        }
        fprintf(fout6, "%s %d\n", s, count);
    }

    fclose(fin6);
    fclose(fout6);

    printf("Программа выполнена успешно\n");

    //Задача 7
    FILE* fin7 = fopen("C:\\Users\\MIX PC\\Desktop\\in7.txt", "rt");
    if (fin7 == NULL) {
        printf("Ошибка открытия входного файла");
        return;
    }

    FILE* fout7 = fopen("C:\\Users\\MIX PC\\Desktop\\out7.txt", "wt");
    if (fout7 == NULL) {
        printf("Ошибка открытия выходного файла");
        fclose(fin7);
        return;
    }

    while (fgets(s, MAX_LEN, fin7) != NULL) {
        for (int i = 0; s[i] != '\0'; i++) {
            if (strchr("aeiouAEIOU", s[i])) {
                fprintf(fout7, "&");
            }
            else {
                fprintf(fout7, "%c", s[i]);
            }
        }
    }

    fclose(fin7);
    fclose(fout7);

    printf("Замена завершена\n");
}

