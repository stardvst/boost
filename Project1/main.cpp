#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/geometries/box.hpp>

#include <boost/geometry/index/rtree.hpp>
#include <boost/foreach.hpp>

#include <iostream>
#include <vector>

namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;

int main()
{
	using point = bg::model::point<float, 2, bg::cs::cartesian>;
	using box = bg::model::box<point>;
	using value = std::pair<box, unsigned>;

	bgi::rtree<value, bgi::quadratic<16>> rtree;

	for (unsigned idx = 0; idx < 10; ++idx)
	{
		const box bbox(point(idx + 0.0f, idx + 0.0f), point(idx + 0.5f, idx + 0.5f));
		std::cout << bg::wkt<box>(bbox) << "\n";
		rtree.insert(std::make_pair(bbox, idx));
	}

	box query_box(point(0, 0), point(5, 5));

	std::vector<value> result_s;
	rtree.query(bgi::intersects(query_box), std::back_inserter(result_s));

	// find 5 nearest values to a point
	std::vector<value> result_n;
	rtree.query(bgi::nearest(point(0, 0), 5), std::back_inserter(result_n));

	// display results
	std::cout << "\nspatial query box:" << std::endl;
	std::cout << bg::wkt<box>(query_box) << std::endl;

	std::cout << "\nspatial query result:" << std::endl;

	BOOST_FOREACH(value const &v, result_s)
		std::cout << bg::wkt<box>(v.first) << " - " << v.second << std::endl;

	std::cout << "\nknn query point:" << std::endl;
	std::cout << bg::wkt<point>(point(0, 0)) << std::endl;

	std::cout << "\nknn query result:" << std::endl;
	BOOST_FOREACH(value const &v, result_n)
		std::cout << bg::wkt<box>(v.first) << " - " << v.second << std::endl;

	std::cin.get();
	return 0;
}