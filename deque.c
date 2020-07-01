
#include <stdio.h>
#include <stdlib.h>

//элементы в деке
struct list
{
	// 1 - если число; 2 - знак
	int type;
	int data;
	struct list* prev;
	struct list* next;
};

struct deque
{
	struct list* first;
	struct list* last;
};

//создание дека
//в начале в деке есть одно пустое место
//дл€ заполнени€ которого push_front и push_back не подход€т
int* create_deque()
{
	struct deque* deque;
	//выделение пам€ти под 1 элемент дека
	deque = malloc(sizeof(struct deque));
	deque->first = malloc(sizeof(struct list));
	//указательи на первый и последний элемент (сейчас он один)
	deque->last = deque->first;
	// указатели на следующий и предыдущий элемент - NULL, т.к. их нет
	deque->first->next = NULL;
	deque->first->prev = NULL;
	return deque;
}

//положить x в начало
void push_front(struct deque* deque, int x, int t)
{
	struct list* P;
	// выделение пам€ти дл€ элемента дека
	P = malloc(sizeof(struct list));
	// записывание значени€ и типа
	P->data = x;
	P->type = t;
	// св€зывание этого элемента с деком, изменение указател€ на начало дека
	P->prev = NULL;
	P->next = deque->first;
	deque->first->prev = P;
	deque->first = P;
	return;
}

//положить x в конец
void push_back(struct deque* deque, int x, int t)
{
	struct list* P;
	// выделение пам€ти дл€ элемента дека
	P = malloc(sizeof(struct list));
	// записывание значени€ и типа
	P->data = x;
	P->type = t;
	// св€зывание этого элемента с деком, изменение указател€ на конец дека
	P->next = NULL;
	P->prev = deque->last;
	deque->last->next = P;
	deque->last = P;
	return;
}

//вз€ть из начала
// arr[0] - значение; arr[1] - тип
int* pop_front(struct deque* deque, int* arr)
{
	struct list* P;
	// в – записываетс€ указатель на первый элемент
	P = deque->first;
	// изменение указател€ на начало
	deque->first = deque->first->next;
	deque->first->prev = NULL;
	// запись значени€ и типа элемента
	arr[0] = P->data;
	arr[1] = P->type;
	// удаление –
	free (P);
	return arr;
}

//вз€ть из конца
// arr[0] - значение; arr[1] - тип
int* pop_back(struct deque* deque, int* arr)
{
	struct list* P;
	// в – записываетс€ указатель на последний элемент
	P = deque->last;
	// изменение указател€ на конец
	deque->last = deque->last->prev;
	deque->last->next = NULL;
	// запись значени€ и типа элемент
	arr[0] = P->data;
	arr[1] = P->type;
	// удаление –
	free(P);
	return arr;
}

// прочитать из начала
// arr[0] - значение; arr[1] - тип
int* top_front(struct deque* deque, int* arr)
{
	arr[0] = deque->first->data;
	arr[1] = deque->first->type;
	return arr;
}

// прочитать из конца
// arr[0] - значение; arr[1] - тип
int* top_back(struct deque* deque, int* arr)
{
	arr[0] = deque->last->data;
	arr[1] = deque->last->type;
	return arr;
}