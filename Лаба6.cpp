#include <stdio.h>
#include <Windows.h>
//Лабораторная работа №6

void main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Задача 1. Ряд натуральных чисел
	printf("Задача 1. Ряд натуральных чисел \n");

	int i, n;
	printf("n = ");
	scanf_s("%d", &n);
	i = 1;
	do {
		printf("%d ", i);
		i = i + 1;
	} while (i <= n);

	printf("\n");
	printf("\n");

	//Задача 2. Степени двойки
	printf("Задача 2. Степени двойки \n");

	int i1 = 0;
	int stepen = 1;

	do {
		printf("2^%d = %d\n", i1, stepen);
		stepen *= 2;
		i1++;
	} while (i1<=5);

	printf("\n");

	//Задача 4. Вывод первых N четных чисел
	printf("Задача 4. Вывод первых N четных чисел \n");

	int n1, chet, n2;
	n2 = 1;
	printf("n1 = ");
	scanf_s("%d", &n1);
	chet = 2;
	do {
		printf("%d ", chet);
		chet += 2;
		n2++;
	} while (n2<=n1);

	printf("\n");
	printf("\n");

	//Задача 5. Вывод первых N чисел кратных A
	printf("Задача 5. Вывод первых N чисел кратных A \n");

	int N, A;
	printf("Введите N: ");
	scanf_s("%d", &N);
	printf("Введите A: ");
	scanf_s("%d", &A);

	int step = 1;
	int count = 0;

	do {
		int multiple = A * step;
		printf("%d ", multiple);
		count++;
		step++;
	} while (count < N);

	printf("\n");
	printf("\n");

	//Задача 6. Первые N чисел Фибоначчи.
	printf("Задача 6. Первые N чисел Фибоначчи.\n");
	int first, second, next, Number,Counter;
	Counter = 3;
	first = 0;
	second = 1;
	printf("Введите N: ");
	scanf_s("%d", &Number);
	if (N >= 1) {
		printf("%d ", first);
	}
	if (N >= 2) {
		printf("%d ", second);
	}

	do {	
		next = first + second;
		printf("%d ", next);
		first = second;
		second = next;
		Counter++;
	} while (Counter <= Number);
	printf(" \n");
}
