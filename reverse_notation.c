
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "deque.h"

//����� ������� ��� 0 ���� �����
int convert_symbol(char symbol)
{
	int s;
	switch (symbol)
	{
		//���� ������
	case '(':
		s = 5;
		break;
	case ')':
		s = 6;
		break;
	case '+':
		s = 1;
		break;
	case '-':
		s = 2;
		break;
	case '*':
		s = 3;
		break;
	case '/':
		s = 4;
		break;
		//���� �����
	default:
		s = 0;
		break;
	}
	return s;
}



// ��������� ������������������ �������� � �����
//���������� ������ � �������
//arr[0] - ����������� �����; arr[1] - ��������� ������, ��� ������������� � �����
int* convert(int* arr, char numeral)
{
	//������ ������ ����� 
	int number;
	switch (numeral)
	{
	case '1':
		number = 1;
		break;
	case '2':
		number = 2;
		break;
	case '3':
		number = 3;
		break;
	case '4':
		number = 4;
		break;
	case '5':
		number = 5;
		break;
	case '6':
		number = 6;
		break;
	case '7':
		number = 7;
		break;
	case '8':
		number = 8;
		break;
	case '9':
		number = 9;
		break;
	}
	// ������ ����������� ��������
	char symbol;
	while (1)
	{
		//���� �����
		scanf_s("%c", &symbol);
		switch (symbol)
		{
		case '1':
			number = 10 * number + 1;
			break;
		case '2':
			number = 10 * number + 2;
			break;
		case '3':
			number = 10 * number + 3;
			break;
		case '4':
			number = 10 * number + 4;
			break;
		case '5':
			number = 10 * number + 5;
			break;
		case '6':
			number = 10 * number + 6;
			break;
		case '7':
			number = 10 * number + 7;
			break;
		case '8':
			number = 10 * number + 8;
			break;
		case '9':
			number = 10 * number + 9;
			break;
		case '0':
			number = 10 * number;
			break;
		// ���� ������
		default:
			arr[0] = number;
			arr[1] = convert_symbol (symbol);
			return arr;
			break;
		}
	}
}

// ��������� ������ ��� ����� � ���
// ������ ��������� ������, ��� ����������
int add_symbol()
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
	char symbol;
	scanf_s("%c", &symbol);
	//���������� ������� �������� ����
	int num;
	num = convert_symbol(symbol);
	if (num != 0)
	{
		deque1->first->type = 2;
		deque1->first->data = num;
		scanf_s("%c", &symbol);
	}
	else
	{
		arr = convert(arr, symbol);
		deque1->first->type = 1;
		deque1->first->data = arr[0];
		symbol = arr[1];
	}
	/*
	//���������� ��������� ���������
	// ���� ������ �� �����������
	while (symbol != '\n')
	{
		// ������ ��� ����� ������������ � ���
		//�������� ����� ������
		symbol = add_simbol();
	}
	*/
	return deque1;
}

