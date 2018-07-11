#include <iostream>
#include <boost/ptr_container/ptr_vector.hpp>

int main()
{
	boost::ptr_vector<int> v;
	v.push_back(new int{ 1 });
	v.push_back(new int{ 2 });
	std::cout << v.back() << '\n';

	std::cin.get();
	return 0;
}
