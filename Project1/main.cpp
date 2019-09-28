#include <iostream>
#include <string>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>

using namespace boost::multi_index;

struct animal
{
	std::string name;
	int legs;
};

using animal_multi = multi_index_container<animal,
	indexed_by<
	hashed_non_unique<member<animal, std::string, &animal::name>>,
	hashed_non_unique<member<animal, int, &animal::legs>>
	>
>;

int main()
{
	animal_multi animals;
	animals.insert({ "cat", 4 });
	animals.insert({ "shark", 0 });
	animals.insert({ "spider", 8 });
	animals.insert({ "scorpion", 8 });

	std::cout << animals.count("cat") << '\n';

	const animal_multi::nth_index<1>::type &legs_index = animals.get<1>();
	std::cout << legs_index.count(8) << '\n';

	//auto it = legs_index.find(4);
	//legs_index.modify(it, [](animal &a) { a.name = "dog"; });

	//std::cout << animals.count("dog") << '\n';

	std::cin.get();
	return 0;
}
