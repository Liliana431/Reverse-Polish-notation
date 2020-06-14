
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct list
{
	// 1 - если число; 2 - знак
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
int* create_deque()
{
	struct Deque* deque;
	deque = malloc(sizeof(struct Deque));
	deque->first = malloc(sizeof(struct list));
	deque->last = deque->first;
	deque->first->next = NULL;
	deque->first->prev = NULL;
	return deque;
};

//положить x в начало
void push_front(struct Deque* deque, int x, int t)
{
	struct list* P;
	P = malloc(sizeof(struct list));
	P->data = x;
	P->type = t;
	P->prev = NULL;
	P->next = deque->first;
	deque->first->prev = P;
	deque->first = P;
	return;
}

//положить x в конец
void push_back(struct Deque* deque, int x, int t)
{
	struct list* P;
	P = malloc(sizeof(struct list));
	P->data = x;
	P->type = t;
	P->next = NULL;
	P->prev = deque->last;
	deque->last->next = P;
	deque->last = P;
	return;
}

//взять из начала
// arr[0] - значение; arr[1] - тип
int pop_front(struct Deque* deque, int* arr)
{
	struct list* P;
	P = deque->first;
	deque->first = deque->first->next;
	deque->first->prev = NULL;
	arr[0] = P->data;
	arr[1] = P->type;
	free (P);
	return arr;
}

//взять из конца
// arr[0] - значение; arr[1] - тип
int pop_back(struct Deque* deque, int* arr)
{
	struct list* P;
	P = deque->last;
	deque->last = deque->last->prev;
	deque->last->next = NULL;
	arr[0] = P->data;
	arr[1] = P->type;
	free(P);
	return arr;
}

