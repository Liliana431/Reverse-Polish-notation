
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
struct Deque* create_deque();

//�������� x � ������
void push_front(struct Deque* Deque, int x, int t);

//�������� x � �����
void push_back(struct Deque* Deque, int x, int t);

//����� �� ������
// arr[0] - ��������; arr[1] - ���
int* pop_front(struct Deque* Deque, int* arr);

//����� �� �����
// arr[0] - ��������; arr[1] - ���
int* pop_back(struct Deque* Deque, int* arr);

// ��������� �� ������
// arr[0] - ��������; arr[1] - ���
int* top_front(struct Deque* Deque, int* arr);

// ��������� �� �����
// arr[0] - ��������; arr[1] - ���
int* top_back(struct Deque* Deque, int* arr);

#endif