 
#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

// ������� �� ������ � ������
char convert_number(int number)
{
	char s;
	switch (number)
	{
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
	case 8:
		s = 'x';
		break;
	}
	return s;
}

//������� �� ������� � ��� �����
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
	case 'x':
		s = 8;
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
int* convert(int* arr, char symbol)
{
	int number = 0;
	while (1)
	{
		//���� �����
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
		scanf_s("%c", &symbol);
	}
}

// ��������� ������ ��� ����� � ���
// ������ ��������� ������, ��� ����������
char add_symbol(struct deque* deque, char symbol)
{
	int data, * arr;
	arr = malloc(2 * sizeof(int));
	char new_symbol;
	// ����� �������
	data = convert_symbol(symbol);
	//���� ��� ������ - ��������
	if (data != 0)
	{
		push_back(deque, data, 2);
		scanf_s("%c", &new_symbol);
	}
	else
	//��������� � ����� � ��������
	{
		arr = convert(arr, symbol);
		push_back(deque, arr[0], 1);
		new_symbol = convert_number(arr[1]);
	}
	return new_symbol;
}

// ������ ���������
struct deque* reading_expression()
{
	int* arr;
	// ������, � ������� ������������ ����� �������� � �����
	//arr[0] - ����������� �����; arr[1] - ��������� ������
	arr = malloc(2 * sizeof(int));
	//�������� ����
	struct deque* deque;
	deque = create_deque();
	char symbol;
	scanf_s("%c", &symbol);
	//���������� ������� �������� ����
	int num;
	num = convert_symbol(symbol);
	if (num != 0)
	{
		deque->first->type = 2;
		deque->first->data = num;
		scanf_s("%c", &symbol);
	}
	else
	{
		arr = convert(arr, symbol);
		deque->first->type = 1;
		deque->first->data = arr[0];
		symbol = convert_number(arr[1]);
	}
	//���������� ��������� ���������
	// ���� ������ �� �����������
	while (symbol != '\n')
	{
		// ������ ��� ����� ������������ � ���
		//�������� ����� ������
		symbol = add_symbol(deque, symbol);
	}
	return deque;
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
struct deque* RPN(struct deque* normal_notation)
{
	// deque - ��������������� ���
	struct deque* deque,* rev_polish_notat;
	deque = create_deque();
	rev_polish_notat = create_deque();
	// �������, � ������� ������������ 
	// �rr[0] - ��������; arr[1] - ���
	// first_element - ������ � ���������� ������, last_element - ��������� �� ���������������
	int* first_element,* last_element;
	first_element = malloc(2 * sizeof(int));
	last_element = malloc(2 * sizeof(int));
	//���������� ������� ��������
	deque->first->data = 0;
	deque->first->type = 2;
	rev_polish_notat->first->data = 0;
	rev_polish_notat->first->type = 2;
	// �������� ������, ������������, ��� ������ ���������
	push_back(normal_notation, 0, 2);
	// ���� ������������ ��������������� �������� �� �������
	int k = 0;
	//���� ��������� �� �������������
	while (k != 4)
	{
		first_element = top_front(normal_notation, first_element);
		// ���� ��������� �����
		if (first_element[1] == 1 || (first_element[1] == 2 && first_element[0] == 8))
		{
			//������ ������������ � ����� ����� ������
			first_element = pop_front(normal_notation, first_element);
			push_back(rev_polish_notat, first_element[0], first_element[1]);
		}
		else
		{
			// �������� ���������� � ����������� ������ ��������
			last_element = top_back(deque, last_element);
			k = what_do(last_element[0], first_element[0]);
			switch (k)
			{
			case 1:
				first_element = pop_front(normal_notation, first_element);
				push_back(deque, first_element[0], 2);
				break;
			case 2:
				last_element = pop_back(deque, last_element);
				push_back(rev_polish_notat, last_element[0], 2);
				break;
			case 3:
				first_element = pop_front(normal_notation, first_element);
				last_element = pop_back(deque, last_element);
				break;
			case 4:
				break;
			}
		}
		
	}
	// ��������� ������ ������� � ������
	first_element = pop_front(rev_polish_notat, first_element);
	return rev_polish_notat;
}

// ����� ���������
void output(struct deque* deque)
{
	struct list* P;
	P = deque->first;
	if (P->type == 1)
		printf("%d ", P->data);
	else
		printf("%c ", convert_number(P->data));
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

