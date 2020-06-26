
#ifndef calculating_expression
#define calculating_expression

//заметна параметра
void replacing_parameter(struct Deque* Deque);

//вычисление одного действия выражения
int value(int a, int b, int sign);

//вычисление выражения
int calculation(struct Deque* expression);

#endif
