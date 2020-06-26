
#include <stdio.h>
#include <stdlib.h>
#include "deque.h"
#include "reverse_notation.h"

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
int calculation(struct Deque* expression)
{
	// вспомогательный дек
	struct Deque* Deque;
	Deque = create_deque();
	//заполнение первого элемента
	Deque->first->data = 0;
	Deque->first->type = 2;
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
			push_back(Deque, arr[0], 1);
		//если символ
		else
		{
			// посчитать одно действие
			number1 = pop_back(Deque, number1);
			number2 = pop_back(Deque, number2);
			push_back(Deque, value(number2[0], number1[0], arr[0]), 1);
		}
	}
	arr = pop_back(Deque, arr);
	return arr[0];
}
