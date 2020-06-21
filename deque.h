
#ifndef deque
#define deque

struct list
{
	//type: 1 - ���� �����; 2 - ����
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
int* create_deque();

//�������� x � ������
void push_front(struct Deque* deque, int x, int t);

//�������� x � �����
void push_back(struct Deque* deque, int x, int t);

//����� �� ������
// arr[0] - ��������; arr[1] - ���
int* pop_front(struct Deque* deque, int* arr);

//����� �� �����
// arr[0] - ��������; arr[1] - ���
int* pop_back(struct Deque* deque, int* arr);

#endif