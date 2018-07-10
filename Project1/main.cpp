#include <iostream>
#include <boost/shared_ptr.hpp>
#include <Windows.h>

int main()
{
	boost::shared_ptr<int> p1{ new int {1} };
	std::cout << *p1 << '\n';

	boost::shared_ptr<int> p2{ p1 };
	std::cout << *p2 << '\n';

	p1.reset(new int{ 2 });
	std::cout << *p1.get() << '\n';

	p1.reset();

	std::cout << std::boolalpha << static_cast<bool>(p2) << '\n';

	// deleter
	boost::shared_ptr<void> handle{ OpenProcess(PROCESS_SET_INFORMATION, FALSE, GetCurrentProcessId()), CloseHandle() };
	
	std::cin.get();
	return 0;
}
