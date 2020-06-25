
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "deque.h"

char convert_number(int number)
{
	char s;
	switch (number)
	{
		//���� ������
	case 5:
		s = '(';
		break;
	case 6:
		s = ')';
		break;
	case 1:
		s = '+';
		break;
	case 2:
		s = '-';
		break;
	case 3:
		s = '*';
		break;
	case 4:
		s = '/';
		break;
	case 7:
		s = '\n';
		break;
	}
	return s;
}

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
	case '\n':
		s = 7;
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
//arr[0] - ����������� �����; arr[1] - ��������� ������, ������������� � �����
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
char add_symbol(struct Deque* Deque, char symbol)
{
	int data, * arr;
	arr = malloc(2 * sizeof(int));
	char new_symbol;
	// ����� �������
	data = convert_symbol(symbol);
	//���� ��� ������ - ��������
	if (data != 0)
	{
		push_back(Deque, data, 2);
		scanf_s("%c", &new_symbol);
	}
	else
	//��������� � ����� � ��������
	{
		arr = convert(arr, symbol);
		push_back(Deque, arr[0], 1);
		new_symbol = convert_number(arr[1]);
	}
	return new_symbol;
}

// ������ ���������
struct Deque* reading_expression()
{
	int* arr;
	// ������, � ������� ������������ ����� �������� � �����
	//arr[0] - ����������� �����; arr[1] - ��������� ������
	arr = malloc(2 * sizeof(int));
	//�������� ����
	struct Deque* Deque;
	Deque = create_deque();
	char symbol;
	scanf_s("%c", &symbol);
	//���������� ������� �������� ����
	int num;
	num = convert_symbol(symbol);
	if (num != 0)
	{
		Deque->first->type = 2;
		Deque->first->data = num;
		scanf_s("%c", &symbol);
	}
	else
	{
		arr = convert(arr, symbol);
		Deque->first->type = 1;
		Deque->first->data = arr[0];
		symbol = convert_number(arr[1]);
	}
	//���������� ��������� ���������
	// ���� ������ �� �����������
	while (symbol != '\n')
	{
		// ������ ��� ����� ������������ � ���
		//�������� ����� ������
		symbol = add_symbol(Deque, symbol);
	}
	return Deque;
}

// �� ������� ������������ ���� ����� ���� ����������
// �� ������� - ���������� ������������ ������, �� �������� - �������
// 1 - �������� � �������������� ���
// 2 - �� ���. ���� � ����� ����� ������
// 3 - ������� � ��������� ������������, � ������� ������
// 4 - ��������� �������������
// 0 - ������ ����� 
int what_do(int last_element, int first_element)
{
	int matrix[6][7] = { {4, 1, 1, 1, 1, 1, 0}, 
						 {2, 2, 2, 1, 1, 1, 2}, 
						 {2, 2, 2, 1, 1, 1, 2}, 
						 {2, 2, 2, 2, 2, 1, 2}, 
						 {2, 2, 2, 2, 2, 1, 2}, 
						 {0, 1, 1, 1, 1, 1, 3} };
	return matrix[last_element][first_element];
}

// �������� ������
struct Deque* RPN(struct Deque* normal_notation)
{
	// deque1 - ��������������� ���
	struct Deque* deque1,* rev_Polish_not;
	deque1 = create_deque();
	rev_Polish_not = create_deque();
	// �������, � ������� ������������ 
	// �rr[0] - ��������; arr[1] - ���
	// first_element - ������ � ���������� ������, last_element - ��������� �� ���������������
	int* first_element,* last_element;
	first_element = malloc(2 * sizeof(int));
	last_element = malloc(2 * sizeof(int));
	//���������� ������� ��������
	deque1->first->data = 0;
	deque1->first->type = 2;
	rev_Polish_not->first->data = 0;
	rev_Polish_not->first->type = 2;
	// �������� ������, ������������, ��� ������ ���������
	push_back(normal_notation, 0, 2);
	// ���� ������������ ��������������� �������� �� �������
	int k = 0;
	//���� ��������� �� �������������
	while (k != 4)
	{
		first_element = top_front(normal_notation, first_element);
		// ���� ��������� �����
		if (first_element[1] == 1)
		{
			//������ ������������ � ����� ����� ������
			first_element = pop_front(normal_notation, first_element);
			push_back(rev_Polish_not, first_element[0], 1);
		}
		else
		{
			// �������� ���������� � ����������� ������ ��������
			last_element = top_back(deque1, last_element);
			k = what_do(last_element[0], first_element[0]);
			switch (k)
			{
			case 1:
				first_element = pop_front(normal_notation, first_element);
				push_back(deque1, first_element[0], 2);
				break;
			case 2:
				last_element = pop_back(deque1, last_element);
				push_back(rev_Polish_not, last_element[0], 2);
				break;
			case 3:
				first_element = pop_front(normal_notation, first_element);
				last_element = pop_back(deque1, last_element);
				break;
			case 4:
				break;
			}
		}
		
	}
	// ��������� ������ ������� � ������
	first_element = pop_front(rev_Polish_not, first_element);
	return rev_Polish_not;
}

// ����� ���������
void output(struct Deque* Deque)
{
	struct list* P;
	P = Deque->first;
	printf("%d ", P->data);
	while (P->next != NULL)
	{
		P = P->next;
		if(P->type == 1)
			printf("%d ", P->data);
		else 
			printf("%c ", convert_number(P->data));
	}
	return;
}

