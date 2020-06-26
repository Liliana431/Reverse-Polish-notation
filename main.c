
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
	printf("введите выражение\n");
	//чтение вражения
	Deque = reading_expression();
	//перевод в обратную польскую запись
	Deque = RPN(Deque);
	//вывод обратной польской записи
	printf("обратная польская запись: ");
	output(Deque);
	int a;
	//вычисление выражения
	a = calculation(Deque);
	//вывод значения
	printf("\n = %d", a);
}
