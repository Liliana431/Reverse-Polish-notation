
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
	printf("введите выражение\n");
	//чтение вражения
	deque = reading_expression();
	//перевод в обратную польскую запись
	deque = RPN(deque);
	if (deque->first->type == 0)
		return;
	//вывод обратной польской записи
	printf("обратная польская запись: \n");
	output(deque);
	printf("\n");
	int a;
	//вычисление выражения
	a = calculation(deque);
	//вывод значения
	printf(" = %d", a);

}

//тесты:
//5+7+9/3-(4*2) = 7
//(((((5+3)/2)))*9) = 36
//(((((5+3)/2)*9  - ошибка ввода 
//((5+3)/2)))*9)  - ошибка ввода
//x+7+9/3-(4*2) = 12(х=10)
//5+7+x/3-(4*2) = 8(х=12)
//x+7+x/3-(4*2) = 11(х=9)