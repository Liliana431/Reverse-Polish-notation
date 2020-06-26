
#ifndef reverse_notation
#define reverse_notation

// перевод из номера в символ
char convert_number(int number);

//перевод из символа в его номер
//номер символа или 0 если цифра
int convert_symbol(char symbol);

// переводит последовательность символов в число
//возвращает массив в котором
//arr[0] - прочитанное число; arr[1] - следующий символ, перееведенный в число
int* convert(int* arr, char numeral);

// добавляет символ или число в дек
// читает следующий символ, его возвращает
char add_symbol(struct Deque* deque1, char symbol);

// чтение выражения
struct Deque* reading_expression();

// по таблице определяется куда какой знак записывать
// по строкам - предыдущий незаписанный символ, по столбцам - текущий
// 1 - записать в дополнительный дек
// 2 - из доп. дека в конец новой записи
// 3 - удалить и последний незаписанный, и текущий символ
// 4 - выражение преобразовано
// 0 - ошибка ввода 
int what_do(int last_element, int first_element);

// обратная запись
struct Deque* RPN(struct Deque* normal_notation);

// вывод выражения
void output(struct Deque* deque1);

#endif
