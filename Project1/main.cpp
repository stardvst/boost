#include <boost/config.hpp>
#include <iostream>
#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/graph_utility.hpp>

int main()
{
	enum { A, B, C, D, E, F, N };
	const char *name = "ABCDEF";

	using Graph = boost::adjacency_matrix<boost::directedS>;

	Graph g(N);
	boost::add_edge(B, C, g);
	boost::add_edge(B, F, g);
	boost::add_edge(C, A, g);
	boost::add_edge(C, C, g);
	boost::add_edge(D, E, g);
	boost::add_edge(E, D, g);
	boost::add_edge(F, A, g);

	std::cout << "vertex set: ";
	boost::print_vertices(g, name);
	std::cout << '\n';

	std::cout << "edge set: ";
	boost::print_edges(g, name);
	std::cout << '\n';

	std::cout << "out-edges:\n";
	boost::print_graph(g, name);
	std::cout << '\n';

	std::cin.get();
	return EXIT_SUCCESS;
}
