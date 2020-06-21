
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "deque.h"

// переводит в число последовательность символов
//возвращает массив в котором
//arr[0] - прочитанное число; arr[1] - следующий символ
int convert()
{

}

// добавляет символ или число в дек
// читает следующий символ, его возвращает
int add_simbol()
{

}


struct Deque* reading_expression()
{
	int* arr;
	// массив, в который записываются после перевода в число
	//arr[0] - прочитанное число; arr[1] - следующий символ
	arr = malloc(2 * sizeof(int));
	//создание дека
	struct Deque* deque1;
	deque1 = create_deque();
	char simbol;
	scanf_s("%c", &simbol);
	//заполнение первого элемента дека
	switch (simbol) 
	{
	//если первый символ
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
	//если первое число
	default:
		arr = convert();
		deque1->first->type = 1;
		deque1->first->data = arr[0];
		simbol = arr[1];
		break;
	}
	//заполнение остальных элементов
	// пока строка не закончилась
	while (simbol != '\n')
	{
		// символ или число записывается в дек
		//читается новый символ
		simbol = add_simbol();
	}

	return deque1;
}


