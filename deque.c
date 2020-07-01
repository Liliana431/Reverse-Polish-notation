
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

struct deque
{
	struct list* first;
	struct list* last;
};

//�������� ����
//� ������ � ���� ���� ���� ������ �����
//��� ���������� �������� push_front � push_back �� ��������
int* create_deque()
{
	struct deque* deque;
	//��������� ������ ��� 1 ������� ����
	deque = malloc(sizeof(struct deque));
	deque->first = malloc(sizeof(struct list));
	//���������� �� ������ � ��������� ������� (������ �� ����)
	deque->last = deque->first;
	// ��������� �� ��������� � ���������� ������� - NULL, �.�. �� ���
	deque->first->next = NULL;
	deque->first->prev = NULL;
	return deque;
}

//�������� x � ������
void push_front(struct deque* deque, int x, int t)
{
	struct list* P;
	// ��������� ������ ��� �������� ����
	P = malloc(sizeof(struct list));
	// ����������� �������� � ����
	P->data = x;
	P->type = t;
	// ���������� ����� �������� � �����, ��������� ��������� �� ������ ����
	P->prev = NULL;
	P->next = deque->first;
	deque->first->prev = P;
	deque->first = P;
	return;
}

//�������� x � �����
void push_back(struct deque* deque, int x, int t)
{
	struct list* P;
	// ��������� ������ ��� �������� ����
	P = malloc(sizeof(struct list));
	// ����������� �������� � ����
	P->data = x;
	P->type = t;
	// ���������� ����� �������� � �����, ��������� ��������� �� ����� ����
	P->next = NULL;
	P->prev = deque->last;
	deque->last->next = P;
	deque->last = P;
	return;
}

//����� �� ������
// arr[0] - ��������; arr[1] - ���
int* pop_front(struct deque* deque, int* arr)
{
	struct list* P;
	// � � ������������ ��������� �� ������ �������
	P = deque->first;
	// ��������� ��������� �� ������
	deque->first = deque->first->next;
	deque->first->prev = NULL;
	// ������ �������� � ���� ��������
	arr[0] = P->data;
	arr[1] = P->type;
	// �������� �
	free (P);
	return arr;
}

//����� �� �����
// arr[0] - ��������; arr[1] - ���
int* pop_back(struct deque* deque, int* arr)
{
	struct list* P;
	// � � ������������ ��������� �� ��������� �������
	P = deque->last;
	// ��������� ��������� �� �����
	deque->last = deque->last->prev;
	deque->last->next = NULL;
	// ������ �������� � ���� �������
	arr[0] = P->data;
	arr[1] = P->type;
	// �������� �
	free(P);
	return arr;
}

// ��������� �� ������
// arr[0] - ��������; arr[1] - ���
int* top_front(struct deque* deque, int* arr)
{
	arr[0] = deque->first->data;
	arr[1] = deque->first->type;
	return arr;
}

// ��������� �� �����
// arr[0] - ��������; arr[1] - ���
int* top_back(struct deque* deque, int* arr)
{
	arr[0] = deque->last->data;
	arr[1] = deque->last->type;
	return arr;
}