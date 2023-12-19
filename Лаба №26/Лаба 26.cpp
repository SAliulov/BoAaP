#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};


struct Node* first = NULL;

void printList() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		printf("(%d) -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}


void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->next = first;
	newNode->data = value;

	first = newNode;
}


int deleteFromHead() {
	int value = first->data;
	struct Node* delNode = first;
	first = first->next;
	free(delNode);
	return value;
}


int contains(int value) {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data == value) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

// Сумма всех элементов

int sum() {

	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL) {
		s += ptr->data;
		ptr = ptr->next;
	}
	return s;
}

// Подсчет кол-ва чётных элементов

int evenCount() {

	struct Node* ptr = first;
	int cnt = 0;

	while (ptr != NULL) {
		if (ptr->data % 2 == 0) {
			cnt++;
		}
		ptr = ptr->next;
	}
	return cnt;
}

// Все нечётные увеличить в 10 раз

void oddsX10() {
	struct Node* ptr = first;

	while (ptr != NULL) {
		if (ptr->data % 2 != 0) {
			ptr->data *= 10;
		}
		ptr = ptr->next;
	}

}

// i-ый элемент увеличить в 100 раз

void elementIx100(int i) {
	struct Node* ptr = first;
	int index = 0;
	while (ptr != NULL) {
		if (index == i) {
			ptr->data = ptr->data * 100;
			return;
		}
		ptr = ptr->next;
		index++;
	}
}

// Все элементы левее i-го увеличить в 10 раз

void elementLeftIx10(int index) {
	struct Node* ptr = first;
	int i = 0;
	while (ptr != NULL) {
		if (i < index) {
			ptr->data = ptr->data * 10;

		}
		ptr = ptr->next;
		i++;
	}
}


void clearList() {
	while (first != NULL)
	{
		struct Node* delNode = first;
		first = first->next;
		free(delNode);
	}
}

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	first = NULL;
	printf("Задача 1. Думайте.\n");
	printList();

	addToHead(10);
	printList();

	addToHead(20);
	printList();

	addToHead(30);
	printList();

	int x1 = deleteFromHead();
	printf("x1 = %d\n", x1);
	printList();

	int x2 = deleteFromHead();
	printf("x2 = %d\n", x2);
	printList();

	clearList();
	printf("\n\n\n");

	addToHead(400);
	addToHead(300);
	addToHead(200);
	addToHead(100);
	printList();

	printf("contains(100) = %d\n", contains(100));
	printf("contains(200) = %d\n", contains(200));
	printf("contains(300) = %d\n", contains(300));

	clearList();
	printList();

	printf("contains(100) = %d\n", contains(100));
	printf("contains(300) = %d\n", contains(300));
	printf("contains(200) = %d\n", contains(200));

	printf("\n\n\n");

	// Задача 2
	printf("Задача 2. Думайте.\n");
	printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(9);

	printList();

	printf("sum = %d\n", sum());

	clearList();
	printList();

	printf("sum = %d\n", sum());
	printf("\n\n\n");

	// Задача 3 Кол-во четных

	printf("Задача 3. Думайте.\n");
	printList();

	addToHead(1);
	addToHead(3);
	addToHead(8);
	addToHead(6);
	addToHead(-24);
	addToHead(228);

	printList();

	printf("Even numbers = %d\n", evenCount());

	clearList();
	printList();
	printf("Even numbers = %d\n", evenCount());
	printf("\n\n\n");

	// Задача 4  Все нечётные *= 10
	printf("Задача 4. Думайте.\n");
	printList();

	addToHead(1);
	addToHead(3);
	addToHead(5);
	addToHead(8);
	addToHead(-31);


	printList();
	oddsX10();
	printList();

	printf("\n\n\n");

	// Задача 5 i-ый элемент увеличить в 100 раз
	printf("Задача 5. Думайте.\n");

	printList();

	addToHead(54);
	addToHead(26);
	addToHead(7);
	addToHead(3);
	printList();

	elementIx100(0);

	printList();

	clearList();
	printf("\n\n\n");

	addToHead(54);
	addToHead(26);
	addToHead(7);
	addToHead(3);
	printList();

	elementIx100(1);

	printList();

	printf("\n\n\n");

	// Задача 6 все элементы левее i-го увелечить в 10 раз
	printf("Задача 6. Думайте.\n");

	printList();

	addToHead(13);
	addToHead(31);
	addToHead(68);
	addToHead(86);
	printList();
	printf("\n\n\n");

	elementLeftIx10(1);

	printList();

	printf("\n\n\n");

	elementLeftIx10(2);

	printList();

	printf("\n\n\n");

	elementLeftIx10(4);

	printList();
}