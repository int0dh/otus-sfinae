#include <list>
#include <string>
#include <vector>
#include <climits>
#include <iostream>

// for some reason there is no std::is_container in std:: ._____.
// so we implement it here
template <typename ...>
using void_t = void;
template <typename T, class = void> struct is_container : std::false_type {};
template <typename T>
struct is_container<T, void_t<typename T::iterator>> : std::true_type {};

void print_ip(std::string &&str) {

	std::cout << str << std::endl;
}

template <typename T>
std::enable_if_t<std::is_integral<T>::value> print_ip(T t) {

	static_assert(CHAR_BIT == 8, "sorry dude, we do not support that here");

	for (size_t i = sizeof(T); i > 0; i --) {
		std::cout << ((t >> ((i - 1) * CHAR_BIT)) & ((1 << CHAR_BIT) - 1));
		if (i > 1) {
			std::cout << ".";
		}
	}
	std::cout << std::endl;
}

template <typename T>
std::enable_if_t<is_container<T>::value> print_ip(T &&t) {

	size_t offset = 0;
	for (auto const &k : t) {
		std::cout << k;
		if (offset < t.size() - 1) {
			std::cout << ".";
		}
		offset ++;
	}
	std::cout << std::endl;
}

int main() {

	print_ip(int8_t{-1});
	print_ip(int16_t{0});
	print_ip(int32_t{2130706433});
	print_ip(int64_t{8875824491850138409});
	print_ip(std::string{"Hello, world!"});
	print_ip(std::vector<int>{100, 200, 300, 400});
	print_ip(std::list<short>{400, 300, 200, 100});

	return 0;
} 
