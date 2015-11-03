#pragma once

#include<cstdlib>
using namespace std;

template<class Item>
class GraphNode;


template<class Item>
class Edge
{
public:
	Edge(GraphNode<Item>* f = NULL, GraphNode<Item>* t = NULL, size_t w=1)
		: from(f), to(t), weight(w)
	{}
	GraphNode<Item>* from;
	GraphNode<Item>* to;
	size_t weight;
};

