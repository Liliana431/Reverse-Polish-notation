
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "deque.h"

// ��������� � ����� ������������������ ��������
//���������� ������ � �������
//arr[0] - ����������� �����; arr[1] - ��������� ������
int convert()
{

}

// ��������� ������ ��� ����� � ���
// ������ ��������� ������, ��� ����������
int add_simbol()
{

}


struct Deque* reading_expression()
{
	int* arr;
	// ������, � ������� ������������ ����� �������� � �����
	//arr[0] - ����������� �����; arr[1] - ��������� ������
	arr = malloc(2 * sizeof(int));
	//�������� ����
	struct Deque* deque1;
	deque1 = create_deque();
	char simbol;
	scanf_s("%c", &simbol);
	//���������� ������� �������� ����
	switch (simbol) 
	{
	//���� ������ ������
	case '(':
		deque1->first->type = 2;
		deque1->first->data = 5;
		scanf_s("%c", &simbol);
		break;
	case ')':
		deque1->first->type = 2;
		deque1->first->data = 6;
		scanf_s("%c", &simbol);
		break;
	case '+':
		deque1->first->type = 2;
		deque1->first->data = 1;
		scanf_s("%c", &simbol);
		break;
	case '-':
		deque1->first->type = 2;
		deque1->first->data = 2;
		scanf_s("%c", &simbol);
		break;
	case '*':
		deque1->first->type = 2;
		deque1->first->data = 3;
		scanf_s("%c", &simbol);
		break;
	case '/':
		deque1->first->type = 2;
		deque1->first->data = 4;
		scanf_s("%c", &simbol);
		break;
	//���� ������ �����
	default:
		arr = convert();
		deque1->first->type = 1;
		deque1->first->data = arr[0];
		simbol = arr[1];
		break;
	}
	//���������� ��������� ���������
	// ���� ������ �� �����������
	while (simbol != '\n')
	{
		// ������ ��� ����� ������������ � ���
		//�������� ����� ������
		simbol = add_simbol();
	}

	return deque1;
}


