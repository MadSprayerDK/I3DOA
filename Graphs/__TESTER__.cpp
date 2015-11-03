#include "GraphToolkit.h"


int main()
{

	// Define graph nodes
	GraphToolkit<char>::Graph graph;
	GraphNode<char>* a = new GraphNode<char>('a');
	GraphNode<char>* b = new GraphNode<char>('b');
	GraphNode<char>* c = new GraphNode<char>('c');
	GraphNode<char>* d = new GraphNode<char>('d');
	GraphNode<char>* e = new GraphNode<char>('e');
	GraphNode<char>* f = new GraphNode<char>('f');
	GraphNode<char>* g = new GraphNode<char>('g');
	GraphNode<char>* h = new GraphNode<char>('h');

	// Connect the nodes with edges
	GraphToolkit<char>::addEdge(a, b, 3);
	GraphToolkit<char>::addEdge(a, d, 1);

	GraphToolkit<char>::addEdge(b, c, 4);
	GraphToolkit<char>::addEdge(b, d, 2);
	GraphToolkit<char>::addEdge(b, e, 3);

	GraphToolkit<char>::addEdge(c, e, 6);
	GraphToolkit<char>::addEdge(c, f, 1);
	GraphToolkit<char>::addEdge(c, g, 2);

	GraphToolkit<char>::addEdge(d, e, 11);

	GraphToolkit<char>::addEdge(e, f, 2);
	GraphToolkit<char>::addEdge(e, h, 1);

	// Add the nodes to a Graph object
	graph.push_back(a);
	graph.push_back(b);
	graph.push_back(c);
	graph.push_back(d);
	graph.push_back(e);
	graph.push_back(f);
	graph.push_back(g);
	graph.push_back(h);

	// Dump the graph
	GraphToolkit<char>::dumpGraph(graph);

	cout << "----" << endl;

	GraphToolkit<char>::Dijkstra(&graph, a);
	GraphToolkit<char>::dumpGraph(graph);

	cout << "----" << endl;
	cout << "New Example" << endl;
	cout << "----" << endl;

	GraphToolkit<char>::Graph graph2;

	auto a2 = new GraphNode<char>('a');
	auto b2 = new GraphNode<char>('b');
	auto c2 = new GraphNode<char>('c');
	auto d2 = new GraphNode<char>('d');
	auto e2 = new GraphNode<char>('e');
	auto f2 = new GraphNode<char>('f');
	auto g2 = new GraphNode<char>('g');
	auto h2 = new GraphNode<char>('h');

	graph2.push_back(a2);
	graph2.push_back(b2);
	graph2.push_back(c2);
	graph2.push_back(d2);
	graph2.push_back(e2);
	graph2.push_back(f2);
	graph2.push_back(g2);
	graph2.push_back(h2);

	GraphToolkit<char>::addEdge(a2, b2, 3);
	GraphToolkit<char>::addEdge(a2, d2, 1);

	GraphToolkit<char>::addEdge(b2, c2, 4);
	GraphToolkit<char>::addEdge(b2, d2, 2);
	GraphToolkit<char>::addEdge(b2, e2, 11);

	GraphToolkit<char>::addEdge(c2, g2, 2);
	GraphToolkit<char>::addEdge(c2, e2, 6);

	GraphToolkit<char>::addEdge(e2, f2, 0);

	GraphToolkit<char>::addEdge(f2, e2, 4);

	GraphToolkit<char>::addEdge(h2, e2, 1);


	GraphToolkit<char>::dumpGraph(graph2);

	GraphToolkit<char>::Dijkstra(&graph2, a2);

	cout << "----" << endl;

	GraphToolkit<char>::dumpGraph(graph2);

	return 0;
}