
#ifndef Calculating_expression
#define Calculating_expression

//заметна параметра
void replacing_parameter(struct deque* deque);

//вычисление одного действия выражения
int value(int a, int b, int sign);

//вычисление выражения
int calculation(struct deque* expression);

#endif
