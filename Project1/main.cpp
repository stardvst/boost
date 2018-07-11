#include <iostream>
#include <boost/ptr_container/ptr_set.hpp>
#include <boost/ptr_container/indirect_fun.hpp>
#include <set>
#include <memory>
#include <functional>

int main()
{
	boost::ptr_set<int> s;
	s.insert(new int{ 2 });
	s.insert(new int{ 1 });
	std::cout << *s.begin() << '\n';

	std::set<std::unique_ptr<int>, boost::indirect_fun<std::less<>>> v;
	v.insert(std::make_unique<int>(int{ 2 }));
	v.insert(std::make_unique<int>(int{ 1 }));
	std::cout << **v.begin() << '\n';

	std::cin.get();
	return 0;
}
