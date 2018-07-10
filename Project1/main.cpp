#include <iostream>
#include <boost/shared_array.hpp>

int main()
{
	boost::shared_array<int> p1{ new int{1} };

	{
		boost::shared_array<int> p2{ p1 };
		p2[0] = 1;
	}

	std::cout << p1[0] << '\n';

	std::cin.get();
	return 0;
}
