
#ifndef reverse_notation
#define reverse_notation

// ������� �� ������ � ������
char convert_number(int number);

//������� �� ������� � ��� �����
//����� ������� ��� 0 ���� �����
int convert_symbol(char symbol);

// ��������� ������������������ �������� � �����
//���������� ������ � �������
//arr[0] - ����������� �����; arr[1] - ��������� ������, ������������� � �����
int* convert(int* arr, char numeral);

// ��������� ������ ��� ����� � ���
// ������ ��������� ������, ��� ����������
char add_symbol(struct Deque* deque1, char symbol);

// ������ ���������
struct Deque* reading_expression();

// �� ������� ������������ ���� ����� ���� ����������
// �� ������� - ���������� ������������ ������, �� �������� - �������
// 1 - �������� � �������������� ���
// 2 - �� ���. ���� � ����� ����� ������
// 3 - ������� � ��������� ������������, � ������� ������
// 4 - ��������� �������������
// 0 - ������ ����� 
int what_do(int last_element, int first_element);

// �������� ������
struct Deque* RPN(struct Deque* normal_notation);

// ����� ���������
void output(struct Deque* deque1);

#endif
