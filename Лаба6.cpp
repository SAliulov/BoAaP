#include <stdio.h>
#include <Windows.h>
//������������ ������ �6

void main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//������ 1. ��� ����������� �����
	printf("������ 1. ��� ����������� ����� \n");

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

	//������ 2. ������� ������
	printf("������ 2. ������� ������ \n");

	int i1 = 0;
	int stepen = 1;

	do {
		printf("2^%d = %d\n", i1, stepen);
		stepen *= 2;
		i1++;
	} while (i1<=5);

	printf("\n");

	//������ 4. ����� ������ N ������ �����
	printf("������ 4. ����� ������ N ������ ����� \n");

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

	//������ 5. ����� ������ N ����� ������� A
	printf("������ 5. ����� ������ N ����� ������� A \n");

	int N, A;
	printf("������� N: ");
	scanf_s("%d", &N);
	printf("������� A: ");
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

	//������ 6. ������ N ����� ���������.
	printf("������ 6. ������ N ����� ���������.\n");
	int first, second, next, Number,Counter;
	Counter = 3;
	first = 0;
	second = 1;
	printf("������� N: ");
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
