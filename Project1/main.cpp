#include <iostream>
#include <utility>
#include <boost/scope_exit.hpp>

template <typename T>
struct scope_exit
{
	scope_exit(T &&t) : m_t{ std::move(t) } {}
	~scope_exit() { m_t(); }
	T m_t;
};

template <typename T>
scope_exit<T> make_scope_exit(T &&t)
{
	return scope_exit<T>{ std::move(t) };
}

int *foo()
{
	auto i = new int{ 10 };
	auto cleanup = make_scope_exit([&i]() mutable
	{
		delete i; i = nullptr;
	});

	std::cout << *i << '\n';
	return i;
}

int main()
{
	int *j = foo();
	std::cout << *j << '\n';

	std::cin.get();
	return 0;
}
