#include <iostream>

auto derefUPless = [](const auto &a, const auto &b) {return a < b; };// 这就是写了一个模板函数，随便放各种类型

int main(int argc, char **argv) {
	std::cout << derefUPless(1.0, 2.0) << std::endl;//const double &
	std::cout << derefUPless(1, 2) << std::endl;//const int &
	std::cout << derefUPless('a', 'b') << std::endl;//const char &
	std::cout << derefUPless("abc", "abcd") << std::endl;//const char[4]&,const char[5]&
	return 0;
}