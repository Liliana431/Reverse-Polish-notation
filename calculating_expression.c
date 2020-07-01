
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "deque.h"
#include "reverse_notation.h"

//������� ���������
void replacing_parameter(struct deque* deque)
{
	setlocale(LC_ALL, "RUS");
	struct list* p;
	p = deque->first;
	//k - ���������� ������ �� ��������� � ��� ���
	int k = 0, x;
	while (p->next != NULL)
	{
		// ���� �
		if (p->type == 2 && p->data == 8)
		{
			// ���� ��� ������ ��������� �
			if (k == 0)
			{
				k = 1;
				printf("������� �������� �: ");
				scanf_s("%d", &x);
			}
			p->data = x;
			p->type = 1;
		}
		p = p->next;
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
int calculation(struct deque* expression)
{
	replacing_parameter(expression);
	// ��������������� ���
	struct deque* deque;
	deque = create_deque();
	//���������� ������� ��������
	deque->first->data = 0;
	deque->first->type = 2;
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
			push_back(deque, arr[0], 1);
		//���� ������
		else
		{
			// ��������� ���� ��������
			number1 = pop_back(deque, number1);
			number2 = pop_back(deque, number2);
			push_back(deque, value(number2[0], number1[0], arr[0]), 1);
		}
	}
	arr = pop_back(deque, arr);
	return arr[0];
}
