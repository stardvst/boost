#include <iostream>
#include <typeinfo>
#include <boost/make_shared.hpp>

int main()
{
	auto p1 = boost::make_shared<int>(1);
	std::cout << typeid(p1).name() << '\n';

	auto p2 = boost::make_shared<int[]>(10);
	std::cout << typeid(p2).name() << '\n';
	
	std::cin.get();
	return 0;
}
