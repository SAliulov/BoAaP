// Лаба 16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//!!!!!!!!!!!!!!!!Сбросьте на рабочий стол, поменяйте имя пользователя (ctrl + H) на свое


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#define NUM_ELEMENTS 100

//ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ (И МАССИВЫ)

int arr[NUM_ELEMENTS];

int n = 0;


//Вариант (Власенко)
void printElements() {
	printf("< ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf(">\n");
}

//Задача 1.
void Input_keyboard_array() {
	printf("n = ");
	scanf_s("%d", &n);
	printf("input %d values: ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]); 
	}
}


void OddsX10() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0) {
			arr[i] = arr[i] * 10;
		}
	}
}
int findMin() {
	int min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

//Задача 2. Кол-во элементов больше 10
int Elements_more10() {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 10) {
			count += 1;
		}
	}
	return count;
}
//Задача 3. Последний чётный в 2 раза увеличить (у Власенко не учитываются отрицательные числа)
int FindLastEven() {
	int inx;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			inx = i;
		}
	}
	return inx;
}

int Find_Min_Index() {
	int index = 0;
	int min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			index = i;
			min = arr[i];
		}
	}
	return index;
}

//Как с помощью Указателей (или еще как то) вернуть массив в Си???

//int Find_First_And_Last_Even() {
//	int index_first = 0;
//	int index_last = n-1;
//
//	for (int i = 0; i < n; i++) {
//		if (arr[i] % 2 == 0) {
//			index_first = i;
//			break;
//		}
//	}
//
//	for (int i = (n-1); i > 0; i--) {
//		if (arr[i] % 2 == 0) {
//			index_last = i;
//			break;
//		}
//	}
//	int Massive[2] = {index_first, index_last};
//	return Massive;
//}


int Find_First_Even() {
	int index_first = 101;

	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			index_first = i;
			break;
		}
	}
	return index_first;
}

int Find_Last_Even() {
	int index_last = 0;

	for (int i = (n - 1); i > 0; i--) {
		if (arr[i] % 2 == 0) {
			index_last = i;
			break;
		}
	}
	return index_last;
}

//Лаба 17

//Задание 1 Удалить элемент
void deleteElement(int delIndex) {
	for (int i = delIndex; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	n--;
}

//Задание 2 Вставить элемент в i-ую позицию
void insertElement(int Index, int value) {
	for (int i = n; i > Index; i--) {
		arr[i] = arr[i-1];
	}
	n++;
	arr[Index] = value;
}

//Задание 3 Удалить минмимальный элемент

void DeleteMinElement() {
	int min_index = Find_Min_Index();
	for (int i = min_index; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	n--;
}
	
//Задание 4 Перед минимальным элементом вставить 0
void AddZeroBeforeMinElement(int indexMin, int value) {
	for (int i = n; i > indexMin; i--) {
		arr[i] = arr[i - 1];
	}
	n++;
	arr[indexMin] = value;
}

void main() {
	int item;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Задача 1. Базовые операции
	
	do {
		printf("\n-----------------------------\n");
		printf("Содержимое массива: ");
		printElements();
		printf("1: Ввести с клавиатуры массив\n");
		printf("2: x10 для всех нечётных элементов\n");
		printf("3: Найти минимальный элемент\n");
		printf("4: Сколько elements > 10\n");
		printf("5: Последний чётный элемент в массиве увеличить в 2 раза\n");
		printf("6: Сколько чётных левее минимального\n");
		printf("7: Увеличение в 10 раз для нечётных правее минимального\n");
		printf("8: Все чётные элементы массива умножить на -1\n");
		printf("9: Все элементы массива меньше 4 заменить на 4\n");
		printf("10: Все элементы между первым четным и последним четным увеличить в 100 раз\n");
		printf("11: Удалить заданный элемент\n");
		printf("12: Вставить элемент перед i-ой позицией\n");
		printf("13: Удалить минимальный элемент\n");
		printf("14: Вставить 0 перед минимальным элементом\n");
		printf("15: Загрузить массив из файла CurrentArr\n");

		printf("\n0: Выйти из программы\n");

		printf("Выбранная операция >>>>>>>>> ");

		scanf_s("%d", &item);


		


		switch (item) {
		case 1:
			Input_keyboard_array();
			break;
		case 2:
			OddsX10();
			printElements();
			break;
		case 3: {
				int min = findMin();
				printf("min = %d \n", min);
				break;
			}
		case 4: {
				int counter = Elements_more10();
				printf("Количество элементов больше 10: %d \n", counter);
				break;
			}
		case 5: {
				int index = FindLastEven();
				if (index >= 0) {
					arr[index] *= 2;
				}
				break;
			}
			
		case 6: {
				int Index_min = Find_Min_Index();
				printf("Индекс минимального элемента = %d \n", Index_min);
				int cnt = 0;

				for (int i = 0; i < Index_min; i++) {
					if (arr[i] % 2 == 0) {
						cnt += 1;
					}
				}
				printf("Левее минимального %d четных элементов \n", cnt);
				break;
			}

		//Задача 5*
		case 7: {
				int Index_min = Find_Min_Index();
				printf("Индекс минимального элемента = %d \n", Index_min);
				
				for (int i = (n-1); i > Index_min; i--) {
					if (arr[i] % 2 != 0) {
						arr[i] *= 10;
					}	
				}
				break;
			}
		//Задача 7
		case 8: {
				for (int i = 0; i < n; i++) {
					if (arr[i] % 2 == 0) {
						arr[i] *= (-1);
					}
				}
				break;
			}
		//Задача 8
		case 9: {
				for (int i = 0; i < n; i++) {
					if (arr[i] < 4) {
						arr[i] = 4;
					}
				}
				break;
			}
		//Задача 10**
		case 10: {
			int first_index = Find_First_Even();
			int last_index = Find_Last_Even();
			if (first_index == 101) {
				printf("Не могу совершить операцию, так как нет ни 1 чётного числа. Массив чисел остаётся прежним.");
			}
			else {
				printf("Индекс первого четного элемента = %d \n", first_index);
				printf("Индекс последнего чётного элемента = %d \n", last_index);
			}
			for (int i = 0; i > first_index; i--) {
					arr[i] = arr[i] * 100;		
				}	
			}
			break;

		//Лаба 17
		case 11: {
				printf("Индекс удаляемого элемента = ");
				int index;
				scanf_s("%d", &index);
				deleteElement(index);
				
			}
			break;

		case 12: {
				printf("Перед каким элементом нужно вставить новый? Индекс = ");
				int index;
				scanf_s("%d", &index);
				printf("Значение, которое нужно вставить: ");
				int value;
				scanf_s("%d", &value);
				insertElement(index, value);

			}
			break;
		case 13: {
				int min = findMin();
				printf("min = %d\n", min);
				DeleteMinElement();

			}
			break;
		case 14: {
				int indexMin = Find_Min_Index();
				printf("Индекс минимального элемента = %d\n", indexMin);
				AddZeroBeforeMinElement(indexMin, 0);
			}
			break;

		//Лаба 18
		case 15: {
				//В чем смысл загружать состояние массива из файла, в котором это же состояние массива до этого и сохранялась?
				//Загрузка массива из файла (Лаба 18(8))
				FILE* SavedArr = fopen("C:\\Users\\MIX PC\\Desktop\\CurrentArr.txt", "rt");
				if (SavedArr == NULL) {
					printf("ГГВП стоит задуматься Думайте.");
					return;
				}

				for (int i8 = 0; i8 < n; i8++) {
					fscanf(SavedArr, "%d ", &arr[i8]);
				}
				fclose(SavedArr);

			}

		}


		//Сохранение состояния массива в файле (Лаба 18(7))
		FILE* CurrentArr = fopen("C:\\Users\\MIX PC\\Desktop\\CurrentArr.txt", "wt");
		if (CurrentArr == NULL) {
			printf("ГГВП стоит задуматься Думайте.");
			return;
		}
		for (int i7 = 0; i7 < n; i7++) {
			fprintf(CurrentArr, "%d ", arr[i7]);
		}
		fclose(CurrentArr);
		//Чек файл CurrentArr

		

	} while (item != 0);
}
