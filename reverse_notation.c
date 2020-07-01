 
#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

// перевод из номера в символ
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

//перевод из символа в его номер
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
	case '\n':
		s = 7;
		break;
	case 'x':
		s = 8;
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
//arr[0] - прочитанное число; arr[1] - следующий символ, перееведенный в число
int* convert(int* arr, char symbol)
{
	int number = 0;
	while (1)
	{
		//если цифра
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
		scanf_s("%c", &symbol);
	}
}

// добавляет символ или число в дек
// читает следующий символ, его возвращает
char add_symbol(struct deque* deque, char symbol)
{
	int data, * arr;
	arr = malloc(2 * sizeof(int));
	char new_symbol;
	// номер символа
	data = convert_symbol(symbol);
	//если это символ - добавить
	if (data != 0)
	{
		push_back(deque, data, 2);
		scanf_s("%c", &new_symbol);
	}
	else
	//перевести в число и добавить
	{
		arr = convert(arr, symbol);
		push_back(deque, arr[0], 1);
		new_symbol = convert_number(arr[1]);
	}
	return new_symbol;
}

// чтение выражения
struct deque* reading_expression()
{
	int* arr;
	// массив, в который записываются после перевода в число
	//arr[0] - прочитанное число; arr[1] - следующий символ
	arr = malloc(2 * sizeof(int));
	//создание дека
	struct deque* deque;
	deque = create_deque();
	char symbol;
	scanf_s("%c", &symbol);
	//заполнение первого элемента дека
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
	//заполнение остальных элементов
	// пока строка не закончилась
	while (symbol != '\n')
	{
		// символ или число записывается в дек
		//читается новый символ
		symbol = add_symbol(deque, symbol);
	}
	return deque;
}

// по таблице определяется куда какой знак записывать
// по строкам - предыдущий незаписанный символ, по столбцам - текущий
// 1 - записать в дополнительный дек
// 2 - из доп. дека в конец новой записи
// 3 - удалить и последний незаписанный, и текущий символ
// 4 - выражение преобразовано
// 0 - ошибка ввода 
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

// обратная запись
struct deque* RPN(struct deque* normal_notation)
{
	// deque - вспомогательный дек
	struct deque* deque,* rev_polish_notat;
	deque = create_deque();
	rev_polish_notat = create_deque();
	// массивы, в которых записываются 
	// аrr[0] - значение; arr[1] - тип
	// first_element - первый в нормальной записи, last_element - последний во вспомогательном
	int* first_element,* last_element;
	first_element = malloc(2 * sizeof(int));
	last_element = malloc(2 * sizeof(int));
	//заполнение первого элемента
	deque->first->data = 0;
	deque->first->type = 2;
	rev_polish_notat->first->data = 0;
	rev_polish_notat->first->type = 2;
	// добавлен элемен, показывающий, что строка закончена
	push_back(normal_notation, 0, 2);
	// сюда записывается соответствующее значение из таблицы
	int k = 0;
	//пока выражение не преобразовано
	while (k != 4)
	{
		first_element = top_front(normal_notation, first_element);
		// если прочитано число
		if (first_element[1] == 1 || (first_element[1] == 2 && first_element[0] == 8))
		{
			//просто записывается в конец новой записи
			first_element = pop_front(normal_notation, first_element);
			push_back(rev_polish_notat, first_element[0], first_element[1]);
		}
		else
		{
			// читается предыдущий и выполняется нужное действие
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
	// удаляется лишний элемент в начале
	first_element = pop_front(rev_polish_notat, first_element);
	return rev_polish_notat;
}

// вывод выражения
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

