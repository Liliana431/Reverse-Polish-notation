
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "deque.h"
#include "reverse_notation.h"

//заметна параметра
void replacing_parameter(struct deque* deque)
{
	setlocale(LC_ALL, "RUS");
	struct list* p;
	p = deque->first;
	//k - обозначает первое ли появление х или нет
	int k = 0, x;
	while (p->next != NULL)
	{
		// если х
		if (p->type == 2 && p->data == 8)
		{
			// если это первое появление х
			if (k == 0)
			{
				k = 1;
				printf("введите значение х: ");
				scanf_s("%d", &x);
			}
			p->data = x;
			p->type = 1;
		}
		p = p->next;
	}
	return;
}

//вычисление одного действия выражения
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

//вычисление выражения
int calculation(struct deque* expression)
{
	replacing_parameter(expression);
	// вспомогательный дек
	struct deque* deque;
	deque = create_deque();
	//заполнение первого элемента
	deque->first->data = 0;
	deque->first->type = 2;
	// окончание строчки
	push_back(expression, 0, 2);
	// arr - элемент из дека с выражением
	int* arr,* number1,* number2;
	arr = malloc(2 * sizeof(int));
	number1 = malloc(2 * sizeof(int));
	number2 = malloc(2 * sizeof(int));
	// пока строка не закончилась 
	while (!(expression->first->type == 2 && expression->first->data == 0))
	{
		arr = pop_front(expression, arr);
		// если это число
		if (arr[1] == 1)
			// записать в дек
			push_back(deque, arr[0], 1);
		//если символ
		else
		{
			// посчитать одно действие
			number1 = pop_back(deque, number1);
			number2 = pop_back(deque, number2);
			push_back(deque, value(number2[0], number1[0], arr[0]), 1);
		}
	}
	arr = pop_back(deque, arr);
	return arr[0];
}
