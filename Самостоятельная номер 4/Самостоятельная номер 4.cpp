﻿// Самостоятельная номер 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>

int a2[5] = { 2, 3, 4, 5, 6 };
int b2[6] = { 1, 2, 3, 4, 5, 6 };

void main()
{
    // Задача 31B

    int  k, a, b;

    scanf_s("%d%d", &a, &b);

    for (k = b; k >= a; k -= a)
        printf("%d ", k);
    printf("\n");
    for (k = b * 2; k <= b * b / a; k += b)
        printf("%d\n", k);
    //Тест 1. Введите 
    //2 8

    //Тест 2. Введите
    //2 10

    //Тест 3. Введите
    //1 10


    
    // Задача 32B

    int  i, s;

    for (i = 0; i < 5; i++)
        if (a2[i] % 2 == 0)
            a2[i] = 2;

    s = -2;
    for (i = 2; i < 5; i++)
        s += a2[i];

    printf("%d", s);
    //Тест 1. Выполните код.



    // Задача 33B
        
    int  i, k, t;

    scanf_s("%d", &k);

    t = b2[k];
    for (i = k; i > 0; i--)
        b2[i] = b2[i - 1];
    b2[0] = t;

    for (i = 0; i < 6; i++)
        printf("%d ", b2[i]);
    //Тест 1. Введите
    //3

    //Тест 2. Введите
    //0

    //Тест 3. Введите
    //5


}
