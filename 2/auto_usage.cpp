#include <iostream>

// test auto ,const auto, const auto &

void test() {
	auto x = 0; // int
	const auto cx = x; // const int
	const auto &rx = cx; // const int &

	auto&& uref1 = x; // int &
	auto&& uref2 = cx; // const int &
	auto&& uref3 = rx; // const int &
	auto&& uref4 = 1;
}

int main(int argc, char **argv) {
	test();
	return 0;
}