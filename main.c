
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "deque.h"
#include "reverse_notation.h"
#include "calculating_expression.h"


void main()
{
	setlocale(LC_ALL, "RUS");
	struct Deque* Deque;
	printf("������� ���������\n");
	//������ ��������
	Deque = reading_expression();
	//������� � �������� �������� ������
	Deque = RPN(Deque);
	//����� �������� �������� ������
	printf("�������� �������� ������: ");
	output(Deque);
	int a;
	//���������� ���������
	a = calculation(Deque);
	//����� ��������
	printf("\n = %d", a);
}
