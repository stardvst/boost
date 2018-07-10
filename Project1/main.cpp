#include <iostream>
#include <boost/scoped_array.hpp>
#include <boost/range.hpp>

int main()
{
	boost::scoped_array<int> p{ new int[2] };
	*p.get() = 1;
	p[1] = 2;

	auto ptr = p.get();
	for (auto it : boost::make_iterator_range(ptr, ptr + 2))
		std::cout << it << ' ';

	p.reset(new int[3]);

	// can't get array's size, oops

	std::cin.get();
	return 0;
}
