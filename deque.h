
#ifndef Deque
#define Deque

struct list
{
	//type: 1 - ���� �����; 2 - ����
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
struct deque* create_deque();

//�������� x � ������
void push_front(struct deque* deque, int x, int t);

//�������� x � �����
void push_back(struct deque* deque, int x, int t);

//����� �� ������
// arr[0] - ��������; arr[1] - ���
int* pop_front(struct deque* deque, int* arr);

//����� �� �����
// arr[0] - ��������; arr[1] - ���
int* pop_back(struct deque* deque, int* arr);

// ��������� �� ������
// arr[0] - ��������; arr[1] - ���
int* top_front(struct deque* deque, int* arr);

// ��������� �� �����
// arr[0] - ��������; arr[1] - ���
int* top_back(struct deque* deque, int* arr);

#endif