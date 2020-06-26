
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "deque.h"
#include "reverse_notation.h"

//������� ���������
void replacing_parameter(struct Deque* Deque)
{
	setlocale(LC_ALL, "RUS");
	struct list* P;
	P = Deque->first;
	//���� �������� �, k ������ ����� 1
	int k = 0;
	// �������� ������� �������
	if (P->type == 2 && P->data == 8)
	{
		k = 1;
		printf("\n������� �������� �: ");
	}
	//����� �� �� � - ��� ���������
	else
		while (P->next != NULL)
		{
			P = P->next;
			// ���� �
			if (P->type == 2 && P->data == 8)
			{
				// �������� k �� 1
				k = 1;
				printf("\n������� �������� �: ");
				//���� �������������
				break;
			}
		}
	// ���� � ����
	if (k == 1)
	{
		//������ ��� ��������
		scanf_s("%d", &k);
		P = Deque->first;
		// ������ ��������� �� �����
		if (P->type == 2 && P->data == 8)
		{
			P->data = k;
			P->type = 1;
		}
		while (P->next != NULL)
		{
			P = P->next;
			if (P->type == 2 && P->data == 8)
			{
				P->data = k;
				P->type = 1;
			}
		}
	}
	return;
}

//���������� ������ �������� ���������
int value(int a, int b, int sign)
{
	int s;
	switch (sign)
	{
	case 1:
		s = a + b;
		break;
	case 2:
		s = a - b;
		break;
	case 3:
		s = a * b;
		break;
	case 4:
		s = a / b;
		break;
	}
	return s;
}

//���������� ���������
int calculation(struct Deque* expression)
{
	replacing_parameter(expression);
	// ��������������� ���
	struct Deque* Deque;
	Deque = create_deque();
	//���������� ������� ��������
	Deque->first->data = 0;
	Deque->first->type = 2;
	// ��������� �������
	push_back(expression, 0, 2);
	// arr - ������� �� ���� � ����������
	int* arr,* number1,* number2;
	arr = malloc(2 * sizeof(int));
	number1 = malloc(2 * sizeof(int));
	number2 = malloc(2 * sizeof(int));
	// ���� ������ �� ����������� 
	while (!(expression->first->type == 2 && expression->first->data == 0))
	{
		arr = pop_front(expression, arr);
		// ���� ��� �����
		if (arr[1] == 1)
			// �������� � ���
			push_back(Deque, arr[0], 1);
		//���� ������
		else
		{
			// ��������� ���� ��������
			number1 = pop_back(Deque, number1);
			number2 = pop_back(Deque, number2);
			push_back(Deque, value(number2[0], number1[0], arr[0]), 1);
		}
	}
	arr = pop_back(Deque, arr);
	return arr[0];
}
