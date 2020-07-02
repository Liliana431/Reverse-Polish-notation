
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "deque.h"
#include "reverse_notation.h"
#include "calculating_expression.h"


void main()
{
	setlocale(LC_ALL, "RUS");
	struct deque* deque;
	printf("������� ���������\n");
	//������ ��������
	deque = reading_expression();
	//������� � �������� �������� ������
	deque = RPN(deque);
	if (deque->first->type == 0)
		return;
	//����� �������� �������� ������
	printf("�������� �������� ������: \n");
	output(deque);
	printf("\n");
	int a;
	//���������� ���������
	a = calculation(deque);
	//����� ��������
	printf(" = %d", a);

}

//�����:
//5+7+9/3-(4*2) = 7
//(((((5+3)/2)))*9) = 36
//(((((5+3)/2)*9  - ������ ����� 
//((5+3)/2)))*9)  - ������ �����
//x+7+9/3-(4*2) = 12(�=10)
//5+7+x/3-(4*2) = 8(�=12)
//x+7+x/3-(4*2) = 11(�=9)