#include <iostream>

 // ����T&�������Ƶ����
template <typename T>
void func( T& param ) 
{
	std::cout << param << std::endl;
}

void test0() {
	int x = 0;
	const int xc = 1;
	const int &rx = xc;
	func(x); // ���Ƶ��� int &
	func(xc); // ���Ƶ��� const int &
	func(rx); // ���Ƶ��� const int &
}


// ����const T&�������Ƶ����
template <typename T>
void func1(const T& param)
{
	std::cout << param << std::endl;
}

void test1() {
	int x = 0;
	const int xc = 1;
	const int &rx = xc;
	func1(x); // ���Ƶ��� const int &
	func1(xc); // ���Ƶ��� const int &
	func1(rx); // ���Ƶ��� const int &
}

// ���� T*�ı���������һ��

// ������������ ������������������

// ���� T&&�������Ƶ����
template <typename T>
void func2(T&& param)
{
	std::cout << param << std::endl;
}

void test2() {
	int x = 0;
	const int xc = 1;
	const int &rx = xc;
	func2(x); // x����ֵ ���Ƶ��� int &
	func2(xc); // xc����ֵ ���Ƶ��� const int &
	func2(rx); // rx����ֵ ���Ƶ��� const int &
	func2(3); // 3����ֵ ���Ƶ��� int &&
}

 // ����T param ��ֵ����
template <typename T>
void func3(T param)//��ֵ���ݶ������һ������������ �����Ƶ���int��
{
	std::cout << param << std::endl;
}

void test3() {
	int x = 0;
	const int xc = 1;
	const int &rx = xc;
	func3(x); // ���Ƶ��� int
	func3(xc); // ���Ƶ��� int
	func3(rx); // ���Ƶ��� int
}

int main(int argc, char **argv) {
	test0();
	test1();
	test2();
	test3();
	return 0;
}