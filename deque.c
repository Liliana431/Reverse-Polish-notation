
#include <stdio.h>
#include <stdlib.h>

//�������� � ����
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
	//��������� ������ ��� 1 ������� ����
	deque = malloc(sizeof(struct Deque));
	deque->first = malloc(sizeof(struct list));
	//���������� �� ������ � ��������� ������� (������ �� ����)
	deque->last = deque->first;
	// ��������� �� ��������� � ���������� ������� - NULL, �.�. �� ���
	deque->first->next = NULL;
	deque->first->prev = NULL;
	return deque;
}

//�������� x � ������
void push_front(struct Deque* Deque, int x, int t)
{
	struct list* P;
	// ��������� ������ ��� �������� ����
	P = malloc(sizeof(struct list));
	// ����������� �������� � ����
	P->data = x;
	P->type = t;
	// ���������� ����� �������� � �����, ��������� ��������� �� ������ ����
	P->prev = NULL;
	P->next = Deque->first;
	Deque->first->prev = P;
	Deque->first = P;
	return;
}

//�������� x � �����
void push_back(struct Deque* Deque, int x, int t)
{
	struct list* P;
	// ��������� ������ ��� �������� ����
	P = malloc(sizeof(struct list));
	// ����������� �������� � ����
	P->data = x;
	P->type = t;
	// ���������� ����� �������� � �����, ��������� ��������� �� ����� ����
	P->next = NULL;
	P->prev = Deque->last;
	Deque->last->next = P;
	Deque->last = P;
	return;
}

//����� �� ������
// arr[0] - ��������; arr[1] - ���
int* pop_front(struct Deque* Deque, int* arr)
{
	struct list* P;
	// � � ������������ ��������� �� ������ �������
	P = Deque->first;
	// ��������� ��������� �� ������
	Deque->first = Deque->first->next;
	Deque->first->prev = NULL;
	// ������ �������� � ���� ��������
	arr[0] = P->data;
	arr[1] = P->type;
	// �������� �
	free (P);
	return arr;
}

//����� �� �����
// arr[0] - ��������; arr[1] - ���
int* pop_back(struct Deque* Deque, int* arr)
{
	struct list* P;
	// � � ������������ ��������� �� ��������� �������
	P = Deque->last;
	// ��������� ��������� �� �����
	Deque->last = Deque->last->prev;
	Deque->last->next = NULL;
	// ������ �������� � ���� �������
	arr[0] = P->data;
	arr[1] = P->type;
	// �������� �
	free(P);
	return arr;
}

// ��������� �� ������
// arr[0] - ��������; arr[1] - ���
int* top_front(struct Deque* Deque, int* arr)
{
	arr[0] = Deque->first->data;
	arr[1] = Deque->first->type;
	return arr;
}

// ��������� �� �����
// arr[0] - ��������; arr[1] - ���
int* top_back(struct Deque* Deque, int* arr)
{
	arr[0] = Deque->last->data;
	arr[1] = Deque->last->type;
	return arr;
}