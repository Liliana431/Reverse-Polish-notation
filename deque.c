
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct list
{
	// 1 - ���� �����; 2 - ����
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

//�������� ����
//� ������ � ���� ���� ���� ������ �����
//��� ���������� �������� push_front � push_back �� ��������
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

//�������� x � ������
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

//�������� x � �����
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

//����� �� ������. 
int PopFront(struct Deque* deque)
{
	
}

//����� �� �����.
int PopBack(struct Deque* deque)
{
	
}


