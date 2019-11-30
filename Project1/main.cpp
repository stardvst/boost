#include <boost/config.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <boost/graph/adjacency_list.hpp>
#include <boost/tuple/tuple.hpp>

int main()
{
	const int V = 2;

	using UGraph = boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS>;
	UGraph ugraph(V);
	boost::add_edge(0, 1, ugraph);
	boost::add_edge(0, 2, ugraph);

	std::cout << "the edges incident to v: ";
	boost::graph_traits<UGraph>::out_edge_iterator e, eEnd;
	boost::graph_traits<UGraph>::vertex_descriptor s = boost::vertex(0, ugraph);
	for (boost::tie(e, eEnd) = boost::out_edges(s, ugraph); e != eEnd; ++e)
	{
		std::cout << '(' << boost::source(*e, ugraph) << ", "
			<< boost::target(*e, ugraph) << ") ";
	}
	std::cout << '\n';

	using EdgeWeight = boost::property<boost::edge_weight_t, double>;
	bool found;

	// directed
	using DGraph = boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property, EdgeWeight>;
	DGraph dgraph(V);
	boost::graph_traits<DGraph>::vertex_descriptor u, v;
	u = boost::vertex(0, dgraph);
	v = boost::vertex(1, dgraph);

	typename boost::property_map<DGraph, boost::edge_weight_t>::type weight = boost::get(boost::edge_weight, dgraph);
	boost::add_edge(u, v, EdgeWeight(1.2), dgraph);
	boost::add_edge(v, u, EdgeWeight(2.4), dgraph);

	boost::graph_traits<DGraph>::edge_descriptor de1, de2;
	boost::tie(de1, found) = boost::edge(u, v, dgraph);
	boost::tie(de2, found) = boost::edge(v, u, dgraph);

	std::cout << "\nin directed graph (u, v) == (v, u): " << std::boolalpha << (de1 == de2) << '\n';
	std::cout << "weight (u, v): " << boost::get(weight, de1) << '\n'
		<< "weight (v, u): " << boost::get(weight, de2) << '\n';

	// undirected
	using UWeightGraph = boost::adjacency_list<boost::listS, boost::setS, boost::undirectedS, boost::no_property, EdgeWeight>;
	UWeightGraph ugraph2(V);
	boost::graph_traits<UWeightGraph>::vertex_descriptor uu, uv;
	uu = boost::vertex(0, ugraph2);
	uv = boost::vertex(1, ugraph2);

	typename boost::property_map<UWeightGraph, boost::edge_weight_t>::type uweight = boost::get(boost::edge_weight, ugraph2);
	boost::add_edge(uu, uv, EdgeWeight(3.1), ugraph2);

	boost::graph_traits<UWeightGraph>::edge_descriptor ue1, ue2;
	boost::tie(ue1, found) = boost::edge(uu, uv, ugraph2);
	boost::tie(ue2, found) = boost::edge(uv, uu, ugraph2);

	std::cout << "\nin undirected graph (u, v) == (v, u): " << std::boolalpha << (ue1 == ue2) << '\n';
	std::cout << "weight (u, v): " << boost::get(uweight, ue1) << '\n'
		<< "weight (v, u): " << boost::get(uweight, ue2) << '\n';

	std::cin.get();
	return EXIT_SUCCESS;
}
