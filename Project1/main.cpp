#include <iostream>
#include <boost/graph/edge_list.hpp>

int main()
{
	enum { u, v, x, y, z, N };
	char name[] = { 'u', 'v', 'x', 'y', 'z' };

	using Edge = std::pair<int, int>;
	Edge edges[] = { Edge(u, y), Edge(u, x), Edge(u, v),
		Edge(v, u),
		Edge(x, y)/* #5 */, Edge(x, v),
		Edge(y, v), Edge(y, z),
		Edge(z, u), Edge(z, x)
	};

	using Graph = boost::edge_list<Edge *>;
	Graph g(edges, edges + sizeof edges / sizeof Edge);

	typename boost::graph_traits<boost::edge_list<Edge *>>::edge_iterator e, e_end;
	boost::tie(e, e_end) = boost::edges(g);
	std::cout << "all edges:" << '\n';
	while (e != e_end)
	{
		std::cout << *e << '\n';
		++e;
	}

	std::cout << "source vertex for edge #5: " << name[boost::source(5, g)] << '\n';
	std::cout << "target vertex for edge #5: " << name[boost::target(5, g)] << '\n';

	std::cin.get();
}
