// Самостоятельная №3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


void main() {
	// Задача 21.B

	int  n, i, j;
	scanf_s("%d", &n);

	i = 10;
	do {
		j = 1;

		do {
			printf("%d ", i + j);
			j++;
		} while (j <= n);

		printf("\n");
		i += 10;
	} while (i <= n * 10);

	//Для тестов нужно ввести 3; 4

	//Задача 22.B

	int  n, i, j;
	scanf_s("%d", &n);

	i = 1;
	do {
		j = n;

		do {
			if (j <= i)
				printf("%d ", j);
			else
				printf("  ");
			j--;
		} while (j >= 1);

		printf("\n");
		i++;
	} while (i <= n);

	//Для тестов нужно ввести 3; 4

	//Задача 23.B

	int  n, i, j;
	char ch;
	scanf_s("%d", &n);
	i = 2;
	do {
		if (i % 2 == 0)
			ch = '>';
		else
			ch = '<';
		j = 1;

		while (j != i) {
			printf("%c ", ch);
			j++;
		}
		printf("\n");
		i++;
	} while (i <= n);
	//Для тестов нужно ввести 4; 5
}
