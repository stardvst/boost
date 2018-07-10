#define BOOST_SP_USE_QUICK_ALLOCATOR

#include <iostream>
#include <ctime>
#include <boost/shared_ptr.hpp>

int main()
{
	boost::shared_ptr<int> p;
	std::time_t then = std::time(nullptr);

	for (auto i = 0; i < 1'000'000; ++i)
		p.reset(new int{ i });

	std::time_t now = std::time(nullptr);
		
	std::cout << "now: " << now << '\n'
		<< "then: " << then << '\n'
		<< "diff: " << now - then << '\n';

	std::cin.get();
	return 0;
}
