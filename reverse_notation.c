
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "deque.h"

//номер символа или 0 если цифра
int convert_symbol(char symbol)
{
	int s;
	switch (symbol)
	{
		//если символ
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
		//если число
	default:
		s = 0;
		break;
	}
	return s;
}



// переводит последовательность символов в число
//возвращает массив в котором
//arr[0] - прочитанное число; arr[1] - следующий символ, уже перееведенный в число
int* convert(int* arr, char numeral)
{
	//чтение первой цифры 
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
	// чтение последующих символов
	char symbol;
	while (1)
	{
		//если цифра
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
		// если символ
		default:
			arr[0] = number;
			arr[1] = convert_symbol (symbol);
			return arr;
			break;
		}
	}
}

// добавляет символ или число в дек
// читает следующий символ, его возвращает
int add_symbol()
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
	char symbol;
	scanf_s("%c", &symbol);
	//заполнение первого элемента дека
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
	//заполнение остальных элементов
	// пока строка не закончилась
	while (symbol != '\n')
	{
		// символ или число записывается в дек
		//читается новый символ
		symbol = add_simbol();
	}
	*/
	return deque1;
}

