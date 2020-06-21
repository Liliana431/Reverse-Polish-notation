
#ifndef deque
#define deque

struct list
{
	//type: 1 - если число; 2 - знак
	int type;
	int data;
	struct list* prev;
	struct list* next;
};

struct Deque
{
	struct list* first;
	struct list* last;
};

//создание дека
//в начале в деке есть одно пустое место
//для заполнения которого push_front и push_back не подходят
int* create_deque();

//положить x в начало
void push_front(struct Deque* deque, int x, int t);

//положить x в конец
void push_back(struct Deque* deque, int x, int t);

//взять из начала
// arr[0] - значение; arr[1] - тип
int* pop_front(struct Deque* deque, int* arr);

//взять из конца
// arr[0] - значение; arr[1] - тип
int* pop_back(struct Deque* deque, int* arr);

#endif