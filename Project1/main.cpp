#include <iostream>
#include <boost/scoped_ptr.hpp>

// const & is ok
void f(boost::scoped_ptr<int> ptr)
{
	std::cout << *ptr << '\n';
}

int main()
{
	boost::scoped_ptr<int> p{ new int{ 1 } };

	// error
	f(p);

	std::cin.get();
	return 0;
}
