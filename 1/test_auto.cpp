#include <iostream>

 // 测试T&的类型推导结果
template <typename T>
void func( T& param ) 
{
	std::cout << param << std::endl;
}

void test0() {
	int x = 0;
	const int xc = 1;
	const int &rx = xc;
	func(x); // 被推导成 int &
	func(xc); // 被推导成 const int &
	func(rx); // 被推导成 const int &
}


// 测试const T&的类型推导结果
template <typename T>
void func1(const T& param)
{
	std::cout << param << std::endl;
}

void test1() {
	int x = 0;
	const int xc = 1;
	const int &rx = xc;
	func1(x); // 被推导成 const int &
	func1(xc); // 被推导成 const int &
	func1(rx); // 被推导成 const int &
}

// 其中 T*的表现与引用一致

// 测试万能引用 ，后续还将继续测试

// 测试 T&&的类型推导结果
template <typename T>
void func2(T&& param)
{
	std::cout << param << std::endl;
}

void test2() {
	int x = 0;
	const int xc = 1;
	const int &rx = xc;
	func2(x); // x是左值 被推导成 int &
	func2(xc); // xc是左值 被推导成 const int &
	func2(rx); // rx是左值 被推导成 const int &
	func2(3); // 3是右值 被推导成 int &&
}

 // 测试T param 按值传递
template <typename T>
void func3(T param)//按值传递都会产生一个副本，所以 都被推导成int了
{
	std::cout << param << std::endl;
}

void test3() {
	int x = 0;
	const int xc = 1;
	const int &rx = xc;
	func3(x); // 被推导成 int
	func3(xc); // 被推导成 int
	func3(rx); // 被推导成 int
}

int main(int argc, char **argv) {
	test0();
	test1();
	test2();
	test3();
	return 0;
}