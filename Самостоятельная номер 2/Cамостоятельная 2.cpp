// Cамостоятельная 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>

void main()
{
    // Задача 11.B
    int a, b, s;

    scanf_s("%d%d", &a, &b);

    s = 0;
    while (a <= b) {
        s += a;
        a += 4;
        printf("%d ", s);
    }

    //Задача 12.B


    int a, b;
    scanf_s("%d", &a);

    b = 1;
    while (b <= a) {

        printf("\n %d", b);

        if (b % 3 == 0)
            printf("*");

        if (b % 4 == 0)
            printf(":");

        b++;
    }

    // Задача 13.B
    int  a, b, k, s;

    scanf_s("%d%d", &a, &b);
    k = 1;
    s = a;
    while (k <= b) {
        s += k;
        k += 1;
        printf("%d ", s);
        if (s % 7 == 0)
            break;
    }
}

